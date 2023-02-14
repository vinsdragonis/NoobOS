#include "../include/keyboard.h"

void kbd_init(KBD *kbd) {
    kbd->status = KBD_INITIALIZED;
}

void kbd_handle_key_press(KBD *kbd, char key) {
    __asm__ __volatile__(
                            "movb $0x0E, %%ah\n"
                            "movb $0, %%al\n"
                            "int $0x10\n"
                            :
                            : "r"(key)
                            : "%ah", "%al"
                        );
}