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
