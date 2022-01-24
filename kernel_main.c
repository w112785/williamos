#include "system.h"

void kernel_main(/* we wil add stuff here as we build the kernel */ void)
{
    init_gdt();
    idt_install();
    
    terminal_initialize();

    terminal_writestring("Hello, Kernel World!\n");
    return;
}