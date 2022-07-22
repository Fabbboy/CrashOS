#include "hal.h"
#include "../i686/gdt.h"
#include "../i686/idt.h"
#include "../i686/isr.h"
#include "../i686/irq.h"

void HAL_Initialize()
{
    i686_GDT_Initialize();
    i686_IDT_Initialize();
    i686_ISR_Initialize();
    i686_IRQ_Initialize();
}