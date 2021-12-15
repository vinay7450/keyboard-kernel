#include "../../include/types.h"


//externel function

extern void print_string(char*,uint8,uint8);
extern void keyboard_init();
extern void cls();

// kernel entry
void kernel_main() {
    cls();
    print_string("JSS >  ",15,0);
    keyboard_init();
}