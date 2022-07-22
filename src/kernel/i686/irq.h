#pragma once

#include <stdint.h>
#include "isr.h"

typedef void (*IRQHandler)(Registers* regs);

void PIC_sendEOI(unsigned char irq);
void PIC_remap();
void PIC_disable();
void IRQ_set_mask(unsigned char irqLine);
void IRQ_clear_mask(unsigned char irqLine);
void IRQ_RegisterHandler(int irq, IRQHandler handler);
void IRQ_UnregisterHandler(int irq);
void i686_IRQ_Initialize();
uint16_t pic_get_irr();
uint16_t pic_get_isr();