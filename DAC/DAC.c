#include <lpc214x.h>
#include"Timer.h"

void analogWrite(unsigned int DAC_data)
{
	PINSEL1=0x00080000;
	DACR = DAC_data << 6;
}

int main()
{
    int i;

    while(1)
    {
        for(i = 0; i < 100; i++)  // Goes from 0 to 990 in steps of 10
        {
            analogWrite(i * 10);  // Output PWM or analog value
            delayMicroseconds(200);         // Delay for 200 microseconds
        }
    }
}
