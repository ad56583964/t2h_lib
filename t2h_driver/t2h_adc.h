/*
 * t2h_adc.h
 *
 *  Created on: 2021年8月3日
 *      Author: tyz
 */

#ifndef T2H_DRIVER_T2H_ADC_H_
#define T2H_DRIVER_T2H_ADC_H_

#include"t2h_config.h"

#ifdef use_stm32h7

#include "stm32h7/_interface_stm32h7.h"

#endif

void t2h_start_adc1();
uint16_t t2h_get_adc1();

#endif /* T2H_DRIVER_T2H_ADC_H_ */
