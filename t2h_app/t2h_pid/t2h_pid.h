/*
 * t2h_pid.h
 *
 *  Created on: Sep 17, 2021
 *      Author: HFJ
 */
#include <math.h>

#ifndef T2H_APP_T2H_PID_T2H_PID_H_
#define T2H_APP_T2H_PID_T2H_PID_H_

//this is an pid application

#include "t2h_app/USMART/usmart.h"

//static unsigned int MotorSpeed_1, MotorSpeed_2;
//static int SpeedTarget = 30;
//static int MotorOutput_1, MotorOutput_2;

extern int Target_A, Target_B, Servo;
extern float Kp, Ki, Kd;
int SpeedInnerControl_Left(int Speed, int Target);
int SpeedInnerControl_Right(int Speed, int Target);
int DiversionControl(int Speed_Diversion, int Target_Diversion);
void Kinematic_Analysis(float velocity,float angle);

#endif /* T2H_APP_T2H_PID_T2H_PID_H_ */
