#include "tm4c123gh6pm.h"
#include "ADC.h"
#include "BlueLED.h"
#include "TM4C123.h"
#include <stdint.h>



void ADC0_Init(void){
	SYSCTL_RCGCADC_R |= SYSCTL_RCGCADC_R0;
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R4;
	ADC0_ACTSS_R &= ~0x8;
	ADC0_EMUX_R = (ADC0_EMUX_R&0x0FFF) | (0x0 << 12);
	ADC0_SSMUX3_R = 0x0;
	ADC0_SSCTL3_R |= ((0x1 << 2) | (0x1 << 1));
	ADC0_ACTSS_R |= 0x8;
	GPIO_PORTE_DIR_R &= ~(0x1 << 3);
	GPIO_PORTE_AFSEL_R |= (0x1 << 3);
  GPIO_PORTE_DEN_R &= ~(0x1 << 3);
  GPIO_PORTE_AMSEL_R |= (0x1 << 3);
}

void ADC0_SS3_In(uint16_t *data){
	ADC0_PSSI_R = (0x1 << 3);
	while((ADC0_RIS_R&(0x1 << 3))!=(0x1 << 3));
	*data = ADC0_SSFIFO3_R&0xFFF;
	ADC0_ISC_R = (0x1 << 3);
}
