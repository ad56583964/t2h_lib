/*
 * encoder_stm32f4.c
 *
 *  Created on: Jul 28, 2021
 *      Author: ad565
 */
#include "t2h_config.h"

#ifdef use_encoder

//t2h_driver置于最上方
#include "t2h_driver/t2h_encoder.h"

#include "stm32h7xx_hal_tim.h"
#include "tim.h"

#include "stm32h7xx_hal_lptim.h"
#include "lptim.h"


#define enable_encoder1

#ifdef enable_encoder1

//PA6 PA7
#define __ENCODER_1_TIM__    htim3

void t2h_encoder1_init()
{
	  HAL_TIM_Encoder_Start(&__ENCODER_1_TIM__, TIM_CHANNEL_ALL);
}

int16_t t2h_get_encoder1()
{
	return __HAL_TIM_GET_COUNTER(&__ENCODER_1_TIM__);
}

void t2h_set_encoder1(int16_t count)
{
	__HAL_TIM_SET_COUNTER(&__ENCODER_1_TIM__,count);
}


int16_t t2h_encoder1_get_speed()
{
	int encoder_count = t2h_get_encoder1();
	t2h_set_encoder1(0);
	return encoder_count;
}

#endif


#ifdef enable_encoder2

//PD12 PD13
#define __ENCODER_2_TIM__    htim4

void t2h_encoder2_init()
{
	  HAL_TIM_Encoder_Start(&__ENCODER_2_TIM__, TIM_CHANNEL_ALL);
}

int16_t t2h_get_encoder2()
{
	return __HAL_TIM_GET_COUNTER(&__ENCODER_2_TIM__);
}

#endif



#endif
