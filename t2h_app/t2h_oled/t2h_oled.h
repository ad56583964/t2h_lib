/*
 * t2h_oled.h
 *
 *  Created on: Jul 30, 2021
 *      Author: 16119
 */

#ifndef T2H_DRIVER_T2H_OLED_H_
#define T2H_DRIVER_T2H_OLED_H_

#include "t2h_config.h"
#include "t2h_oled_port.h"

#include "stdlib.h"
#define OLED_MODE 0
#define SIZE 8
#define XLevelL		0x00
#define XLevelH		0x10
#define Max_Column	128
#define Max_Row		64
#define	Brightness	0xFF
#define X_WIDTH 	128
#define Y_WIDTH 	64




#define OLED_CMD  0
#define OLED_DATA 1
#define OLED_ADDRESS 0x78




void t2h_oled_fdata_init();
void t2h_oled_fdata_1(float num);
void t2h_oled_fdata_2(float num);
void t2h_oled_fdata_3(float num);
void t2h_oled_fdata_4(float num);
void t2h_oled_show();

#endif /* T2H_DRIVER_T2H_OLED_H_ */
