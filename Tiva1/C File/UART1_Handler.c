#include " UART1_Handler.h"
#include "UART1.c"
void UART1_Handler()
{
    
	  char tiva2[20];
	  char convert[]="    ";
	  int i=3;
	  int j=0;
	  int r;
	  int num=0;
 
		
  	r=Recive1(tiva2);

	if((strncmp(tiva2, "P30", 3 ) ==0))
	{
//		if(angle >127)
//		{
//			send_UARTA0(tiva2);
//			angle-=(1.38*53);
//		PWM0->_0_CMPA = angle;
//		}
		SERVO_ANGLE(-60);
	}
	else if((strncmp(tiva2, "N30", 3 ) ==0))
	{
//		if(angle<623)
//		{
//			send_UARTA0(tiva2);
//			angle+=1.38*53;
//			PWM0->_0_CMPA = angle;
//		}
		SERVO_ANGLE(60);
	}
	else if((strncmp(tiva2, "LED", 3 ) ==0))
  {
		j=0;
		
		
	  for(i=3;i<r;i++)
		 {
			 convert[j++]=tiva2[i];
		 }	 
		 
		  num=toString(convert);
	    PWM1->_3_CMPA = num  ;	 
	 }
	
	UART1->ICR |=0x12;

}
