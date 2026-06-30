#include "adc.h"
#include "can.h"
#include "ecu1_sensor.h"
//#include "clcd.h"
#include "msg_id.h"
#include "uart.h"

#define _XTAL_FREQ 8000000
void main()
{
    //Call the functions
    init_adc();
    init_can();
    init_digital_keypad();
    TRISB = 0x08; // Set RB2 as output, RB3 as input, remaining as output
    PORTB = PORTB & 0X0C;
    char speed[4];
    char gear[2];
    while(1)
    {
        uint16_t speed_v = get_speed();
        speed[0] = (speed_v/100)%10 + '0';
        speed[1] = (speed_v/10)%10 + '0';
        speed[2] = (speed_v)%10 + '0';
        speed[3] = 0;
        
        can_transmit(SPEED_MSG_ID, speed, 4);
        __delay_ms(100);

        unsigned char gear_v = get_gear_pos();
        gear[0] = gear_v;
        gear[1] = 0;
        
        can_transmit(GEAR_MSG_ID, gear, 2);
        __delay_ms(100);
    }
    
}