#include <TM4C123.h>
#include "Global.h"
#define CTRL_R          ((*((volatile unsigned long *)0xE000E010))&0x10000)
int toString(char a[])
{
	int c, sign, offset, n;

	c = 0;
	n = 0;
	while (a[c] != '\0')
	{
		if ((0X30 <= a[c]) && (a[c] <= 0X39))
		{
			n = n * 10 + a[c] - '0';

		}
		c++;
	}
	return n;
}

void delayms(int Dm)
		{
			while (Dm != 0)

			{
				SysTick->LOAD = 16000 - 1;
				SysTick->VAL = 0;
				SysTick->CTRL = 5;
				while (CTRL_R == 0) {
				}
				SysTick->CTRL = 1 << 16;
				Dm -= 1;

			}
		}
void clean(char a[])
{
	int i = 0;
	while (a[i] != '\0')
	{
		a[i] = '\0';
		i++;
	}
}