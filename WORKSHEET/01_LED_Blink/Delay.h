#include<lpc21xx.h>

void delay_ms(unsigned int ms)
{
 T0PR=1500-1;
 T0TCR=0X01;
 while(T0TC < ms);
 T0TCR=0X03;
 T0TCR=0X00;
}

