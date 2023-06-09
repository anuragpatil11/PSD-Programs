
/*
 These lines include the necessary header files for the PIC18F4550 microcontroller,
 *  including the processor-specific header file "pic18f4550.h" and other standard library header files.
 */
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <pic18f4550.h>

void T0Delay(void);

void main(void) {
/*
 The TRISD register controls the data direction of Port D pins on the microcontroller. Setting it to 0x00 configures all Port D pins as output pins.
 */
    TRISD=0x00;
/*
 This is the main loop of the program. It continuously sets the value of Port D to 0x55 (alternating 1s and 0s) and then waits for a delay using the T0Delay() function. 
 * After the delay, it sets the value of Port D to 0x0a and waits for another delay. This loop keeps repeating indefinitely.
 */
while(1)
{
PORTD=0x55;
T0Delay();
PORTD=0x0a;
T0Delay();
}
return;
}
void T0Delay()
{
/*
 The T0Delay() function sets up Timer 0 (TMR0) for a specific delay. It configures the Timer 0 control register (T0CON) to enable the timer with a prescaler value of 1:2. 
 * It sets the initial count value for TMR0 to 0x3500 (0x35 in TMR0H and 0x00 in TMR0L). Finally, it enables Timer 0 by setting the TMR0ON bit.
 */    
T0CON=0x08;
TMR0H=0x35;
TMR0L=0x00;
/*
 The T0Delay() function enters a while loop and waits until the Timer 0 overflow flag (TMR0IF) is set. 
 * Once the overflow occurs, indicating that the desired delay has elapsed, it clears the TMR0ON bit to stop Timer 0 and clears the TMR0IF flag.
 */
T0CONbits.TMR0ON=1;
while(INTCONbits.TMR0IF==0);
T0CONbits.TMR0ON=0;
INTCONbits.TMR0IF=0;
}
