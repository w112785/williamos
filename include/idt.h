
#ifndef idt_h
#define idt_h

void idt_install();
void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);


#endif //idt_h