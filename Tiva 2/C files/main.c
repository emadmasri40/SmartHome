#include "tm4c123gh6pm.h"
#include "ADC.h"
#include <stdint.h>
#include <stdio.h> 
#include "UART.h"
#include "Init_switch.h"
#include "TM4C123.h"
#include "LCD.h"


uint16_t AIN0_DValue;
uint16_t fAIN0_DValue;
float	AIN0_AValue;
volatile static uint32_t Result;

void SystemInit(void){

    ADC0_Init();
    UART5_Init();
    SW1_Init();
    SW2_Init();
	LCD_init();
	  
}
 

int main(void){
volatile  long ADC_Output  =0 ;
volatile long long 	temp_c =0 ; 
	char res[4];
	uint16_t prevv=0;
	int flag =0;
	int i=3;
	int j=0;
	char led[7]="LED";
	char prev[7]="LED";	
	SystemInit();

	LCD_Data('S');LCD_Cmd(0xC8); LCD_Data('i');LCD_Cmd(0xC8);LCD_Data('x');LCD_Cmd(0xC8);LCD_Data('t');LCD_Cmd(0xC8);LCD_Data('h');
	LCD_Cmd(0xC8);
	LCD_Data(' ');LCD_Cmd(0xC8);LCD_Data('F');LCD_Cmd(0xC8);LCD_Data('l');LCD_Cmd(0xC8);LCD_Data('e');LCD_Cmd(0xC8); LCD_Data('e'); //TEMP. NOW :
	LCD_Cmd(0xC8);LCD_Data('t');LCD_Cmd(0xC8);LCD_Data(' ');LCD_Cmd(0xC8);LCD_Data('G');LCD_Cmd(0xC8);LCD_Data('3');LCD_Cmd(0xC8);LCD_Data('9'); //cel= 
	LCD_Cmd(0xC8);
	LCD_Cmd(0xC0);
	LCD_Data('T');LCD_Cmd(0xC8); LCD_Data('E');LCD_Cmd(0xC8);LCD_Data('M');LCD_Cmd(0xC8);LCD_Data('P');LCD_Cmd(0xC8);LCD_Data('.');
	LCD_Cmd(0xC8);LCD_Data(' ');LCD_Cmd(0xC8);LCD_Data('N');LCD_Cmd(0xC8);LCD_Data('O');LCD_Cmd(0xC8);LCD_Data('W');LCD_Cmd(0xC8); LCD_Data(':');LCD_Cmd(0xC8);//TEMP. NOW :
	LCD_Data(' ');LCD_Cmd(0xC8);LCD_Data(' ');LCD_Cmd(0xC8);LCD_Data(' ');LCD_Cmd(0xC8);
	
while (1)	
{ 
		
	ADC0_SS3_In(&AIN0_DValue);
	fAIN0_DValue=(int)AIN0_DValue*ADC_RESOLUTION*3.0;
	
	if( fAIN0_DValue!=prevv )
	{
		prevv=fAIN0_DValue;
		sprintf (res ,"%d" ,prevv*100);

	for (i=0 ; i<4 && res[i]!='\0'; i++)
		led [i+3] = res[i];
		
		send5_string(led);
		
	
	}
		
		

	}
	return 0;

}
