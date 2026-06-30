#include "ecu2_sensor.h"
#include "adc.h"
#include "can.h"
#include "msg_id.h"
#include "uart.h"

//uint16_t get_rpm()
//{
//    //Implement the rpm function
//    return ((uint32_t)(read_adc(CHANNEL4)*6000)/1023); 
//}

uint16_t get_rpm()
{
    return ((uint32_t)read_adc(CHANNEL4) * 6000UL) / 1023;
}

unsigned char process_indicator()
{
    static unsigned char prev = SWITCH4;

    unsigned char key = read_digital_keypad(STATE_CHANGE);

    switch(key)
    {
        case SWITCH1:
        case SWITCH2:
        case SWITCH3:
        case SWITCH4:
            prev = key;
            break;
    }

    switch(prev)
    {
        case SWITCH1: return 'L';
        case SWITCH2: return 'R';
        case SWITCH3: return 'H';
        case SWITCH4: return 'O';
    }

    return 'O';
}