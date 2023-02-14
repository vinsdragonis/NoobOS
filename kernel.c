#include "./include/print.h"
#include "./include/keyboard.h"

void kernel_main() {
    // Initialize keyboard device
    KBD kbd;
    kbd_init(&kbd);
    char key = 0;
    __asm__ __volatile__(
        "int $0x16\n"
        : "=al"(key)
    );
    // Simple usage of print_msg() to print a string to the screen
    clear_screen();
    print_msg("kernel_main() has been called!\n");
    print_msg("print_msg() has been called!\n");
    // Print keyboard input to the screen
    if (key != 0) {
        kbd_handle_key_press(&kbd, key);
    }
}
