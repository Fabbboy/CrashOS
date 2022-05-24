#include "hal.h"
#include "../i686/gdt.h"
#include "../i686/idt.h"
#include "../i686/isr.h"

void HAL_Initialize()
{
    i686_GDT_Initialize();
    i686_IDT_Initialize();
    i686_ISR_Initialize();
}