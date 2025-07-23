#include<LPC21XX.h>
#include"uart_driver.h"
#include"lcd_driver.h"
unsigned int adc_val = 0;
float volt = 0.0;


unsigned int ADC_Val()
{
	unsigned int data;
	
	ADCR|=(0x01<<24);
	while(((ADDR>>31)&1)==0);
	data = ADDR;
	data = data>>6 & 0x3ff;

	volt = ((3.3*data)/1023)*100;

	return volt;
}

unsigned int ADC_Check()
{
	ADCR = 0x00000000;
	ADCR|=(0x01<<2);
	ADCR|=(13<<8);
	ADCR|=(0x01<<16);
	ADCR|=(0x01<<21);
	
	adc_val = ADC_Val();

	delay_ms(100);
	return adc_val;		
}

int main()
{
	unsigned int x;
	PINSEL1|=0x4000000;
	lcd_init();
	uart_init();
	while(1)
	{
		x = ADC_Check();
		lcd_command(0x80);
		lcd_command(0x01);
		lcd_string("TEMP:");
		lcd_int(x);
		delay_ms(100);

		if(x>27)
		{
			IOSET0|=(1<<7);
			uart_str("Temperature Exceeded Threshold Value\r\n");
			delay_ms(100);
		}
		else
		{
			IOCLR0|=(1<<7);
			uart_str("Temperature Within Threshold Value\r\n");
			delay_ms(100);

		}
		
		if(((IOPIN0>>14)&1)==0)
		{
			lcd_command(0xc0);
			lcd_string("Motion Detected");
			uart_str("Motion Detected\r\n");
			delay_ms(100);
		}
		else
		{
			lcd_command(0xc0);
			lcd_string("No Motion Detected");
			uart_str("No Motion Detected\r\n");
			delay_ms(100);

		}
		delay(2);
	}
}

