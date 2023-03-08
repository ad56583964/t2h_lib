/*
 * t2h_oled_port.h
 *
 *  Created on: 2021年7月31日
 *      Author: ad565
 */

#ifndef T2H_APP_T2H_OLED_T2H_OLED_PORT_H_
#define T2H_APP_T2H_OLED_T2H_OLED_PORT_H_


#include "t2h_driver/t2h_i2c.h"
#include "t2h_driver/t2h_system.h"

static inline uint8_t t2h_ss1306_i2c_mem_write(uint8_t dev_addr, uint8_t mem_addr,uint8_t* pdata)
{
	return t2h_i2c1_mem_write(dev_addr, mem_addr, pdata,1);
}

#endif /* T2H_APP_T2H_OLED_T2H_OLED_PORT_H_ */
