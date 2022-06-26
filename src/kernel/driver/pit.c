#include "pit.h"
#include "../i686/isr.h"
#include "../i686/irq.h"
#include "../video/stdio.h"
#include "../i686/io.h"

#define CMD_BINARY                      0x00    // Use Binary counter values
#define CMD_BCD                         0x01    // Use Binary Coded Decimal counter values

// Mode
#define CMD_MODE0                       0x00    // Interrupt on Terminal Count
#define CMD_MODE1                       0x02    // Hardware Retriggerable One-Shot
#define CMD_MODE2                       0x04    // Rate Generator
#define CMD_MODE3                       0x06    // Square Wave
#define CMD_MODE4                       0x08    // Software Trigerred Strobe
#define CMD_MODE5                       0x0a    // Hardware Trigerred Strobe

// Read/Write
#define CMD_LATCH                       0x00
#define CMD_RW_LOW                      0x10    // Least Significant Byte
#define CMD_RW_HI                       0x20    // Most Significant Byte
#define CMD_RW_BOTH                     0x30    // Least followed by Most Significant Byte

// Counter Select
#define CMD_COUNTER0                    0x00
#define CMD_COUNTER1                    0x40
#define CMD_COUNTER2                    0x80
#define CMD_READBACK                    0xc0

volatile int timer_ms = 0;

void pit_handler(Registers* regs) {
    timer_ms++;
}

void pit_install() {
    IRQ_RegisterHandler(0, pit_handler);
    uint16_t hz = 1000;
    uint16_t divisor = PIT_FREQUENZY / hz;
    outb(PIT_CMD, CMD_BINARY | CMD_MODE3 | CMD_RW_BOTH | CMD_COUNTER0);
    outb(PIT_COUNTER0, divisor);
    outb(PIT_COUNTER0, divisor >> 8);
    printf("Timer installed!\n");
}

void pit_wait(int ms) {
    unsigned long ems = timer_ms + ms;
    while (timer_ms < ems);
}