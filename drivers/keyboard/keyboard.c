#include "../../include/keyboard.h"
#include "../../include/io_ports.h"
#include "../../include/vga.h"
#include "../../include/types.h"
#include "../../include/ascii_char.h"

// external function

extern void back_space();
extern void print_new_line();
extern void print_char(char,uint8,uint8);
extern void print_string(char*,uint8,uint8);

// timer for wait input and output

void wait_for_io(uint32 timer_count) {
    while(1) {
        asm volatile("nop");
        timer_count--;
        if(timer_count <= 0) 
            break;
    }
}

// for sleep

void sleep(uint32 timer_count) {
    wait_for_io(timer_count);
}


// get input from keycode

char get_input_keycode() {
    char keycode = 0;
    while((keycode = inb(KEYBOARD_PORT)) != 0) {
        if(keycode > 0)
            return keycode;
    }
    return keycode;
}

void keyboard_init() {
    char keycode = 0;
    char ch = 0;

    do {
        keycode = get_input_keycode();
        if(keycode == KEY_ENTER) {
            print_new_line();
            print_string("JSS >  ",WHITE,BLACK);
        }
        else if(keycode == KEY_BACKSPACE) {
            back_space();
        }
        else {
            ch = get_ascii_char(keycode);
            print_char(ch,WHITE,BLACK);
        }sleep(9000000);
    }while(keycode>0);
}