#include "black_box.h"

void display_main_menu(void)
{
    CLEAR_DISP_SCREEN;
    unsigned char arrow = 0;
    char *menu[] = {"View Log","Download Log","Clear Log","Set Time"};
    
    while(1)
    {
        key = read_switches(STATE_CHANGE);
        
        if(key == MK_SW5)
        {
            if(arrow < 3)
            {
                CLEAR_DISP_SCREEN;
                arrow++;
            }
        }
        else if(key == MK_SW6)
        {
            if(arrow > 0)
            {
                CLEAR_DISP_SCREEN;
                arrow--;
            }
        }
        else if(key == MK_SW7)
        {
            switch(arrow)   
            {
                case 0:  
                    //View Log
                    state = e_view_log;  
                    return;

                case 1:   
                    // Download Log
                    state = e_download_log;
                    return;

                case 2:   
                    // Clear Log
                    state = e_clear_log;
                    return;
                    
                case 3:   
                    // Set Time
                    state = e_set_time;
                    return;
               
            }
        }
        else if(key == MK_SW8)
        {
            state = e_dashboard;
            CLEAR_DISP_SCREEN;
            break;
        }
        
        clcd_print("-> ",LINE1(0));
        clcd_print(menu[arrow],LINE1(2));

        if(arrow+1 < 4)
        {
            clcd_print(menu[arrow + 1],LINE2(2));
        }
        else
        {
            clcd_print("             ",LINE2(2));
        }
    }
}
