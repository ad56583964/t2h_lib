#include "control.h"
#include "tim.h"
#include "main.h"
#include "math.h"


//void GetMotorPulse(void)
//{
//	MotorSpeed = (short)(__HAL_TIM_GET_COUNTER(&htim3) / 18 * 12000 / 100);
//	__HAL_TIM_SET_COUNTER(&htim3, 0);
//}



void SetMotorVoltageAndDirection(int Pwm)
{
  __HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, Pwm);
}
