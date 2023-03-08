/*
 * i2c_stm32f4.c
 *
 *  Created on: 2021年7月31日
 *      Author: ad565
 */


#include "t2h_config.h"

#ifdef use_i2c

#include "t2h_driver/t2h_i2c.h"

#include "stm32h7xx_hal_i2c.h"
#include "i2c.h"

#define __I2C1__	hi2c1

#define __TIME_OUT__ 	10

extern I2C_HandleTypeDef hi2c1;

uint8_t t2h_i2c1_mem_write(uint8_t dev_addr, uint8_t mem_addr,uint8_t* pdata,uint8_t length)
{
	return HAL_I2C_Mem_Write(&__I2C1__, dev_addr, mem_addr,I2C_MEMADD_SIZE_8BIT, pdata, length,__TIME_OUT__);
}

uint8_t t2h_i2c1_mem_read(uint8_t dev_addr, uint8_t mem_addr,uint8_t* pdata,uint8_t length)
{
	return HAL_I2C_Mem_Read(&__I2C1__, dev_addr, mem_addr,I2C_MEMADD_SIZE_8BIT, pdata, length,__TIME_OUT__);
}

#endif
