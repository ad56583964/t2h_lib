#include "mpu6050.h"

#include <stdio.h>
#include <math.h>

#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"

#define q30 1073741824.0f
#define DEFAULT_SAMPLE_RATE 50 // 注意，这里需设置为实际采样速率的一半



void MPU_GetTick(unsigned long *Tick)
{
    UNUSED(Tick);
}

//陀螺仪方向设置
static signed char gyro_orientation[9] = {1, 0, 0,
                                          0, 1, 0,
                                          0, 0, 1};

static unsigned short inv_row_2_scale(const signed char *row)
{
    unsigned short b;

    if (row[0] > 0)
        b = 0;
    else if (row[0] < 0)
        b = 4;
    else if (row[1] > 0)
        b = 1;
    else if (row[1] < 0)
        b = 5;
    else if (row[2] > 0)
        b = 2;
    else if (row[2] < 0)
        b = 6;
    else
        b = 7; // error
    return b;
}

static unsigned short inv_orientation_matrix_to_scalar(const signed char *mtx)
{
    unsigned short scalar;
    /*
       XYZ  010_001_000 Identity Matrix
       XZY  001_010_000
       YXZ  010_000_001
       YZX  000_010_001
       ZXY  001_000_010
       ZYX  000_001_010
     */

    scalar = inv_row_2_scale(mtx);
    scalar |= inv_row_2_scale(mtx + 3) << 3;
    scalar |= inv_row_2_scale(mtx + 6) << 6;

    return scalar;
}

uint8_t t2h_mpu6050_get_data(float *pitch, float *roll, float *yaw)
{
    float q0 = 1.0f, q1 = 0.0f, q2 = 0.0f, q3 = 0.0f;
    unsigned long sensor_timestamp;
    short gyro[3], accel[3], sensors;
    unsigned char more;
    long quat[4];
    if (dmp_read_fifo(gyro, accel, quat, &sensor_timestamp, &sensors, &more))
        return 1;
    if (sensors & INV_WXYZ_QUAT)
    {
        q0 = quat[0] / q30; //q30格式转换为浮点数
        q1 = quat[1] / q30;
        q2 = quat[2] / q30;
        q3 = quat[3] / q30;
        //计算得到俯仰角/横滚角/航向角
        *pitch = asin(-2 * q1 * q3 + 2 * q0 * q2) * 57.3;                                    // pitch
        *roll = atan2(2 * q2 * q3 + 2 * q0 * q1, -2 * q1 * q1 - 2 * q2 * q2 + 1) * 57.3;     // roll
        *yaw = atan2(2 * (q1 * q2 + q0 * q3), q0 * q0 + q1 * q1 - q2 * q2 - q3 * q3) * 57.3; //yaw
    }
    else
    {
        return 2;
    }

    return 0;
}

static uint8_t run_self_test(void)
{
    int result;
    //char test_packet[4] = {0};
    long gyro[3], accel[3];
    result = mpu_run_self_test(gyro, accel);
    if (result == 0x3)
    {
        /* Test passed. We can trust the gyro data here, so let's push it down
		* to the DMP.
		*/
        float sens;
        unsigned short accel_sens;
        mpu_get_gyro_sens(&sens);
        gyro[0] = (long)(gyro[0] * sens);
        gyro[1] = (long)(gyro[1] * sens);
        gyro[2] = (long)(gyro[2] * sens);
        dmp_set_gyro_bias(gyro);
        mpu_get_accel_sens(&accel_sens);
        accel[0] *= accel_sens;
        accel[1] *= accel_sens;
        accel[2] *= accel_sens;
        dmp_set_accel_bias(accel);
        return 0;
    }
    else
        return 1;
}

int t2h_mpu6050_init(void)
{
    int result;
    if (!mpu_init(NULL))
    {
        printf("MPU6050 init successfully\n");
    }
    else
    {
        printf("MPU6050 init failed\n");

        return -1;
    }

    mpu_set_sensors(INV_XYZ_ACCEL | INV_XYZ_GYRO);
    mpu_configure_fifo(INV_XYZ_ACCEL | INV_XYZ_GYRO);
    mpu_set_sample_rate(DEFAULT_SAMPLE_RATE);

    result = dmp_load_motion_driver_firmware();
    if (!result)
    {
        printf("dmp load successfully.\n");
    }
    else
    {
        printf("dmp load failed\n");
        return -1;
    }
    dmp_set_orientation(inv_orientation_matrix_to_scalar(gyro_orientation)); //设置陀螺仪方向
    dmp_enable_feature(DMP_FEATURE_6X_LP_QUAT | DMP_FEATURE_TAP |            //设置dmp功能
                       DMP_FEATURE_ANDROID_ORIENT | DMP_FEATURE_SEND_RAW_ACCEL | DMP_FEATURE_SEND_CAL_GYRO |
                       DMP_FEATURE_GYRO_CAL);
    dmp_set_fifo_rate(DEFAULT_SAMPLE_RATE);

    run_self_test();

    result = mpu_set_dmp_state(1);
    if (!result)
    {
        printf("turn on dmp successfully.\n");
    }
    else
    {
        printf("turn on failed\n");
        return -1;
    }

    return 0;
}
