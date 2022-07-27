#include <stdint.h>
#include "video/stdio.h"
#include "lib/memory.h"
#include "hal/hal.h"
#include "driver/pit.h"
#include "driver/keyboard.h"
#include "driver/rtc.h"
#include "driver/disk.h"

extern uint8_t __bss_start;
extern uint8_t __end;

__attribute__((unused)) _Noreturn void __attribute__((section(".entry"))) start(uint16_t bootDrive)
{
    memset(&__bss_start, 0, (&__end) - (&__bss_start));
    HAL_Initialize();
    //init disk and fat
    DISK disk;
    if (!DISK_Initialize(&disk, bootDrive))
    {
        printf("Disk init error\r\n");
    }

    clear_screen();

    printf("Kernel starting...\n");

    pit_install();
    keyboard_install();
    rtc_install();

    print_current_time();

    for (;;);
}
