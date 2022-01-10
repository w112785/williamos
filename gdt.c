#include "system.h"

/* Defines a GDT entry */
struct gdt_entry
{
    unsigned short limit_low;
    unsigned short base_low;
    unsigned char base_middle;
    unsigned char access;
    unsigned char granularity;
    unsigned char base_high;
} __attribute__((packed));

struct gdt_ptr
{
    unsigned short limit;
    unsigned int *base;
} __attribute__((packed));

void encodeGdtEntry (uint8_t *target, struct gdt_entry source)
{
    if ((source.limit_low > 65536) && ((source.limit_low )))
}

