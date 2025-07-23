#include<lpc21xx.h>
void uart_init()
{
	PINSEL0 = 0X05;
	U0LCR = 0x83;
	U0DLL = 97;
	U0DLM = 0;
	U0LCR = 0x03;
}

void uart_tx(unsigned char ch)
{
	U0THR = ch;
	while((U0LSR>>5&1)==0);
}

unsigned char uart_rx()
{
	while((U0LSR&1)==0);
	return U0RBR;
}
void uart_str(unsigned char* s)
{
	while(*s)
		uart_tx(*s++);
}
