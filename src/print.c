#include "../include/print.h"

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
    for (int i = (int)(vgaBuffPos / 160) + (vgaBuffPos % 160); i < 80 + (vgaBuffPos % 160); i++)
    {
        vgaBuff[i] = 0;
        vgaBuffPos += 2;
    }
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
        // In case of next line, handle_next_line() is executed
        if (msg[i] == '\n')
        {
            handle_next_line();
            i++;
            continue;
        }

        vgaBuff[vgaBuffPos] = msg[i];  // ASCII character is pushed into the buffer
        vgaBuff[vgaBuffPos + 1] = 15; // Color of the character is pushed into the buffer

        ++i;             // Increment position in message string
        vgaBuffPos += 2; // Since we have used 2 indexes to make up a single character (ASCII character + color), we need to increment the position by 2
    }
}
