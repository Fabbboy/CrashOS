#include <stdint.h>
#include "stdio.h"
#include "memory.h"

extern uint8_t __bss_start;
extern uint8_t __end;

_Noreturn void __attribute__((section(".entry"))) start(uint16_t bootDrive)
{
    memset(&__bss_start, 0, (&__end) - (&__bss_start));

    clear_screen();

    printf("Hello world from kernel!!!\nTest");
    rm_last_line();

end:
    for (;;);
}
