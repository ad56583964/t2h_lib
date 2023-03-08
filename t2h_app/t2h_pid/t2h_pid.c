/*
 * t2h_pid.c
 *
 *  Created on: Sep 17, 2021
 *      Author: HFJ
 */
#include "t2h_pid.h"

#define K 2.222f
#define SERVO_INIT 300
#define T 0.156f
#define L 0.1445f


//static int Error_Last_Diversion, Error_Prev_Diversion;
//static int Pwm_add, Pwm, Pwm_Diversion_add, Pwm_Diversion;
float Kp = 0, Ki = 0.5, Kd = 0;
//static float Kp_Diversion, Ki_Diversion, Kd_Diversion;

int SpeedInnerControl_Left(int Speed, int Target)
{
	static int Pwm_add_Left, Pwm_Left;
	static int Error_Last_Left, Error_Prev_Left;
	int Error_Left;

    Kp = Kp_2 / 1000;
    Ki = Ki_2 / 1000;
    Kd = Kd_2 / 1000;

	Error_Left = Target -Speed;

	Pwm_add_Left = Kp * (Error_Left - Error_Last_Left) + Ki * Error_Left + Kd * (Error_Left - 2.0f * Error_Last_Left + Error_Prev_Left);
	Pwm_Left += Pwm_add_Left;

	Error_Prev_Left = Error_Last_Left;
	Error_Last_Left = Error_Left;

	if(Pwm_Left >  1000) Pwm_Left = 1000;
	if(Pwm_Left < 0) Pwm_Left = 0;

	return Pwm_Left;
}

int SpeedInnerControl_Right(int Speed, int Target)
{
	static int Pwm_add, Pwm;
	static int Error_Last, Error_Prev;
	int Error;

    Kp = Kp_2 / 1000;
    Ki = Ki_2 / 1000;
    Kd = Kd_2 / 1000;

	Error = Target -Speed;

	Pwm_add = Kp * (Error - Error_Last) + Ki * Error + Kd * (Error - 2.0f * Error_Last + Error_Prev);
	Pwm += Pwm_add;

	Error_Prev = Error_Last;
	Error_Last = Error;

	if(Pwm >  1000) Pwm = 1000;
	if(Pwm < 0) Pwm = 0;

	return Pwm;
}

void Kinematic_Analysis(float velocity,float angle)
{
		Target_Left=velocity*(1+T*tan(angle)/2/L);
		Target_Right=velocity*(1-T*tan(angle)/2/L);  
		Servo=SERVO_INIT+angle*K;                    
}
