
global loader
extern kernel_main

magic equ 0x1badb002
flags equ 0
cksum equ -(magic+flags)


section .text

align 4
dd magic
dd flags
dd cksum

loader:
    call kernel_main
    cli

jmp $


times 512 -($-$$) db 0
dw 0xaa55
