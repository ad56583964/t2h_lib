/*
 * pwm_tm4c.c
 *
 *  Created on: 2021年7月23日
 *      Author: ad565
 */
#include "t2h_config.h"

#ifdef use_pwm

#include "../t2h_pwm.h"

#include "tim.h"

//PE9
#define __PWM1_TIM__		htim1
#define __PWM1_CHANNEL__	TIM_CHANNEL_1

//PE11
#define __PWM2_TIM__		htim1
#define __PWM2_CHANNEL__	TIM_CHANNEL_2

//PE13
#define __PWM3_TIM__		htim1
#define __PWM3_CHANNEL__	TIM_CHANNEL_3

//PE14
#define __PWM4_TIM__		htim1
#define __PWM4_CHANNEL__	TIM_CHANNEL_4

//uart句柄
extern TIM_HandleTypeDef htim1;


#define __PWM1_CNT__ 				2000
#define __PWM1_RESOLUTION__			1000

#define __PWM2_CNT__				2000
#define __PWM2_RESOLUTION__			1000

#define __PWM3_CNT__				2000
#define __PWM3_RESOLUTION__			1000

#define __PWM4_CNT__				2000
#define __PWM4_RESOLUTION__			1000



void t2h_start_pwm1()
{
	HAL_TIM_PWM_Start(&__PWM1_TIM__, __PWM1_CHANNEL__);
}

void t2h_start_pwm2()
{
	HAL_TIM_PWM_Start(&__PWM2_TIM__, __PWM2_CHANNEL__);
}

void t2h_start_pwm3()
{
	HAL_TIM_PWM_Start(&__PWM3_TIM__, __PWM3_CHANNEL__);
}

void t2h_start_pwm4()
{
	HAL_TIM_PWM_Start(&__PWM4_TIM__, __PWM4_CHANNEL__);
}
//0~1000


void t2h_set_pwm1(int duty)
{
	__HAL_TIM_SET_COMPARE(&__PWM1_TIM__, __PWM1_CHANNEL__, (int)(duty * (float)(__PWM1_CNT__/__PWM1_RESOLUTION__)));
}


void t2h_set_pwm2(int duty)
{
	__HAL_TIM_SET_COMPARE(&__PWM2_TIM__, __PWM2_CHANNEL__, (int)(duty * (float)(__PWM2_CNT__/__PWM2_RESOLUTION__)));
}


void t2h_set_pwm3(int duty)
{
	__HAL_TIM_SET_COMPARE(&__PWM3_TIM__, __PWM3_CHANNEL__, (int)(duty * (float)( __PWM3_CNT__/__PWM3_RESOLUTION__)));
}


void t2h_set_pwm4(int duty)
{
	__HAL_TIM_SET_COMPARE(&__PWM4_TIM__, __PWM4_CHANNEL__, (int)(duty * (float)( __PWM4_CNT__ /__PWM4_RESOLUTION__)));
}

#endif
