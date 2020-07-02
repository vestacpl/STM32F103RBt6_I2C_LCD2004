#ifndef INC_USER_LSD_2004_H_
#define INC_USER_LSD_2004_H_

/* Private includes ---------------------------------------------------------*/
#include "stm32f1xx_ll_utils.h"
#include "stm32f1xx.h"
#include "stm32f103xb.h"
/* Private defines -----------------------------------------------------------*/
#define ADDRESS 0x4E
#define COMMAND_MODE 0x00
#define DATA_MODE 0x01
#define E_SET 0x04																	// Считать даные с шины (стробирование ON)
#define RS_SET() LCD_WriteByteByI2C(vBitMask|=0x01)					// Тип данных - DATA
#define RS_RESET() LCD_WriteByteByI2C(vBitMask&=~0x01)			// Тип данных - COMMAND
#define SETLED() LCD_WriteByteByI2C(vBitMask|=0x08)					// Включение подсветки
/* Functions prototypes ----------------------------------------------------*/
void LCD_Init(void);
void LCD_Clear(void);
void LCD_SendChar(char ch);
void LCD_String(char* str);
void LCD_SetPos(uint8_t x, uint8_t y);
void SendHalfByte(uint8_t halfbyte);
void SendByte(uint8_t byte, uint8_t mode);
void LCD_WriteByteByI2C(uint8_t byte);
void mcDelay(uint16_t period);
/*-----------------------------------------------------------------------------*/


#endif /* INC_USER_LSD_2004_H_ */
