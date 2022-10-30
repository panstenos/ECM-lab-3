#include <xc.h>
#include "interrupts.h"

/************************************
 * Function to turn on interrupts and set if priority is used
 * Note you also need to enable peripheral interrupts in the INTCON register to use CM1IE.
************************************/
void Interrupts_init(void)
{   INTCONbits.PEIE = 1;    //turns on all the peripheral interrupts
    PIE2bits.C1IE = 1;      //enable the comparator interrupt bit
    INTCONbits.GIE = 1; 	//turn on interrupts globally (when this is off, all interrupts are deactivated)
}

/************************************
 * High priority interrupt service routine
 * Make sure all enabled interrupts are checked and flags cleared
************************************/
void __interrupt(high_priority) HighISR()
{   
    if(PIR2bits.C1IF == 1){//check the interrupt source
        LATHbits.LATH3 = !LATHbits.LATH3; //toggle LED
        PIR2bits.C1IF = 0; // turn flag off
	}
}

