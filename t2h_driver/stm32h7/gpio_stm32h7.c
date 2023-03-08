/*
 * gpio_stm32f4.c
 *
 *  Created on: Jul 28, 2021
 *      Author: ad565
 */
#include "t2h_config.h"

#ifdef use_gpio

#include "t2h_driver/t2h_gpio.h"
#include "stm32h7xx_hal_gpio.h"
#include "gpio.h"


//a4950
#define A1_GPIO	GPIOA
#define A1_PIN  GPIO_PIN_1

#define A2_GPIO	GPIOA
#define A2_PIN  GPIO_PIN_2

//void t2h_gpio_A1_set(char pin_set)
//{
//	HAL_GPIO_WritePin(A1_GPIO, A1_PIN, pin_set);
//}
//
//void t2h_gpio_A2_set(char pin_set)
//{
//	HAL_GPIO_WritePin(A2_GPIO, A2_PIN, pin_set);
//}

#endif
