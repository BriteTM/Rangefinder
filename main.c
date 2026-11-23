#include <msp430.h>
#include "stdio.h"
#include "Junior_Design.h"


#define MOSFET BIT5 // Mosfet at Port 1 pin 5.
#define ADCOUT BIT4 // ADC Out at Port 1 pin 4.


    void main(void) {
    Init_HW();
    LCD_Initialize();
    static unsigned int ADC_Result;

    P1DIR |= BIT5 | BIT4 | BIT6 | BIT7;
    P1OUT |= BIT5 | BIT4;
    char data[] = "Junior Design ";
    char data2[32] = "";
    int d1, d_1, d_10;

    while(1){
        P1OUT ^= BIT5;

        LCD_CLRscreen();
        ADC_Result = ADC_Read();
        Duty = (int)((float) ADC_Result / (float) 10.23);
        Ultrasonic_Trigger();
        Delay_Timer(DELAYT_100ms);
        d1 = Ultrasonic_Echo_Read();
        d_1 = (int)((float)d1*0.066929);
        d_10 = (int)((float)d1*0.66929)- d_1*10;
        sprintf(data2,"%dmm %d.%din",(int)((float)d1*3.4/2.0),d_1,d_10);


        //LCD Functions
        LCD_String(data);
        LCD_Cursor_Postion(0x40);
        LCD_Cursor_On_No_Blink();
        LCD_String(data2);

        Delay_Timer(DELAYT_500ms);
    }
}
