#include <TM4C123.h>
#include "tm4c123gh6pm.h"
#include "Global.c"
#include <stdio.h>

void INT_PWM()
{

	SYSCTL->RCGCPWM |= 3;
	while ((SYSCTL->PRPWM & 0x3) == 0)
	{
	}
	SYSCTL->RCGCGPIO |= (1 << 1) | (1 << 5);
	while ((SYSCTL->PRGPIO & 0x22) == 0)
	{
	}
	GPIOB->AFSEL |= 1 << 6;
	GPIOF->AFSEL |= 0x08;

	GPIOF->PCTL &= ~0x0000F000;

	GPIOB->PCTL |= 0x04000000; // use pin 4 as pwm
	GPIOF->PCTL |= 0x00005000;

	GPIOB->DEN |= (1 << 6);
	GPIOF->DEN |= (1 << 3);

	SYSCTL->RCC |= 1 << 20; //DIVIDER

	PWM0->_0_CTL = 0;

	PWM1->_3_CTL = 0;

	PWM0->_0_GENA = 0xC8;
	PWM1->_3_GENB = 0xC8;

	PWM0->_0_LOAD = 4999;//SERVO

	PWM1->_3_LOAD = 950;

	PWM0->_0_CMPA = 375;
	PWM1->_3_CMPA = 5;

	PWM0->_0_CTL = 1;
	PWM1->_3_CTL = 1;

	PWM0->ENABLE |= 1;
	PWM1->ENABLE |= 0x80;

}