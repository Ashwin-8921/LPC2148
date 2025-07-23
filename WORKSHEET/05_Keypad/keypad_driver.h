#include<lpc21xx.h>
#include"lcd_driver.h"
#define c0 (IOPIN0&(1<<5))
#define c1 (IOPIN0&(1<<6))
#define c2 (IOPIN0&(1<<7))
#define c3 (IOPIN0&(1<<8))
#define r0 1<<0
#define r1 1<<1
#define r2 1<<2
#define r3 1<<3



unsigned char key[4][4]={{'7','8','9','A'},{'4','5','6','B'},{'1','2','3','C'},{'*','0','#','D'}};

unsigned char key_scan(void)
{
	unsigned char row_val,col_val;
	IODIR0|=r0|r1|r2|r3;
	
	while(1)
	{
		IOCLR0|=r0|r1|r2|r3;
		IOSET0|=c0|c1|c2|c3;

		while((c0&&c1&&c2&&c3)==1);

		IOCLR0|=r0;
		IOSET0|=r1|r2|r3;
		if(((c0&&c1&&c2&&c3)==0))
		{
			row_val=0;
			break;
		}

		IOCLR0|=r1;
		IOSET0|=r0|r2|r3;
		if(((c0&&c1&&c2&&c3)==0))
		{
			row_val=1;
			break;
		}
			
		IOCLR0|=r2;
		IOSET0|=r1|r0|r3;
		if(((c0&&c1&&c2&&c3)==0))
		{
			row_val=2;
			break;
		}
			
		IOCLR0|=r3;
		IOSET0|=r1|r2|r0;
		if(((c0&&c1&&c2&&c3)==0))
		{
			row_val=3;
			break;
		}
	}
if(((c0&&c1&&c2&&c3)==0))
{
	if(c0==0)
		col_val=0;
	else if(c1==0)
		col_val=1;
	else if(c2==0)
		col_val=2;
	else if(c3==0)
		col_val=3;
}
		
	while(((c0&&c1&&c2&&c3)==0));
	delay_ms(500);
	return key[row_val][col_val];	
	
}
