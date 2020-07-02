/* Includes ------------------------------------------------------------------*/
#include "user_lsd_2004.h"
#include "i2c.h"
/* Private variables ---------------------------------------------------------*/
uint8_t vBitMask = 0;
/* Functions ----------------------------------------------------------------*/
/*******************************************************************************/
void mcDelay(uint16_t period)		// period = X-1mc
{
	TIM1->CNT = 0;
	TIM1->CR1 |= TIM_CR1_CEN;
	while(TIM1->CNT < period);
	TIM1->SR &= ~TIM_SR_UIF;
}
/*-----------------------------------------------------------------------------*/
/*******************************************************************************/
void SendByte(uint8_t byte, uint8_t mode)
{
	uint8_t vSeniorTetrad = 0;

	if(mode) {RS_SET();} 	// LCD_WriteByteByI2C(mask|=0x01)				Тип данных - DATA
	else {RS_RESET();}		// LCD_WriteByteByI2C(mask&=~0x01)			 Тип данных - COMMAND

	vSeniorTetrad = (byte>>4);
	SendHalfByte(vSeniorTetrad);
	SendHalfByte(byte);
}
/*-----------------------------------------------------------------------------*/
/*******************************************************************************/
void SendHalfByte(uint8_t halfbyte)
{
  halfbyte <<=4;
  //LCD_WriteByteByI2C(vBitMask | halfbyte);
  LCD_WriteByteByI2C((vBitMask |= E_SET) | halfbyte);
  mcDelay(2);
  LCD_WriteByteByI2C(vBitMask &= ~E_SET);
  mcDelay(50);
}
/*-----------------------------------------------------------------------------*/
/*******************************************************************************/
void LCD_WriteByteByI2C(uint8_t byte)
{
	I2C_TransmitData(I2C1, byte , ADDRESS);
}
/*-----------------------------------------------------------------------------*/
/*******************************************************************************/
void LCD_SendChar(char ch)
{
	SendByte(ch, DATA_MODE);
}
/*-----------------------------------------------------------------------------*/
/*******************************************************************************/
void LCD_String(char* str)
{
	uint8_t indexx = 0;
	while(str[indexx] != 0)
	{
		SendByte(str[indexx], DATA_MODE);
		indexx++;
	}
}
/*-----------------------------------------------------------------------------*/
/*******************************************************************************/
void LCD_SetPos(uint8_t x, uint8_t y)
{
	switch(y)
	{
		case 0:
			SendByte(x | 0x80, COMMAND_MODE);
			break;
		case 1:
			SendByte((0x40+x) | 0x80, COMMAND_MODE);
			break;
		case 2:
			SendByte((0x14+x) | 0x80, COMMAND_MODE);
			break;
		case 3:
			SendByte((0x54+x) | 0x80, COMMAND_MODE);
			break;
	}
}
/*-----------------------------------------------------------------------------*/
/*******************************************************************************/
void LCD_Clear(void)
{
	SendByte(0x01, COMMAND_MODE);
	LL_mDelay(2);
}
/*-----------------------------------------------------------------------------*/
/*******************************************************************************/
void LCD_Init(void)
{
  LL_mDelay(50);

  SendHalfByte(0x03);
  LL_mDelay(5);

  SendHalfByte(0x03);
  LL_mDelay(5);

  SendHalfByte(0x03);
  mcDelay(200);

  SendHalfByte(0x02);
  SendByte(0x28, COMMAND_MODE);
  SendByte(0x0C, COMMAND_MODE);
  LL_mDelay(1);

  SendByte(0x01, COMMAND_MODE);
  LL_mDelay(2);
  SendByte(0x06, COMMAND_MODE);
  LL_mDelay(1);
  SendByte(0x02, COMMAND_MODE);
  LL_mDelay(2);

  SETLED();
}












