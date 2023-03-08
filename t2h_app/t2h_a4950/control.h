#ifndef __CONTROL_H
#define __CONTROL_H

//全局变量
extern unsigned int MotorSpeed; // 电机速度
extern int SpeedTarget;         // 目标速度
extern int MotorOutput;         // 电机输出

//函数声明
void GetMotorPulse(void);                     // 通过TIM4读取电机脉冲并计算速度
void SetMotorVoltageAndDirection(int Pwm);    // 电机电压和方向控制函数

#endif

