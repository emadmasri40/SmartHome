#include "tm4c123gh6pm.h"
#include "TM4C123.h"
#include "stdint.h"
#define GPIO_PF4_M					0x10U		// Pin 4 is connected to switch


//E1
void SW1_Init(void){
	volatile unsigned long delay;
  SYSCTL_RCGCGPIO_R |= 0x10;  
  delay = 0x10;        				
  GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY;   			  
  GPIO_PORTE_CR_R |= 0x02;          	 
  GPIO_PORTE_AMSEL_R &= ~0x02;      
  GPIO_PORTE_PCTL_R &= ~GPIO_PCTL_PE1_M;  
  GPIO_PORTE_AFSEL_R &= ~0x02;      
	GPIO_PORTE_DIR_R &= ~0x02;
	GPIO_PORTE_PUR_R |= 0x02;
  GPIO_PORTE_DEN_R |= 0x02;	
	GPIOE->IS&=~0x02;
	GPIOE->IBE&=~0x02;
  GPIOE->IEV&=~0x02; //falling edge
  GPIOE->ICR|=0x02;
  GPIOE->IM|=0x02;
	NVIC_EN0_R=0x10;	
}
//E2
void SW2_Init(void){
	volatile unsigned long delay;
  SYSCTL_RCGCGPIO_R |= 0x10;  
  delay = 0x10;        				
  GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY;   			  
  GPIO_PORTE_CR_R |= 0x04;          	 
  GPIO_PORTE_AMSEL_R &= ~0x04;      
  GPIO_PORTE_PCTL_R &= ~GPIO_PCTL_PE2_M;  
  GPIO_PORTE_AFSEL_R &= ~0x04;      
	GPIO_PORTE_DIR_R &= ~0x04;
	GPIO_PORTE_PUR_R |= 0x04;
  GPIO_PORTE_DEN_R |= 0x04;	
	GPIOE->IS&=~0x04;
	GPIOE->IBE&=~0x04;
  GPIOE->IEV&=~0x04; //falling edge
  GPIOE->ICR|=0x04;
  GPIOE->IM|=0x04;
	NVIC_EN0_R=0x10;	
}