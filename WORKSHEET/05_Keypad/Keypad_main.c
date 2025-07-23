#include<LPC21xx.h>
#include<string.h>
#include"keypad_driver.h"




int main()
{
	char s[5];
	int i;
	lcd_init();
	lcd_command(0x80);
	lcd_string("KEYPAD");
	lcd_command(0X01);
	lcd_command(0xc0);
	
	for(i=0;i<5;i++)
	{
		s[i]=key_scan();
		lcd_data('*');
	}
	lcd_string(s);
	if(strcmp(s,"89210")==0)
	{
		lcd_command(0X01);
		lcd_command(0x80);
		lcd_string("PASSWORD CORRECT");
		delay_ms(500);
		lcd_command(0X01);
		lcd_command(0x80);
		
	}
	else
	{
		lcd_command(0X01);
		lcd_command(0x80);
		lcd_string("PASSWORD INVALID");
		

	}
}
