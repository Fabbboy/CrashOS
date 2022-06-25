#include "timer.h"
#include "../i686/isr.h"
#include "../i686/irq.h"
#include "../video/stdio.h"

int timer_ticks = 0;

void timer_handler(Registers* regs) {
    timer_ticks++;
}

void timer_install() {
    IRQ_RegisterHandler(0, timer_handler);
    printf("Timer installed!\n");
}

void timer_wait(int ticks) {
    unsigned long eticks = timer_ticks + ticks;
    while (timer_ticks < eticks);
}