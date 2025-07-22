#include<lpc21xx.h>
#include"uart.h"
#include<stdio.h>


void delaySec(unsigned int sec);
unsigned int adc_get_data(void);


char buffer[20];
unsigned int adc;

int main()
{
	uart_init();
	while(1)
	{	
		adc = adc_get_data();
		uart_str("ADC:");
    sprintf(buffer, "%d\r\n", adc);
    uart_str(buffer);
		uart_str("\n\r");
		delaySec(1);
	
	}
	
}



unsigned int adc_get_data()
{
	unsigned int my_data;
	PINSEL0|=0x00000300; //set P0.4 as ADC input

	ADCR=0X00000000;
	ADCR=ADCR|(1<<6);  //channel 0
	ADCR=ADCR|(4<<8);  // set ADC clk < 4.5 MHz
	ADCR=ADCR|(1<<16); // set burst bit 
	ADCR=ADCR|(1<<21);  //PDN = 1
	ADCR=ADCR|(1<<24);  // start conversion
	
	while((ADDR & (1<<31))== 0);
	my_data=ADDR;
	my_data=(my_data>>6);
	my_data=my_data & 0x3FF;
	return my_data;
	
}

void delaySec(unsigned int sec) 
{
    T0PR = 15000000 - 1;        
    T0TCR = 0x01;              
    while (T0TC < sec);         
    T0TCR = 0x03;               
    T0TCR = 0x00;               
}