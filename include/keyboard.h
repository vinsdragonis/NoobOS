#define KBD_UNINITIALIZED 0
#define KBD_INITIALIZED 1

typedef struct keyboard_device {
    int status;
} KBD;

void kbd_init(KBD *kbd);
void kbd_handle_key_press(KBD *kbd, char key);