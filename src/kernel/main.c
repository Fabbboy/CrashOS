#include <stdint.h>
#include "stdio.h"
#include "memory.h"
#include "isr.h"
#include "keyboard.h"

extern uint8_t __bss_start;
extern uint8_t __end;

__attribute__((unused)) _Noreturn void __attribute__((section(".entry"))) start(uint16_t bootDrive)
{
    memset(&__bss_start, 0, (&__end) - (&__bss_start));

    clear_screen();
    printf("Boot drive: %u\n", bootDrive);

    printf("Installing Interrupt services...\n");
    isr_install();
    printf("Interrupt services installed!\n");

    printf("Enabling external interrupts\n");
    __asm__ volatile("sti");
    printf("External interrupts enabled!\n");

    printf("Initializing keyboard (IRQ 1)...\n");
    init_keyboard();
    printf("Keyboard initialized!\n");
    init_keyboard();

    for (;;);
}
