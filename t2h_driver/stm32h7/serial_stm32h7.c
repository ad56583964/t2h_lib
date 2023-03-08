/*
 * serial_tm4c.c
 *
 *  Created on: 2021骞�7鏈�8鏃�
 *      Author: ad565
 */
#include "t2h_config.h"

#ifdef use_serial

//output_way
#include "../t2h_serial.h"

//peripherals driver
#include "stm32h7xx_hal_uart.h"

//cubemx auto build header
#include "usart.h"
#include "stdarg.h"
#include "stdio.h"
#include "string.h"

#define UART_TXBUF_SIZE         256
#define UART_RXBUF_SIZE         256
#define LOG_BUF_SIZE			256

#define TX_TIMEOUT 10
#define RX_TIMEOUT 1

#define MAX_DATA 5

#define MAX_MATLAB_DATA 5

//更改UART外设
#define __UART1_PORT__	huart1

extern UART_HandleTypeDef huart1;

//vofa	帧尾
//static uint8_t tail[4]= {0x00, 0x00, 0x80, 0x7f};

static char string[LOG_BUF_SIZE];

static char data0_buf[sizeof(float)*MAX_DATA+4*sizeof(char)] = {0};

static char matlab_data_buf[sizeof(int32_t)*MAX_MATLAB_DATA+1*sizeof(char)] = {0};


void t2h_uart1_send(uint8_t *pui8Buffer, uint32_t ui32Count)
{
	HAL_UART_Transmit(&__UART1_PORT__, pui8Buffer, ui32Count, TX_TIMEOUT);
}

void t2h_uart1_get(uint8_t *pui8Buffer, uint32_t ui32Count)
{
	HAL_UART_Receive(&__UART1_PORT__, pui8Buffer, ui32Count, RX_TIMEOUT);
}

void t2h_LOG0_init(void)
{

}

void t2h_LOG0(const char* fmt, ...)
{
    va_list ap;
    va_start(ap,fmt);//将第一个可变参数的地址付给ap，即ap指向可变参数列表的开始
    vsprintf(string,fmt,ap);//将参数fmt、ap指向的可变参数一起转换成格/sprintf（），只是参数类型不同
    t2h_uart1_send((uint8_t*)string, strlen(string));
    va_end(ap);    //ap付值为0，没什么实际用处，主要是为程序健壮性
}

void t2h_fdata0(float *fdata,uint8_t fcount)
{
	memset(data0_buf, 0, sizeof(data0_buf));
	for(int i = 0; i < fcount; i++)
	{
		*(float*) (data0_buf + (i * sizeof(float)) ) = fdata[i];
	}

	//帧尾
    *(data0_buf + fcount*sizeof(float)) = 0x00;
    *(data0_buf + fcount*sizeof(float) + 1) = 0x00;
    *(data0_buf + fcount*sizeof(float) + 2) = 0x80;
    *(data0_buf + fcount*sizeof(float) + 3) = 0x7f;

    t2h_uart1_send((uint8_t*)data0_buf,sizeof(float)*fcount+4*sizeof(char));
}

void t2h_matlab_fdata0(int32_t *fdata,uint8_t fcount)
{
	memset(matlab_data_buf, 0, sizeof(matlab_data_buf));
	for(int i = 0; i < fcount; i++)
	{
		*(int32_t*) (matlab_data_buf + (i * sizeof(int32_t)) ) = fdata[i];
	}

	//帧尾
    *(matlab_data_buf + fcount*sizeof(int32_t)) = ']';


    t2h_uart1_send((uint8_t*)matlab_data_buf,sizeof(int32_t)*fcount+1*sizeof(char));
}

#endif
