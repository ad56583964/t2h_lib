/*
 * t2h_system.h
 *
 *  Created on: 2021年8月1日
 *      Author: ad565
 */

#ifndef T2H_DRIVER_T2H_SYSTEM_H_
#define T2H_DRIVER_T2H_SYSTEM_H_

#include "../t2h_config.h"

#ifdef use_stm32h7

#include <t2h_driver/stm32h7/_interface_stm32h7.h>

void t2h_delay(uint32_t ms);

#endif



#endif /* T2H_DRIVER_T2H_SYSTEM_H_ */
