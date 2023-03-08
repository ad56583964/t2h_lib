/*
 * t2h_mpu6050_port.h
 *
 *  Created on: Aug 2, 2021
 *      Author: ad565
 */

#ifndef T2H_APP_T2H_MPU6050_T2H_MPU6050_PORT_H_
#define T2H_APP_T2H_MPU6050_T2H_MPU6050_PORT_H_

#include "t2h_driver/t2h_i2c.h"

static inline uint8_t Sensors_I2C_WriteRegister(uint8_t Addr, uint8_t RegAddr, uint16_t Len, uint8_t *Data)
{
	return t2h_i2c1_mem_write(Addr<<1, RegAddr, Data, Len);
}


static inline uint8_t Sensors_I2C_ReadRegister(uint8_t Addr, uint8_t RegAddr, uint16_t Len, uint8_t *Data)
{
	return t2h_i2c1_mem_read(Addr<<1, RegAddr, Data, Len);
}



#endif /* T2H_APP_T2H_MPU6050_T2H_MPU6050_PORT_H_ */
