/*
 * t2h_a4950_port.h
 *
 *  Created on: Jul 28, 2021
 *      Author: ad565
 */

#ifndef T2H_APP_T2H_A4950_T2H_A4950_PORT_H_
#define T2H_APP_T2H_A4950_T2H_A4950_PORT_H_

#include "t2h_driver/t2h_pwm.h"

static inline void t2h_a4950_pwm_init(){
	t2h_start_pwm1();
	t2h_start_pwm2();
	t2h_start_pwm3();
	t2h_start_pwm4();
}

static inline void t2h_A1(int duty){
	t2h_set_pwm1(duty);
}

static inline void t2h_A2(int duty){
	t2h_set_pwm2(duty);
}

static inline void t2h_A3(int duty){
	t2h_set_pwm3(duty);
}

static inline void t2h_A4(int duty){
	t2h_set_pwm4(duty);
}

#endif /* T2H_APP_T2H_A4950_T2H_A4950_PORT_H_ */
