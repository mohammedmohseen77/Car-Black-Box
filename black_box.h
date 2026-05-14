#ifndef BLACK_BOX_H
#define	BLACK_BOX_H

#include <xc.h>
#include "clcd.h"
#include "adc.h"
#include "i2c.h"
#include "ds1307.h"
#include "matrix_keypad.h"
#include "external_eeprom.h"
#include "uart.h"

#define _XTAL_FREQ 20000000
/* Enum for maintaining the app state */
typedef enum {
    e_dashboard, e_main_menu, e_view_log, e_set_time, e_download_log, e_clear_log
} State_t;


extern State_t state; // App state

unsigned char clock_reg[3];
unsigned char time[9];
unsigned char speed[4] = "000";
unsigned char key;
char * events[ 9 ] = {"ON", "GN", "G1", "G2","G3", "G4", "G5", "GR", " C"};
int pos, log_count;
unsigned char data[17];
//Function declarations

//Dashboard function declaration
void view_dashboard(void);

//Storing events function declaration
void event_store(void);

//main menu function declaration
void display_main_menu(void);

//View log function declaration
void view_log(void);

//Reading events function declaration
void event_reader(unsigned char);

//Set time function declaration
void set_time(void);

//Download log function _declaration
void download_log(void);

//Clear log function declaration
void clear_log(void);

// display the speed
void display_speed(void);

// display the gear shifting
void display_gear_shifting(void);

#endif	/* BLACK_BOX_H */