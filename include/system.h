#ifndef system_h
#define system_h

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "scrn.h"
#include "gdt.h"
#include "idt.h"

extern void outb(uint16_t port, uint8_t value);
extern uint8_t inb(uint16_t port);
extern uint16_t inw(uint16_t port);

#endif
