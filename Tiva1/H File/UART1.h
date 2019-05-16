#pragma once
#ifndef __UART1_H__
#define	__UART1_H__

#include "stdint.h"


void INT_UART_0(void);
void INT_UART_1(void);
void send_UARTA0(char D2[]);
void send_UARTA1(char D2[]);
int Recive1(char tiva2[]);



#endif // __UART1_H__
