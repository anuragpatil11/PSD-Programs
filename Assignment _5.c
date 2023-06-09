#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <pic18f4550.h>

int  mul(int num1,int num2){
    
    int res = 0 ;
    for(int i = 0 ; i < num2 ; i++)
    {
        if(i<=num2)
        {
            res = res+num1 ;
        }
        else
        {
            break;
        }
    }
    TRISD = 0;
    PORTD = res ;
}
 int  divide(int num1,int num2) {
     
    int quotient = 0;
    int remainder = num1;

    while (remainder >= num2) {
        remainder -= num2;
        quotient++;
    }

    TRISB = 0;
    PORTB =  quotient;
}
void main(void)
{
    
    mul(2,2);
   divide(8,2);
    
 } 
