#include<lpc21xx.h>
#include"UART.h"

#define R 5
#define B 4
#define G 3
unsigned char my_data;
int main()
{
 uart_init();
 IODIR0|=(1<<R)|(1<<B)|(1<<G);
 IOCLR0|=(1<<R)|(1<<B)|(1<<G);
	
 while(1)
 {
  my_data=uart_rx();
  if(my_data== 'R')
  {
    IOSET0=1<<R;
	IOCLR0=1<<B;
	IOCLR0=1<<G;
  }
  else if(my_data== 'B')
  {
    IOSET0=1<<B;
	IOCLR0=1<<R;
	IOCLR0=1<<G;
  }
  else if(my_data== 'G')
  {
    IOSET0=1<<G;
	IOCLR0=1<<B;
	IOCLR0=1<<R;
  }
 
 }



}