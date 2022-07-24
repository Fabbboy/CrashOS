#include "keyboard.h"
#include "../i686/irq.h"
#include "../video/stdio.h"
#include "../i686/io.h"



unsigned char kbdde[128] =
        {
                0,  27, '1', '2', '3', '4', '5', '6', '7', '8',	/* 9 */
                '9', '0', '-', '=', '\b',	/* Backspace */
                '\t',			/* Tab */
                'q', 'w', 'e', 'r',	/* 19 */
                't', 'z', 'u', 'i', 'o', 'p', '[', ']', '\n',	/* Enter key */
                0,			/* 29   - Control */
                'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';',	/* 39 */
                '\'', '`',   0,		/* Left shift */
                '\\', 'y', 'x', 'c', 'v', 'b', 'n',			/* 49 */
                'm', ',', '.', '/',   0,				/* Right shift */
                '*',
                0,	/* Alt */
                ' ',	/* Space bar */
                0,	/* Caps lock */
                0,	/* 59 - F1 key ... > */
                0,   0,   0,   0,   0,   0,   0,   0,
                0,	/* < ... F10 */
                0,	/* 69 - Num lock*/
                0,	/* Scroll Lock */
                0,	/* Home key */
                0,	/* Up Arrow */
                0,	/* Page Up */
                '-',
                0,	/* Left Arrow */
                0,
                0,	/* Right Arrow */
                '+',
                0,	/* 79 - End key*/
                0,	/* Down Arrow */
                0,	/* Page Down */
                0,	/* Insert Key */
                0,	/* Delete Key */
                0,   0,   0,
                0,	/* F11 Key */
                0,	/* F12 Key */
                0,	/* All other keys are undefined */
        };

void keyboard_handler(Registers* regs) {
    unsigned char scancode = inb(KEYBOARD_PORT);
    if(scancode & 0x80) {
        //released
    } else {
        //pressed
        //switch case for special keys
        switch(scancode){
            //arrow left
            case 0x4B:
                arrow_left();
                return;
                break;
                //arrow right
            case 0x4D:
                arrow_right();
                return;
                break;
                //shift
            case 0x2A:
                return;
                break;
        }

        if(scancode == 14) {
            rm_last_char();
            return;
        }

        putc(kbdde[scancode]);
    }
}

void keyboard_install() {
    IRQ_RegisterHandler(1, keyboard_handler);
    printf("Keyboard installed!\n");
}