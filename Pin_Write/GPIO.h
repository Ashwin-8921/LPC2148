#include<lpc21xx.h>

void pinWrite(int pinNr,int pinValue)
{
	
	if(pinNr < 100)
	{
		IODIR0 |= (1<<pinNr);
		
		if(pinValue == 0)
		{
			IOCLR0|=(1<<pinNr);
		}
		else
		{
			IOSET0|=(1<<pinNr);
		}
	}
	else
	{
		pinNr=pinNr-100;
		
		IODIR0 |= (1<<pinNr);
		
		if(pinValue == 0)
		{
			IOCLR0|=(1<<pinNr);
		}
		else
		{
			IOSET0|=(1<<pinNr);
		}
		
		
	}
		
}
