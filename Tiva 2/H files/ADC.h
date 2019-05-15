#ifndef __ADC_H__
#define __ADC_H__

#include <stdint.h>
#define ADC_RESOLUTION	(3.3 / 4096)

void ADC0_Init(void);

void ADC0_SS3_In(uint16_t *data);

#endif // __ADC_H__
