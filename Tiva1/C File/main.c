#include <TM4C123.h>
#include "tm4c123gh6pm.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Servo.c"
#include "Tem.c"
#include "UART1.c"
#include "Global.c"
#include "PWM.c"
#include "UART1_Handler.c"


int main()
{
	char K[2];
	static int TEM1 = 0;
	static int save = 0;
	char word[3];
	int i;
	int j = 0;
	volatile int num;

	INT_TIMER();
	INT_PWM();
	INT_TEM();
	INT_UART_1();
	INT_UART_0();

	while (1)
	{

		TEM1 = READ_TEM();

		if (save != TEM1)
		{
			j = 0;
			save = TEM1;
			sprintf(K, "%d", TEM1);

			for (i = 0; i < 2; i++)
			{
				word[i] = K[j++];
			}
			word[2] = 'C';
			send_UARTA1(word);

			delayms(1000);
		}



	}
}

