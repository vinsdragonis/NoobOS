#include "print.h"

char *vgaBuff = (char *)0xb8000; // VGA text buffer is located at physical address 0xb8000
int vgaBuffPos = 0;              // Position of VGA buffer

void clear_screen(void)
{
    /*
        We are multiplying the screen width by 2 because we are using an 8 bit pointer instead of a 16 bit.
        So we need to increment twice on horizontal axis to reach the next VGA character.
    */

    int screen_size = (VGA_WIDTH * 2) * VGA_HEIGHT;

    for (int i = 0; i < screen_size; i++)
    {
        vgaBuff[i] = 0;
    }
}

void handle_next_line(void) {
    int screen_width = VGA_WIDTH * 2;

    for (int i = vgaBuffPos; i < screen_width * 2; i++)
    {
        vgaBuff[i] = 0;
    }
    
    vgaBuffPos += screen_width * 2;
}

void print_msg(char* msg)
{
    /*
        Size of each VGA character = 16 bits
        ASCII character = first 8 bits
        Color of ASCII character = last 8 bits

        For more information, please refer to https://en.wikipedia.org/wiki/VGA_text_mode
    */

    int i = 0;

    while (msg[i] != '\0')
    {
        if (msg[i] == '\n')
        {
            // In case
            handle_next_line();
            i++;
            continue;
        }

        vgaBuff[vgaBuffPos] = msg[i];  // ASCII character is pushed into the buffer
        vgaBuff[vgaBuffPos + 1] = 160; // Color of the character is pushed into the buffer

        ++i;             // Increment position in message string
        vgaBuffPos += 2; // Since we have used 2 indexes to make up a single character (ASCII character + color), we need to increment the position by 2
    }
}