#include "irq.h"
#include "io.h"

void PIC_sendEOI(unsigned char irq) {
    if(irq >= 8)
        i686_outb(PIC2_COMMAND, PIC_EOI);

    i686_outb(PIC1_COMMAND, PIC_EOI);
}

void PIC_remap() {
    //Store masks
    unsigned char a1, a2;

    a1 = i686_inb(PIC1_DATA);
    a2 = i686_inb(PIC2_DATA);

    //Start init
    i686_outb(PIC1_COMMAND, ICW1_INIT | ICW1_ICW4);
    i686_outb(PIC2_COMMAND, ICW1_INIT | ICW1_ICW4);

    //Set offsets since 0-31 are reserved
    i686_outb(PIC1_DATA, 0x20);
    i686_outb(PIC2_DATA, 0x28);

    //other init stuff (tell master pic of slave, give slave identity)
    i686_outb(PIC1_DATA, 4);
    i686_outb(PIC2_DATA, 2);

    //Set mode
    i686_outb(PIC1_DATA, ICW4_8086);
    i686_outb(PIC2_DATA, ICW4_8086);

    //Restore masks
    i686_outb(PIC1_DATA, a1);
    i686_outb(PIC2_DATA, a2);
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

    value = i686_inb(port) | (1 << irqLine);
    i686_outb(port, value);
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

    value = i686_inb(port) & ~(1 << irqLine);
    i686_outb(port, value);
}

static uint16_t __pic_get_irq_reg(int ocw3) {
    i686_outb(PIC1_COMMAND, ocw3);
    i686_outb(PIC2_COMMAND, ocw3);

    return (i686_inb(PIC2_COMMAND) << 8) | i686_inb(PIC1_COMMAND);
}

void IRQ_RegisterHandler(int irq, ISRHandler handler) {
    i686_ISR_RegisterHandler(irq + 32, handler);
}

void IRQ_UnregisterHandler(int irq) {
    i686_ISR_UnregisterHandler(irq + 32);
}

uint16_t pic_get_irr() {
    return __pic_get_irq_reg(PIC_READ_IRR);
}

uint16_t pic_get_isr() {
    return __pic_get_irq_reg(PIC_READ_ISR);
}