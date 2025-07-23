#include <lpc214x.h>
#include "interrupt.h"
#include"Timer.h"


int main(void)
{
    IODIR0 |= (1 << 15);     // P0.15 as output (optional blinking)
    initInterrupt();         // Initialize EINT0

    while (1)
    {
        IOSET0 |= (1 << 15); // Blink P0.15 (debug heartbeat)
        delay_ms(500);
        IOCLR0 |= (1 << 15);
        delay_ms(500);
    }
}
