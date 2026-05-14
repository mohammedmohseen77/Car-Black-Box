#include "black_box.h"
extern State_t state;

void view_log(void)
{
    static unsigned char event_pos;
    unsigned char stored_log_count;
    CLEAR_DISP_SCREEN;
     clcd_print("#   TIME   EV SP",LINE1(0));
    __delay_ms(200);
    
    stored_log_count = read_external_eeprom(130);
    if(stored_log_count == 0)
    {
         clcd_print("    No  logs    ", LINE1(0));
         clcd_print("   available!   ", LINE2(0));
         __delay_ms(2000);
         state = e_main_menu;
         return;
    }
    while(1)
    {
        key = read_switches(STATE_CHANGE);
        if(key == MK_SW5)
        {
             if(event_pos < stored_log_count - 1)
                event_pos++;
        }
        else if(key == MK_SW6)
        {
            if(event_pos > 0)
                 event_pos--;
        }       
        else if(key == MK_SW8)
        {
            state = e_main_menu;
            return; 
        }
        
        event_reader(event_pos);
        clcd_putch(event_pos+48, LINE2(0));
        clcd_print(data, LINE2(2));
    
    }
}


void clear_log(void)
{
    clcd_print("Logs are cleared", LINE1(0));
    clcd_print("  successfully! ", LINE2(0));
    __delay_ms(2000);
    log_count = 0;
    write_external_eeprom(130, log_count);
    state = e_main_menu;
}

void download_log(void)
{
     unsigned char stored_log_count, ind = 0, addr;
     stored_log_count = read_external_eeprom(130);
     if(stored_log_count == 0)
     {
         puts("No logs available\n\r");
         __delay_ms(2000);
         state = e_main_menu;
         return;
     }
     
     puts("E.No   TIME   EV SP \n\r");
     for( ; ind < stored_log_count; ind++ )
     {
         event_reader(ind);
         putch(' ');
         putch(ind+48);
         putch(' ');
         putch(' ');
         putch(' ');
         puts(data);
         puts("\n\r");
     }
     state = e_main_menu;
}

void event_reader(unsigned char event_pos)
{
    unsigned int addr = 0x00, stored_log_count;
    
    stored_log_count = read_external_eeprom(130);
    
    int i, ind = 0;
    
    addr = event_pos * 13;
    
    if(event_pos < stored_log_count)
    {
        for(i = 0; i < 8; i++)
            data[ind++] = read_external_eeprom(addr++);
    
        data[ind++] = ' ';
        
        data[ind++] = read_external_eeprom(addr++);
        data[ind++] = read_external_eeprom(addr++);
        
        data[ind++] = ' ';
        
        for(i = 0; i < 3; i++)
            data[ind++] = read_external_eeprom(addr++);
        
        data[ind] = '\0';
    }
}

void set_time(void)
{
    static unsigned char field = 0; // 0-HH,1-MM,2-SS
    unsigned char blink = 0;
    
    unsigned char hour, min, sec;
    
    get_time();
    
    hour = ((time[0]-48) * 10) + (time[1]-48);
    min  = ((time[3]-48) * 10) + (time[4]-48);
    sec  = ((time[6]-48) * 10) + (time[7]-48);
    
    CLEAR_DISP_SCREEN;
    
    while(1)
    {
        key = read_switches(STATE_CHANGE);
        
        if(key == MK_SW5)
        {
            if(field == 0)
            {
                if(++hour == 24)
                    hour = 0;
            }
            else if(field == 1)
            {
                if(++min == 60)
                    min = 0;
            }
            else if(field == 2)
            {
                if(++sec == 60)
                    sec = 0;
            }
        }
        else if(key == MK_SW6)
        {
            field++;
            if(field > 2)
                field = 0;
        }
        else if(key == MK_SW7)
        {
            write_ds1307(HOUR_ADDR, ((hour/10)<<4) | (hour%10));
            write_ds1307(MIN_ADDR, ((min/10)<<4) | (min%10));
            write_ds1307(SEC_ADDR, ((sec/10)<<4) | (sec%10));
            
            state = e_dashboard;
            return;
        }
        else if(key == MK_SW8)
        {
            state = e_main_menu;
            return;
        }
        
        time[0] = (hour/10) + 48;
        time[1] = (hour%10) + 48;
        time[2] = ':';
        time[3] = (min/10) + 48;
        time[4] = (min%10) + 48;
        time[5] = ':';
        time[6] = (sec/10) + 48;
        time[7] = (sec%10) + 48;
        time[8] = '\0';
        
        clcd_print("  SET TIME  ", LINE1(0));
        
        if(field == 0 && blink)
        {
            clcd_print("  ", LINE2(0));
        }
        else
        {
            clcd_putch(time[0], LINE2(0));
            clcd_putch(time[1], LINE2(1));
        }
        
        clcd_putch(':', LINE2(2));
        
        if(field == 1 && blink)
        {
            clcd_print("  ", LINE2(3));
        }
        else
        {
            clcd_putch(time[3], LINE2(3));
            clcd_putch(time[4], LINE2(4));
        }
        
        clcd_putch(':', LINE2(5));
        
        if(field == 2 && blink)
        {
            clcd_print("  ", LINE2(6));
        }
        else
        {
            clcd_putch(time[6], LINE2(6));
            clcd_putch(time[7], LINE2(7));
        }
        
        blink = !blink;
        __delay_ms(300);
    }
}