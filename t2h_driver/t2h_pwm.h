/*
 * t2h_pwm.h
 *
 *  Created on: 2021年7月23日
 *      Author: ad565
 */

#ifndef T2H_DRIVER_T2H_PWM_H_
#define T2H_DRIVER_T2H_PWM_H_

#include "../t2h_config.h"

#ifdef use_pwm

#ifdef use_tm4c

#include "tm4c123gxl/_interface_tm4c123gxl.h"

void t2h_LOG0_init();

void t2h_LOG0(const char* fmt, ...);

void InitUART1Transfer(void);

void t2h_uart1_int_handler(void);

void t2h_uart1_init();

void t2h_uart1_send(const uint8_t *pui8Buffer, uint32_t ui32Count);


#endif

#ifdef use_stm32h7
#include <t2h_driver/stm32h7/_interface_stm32h7.h>

void t2h_start_pwm1();
void t2h_start_pwm2();
void t2h_start_pwm3();
void t2h_start_pwm4();

void t2h_set_pwm1(int duty);
void t2h_set_pwm2(int duty);
void t2h_set_pwm3(int duty);
void t2h_set_pwm4(int duty);

#endif

#endif

#endif /* T2H_DRIVER_T2H_PWM_H_ */
