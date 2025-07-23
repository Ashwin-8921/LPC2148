#include<lpc21xx.h>
#include"UART.h"
#include"Timer.h"


unsigned int count=0;

int main()
{
	IODIR0&= ~(1<<10);
	IODIR0|=0X3C;
	IOCLR0|=0X3C;
	
	uart_init();
	while(1)
	{
		
		if(((IOPIN0>>10)&1) == 0)
		{
			count++;
			if(count > 4)
			{
				IOCLR0|=0X3C;
				count=0;
			}
			 delay_millisec(500);
			uart_str("count:");
			uart_tx(count+'0');
			uart_str("\r\n");
			
			if(count == 1)
			{
				IOSET0=0X04;
				
			}
			else if(count == 2)
			{
				IOSET0=0X08;
			
			}
			else if(count == 3)
			{
				IOSET0=0X10;
				
			}
			else if(count == 4)
			{
				IOSET0=0X20;
			}
			
		}
		
	}
	

}