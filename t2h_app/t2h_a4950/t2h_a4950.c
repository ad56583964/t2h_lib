/*
 * t2h_a4950.c
 *
 *  Created on: Jul 12, 2021
 *      Author: ad565
 */

#include "t2h_a4950.h"
#include "t2h_a4950_port.h"



void t2h_a4950_init()
{
	t2h_a4950_pwm_init();
	t2h_moto1_speed(0);
	t2h_moto2_speed(0);
}

void t2h_moto1_speed(int m1_speed)
{
	if(m1_speed > 0)
	{
		t2h_A1(1000-m1_speed);
		t2h_A2(1000);
	}
	else
	{
		t2h_A1(1000);
		t2h_A2(1000+m1_speed);
	}
}

void t2h_moto2_speed(int m2_speed)
{
	if(m2_speed > 0)
	{
		t2h_A4(1000-m2_speed);
		t2h_A3(1000);
	}
	else
	{
		t2h_A4(1000);
		t2h_A3(1000+m2_speed);
	}
}
int t2h_Read_Encoder(uint8_t TIMX)
{
   int Encoder_TIM;
   switch(TIMX)
	 {
		 case 3:  Encoder_TIM= (short)TIM3 -> CNT;  TIM3 -> CNT=0;break;
//		 case 4:  Encoder_TIM= (short)TIM4 -> CNT;  TIM4 -> CNT=0;break;
		 case 5:  Encoder_TIM= (short)TIM5 -> CNT;  TIM5 -> CNT=0;break;
		 default:  Encoder_TIM=0;
	 }
		return Encoder_TIM;
}
