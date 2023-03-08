/*
 * system_stm32f4.c
 *
 *  Created on: 2021年8月1日
 *      Author: ad565
 */

#include "t2h_config.h"

#ifdef use_system

#include "t2h_driver/t2h_system.h"

void t2h_delay(uint32_t ms)
{
	HAL_Delay(ms);
}



#endif
