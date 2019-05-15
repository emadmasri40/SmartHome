#include "LCD.h"

static char buf[64] = {0};
void delay_milli(int n){
int i,j;
for(i=0;i<n;i++)
for(j=0;j<3180;j++)
{}
}
 

void delay_micro(int n){
int i,j;
for(i=0;i<n;i++)
for(j=0;j<3;j++){}
}


void LCD_write_string(char *str)
{
	int i = 0;

	while (str[i] != '\0')

	{

	LCD_Data(str[i]); // sending data on LCD byte by byte

	delay_milli(15);

	i++;

	}

}


void LCD_init(void){
	
SYSCTL->RCGCGPIO |= 0x02; //PORTB clock
SYSCTL->RCGCGPIO |= 0x01;//PORTC clock
GPIOA->DIR |=0xA0; //PORTC controls RS , E and  R/W // 5 , 6 , 7
GPIOA->DEN |=0xA0;
GPIOB->DIR |=0xFF; //PORTB D0-D7
GPIOB->DEN |=0xFF; //PORTB D0-D7
LCD_Cmd(0x38); //8-bits,2 display lines, 5x7 font
LCD_Cmd(0x06); //increments automatically
LCD_Cmd(0x0F); //Turn on display
LCD_Cmd(0x01); //clear display
 
}
 
void LCD_Cmd(unsigned char command)
{

GPIOA->DATA =0x00; //RS=0, E=0,RW=0
GPIOB->DATA =command;
GPIOA->DATA =1<<7;
delay_micro(0);
GPIOA->DATA=0<<7;
delay_micro(2000); 
if(command <4) delay_milli(2); else delay_micro(37); 
}

void LCD_Data(unsigned char data) 
{
 GPIOA->DATA|=1<<5;; //RS=1, E=0,RW=0
GPIOB->DATA =data;
GPIOA->DATA|=1<<7;
	
	
GPIOA->DATA=0<<7;
delay_micro(0); 
}








