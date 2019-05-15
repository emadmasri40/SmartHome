#include "tm4c123gh6pm.h"
#include "TM4C123.h"
#include "stdint.h"
#include "UART.h"
#include "LCD.h"

void GPIOE_Handler(void)
{
	GPIOE->ICR|=0x06;
	
	while((GPIOE->DATA&0x02)==0x00)
		{
			if ((GPIOE->DATA&0x02)==0x00)
			send5_string("N30");
			
			while((GPIOE->DATA&0x02)==0x00);
		}
		
			while((GPIOE->DATA&0x04)==0x00)
		{
			if ((GPIOE->DATA&0x04)==0x00)
	       send5_string("P30");
			while((GPIOE->DATA&0x04)==0x00);
		}
	
		
}

