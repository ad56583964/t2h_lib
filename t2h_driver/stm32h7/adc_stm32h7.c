/*
 * adc_stm32h7.c
 *
 *  Created on: 2021年8月3日
 *      Author: tyz
 */

#include "t2h_config.h"

#ifdef use_adc

#include "adc.h"
#include "t2h_driver/t2h_adc.h"

void t2h_start_adc1()
{
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1,10);
}

uint16_t t2h_get_adc1()
{
	uint16_t AD_Value;

	AD_Value = (uint16_t)HAL_ADC_GetValue(&hadc1);

	return AD_Value;
}
#endif
