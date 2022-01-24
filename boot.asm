[BITS 32]

MBALIGN  equ 1 << 0
MEMINFO  equ 1 << 1
FLAGS    equ MBALIGN | MEMINFO
MAGIC    equ 0x1BADB002
CHECKSUM equ -(MAGIC + FLAGS)

section .multiboot
align 4
    dd MAGIC
    dd FLAGS
    dd CHECKSUM

section .bss
align 16
stack_bottom:
resb 16384 ; 16 KiB
stack_top:

section .text
global _start
_start:
    mov esp, stack_top

    extern kernel_main
    call kernel_main

    cli
.hang:
    hlt
    jmp $
;    jmp .hang
.end:

global flush_gdt
flush_gdt:
    extern gdtptr
    lgdt[gdtptr]
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:.flush
.flush:
    ret

global idt_load
idt_load:
extern idtptr
    lidt[idtptr]
    ret
