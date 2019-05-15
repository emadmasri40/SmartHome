#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "UART.h"
#include "LCD.h"
#include "TM4C123.h"
#define GPIO_PA10_M 0x03
#define GPIO_PB10_M 0x03



void UART5_Init(void){
	
	SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R5;	// UART Module 1 Run Mode Clock
	while((SYSCTL->PRUART & 0x20)==0){}
		
		SYSCTL_RCGCGPIO_R |= 0x10; // port E
			while((SYSCTL->PRGPIO & 0x10)==0){}		
	UART5_CTL_R &= ~UART_CTL_UARTEN; //UART disable
	UART5_IBRD_R = 8;    
  UART5_FBRD_R = 44;
	UART5_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN); //0x60 , 0x10 8 bits , UART Enable FIFOs
	UART5->CC=0;
	UART5_CTL_R |= 0x301; //UART Enable
	
	GPIO_PORTE_AFSEL_R |= 0x30; //E4,Rx E5,TX
	GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R&0xFFFFFF00) | (GPIO_PCTL_PE5_U5TX | GPIO_PCTL_PE4_U5RX);
	GPIO_PORTE_DEN_R |= 0x30;
	
UART5->IFLS=0;	
UART5->ICR|=0x10;
UART5->IM |=0x10;
NVIC_EN1_R |=1<<29; 
__enable_irq();
				
				
}


uint8_t UART5_Available(void){
	return ((UART5_FR_R&UART_FR_RXFE) == UART_FR_RXFE) ? 0 : 1;
}


uint8_t UART5_Read(void){
	while(UART5_Available() != 1);
	return (uint8_t)(UART5_DR_R&0xFF);
}

void UART5_Write(char data){
	while((UART5_FR_R&UART_FR_TXFF) != 0);
	UART5_DR_R = data;
	
}

void send5_string(char *s)
{
	while(*s !=0x00)
	{
		UART5_Write(*s);
		s++;
	}
	UART5_Write(0x0D);
}

void UART5_Handler()
{

	char tiva1[3];

	char m;

	int q = 0;
	LCD_Cmd(0x10);
	LCD_Cmd(0x10);
	LCD_Cmd(0x10);
	while (m != 0x0D)
	{
		while ((UART5->FR & 0x10) != 0)
		{
		}
		m = UART5->DR;
		tiva1[q++] = m;
	}
	LCD_Data(tiva1[0]);LCD_Cmd(0xC8); LCD_Data(tiva1[1]);LCD_Cmd(0xC8);LCD_Data(tiva1[2]);LCD_Cmd(0xC8);
	
	UART5->ICR |= 0x10;

}

