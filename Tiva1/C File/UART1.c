#include <TM4C123.h>
#include "Servo.c"
#include "Global.c"
void INT_UART_0()
{

SYSCTL->RCGCGPIO |=1;
while((SYSCTL->PRGPIO & 1)==0){ }	

GPIOA->AFSEL|=0x03;
GPIOA->PCTL |=0x11;
GPIOA->DEN|=0x3;
SYSCTL->RCGCUART |=1;
while((SYSCTL->PRUART & 1)==0){ }	
UART0->CTL=0;
UART0->IBRD=8;
UART0->FBRD=44;
UART0->LCRH =0x70;
UART0->CC=0;
UART0->CTL =0x301;

UART0->ICR|=0x10;
UART0->IM |=0x10;
UART0->IFLS=0;
NVIC_EN0_R |=0x20;
__enable_irq();

}




void INT_UART_1()
{

SYSCTL->RCGCGPIO |=2;
while((SYSCTL->PRGPIO &2)==0){ }	

//GPIOA->LOCK=0x4c4f434b;
GPIOB->AFSEL|=0x03;
GPIOB->PCTL |=0x11;
GPIOB->DEN|=0x03;
SYSCTL->RCGCUART |=2;
while((SYSCTL->PRUART & 2)==0){ }	
UART1->CTL  = 0;
UART1->IBRD = 8;
UART1->FBRD = 44;
UART1->LCRH = 0x70;
UART1->CC=0;
UART1->CTL =0x301;

UART1->ICR =0x12;
UART1->IM =0x12;
UART1->IFLS=0;
NVIC_EN0_R |=0x40;
__enable_irq();

}




void send_UARTA0( char D2[])
{
	int i=0;
	while(D2[i]!='\0')
	{
	while((UART0->FR&0x20) !=0)
	{}
		UART0->DR=D2[i];
		i++;
	}
	UART0->DR=0x0D;// send enter 
	
}


void send_UARTA1( char D2[])
{
	int i=0;
	while(D2[i]!='\0')
	{
	while((UART1->FR&0x20) !=0)
	{}
		UART1->DR=D2[i];
		i++;
	}
	UART1->DR=0x0D;// send enter 
	
}
int Recive1(char tiva2[])
{
	char m;
	int q=0;
	while(m!=0x0D)
	{
		while((UART1->FR&0x10) !=0)
	{}
		m=UART1->DR;
	 tiva2[q++]=m;
	}
	return q-1;
	
}




