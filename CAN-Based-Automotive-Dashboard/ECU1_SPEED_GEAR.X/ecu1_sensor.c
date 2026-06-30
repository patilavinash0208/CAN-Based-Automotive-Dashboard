#include "ecu1_sensor.h"
#include "adc.h"
#include "can.h"
#include "msg_id.h"
#include "uart.h"

uint16_t get_speed()
{
    // Implement the speed function
    return read_adc(CHANNEL4)/10.23;
}

unsigned char get_gear_pos()
{
    // Implement the gear function
    unsigned char gear[] = {'N','1','2','3','4','5','R'};
    static char idx = 0;
    char key = read_digital_keypad(STATE_CHANGE);
    
    if(key == GEAR_UP)
    {
        if(idx < MAX_GEAR)
            idx++;
    }
    else if(key == GEAR_DOWN)
    {
        if(idx > 0)
            idx--;
    }
    
    return gear[idx];
}