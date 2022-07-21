BITS 32 ; We are switching to protected mode after booting from the disk

; There exists a standard for loading various x86 kernels using a bootloader called Multiboot specification

SECTION .text
    align   4
    dd      0x1BADB002          ; This magic number value is used to indentify the header
    dd      0x00                ; Flags
    dd      - (0x1BADB002+0x00) ; Checksum value should be 0 when magic number is added to the flags

GLOBAL start
EXTERN kernel_main      ; We are declaring kernel_main as an external function

start:
    cli                 ; Clear interrupts
    call kernel_main    ; We are calling kernel_main() from the kernel.c file
    jmp end             ; We jump to the end after the function has been called

end:
    hlt                 ; Halt execution
    jmp end             ; Jump back to end label