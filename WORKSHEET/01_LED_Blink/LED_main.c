#include<lpc21xx.h>
#include"Delay.h"


int main()
{
	IODIR0|=0x0F;
	IOCLR0|=0X0F;
	while(1)
	{
	  IOSET0|=(0X01);
	  delay_ms(1000);
	  IOSET0|=(0X01)<<1;
	  delay_ms(1000);
	  IOSET0|=(0X01)<<2;
	  delay_ms(1000);
	  IOSET0|=(0X01)<<3;
	  delay_ms(1000);
	  IOCLR0|=0X0F;
		delay_ms(1000);
	  
	}
	
}
	


