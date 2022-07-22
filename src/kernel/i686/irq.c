#include <stddef.h>
#include "irq.h"
#include "io.h"
#include "../video/stdio.h"

#define PIC1            0x20        //Master PIC
#define PIC2            0xA0        //Slave PIC
#define PIC1_COMMAND    PIC1
#define PIC1_DATA       (PIC1 + 1)
#define PIC2_COMMAND    PIC2
#define PIC2_DATA       (PIC2 + 1)

#define PIC_EOI         0x20

#define ICW1_ICW4	    0x01		/* ICW4 (not) needed */
#define ICW1_SINGLE	    0x02		/* Single (cascade) mode */
#define ICW1_INTERVAL4	0x04		/* Call address interval 4 (8) */
#define ICW1_LEVEL	    0x08		/* Level triggered (edge) mode */
#define ICW1_INIT	    0x10		/* Initialization - required! */

#define ICW4_8086	    0x01		/* 8086/88 (MCS-80/85) mode */
#define ICW4_AUTO	    0x02		/* Auto (normal) EOI */
#define ICW4_BUF_SLAVE	0x08		/* Buffered mode/slave */
#define ICW4_BUF_MASTER	0x0C		/* Buffered mode/master */
#define ICW4_SFNM	    0x10		/* Special fully nested (not) */

#define PIC_READ_IRR    0x0a
#define PIC_READ_ISR    0x0b

IRQHandler  g_IRQHandlers[16];

void i686_IRQ_Handler(Registers* regs) {
    uint32_t irq = regs->interrupt - 32;

    uint8_t pic_isr = pic_get_isr();
    uint8_t pic_irr = pic_get_irr();

    if(g_IRQHandlers[irq] != NULL) {
        g_IRQHandlers[irq](regs);
    } else {
        printf("Unhandled IRQ %d   ISR=%x   IRR=%x...\n", irq, pic_isr, pic_irr);
    }

    PIC_sendEOI(irq);
}

void PIC_sendEOI(unsigned char irq) {
    if(irq >= 8)
        outb(PIC2_COMMAND, PIC_EOI);

    outb(PIC1_COMMAND, PIC_EOI);
}

void PIC_remap() {
    //Start init
    outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
    i686_iowait();
    outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);
    i686_iowait();

    //Set offsets since 0-31 are reserved
    outb(PIC1_DATA, 0x20);
    i686_iowait();
    outb(PIC2_DATA, 0x28);
    i686_iowait();

    //other init stuff (tell master pic of slave, give slave identity)
    outb(PIC1_DATA, 4);
    i686_iowait();
    outb(PIC2_DATA, 2);
    i686_iowait();

    //Set mode
    outb(PIC1_DATA, ICW4_8086);
    i686_iowait();
    outb(PIC2_DATA, ICW4_8086);
    i686_iowait();
}

void PIC_disable() {
    outb(PIC1_DATA, 0xFF);
    i686_iowait();
    outb(PIC2_DATA, 0xFF);
    i686_iowait();
}

void IRQ_set_mask(unsigned char irqLine) {
    uint16_t port;
    uint8_t value;

    if(irqLine < 8) {
        port = PIC1_DATA;
    } else {
        port = PIC2_DATA;
        irqLine -= 8;
    }

    value = inb(port) | (1 << irqLine);
    outb(port, value);
}

void IRQ_clear_mask(unsigned char irqLine) {
    uint16_t port;
    uint8_t value;

    if(irqLine < 8) {
        port = PIC1_DATA;
    } else {
        port = PIC2_DATA;
        irqLine -= 8;
    }

    value = inb(port) & ~(1 << irqLine);
    outb(port, value);
}

static uint16_t __pic_get_irq_reg(int ocw3) {
    outb(PIC1_COMMAND, ocw3);
    outb(PIC2_COMMAND, ocw3);

    return (inb(PIC2_COMMAND) << 8) | inb(PIC1_COMMAND);
}

void IRQ_RegisterHandler(int irq, ISRHandler handler) {
    g_IRQHandlers[irq] = handler;
}

void IRQ_UnregisterHandler(int irq) {
    g_IRQHandlers[irq] = NULL;
}

void i686_IRQ_Initialize() {
    PIC_remap();

    for(int i = 0; i < 16; i++)
        i686_ISR_RegisterHandler(32 + i, i686_IRQ_Handler);

    i686_EnableInterrupts();
}

uint16_t pic_get_irr() {
    return __pic_get_irq_reg(PIC_READ_IRR);
}

uint16_t pic_get_isr() {
    return __pic_get_irq_reg(PIC_READ_ISR);
}