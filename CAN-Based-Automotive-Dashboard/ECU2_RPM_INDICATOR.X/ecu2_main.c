#include "ecu2_sensor.h"
#include "adc.h"
#include "can.h"
#include "msg_id.h"
#include "uart.h"
#define _XTAL_FREQ 8000000

int main()
{
    //call the functions
    init_adc();
    init_can();
    init_digital_keypad();
    TRISB = 0x08; // Set RB2 as output, RB3 as input, remaining as output
    PORTB = PORTB & 0X0C;
    char rpm[5];
    char ind[2];
    while(1)
    {
        uint16_t rpm_v = get_rpm();
        rpm[0] = (rpm_v/1000)%10 + '0';
        rpm[1] = (rpm_v/100)%10 + '0';
        rpm[2] = (rpm_v/10)%10 + '0';
        rpm[3] = (rpm_v)%10 + '0';
        rpm[4] = 0;
        
        can_transmit(RPM_MSG_ID, rpm, 4);
        __delay_ms(100);

        unsigned char ind_v = process_indicator();
        ind[0] = ind_v;
//        ind[0] = 'L';
        ind[1] = 0;
        
        can_transmit(INDICATOR_MSG_ID, ind, 1);
        __delay_ms(100);
    }
}
