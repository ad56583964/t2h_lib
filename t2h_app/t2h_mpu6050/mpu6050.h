#if !defined(__MPU6050_H)
#define __MPU6050_H

#include "t2h_mpu6050_port.h"


void MPU_GetTick(unsigned long *Tick);

uint8_t t2h_mpu6050_get_data(float *pitch, float *roll, float *yaw);
int t2h_mpu6050_init(void);

#endif // __MPU6050_H
