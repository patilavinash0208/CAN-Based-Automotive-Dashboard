#include <xc.h>
#include <string.h>
#include "message_handler.h"
#include "msg_id.h"
#include "can.h"
#include "clcd.h"

volatile unsigned char indicator_state = 'O';
volatile unsigned char blink_flag = 0;


void handle_speed_data(uint8_t *data, uint8_t len)
{
    //Implement the speed function
    clcd_print(data,LINE2(0));
}

void handle_gear_data(uint8_t *data, uint8_t len) 
{
    //Implement the gear function
    clcd_print(data,LINE2(5));
}

void handle_rpm_data(uint8_t *data, uint8_t len) 
{
    //Implement the rpm function
    clcd_print(data,LINE2(9));
}

void handle_indicator_data(uint8_t *data, uint8_t len) 
{
    //Implement the indicator function
    clcd_print(data,LINE2(14));
    
    indicator_state = data[0];
}

void update_indicator_leds(void)
{
    switch(indicator_state)
    {
        case 'L':

            PORTBbits.RB0 = blink_flag;
            PORTBbits.RB1 = blink_flag;

            PORTBbits.RB4 = 0;
            PORTBbits.RB5 = 0;
            PORTBbits.RB6 = 0;
            PORTBbits.RB7 = 0;

            break;

        case 'R':

            PORTBbits.RB0 = 0;
            PORTBbits.RB1 = 0;

            PORTBbits.RB4 = 0;
            PORTBbits.RB5 = 0;

            PORTBbits.RB6 = blink_flag;
            PORTBbits.RB7 = blink_flag;

            break;

        case 'H':

            PORTBbits.RB0 = blink_flag;
            PORTBbits.RB1 = blink_flag;

            PORTBbits.RB4 = 0;
            PORTBbits.RB5 = 0;

            PORTBbits.RB6 = blink_flag;
            PORTBbits.RB7 = blink_flag;

            break;

        case 'O':

        default:

            PORTBbits.RB0 = 0;
            PORTBbits.RB1 = 0;

            PORTBbits.RB4 = 0;
            PORTBbits.RB5 = 0;

            PORTBbits.RB6 = 0;
            PORTBbits.RB7 = 0;

            break;
    }
}

void process_canbus_data() 
{   
    //process the CAN bus data
    char data[5];
    uint16_t msg_id;
    uint8_t length; 
    
    can_receive(&msg_id, data, &length);
    data[length] = '\0';
    
    clcd_print("SPD GEAR RPM IND",LINE1(0));
    if(length == 0)
    {
        return;
    }
    
    
    switch(msg_id)
    {
        case SPEED_MSG_ID:
            handle_speed_data(data, length);
            break;
         
        case GEAR_MSG_ID:
            handle_gear_data(data, length);
            break;
        
        case RPM_MSG_ID:
            handle_rpm_data(data, length);
            break;
            
        case INDICATOR_MSG_ID:
            handle_indicator_data(data, length);
            break;
    }
}

void __interrupt() isr(void)
{
    if(TMR0IF)
    {
        TMR0IF = 0;

        static unsigned int count = 0;

        if(++count >= 10000)
        {
            count = 0;

            blink_flag ^= 1;
        }
    }
}
