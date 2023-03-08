/*
 * t2h_gpio.h
 *
 *  Created on: Jul 28, 2021
 *      Author: ad565
 */

#ifndef T2H_DRIVER_T2H_GPIO_H_
#define T2H_DRIVER_T2H_GPIO_H_

#include "../t2h_config.h"
#ifdef use_gpio
#ifdef use_stm32f4
#include <t2h_driver/stm32h7/_interface_stm32h7.h>

//soft driver



void t2h_pin1_set(char pin_set);

void t2h_pin2_set(char pin_set);


#endif

#endif

#endif /* T2H_DRIVER_T2H_GPIO_H_ */
