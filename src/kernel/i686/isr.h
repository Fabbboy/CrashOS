#pragma once
#include <stdint.h>

typedef struct {
    uint32_t ds;
    uint32_t edi, esi, ebp, kern_esp, ebx, edx, ecx, eax;
    uint32_t interrupt, error;
    uint32_t eip, cs, eflags, esp, ss;
} __attribute__((packed)) Registers;

typedef void (*ISRHandler)(Registers* regs);

#define get_interrupt(arg) __asm__("int %0\n" : : "N"((arg)) : "cc", "memory")

void i686_ISR_Initialize();
void i686_ISR_RegisterHandler(int interrupt, ISRHandler handler);
void i686_ISR_UnregisterHandler(int interrupt);

void print_regs(Registers* regs);