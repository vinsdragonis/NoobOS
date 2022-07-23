#include "./include/print.h"

void kernel_main()
{
    // Simple usage of print_msg() to print a string to the screen
    clear_screen();
    print_msg("kernel_main() has been called!\n");
    print_msg("print_msg() has been called!");
}
