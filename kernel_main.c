#include "tty.h"

void kernel_main(/* we wil add stuff here as we build the kernel */ void)
{
    terminal_initialize();

    terminal_writestring("Hello, Kernel World!\n");
    return;
}