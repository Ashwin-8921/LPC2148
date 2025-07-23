#include<lpc21xx.h>

unsigned long int x;

int main() {
  x=300;
  PINSEL1=0x00000400; //P0.21 as PWM5
  PWMMR0=0x0000000F;  //set PWM period
  PWMMR5=0x00000000;  //initial duty cycle
  PWMMCR=0x00000003;  //reset and interrupt on MR0 match
  PWMPCR=0x00002000;  //enable PWM5 output
  PWMTCR=0x00000009;  //enable PWM and counter
  PWMLER=0x00000020;  //load MR5 value

  while(1) {
    while((PWMIR&0x01)==0); //wait for interrupt
    PWMIR=0x01;             //clear interrupt flag
    PWMMR5=x;               //update duty cycle
    if(x>=PWMMR0) x=0;      //reset if exceeds max
    x=x+300;                //increase speed
    PWMLER=0x00000020;      //latch new value
  }
}
