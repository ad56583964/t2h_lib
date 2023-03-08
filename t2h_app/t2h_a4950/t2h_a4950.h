/*
 * t2h_a4950.h
 *
 *  Created on: Jul 12, 2021
 *      Author: ad565
 */

#ifndef T2H_A4950_H_
#define T2H_A4950_H_

#include "t2h_config.h"

#include "stdint.h"
#include "stdlib.h"

void t2h_a4950_init();
void t2h_moto1_speed(int m1_speed);
int t2h_Read_Encoder(uint8_t TIMX);
void t2h_moto2_speed(int m2_speed);

#endif /* T2H_A4950_H_ */
