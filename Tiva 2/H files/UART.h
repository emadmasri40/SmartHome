#ifndef __UART_H__
#define	__UART_H__

#include "stdint.h"


void UART5_Init(void);
uint8_t UART5_Read(void);
void UART5_Write(char data );
void send5_string(char *s);



#endif // __UART_H__
