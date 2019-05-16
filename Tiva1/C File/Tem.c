
#include "Tem.h"

void INT_TEM()
{
	SYSCTL->RCGCADC|=0x1;
	while((SYSCTL->PRADC &0x1)==0)
	{}
	ADC0->ACTSS &=~0x8;
	ADC0->SSCTL3 |=0xE;
	ADC0->ACTSS|=1<<3;
		
}




int READ_TEM()
{
	  int AD;
	  ADC0->PSSI |=0x8; //begining samplig in seq 3
	  while((ADC0->RIS&0x8)==0){}
		AD=(147.5-((247.5*ADC0->SSFIFO3)/4096));
	  ADC0->ISC=0x8;
		return AD;
		
}
