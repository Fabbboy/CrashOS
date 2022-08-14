#include <stdint.h>
#include "video/stdio.h"
#include "lib/memory.h"
#include "hal/hal.h"
#include "driver/pit.h"
#include "driver/keyboard.h"
#include "driver/rtc.h"

extern uint8_t __bss_start;
extern uint8_t __end;



__attribute__((unused)) _Noreturn void __attribute__((section(".entry"))) start(uint16_t bootDrive)
{
    memset(&__bss_start, 0, (&__end) - (&__bss_start));
    HAL_Initialize();

    clear_screen();

    printf("Kernel starting...\n");

    pit_install();
    keyboard_install();
    rtc_install();
    paging_init();

   //define array with malloc()
    int* array = malloc(sizeof(int) * 0);
    for(int i = 0; i < 10; i++){
        array[i] = i;
    }
    for(int i = 0; i < 10; i++){
        printf("%d\n", array[i]);
    }

    print_current_time();

    for (;;);
}
//0x10900
//