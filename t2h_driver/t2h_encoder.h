/*
 * t2h_encoder.h
 *
 *  Created on: Jul 28, 2021
 *      Author: ad565
 */

#ifndef T2H_DRIVER_T2H_ENCODER_H_
#define T2H_DRIVER_T2H_ENCODER_H_

#include "../t2h_config.h"

#ifdef use_encoder

	#ifdef use_stm32h7
	#include <t2h_driver/stm32h7/_interface_stm32h7.h>

	void t2h_encoder1_init();
	void t2h_encoder2_init();

	int16_t t2h_get_encoder1();
	int16_t t2h_get_encoder2();

	void t2h_set_encoder1(int16_t count);

	int16_t t2h_encoder1_get_speed();

	#endif

#endif

#endif /* T2H_DRIVER_T2H_ENCODER_H_ */
