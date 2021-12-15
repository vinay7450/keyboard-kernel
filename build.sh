mkdir bin
mkdir iso
mkdir iso/boot
mkdir iso/boot/grub

nasm -felf32 -o bin/boot.o asm/boot.asm
gcc -m32 -o bin/screen.o -c drivers/screen/screen.c -ffreestanding
gcc -m32 -o bin/vga.o -c drivers/screen/vga.c -ffreestanding
gcc -m32 -o bin/keyboard.o -c drivers/keyboard/keyboard.c -ffreestanding
ld -T config/linker.ld -m elf_i386 -o bt.bin bin/boot.o bin/screen.o bin/vga.o bin/keyboard.o

cp config/grub.cfg iso/boot/grub
cp bt.bin iso/boot

grub-mkrescue -o os.iso iso
qemu-system-x86_64 -cdrom os.iso
