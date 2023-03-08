/*
 * t2h_serial.h
 *
 *  Created on: 2021��7��10��
 *      Author: ad565
 */

#ifndef T2H_LIB_T2H_DRIVER_INC_T2H_SERIAL_H_
#define T2H_LIB_T2H_DRIVER_INC_T2H_SERIAL_H_

#include "../t2h_config.h"

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
//由于uint8_t 不得不放在这里
#include <t2h_driver/stm32h7/_interface_stm32h7.h>

void t2h_LOG0(const char* fmt, ...);

void t2h_fdata0(float *fdata,uint8_t fcount);

void t2h_matlab_fdata0(int32_t *fdata,uint8_t fcount);

#endif

#endif /* T2H_LIB_T2H_DRIVER_INC_T2H_SERIAL_H_ */
