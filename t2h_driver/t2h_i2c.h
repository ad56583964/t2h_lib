/*
 * t2h_i2c.h
 *
 *  Created on: Jul 30, 2021
 *      Author: 16119
 */

#ifndef T2H_DRIVER_T2H_I2C_H_
#define T2H_DRIVER_T2H_I2C_H_

#include "../t2h_config.h"

#ifdef use_stm32h7

#include <t2h_driver/stm32h7/_interface_stm32h7.h>

uint8_t t2h_i2c1_mem_write(uint8_t dev_addr, uint8_t mem_addr, uint8_t* pdata,uint8_t length);
uint8_t t2h_i2c1_mem_read(uint8_t dev_addr, uint8_t mem_addr,uint8_t* pdata,uint8_t length);

#endif




#endif /* T2H_DRIVER_T2H_I2C_H_ */
