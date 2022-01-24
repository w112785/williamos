#include "system.h"
/* Defines a GDT entry */
struct gdt_entry
{
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed));

struct gdt_ptr
{
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));

struct gdt_entry gdtentry[5];
struct gdt_ptr gdtptr;

extern void flush_gdt();

void gdt_set_gate(int32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran)
{
    gdtentry[num].base_low    = (base & 0xFFFF);
    gdtentry[num].base_middle = (base >> 16) & 0xFF;
    gdtentry[num].base_high   = (base >> 24) & 0xFF;

    gdtentry[num].limit_low   = (limit & 0xFFFF);
    gdtentry[num].granularity = (limit >> 16) & 0x0F;

    gdtentry[num].granularity |= gran & 0xF0;
    gdtentry[num].access      = access;
}

void init_gdt()
{
    gdtptr.limit = (sizeof(struct gdt_entry) * 5) - 1;
    gdtptr.base  = (uint32_t)&gdtentry;

    gdt_set_gate(0, 0, 0, 0, 0);                // Null segment
    gdt_set_gate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Code segment
    gdt_set_gate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Data segment
    gdt_set_gate(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
    gdt_set_gate(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment

    flush_gdt();
}