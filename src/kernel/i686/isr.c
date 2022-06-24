#include "isr.h"
#include "../video/stdio.h"
#include "idt.h"
#include "gdt.h"
#include <stddef.h>
#include "io.h"

#pragma region IDTGates

void __attribute__((cdecl)) i686_ISR0();
void __attribute__((cdecl)) i686_ISR1();
void __attribute__((cdecl)) i686_ISR2();
void __attribute__((cdecl)) i686_ISR3();
void __attribute__((cdecl)) i686_ISR4();
void __attribute__((cdecl)) i686_ISR5();
void __attribute__((cdecl)) i686_ISR6();
void __attribute__((cdecl)) i686_ISR7();
void __attribute__((cdecl)) i686_ISR8();
void __attribute__((cdecl)) i686_ISR9();
void __attribute__((cdecl)) i686_ISR10();
void __attribute__((cdecl)) i686_ISR11();
void __attribute__((cdecl)) i686_ISR12();
void __attribute__((cdecl)) i686_ISR13();
void __attribute__((cdecl)) i686_ISR14();
void __attribute__((cdecl)) i686_ISR15();
void __attribute__((cdecl)) i686_ISR16();
void __attribute__((cdecl)) i686_ISR17();
void __attribute__((cdecl)) i686_ISR18();
void __attribute__((cdecl)) i686_ISR19();
void __attribute__((cdecl)) i686_ISR20();
void __attribute__((cdecl)) i686_ISR21();
void __attribute__((cdecl)) i686_ISR22();
void __attribute__((cdecl)) i686_ISR23();
void __attribute__((cdecl)) i686_ISR24();
void __attribute__((cdecl)) i686_ISR25();
void __attribute__((cdecl)) i686_ISR26();
void __attribute__((cdecl)) i686_ISR27();
void __attribute__((cdecl)) i686_ISR28();
void __attribute__((cdecl)) i686_ISR29();
void __attribute__((cdecl)) i686_ISR30();
void __attribute__((cdecl)) i686_ISR31();

void i686_ISR_InitializeGates() {
    i686_IDT_SetGate(0, i686_ISR0, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(1, i686_ISR1, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(2, i686_ISR2, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(3, i686_ISR3, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(4, i686_ISR4, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(5, i686_ISR5, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(6, i686_ISR6, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(7, i686_ISR7, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(8, i686_ISR8, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(9, i686_ISR9, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(10, i686_ISR10, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(11, i686_ISR11, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(12, i686_ISR12, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(13, i686_ISR13, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(14, i686_ISR14, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(15, i686_ISR15, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(16, i686_ISR16, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(17, i686_ISR17, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(18, i686_ISR18, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(19, i686_ISR19, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(20, i686_ISR20, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(21, i686_ISR21, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(22, i686_ISR22, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(23, i686_ISR23, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(24, i686_ISR24, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(25, i686_ISR25, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(26, i686_ISR26, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(27, i686_ISR27, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(28, i686_ISR28, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(29, i686_ISR29, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(30, i686_ISR30, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(31, i686_ISR31, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
}

#pragma endregion

ISRHandler g_ISRHandlers[256];

static const char* const g_Exceptions[] = {
        "Divide by zero error",
        "Debug",
        "Non-maskable Interrupt",
        "Breakpoint",
        "Overflow",
        "Bound Range Exceeded",
        "Invalid Opcode",
        "Device Not Available",
        "Double Fault",
        "Coprocessor Segment Overrun",
        "Invalid TSS",
        "Segment Not Present",
        "Stack-Segment Fault",
        "General Protection Fault",
        "Page Fault",
        "",
        "x87 Floating-Point Exception",
        "Alignment Check",
        "Machine Check",
        "SIMD Floating-Point Exception",
        "Virtualization Exception",
        "Control Protection Exception",
        "",
        "",
        "",
        "",
        "",
        "",
        "Hypervisor Injection Exception",
        "VMM Communication Exception",
        "Security Exception",
        ""
};

void i686_ISR_Initialize() {
    i686_ISR_InitializeGates();
    for(int i = 0; i < 256; i++) {
        i686_IDT_EnableGate(i);
    }
}

void __attribute__((cdecl)) i686_ISR_Handler(Registers* regs) {
    if(g_ISRHandlers[regs->interrupt] != NULL) {
        g_ISRHandlers[regs->interrupt](regs);
    } else if(regs->interrupt >= 32) {
        printf("Unhandled interrupt %d!\n", regs->interrupt);
    } else {
        printf("Unhandled exception %d %s\n", regs->interrupt, g_Exceptions[regs->interrupt]);
        printf("  eax=%x  ebx=%x  ecx=%x  edx=%x  esi=%x  edi=%x\n",
               regs->eax, regs->ebx, regs->ecx, regs->edx, regs->esi, regs->edi);
        printf("  esp=%x  ebp=%x  eip=%x  eflags=%x  cs=%x  ds=%x  ss=%x\n",
               regs->esp, regs->ebp, regs->eip, regs->eflags, regs->cs, regs->ds, regs->ss);
        printf("  interrupt=%x  errorcode=%x\n", regs->interrupt, regs->error);

        printf("KERNEL PANIC!\n");
        i686_Panic();
    }
}