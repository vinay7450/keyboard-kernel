#ifndef ASCII_CHAR_H
#define ASCII_CHAR_H

#include "keyboard.h"

char get_ascii_char(char ch) {
    if(ch == KEY_A) return 'A';
    if(ch == KEY_B) return 'B';
    if(ch == KEY_C) return 'C';
    if(ch == KEY_D) return 'D';
    if(ch == KEY_E) return 'E';
    if(ch == KEY_F) return 'F';
    if(ch == KEY_G) return 'G';
    if(ch == KEY_H) return 'H';
    if(ch == KEY_I) return 'I';
    if(ch == KEY_J) return 'J';
    if(ch == KEY_K) return 'K';
    if(ch == KEY_L) return 'L';
    if(ch == KEY_M) return 'M';
    if(ch == KEY_N) return 'N';
    if(ch == KEY_O) return 'O';
    if(ch == KEY_P) return 'P';
    if(ch == KEY_Q) return 'Q';
    if(ch == KEY_R) return 'R';
    if(ch == KEY_S) return 'S';
    if(ch == KEY_T) return 'T';
    if(ch == KEY_U) return 'U';
    if(ch == KEY_V) return 'V';
    if(ch == KEY_W) return 'W';
    if(ch == KEY_X) return 'X';
    if(ch == KEY_Y) return 'Y';
    if(ch == KEY_Z) return 'Z';
    if(ch == KEY_0) return '0';
    if(ch == KEY_1) return '1';
    if(ch == KEY_2) return '2';
    if(ch == KEY_3) return '3';
    if(ch == KEY_4) return '4';
    if(ch == KEY_5) return '5';
    if(ch == KEY_6) return '6';
    if(ch == KEY_7) return '7';
    if(ch == KEY_8) return '8';
    if(ch == KEY_9) return '9';
    if(ch == KEY_SPACE) return ' ';
}
#endif