
#include <xc.h>
#include<pic18f4550.h>
#include<stdlib.h>

void main()
{
    TRISD=0x00; // Configures PORTD as output
    T0CON=0x48; // Configures Timer 0 with prescaler
    TMR0L=0x00;
   
    while(1)
	{
         T0CONbits.TMR0ON=1; // Turn on timer 0
    		do
		{
       		 /*PORTD = TMR0L;*/ // Sets the value of TMR0L to PORTD

            // A delay loop for some time
       		 for(int i=0;i<500 ;i++)
				{
					for(int j=0;j<100;j++){ }
				}
    		}
   		while(INTCONbits.TMR0IF==0); // Checks for Timer 0 overflow flag
        
         	PORTD=0xFF; // Sets PORTD to 0xFF (all bits 1)
            
            // Another delay loop for some time
           for(int i=0;i<100 ;i++)
		{
			for(int j=0;j<100;j++){}
		}
          T0CONbits.TMR0ON=0;// Turns off Timer 0
          INTCONbits.TMR0IF=0; // Clears Timer 0 overflow flag
          if(T0CONbits.TMR0ON==0)
		{
              PORTD=0x00; // Sets PORTD to 0x00 (all bits 0)
		}
    }
}
