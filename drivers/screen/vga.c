#include "../../include/vga.h"
#include "../../include/types.h"

uint16 *vga_buffer = (uint16*)0xb8000;

uint32 vga_line_lidex = 0;
uint32 vga_index = 0;
uint32 vga_line_pixel = 0;

// for vga entry

uint16 vga_entry(unsigned char ch, uint8 fore_color, uint8 back_color) {
    uint16 ax = 0;
    uint8 ah = 0, al = 0;

    ah = back_color;
    ah <<= 4;
    ah |= fore_color;
    ax = ah;
    ax <<= 8;
    al = ch;
    ax |= al;

    return ax;
}




// for print char 

void print_char(char ch, uint8 fore_color, uint8 back_color) {
    vga_buffer[vga_index] = vga_entry(ch,fore_color,back_color);
    vga_index++;
    vga_line_pixel++;
    if(vga_line_pixel > 79) {
        vga_line_pixel = 0;
        vga_line_lidex++;
    }
}

// for print string

void print_string(char *str, uint8 fore_color, uint8 back_color) {
    uint32 i = 0;
    while(str[i]) {
        print_char(str[i],fore_color,back_color);
        i++;
    }
}

//for clear screen

void cls() {
    uint16 *vidmem = (uint16*)0xb8000;
    uint32 i = 0;
    while(i<2000) {
        vidmem[i] = vga_entry(0,WHITE,BLACK);
        i++;
    }
}

// for print new line

void print_new_line() {
    uint32 distance;
    distance = 79 - vga_line_pixel;
    uint32 i = 0;
    for(i=0; i<=distance; i++) {
        print_char(0,WHITE,BLACK);
    }
    if(vga_line_lidex>24) {
        cls();
        vga_line_lidex = 0;
        vga_index = 0;
        vga_line_pixel = 0;
    }
}


void back_space() {
    if(vga_line_pixel > 7) {
        vga_buffer[vga_index-1] = vga_entry(0,WHITE,BLACK);
        vga_index--;
        vga_line_pixel--;
    }
}
