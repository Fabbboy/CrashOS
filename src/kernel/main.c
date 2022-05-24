#include <stdint.h>
#include "video/stdio.h"
#include "util/memory.h"
#include "hal/hal.h"

extern uint8_t __bss_start;
extern uint8_t __end;

__attribute__((unused)) _Noreturn void __attribute__((section(".entry"))) start(uint16_t bootDrive)
{
    memset(&__bss_start, 0, (&__end) - (&__bss_start));

    HAL_Initialize();

    clear_screen();

    printf("Hello World from Kernel!!!\n");

    for (;;);
}
