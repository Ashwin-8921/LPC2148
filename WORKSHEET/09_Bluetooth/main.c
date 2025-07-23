#include<LPC21xx.h>
#include"uart_driver.h"

#define LED 1<<5
int main()
{
	unsigned char c; 
	IODIR0|=LED;
	uart_init();
	while(1)
	{
		c=uart_rx();
		if(c=='A')
		{
			uart_str("LED ON");
			IOSET0|=LED;
			delay(2);
		} 
		else if(c=='B')
		{
			uart_str("LED OFF");
			IOCLR0|=LED;
			delay(2);
		}
	}
}
