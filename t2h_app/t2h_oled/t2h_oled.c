/*
 * t2h_oled.c
 *
 *  Created on: Sep 17, 2021
 *      Author: HFJ
 */

#include "oledfont.h"
#include "t2h_oled.h"
#include "stdio.h"
#include "main.h"

#define __FDATA_SIZE__  6

static uint8_t fdata[__FDATA_SIZE__];

//i2c
void OLED_Write_IIC_Command(unsigned char I2C_Command)
{
	t2h_ss1306_i2c_mem_write(OLED_ADDRESS, 0x00, &I2C_Command);
}

void OLED_Write_IIC_Data(unsigned char IIC_Data)
{
	t2h_ss1306_i2c_mem_write(OLED_ADDRESS, 0x40, &IIC_Data);
}

void OLED_WR_Byte(unsigned dat,unsigned cmd)
{
	if(cmd)
	{
		OLED_Write_IIC_Data(dat);
	}
	else
	{
		OLED_Write_IIC_Command(dat);
	}
}


/********************************************
// fill_Picture
********************************************/
void fill_picture(unsigned char fill_Data)
{
	unsigned char m,n;
	for(m=0;m<8;m++)
	{
		OLED_WR_Byte(0xb0+m,0);		//page0-page1
		OLED_WR_Byte(0x00,0);		//low column start address
		OLED_WR_Byte(0x10,0);		//high column start address
		for(n=0;n<128;n++)
			{
				OLED_WR_Byte(fill_Data,1);
			}
	}
}

	void OLED_Set_Pos(unsigned char x, unsigned char y)
{ 	OLED_WR_Byte(0xb0+y,OLED_CMD);
	OLED_WR_Byte(((x&0xf0)>>4)|0x10,OLED_CMD);
	OLED_WR_Byte((x&0x0f),OLED_CMD);
}

void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD); 
	OLED_WR_Byte(0X14,OLED_CMD); 
	OLED_WR_Byte(0XAF,OLED_CMD); 
}

void OLED_Display_Off(void)
{
	OLED_WR_Byte(0X8D,OLED_CMD);  
	OLED_WR_Byte(0X10,OLED_CMD);  
	OLED_WR_Byte(0XAE,OLED_CMD);  
}

void OLED_Clear(void)
{
	uint8_t i,n;
	for(i=0;i<8;i++)
	{
		OLED_WR_Byte (0xb0+i,OLED_CMD);    
		OLED_WR_Byte (0x00,OLED_CMD);      
		OLED_WR_Byte (0x10,OLED_CMD);      
		for(n=0;n<128;n++)OLED_WR_Byte(0,OLED_DATA);
	} 
}
void OLED_On(void)
{
	uint8_t i,n;
	for(i=0;i<8;i++)
	{
		OLED_WR_Byte (0xb0+i,OLED_CMD);   
		OLED_WR_Byte (0x00,OLED_CMD);      
		OLED_WR_Byte (0x10,OLED_CMD);      
		for(n=0;n<128;n++)OLED_WR_Byte(1,OLED_DATA);
	} 
}

void OLED_ShowChar(uint8_t x,uint8_t y,uint8_t chr,uint8_t Char_Size)
{
	unsigned char c=0,i=0;
		c=chr-' ';
		if(x>Max_Column-1){x=0;y=y+2;}
		if(Char_Size ==16)
			{
			OLED_Set_Pos(x,y);
			for(i=0;i<8;i++)
			OLED_WR_Byte(F8X16[c*16+i],OLED_DATA);
			OLED_Set_Pos(x,y+1);
			for(i=0;i<8;i++)
			OLED_WR_Byte(F8X16[c*16+i+8],OLED_DATA);
			}
			else {
				OLED_Set_Pos(x,y);
				for(i=0;i<6;i++)
				OLED_WR_Byte(F6x8[c][i],OLED_DATA);

			}
}

uint32_t oled_pow(uint8_t m,uint8_t n)
{
	uint32_t result=1;
	while(n--)result*=m;
	return result;
}

void OLED_ShowNumber(uint8_t x,uint8_t y,uint32_t num,uint8_t len,uint8_t size2)
{
	uint8_t t,temp;
	uint8_t enshow=0;
	for(t=0;t<len;t++)
	{
		temp=(num/oled_pow(10,len-t-1))%10;
		if(enshow==0&&t<(len-1))
		{
			if(temp==0)
			{
				OLED_ShowChar(x+(size2/2)*t,y,' ',size2);
				continue;
			}else enshow=1;

		}
	 	OLED_ShowChar(x+(size2/2)*t,y,temp+'0',size2);
	}
}

void OLED_ShowString(uint8_t x,uint8_t y,uint8_t *chr,uint8_t Char_Size)
{
	while (*chr!='\0')
	{		OLED_ShowChar(x,y,*chr,Char_Size);
			x+=8;
		if(x>120){x=0;y+=2;}
			chr++;
	}
}

void OLED_ShowCHinese(uint8_t x,uint8_t y,uint8_t no)
{
	uint8_t t,adder=0;
	OLED_Set_Pos(x,y);
    for(t=0;t<16;t++)
		{
				OLED_WR_Byte(Hzk[2*no][t],OLED_DATA);
				adder+=1;
     }
		OLED_Set_Pos(x,y+1);
    for(t=0;t<16;t++)
			{
				OLED_WR_Byte(Hzk[2*no+1][t],OLED_DATA);
				adder+=1;
      }
}

void OLED_fuhao_write(unsigned char x,unsigned char y,unsigned char asc)
{

	  int i=0;
    OLED_Set_Pos(x*6,y);
    for(i=0;i<6;i++)
    {
       OLED_WR_Byte(F6x8[asc][i],OLED_DATA);
    }

}

void OLED_Num_write(unsigned char x,unsigned char y,unsigned char asc)
{
	int i=0;
	OLED_Set_Pos(x*6,y);
	for(i=0;i<6;i++)
	{
		 OLED_WR_Byte(F6x8[asc+16][i],OLED_DATA);
	}
}

void OLED_DrawBMP(unsigned char x0, unsigned char y0,unsigned char x1, unsigned char y1,unsigned char BMP[])
{
 unsigned int j=0;
 unsigned char x,y;

  if(y1%8==0) y=y1/8;
  else y=y1/8+1;
	for(y=y0;y<y1;y++)
	{
		OLED_Set_Pos(x0,y);
    for(x=x0;x<x1;x++)
	    {
	    	OLED_WR_Byte(BMP[j++],OLED_DATA);
	    }
	}
}
void OLED_Float(unsigned char Y,unsigned char X,double real,unsigned char N)
{
   unsigned char   i_Count=1;
   unsigned char   n[12]={0};
   long   j=1;
   int    real_int=0;
   double decimal=0;
   unsigned int   real_decimal=0;
   if(real<0)
	 {
		 real_int=(int)(-real);
	 }
	 else
	 {
		 real_int=(int)real;
   }
	 decimal=real-real_int;
   real_decimal=decimal*1e4;
   while(real_int/10/j!=0)
   {
      j=j*10;i_Count++;
   }
   n[0]=(real_int/10000)%10;
   n[1]=(real_int/1000)%10;
   n[2]=(real_int/100)%10;
   n[3]=(real_int/10)%10;
   n[4]=(real_int/1)%10;
   n[5]='.';
   n[6]=(real_decimal/1000)%10;
   n[7]=(real_decimal/100)%10;
   n[8]=(real_decimal/10)%10;
   n[9]=real_decimal%10;
   n[6+N]='\0';
   for(j=0;j<10;j++) n[j]=n[j]+16+32;
	 if(real<0)
	 {
		 i_Count+=1;
		 n[5-i_Count]='-';
	 }
   n[5]='.';
   n[6+N]='\0';
   OLED_ShowString(X,Y,&n[5-i_Count],12);
}

 void OLED_Float2(unsigned char Y,unsigned char X,double real,unsigned char N1,unsigned char N2)
{
   unsigned char   i_Count=1;
   unsigned char   n[12]={0};
   long   j=1;
   unsigned int   real_int=0;
   double decimal=0;
   unsigned int   real_decimal=0;
   X=X*8;
   real_int=(int)real;
   //Dis_Num(2,0,real_int,5);
   decimal=real-real_int;
   real_decimal=decimal*1e4;
   //Dis_Num(2,6,real_decimal,4);
   while(real_int/10/j!=0)
   {
      j=j*10;i_Count++;
   }
   n[0]=(real_int/10000)%10;
   n[1]=(real_int/1000)%10;
   n[2]=(real_int/100)%10;
   n[3]=(real_int/10)%10;

   n[5]='.';
   n[6]=(real_decimal/1000)%10;
   n[7]=(real_decimal/100)%10;
   n[8]=(real_decimal/10)%10;
   n[9]=real_decimal%10;
   n[6+N2]='\0';
   for(j=0;j<10;j++) n[j]=n[j]+16+32;
   n[5]='.';
   n[6+N2]='\0';
   OLED_ShowString(X,Y,&n[5-N1],12);
}

  void OLED_Num2(unsigned char x,unsigned char y, int number)
{
        unsigned char qian, bai, shi, ge;
	      int num =number;
	if(num<0)
	{
		num=-num;
		qian = num % 10000 / 1000;
		bai = num % 1000 / 100;
		shi=num % 100 / 10;
		ge=num % 10;
		OLED_fuhao_write(x,y,13);
		OLED_Num_write(x+1,y,qian);
		OLED_Num_write(x+2,y,bai);
		OLED_Num_write(x+3,y,shi);
		OLED_Num_write(x+4,y,ge);
	}
  else
	{
	    qian = num % 10000 / 1000;
		bai = num % 1000 / 100;
		shi=num % 100 / 10;
		ge=num % 10;
		OLED_fuhao_write(x,y,11);
		OLED_Num_write(x+1,y,qian);
		OLED_Num_write(x+2,y,bai);
		OLED_Num_write(x+3,y,shi);
		OLED_Num_write(x+4,y,ge);

  }

}

void OLED_Num3(unsigned char x,unsigned char y,int number)
{
  unsigned char ge,shi,bai;
	int num =number;
	if(num<0)
	{
		    num=-num;
		    OLED_fuhao_write(x,y,13); 
        ge = num %10;
        shi = num/10%10;
        bai = num/100;
        OLED_Num_write(x+3,y,ge);
        OLED_Num_write(x+2,y,shi);
        OLED_Num_write(x+1,y,bai);
	}
	else
	{
       OLED_fuhao_write(x,y,11);
        ge = num %10;
        shi = num/10 %10;
        bai = num/100;
        OLED_Num_write(x+3,y,ge);
        OLED_Num_write(x+2,y,shi);
        OLED_Num_write(x+1,y,bai);
  }
}

void OLED_Num4(unsigned char x,unsigned char y, int number)
{
	unsigned char qian,bai,shi,ge;
	int num =number;
	if(num<0)
	{
		num=-num;
	}
	qian=num/1000;
	bai=num%1000/100;
	shi=num/100%10;
	ge=num%10;

	OLED_Num_write(x,y,qian);
	OLED_Num_write(x+1,y,bai);
	OLED_Num_write(x+2,y,shi);
	OLED_Num_write(x+3,y,ge);
}


void OLED_Num5(unsigned char x,unsigned char y,unsigned int number)
{
        unsigned char wan,qian,bai,shi,ge;
        wan=number/10000;
	    	qian = number%10000/1000;
        bai=number%1000/100;
        shi=number%100/10;
        ge=number%10;
        OLED_Num_write(x,y,wan);
        OLED_Num_write(x+1,y,qian);
        OLED_Num_write(x+2,y,bai);
        OLED_Num_write(x+3,y,shi);
		    OLED_Num_write(x+4,y,ge);
}

//鲁玫脢录禄炉SSD1306
void OLED_Init(void)
{
	t2h_delay(800);
	OLED_WR_Byte(0xAE,OLED_CMD);//--display off
	OLED_WR_Byte(0x00,OLED_CMD);//---set low column address
	OLED_WR_Byte(0x10,OLED_CMD);//---set high column address
	OLED_WR_Byte(0x40,OLED_CMD);//--set start line address
	OLED_WR_Byte(0xB0,OLED_CMD);//--set page address
	OLED_WR_Byte(0x81,OLED_CMD); // contract control
	OLED_WR_Byte(0xFF,OLED_CMD);//--128
	OLED_WR_Byte(0xA1,OLED_CMD);//set segment remap
	OLED_WR_Byte(0xA6,OLED_CMD);//--normal / reverse
	OLED_WR_Byte(0xA8,OLED_CMD);//--set multiplex ratio(1 to 64)
	OLED_WR_Byte(0x3F,OLED_CMD);//--1/32 duty
	OLED_WR_Byte(0xC8,OLED_CMD);//Com scan direction
	OLED_WR_Byte(0xD3,OLED_CMD);//-set display offset
	OLED_WR_Byte(0x00,OLED_CMD);//

	OLED_WR_Byte(0xD5,OLED_CMD);//set osc division
	OLED_WR_Byte(0x80,OLED_CMD);//

	OLED_WR_Byte(0xD8,OLED_CMD);//set area color mode off
	OLED_WR_Byte(0x05,OLED_CMD);//

	OLED_WR_Byte(0xD9,OLED_CMD);//Set Pre-Charge Period
	OLED_WR_Byte(0xF1,OLED_CMD);//

	OLED_WR_Byte(0xDA,OLED_CMD);//set com pin configuartion
	OLED_WR_Byte(0x12,OLED_CMD);//

	OLED_WR_Byte(0xDB,OLED_CMD);//set Vcomh
	OLED_WR_Byte(0x30,OLED_CMD);//

	OLED_WR_Byte(0x8D,OLED_CMD);//set charge pump enable
	OLED_WR_Byte(0x14,OLED_CMD);//

	OLED_WR_Byte(0xAF,OLED_CMD);//--turn on oled panel
}

void t2h_oled_show_1(uint8_t *chr)
{
	OLED_ShowString(0,0,chr,12);
}

void t2h_oled_show_2(uint8_t *chr)
{
	OLED_ShowString(0,2,chr,12);
}

void t2h_oled_show_3(uint8_t *chr)
{
	OLED_ShowString(0,4,chr,12);
}

void t2h_oled_show_4(uint8_t *chr)
{
	OLED_ShowString(0,6,chr,12);
}

void t2h_oled_float(uint8_t x,uint8_t y,float real)
{
	sprintf((char *)fdata,"%.3f",real);
	OLED_ShowString(x,y,fdata,12);
}

void t2h_oled_fdata_1(float num)
{
	t2h_oled_float(60,0,num);
}

void t2h_oled_fdata_2(float num)
{
	t2h_oled_float(60,2,num);
}

void t2h_oled_fdata_3(float num)
{
	t2h_oled_float(60,4,num);
}

void t2h_oled_fdata_4(float num)
{
	t2h_oled_float(60,6,num);
}

void t2h_oled_fdata_init()
{
	OLED_Init();
	OLED_Clear();

	t2h_oled_show_1((uint8_t*)"L:");
	t2h_oled_show_2((uint8_t*)"R:");
}

void t2h_oled_show()
{
	OLED_Num2(3,0,Encoder_Right);					
	OLED_Num2(3,2,Encoder_Left);					
}




