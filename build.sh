nasm -f elf32 boot.asm -o boot.o
gcc -m32 -c kernel.c -o kernel.o
gcc -m32 -c ./src/print.c -o ./src/print.o
ld -m elf_i386 -T link.ld -o kernel.bin boot.o kernel.o ./src/print.o
qemu-system-i386 -kernel kernel.bin --curses