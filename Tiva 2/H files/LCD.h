#include "tm4c123gh6pm.h"
#include "systick.h"
#include "TM4C123.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void delay_milli(int n);

/**********Make a delay in micro seconds***************/
void delay_micro(int n);

/**********Initiate LCD********************************/
void LCD_init(void);

/**********Send Commands to the LCD********************/
void LCD_Cmd(unsigned char command);

/**********Send Data To LCD****************************/
void LCD_Data(unsigned char data);

/**********Send String to LCD**************************/
void LCD_write_string(char *str);

/**********Send Integer to LCD through transform it to string then send it***********/
void LCD_Send_Intege(long long number);

