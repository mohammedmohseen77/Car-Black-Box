#include "black_box.h"

void view_dashboard(void)
{
    // display the title 
    clcd_print("  TIME   EV SP  ", LINE1(0));
    
    // get data from RTC
    get_time();
    // display the time 
    display_time();
    
    //Gear shiftings using switches
    display_gear_shifting();
    
    // display the speed
    display_speed();
    
}

void display_speed(void)
{
    // read ADC value
     unsigned short adc_val = read_adc(CHANNEL4) / 10.23; // range the ADC value (0-100)
     
     // convert adc_val into chars
     speed[0] = (adc_val / 100) + 48;
     speed[1] = ((adc_val / 10) % 10) + 48;
     speed[2] = (adc_val % 10) + 48;
     
     clcd_print(speed, LINE2(12));
}

void display_gear_shifting(void)
{
    if(key == MK_SW1)
    {
        // increment the gear
        if(pos < 7)
          pos++;
        
        event_store();
        
    }
    else if(key == MK_SW2)
    {
        // decrement the gear
        if(pos > 1)
            pos--;
        
        event_store();
    }
    else if(key == MK_SW3)
    {
        // make collision
        pos = 8;
        event_store();
    }
    clcd_print(events[pos], LINE2(9));
}

void event_store(void)
{
    static unsigned int addr = 0x00;
    int i, ind = 0;
    for( i = 0; i < 8; i++)
        write_external_eeprom(addr++, time[i]);
    
    write_external_eeprom(addr++, events[pos][0]);
    write_external_eeprom(addr++, events[pos][1]);
    
    for( i = 0; i < 3; i++)
        write_external_eeprom(addr++, speed[i]);
    
    if(log_count < 10)
    {
        ++log_count;
        write_external_eeprom(130, log_count);
    }
    
    if(addr == 129)
    {
        addr = 0x00;
    }
    
}