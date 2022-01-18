#include "keyboard.h"
#include "ports.h"
#include "isr.h"
#include "stdio.h"
#include "string.h"

enum keycode get_de_keycode(uint8_t scancode) {
    switch (scancode) {
        case 0x01:
            return VK_ESCAPE;
        case 0x02:
            return VK_1;
        case 0x03:
            return VK_2;
        case 0x04:
            return VK_3;
        case 0x05:
            return VK_4;
        case 0x06:
            return VK_5;
        case 0x07:
            return VK_6;
        case 0x08:
            return VK_7;
        case 0x09:
            return VK_8;
        case 0x0A:
            return VK_9;
        case 0x0B:
            return VK_0;
        case 0x0C:
            return VK_OEM_4;
        case 0x0D:
            return VK_OEM_6;
        case 0x0E:
            return VK_BACK;
        case 0x0F:
            return VK_TAB;
        case 0x10:
            return VK_Q;
        case 0x11:
            return VK_W;
        case 0x12:
            return VK_E;
        case 0x13:
            return VK_R;
        case 0x14:
            return VK_T;
        case 0x15:
            return VK_Z;
        case 0x16:
            return VK_U;
        case 0x17:
            return VK_I;
        case 0x18:
            return VK_O;
        case 0x19:
            return VK_P;
        case 0x1A:
            return VK_OEM_1;
        case 0x1B:
            return VK_OEM_PLUS;
        case 0x1C:
            return VK_RETURN;
        case 0x1D:
            return VK_LCONTROL;
        case 0x1E:
            return VK_A;
        case 0x1F:
            return VK_S;
        case 0x20:
            return VK_D;
        case 0x21:
            return VK_F;
        case 0x22:
            return VK_G;
        case 0x23:
            return VK_H;
        case 0x24:
            return VK_J;
        case 0x25:
            return VK_K;
        case 0x26:
            return VK_L;
        case 0x27:
            return VK_OEM_3;
        case 0x28:
            return VK_OEM_7;
        case 0x29:
            return VK_OEM_5;
        case 0x2A:
            return VK_LSHIFT;
        case 0x2B:
            return VK_OEM_2;
        case 0x2C:
            return VK_Y;
        case 0x2D:
            return VK_X;
        case 0x2E:
            return VK_C;
        case 0x2F:
            return VK_V;
        case 0x30:
            return VK_B;
        case 0x31:
            return VK_N;
        case 0x32:
            return VK_M;
        case 0x33:
            return VK_OEM_COMMA;
        case 0x34:
            return VK_OEM_PERIOD;
        case 0x35:
            return VK_OEM_MINUS;
        case 0x36:
            return VK_RSHIFT;
        case 0x37:
            return VK_MULTIPLY;
        case 0x38:
            return VK_LMENU;
        case 0x39:
            return VK_SPACE;
        case 0x3A:
            return VK_CAPITAL;
        case 0x3B:
            return VK_F1;
        case 0x3C:
            return VK_F2;
        case 0x3D:
            return VK_F3;
        case 0x3E:
            return VK_F4;
        case 0x3F:
            return VK_F5;
        case 0x40:
            return VK_F6;
        case 0x41:
            return VK_F7;
        case 0x42:
            return VK_F8;
        case 0x43:
            return VK_F9;
        case 0x44:
            return VK_F10;
        case 0x45:
            return VK_NUMLOCK;
        case 0x46:
            return VK_SCROLL;
        case 0x47:
            return VK_HOME;
        case 0x48:
            return VK_UP;
        case 0x49:
            return VK_PRIOR;
        case 0x4A:
            return VK_SUBTRACT;
        case 0x4B:
            return VK_LEFT;
        case 0x4C:
            return VK_CLEAR;
        case 0x4D:
            return VK_RIGHT;
        case 0x4E:
            return VK_ADD;
        case 0x4F:
            return VK_END;
        case 0x50:
            return VK_DOWN;
        case 0x51:
            return VK_NEXT;
        case 0x52:
            return VK_INSERT;
        case 0x53:
            return VK_DELETE;
        case 0x54:
            return VK_SNAPSHOT;
        case 0x56:
            return VK_OEM_102;
        case 0x57:
            return VK_F11;
        case 0x58:
            return VK_F12;
        case 0x59:
            return VK_CLEAR;
        case 0x5A:
            return VK_OEM_WSCCTRL;
        case 0x5B:
            return VK_DBE_KATAKANA;
        case 0x5C:
            return VK_OEM_JUMP;
        case 0x5D:
            return VK_DBE_FLUSHSTRING;
        case 0x5E:
            return VK_OEM_BACKSTAB;
        case 0x5F:
            return VK_OEM_AUTO;
        case 0x62:
            return VK_DBE_NOCODEINPUT;
        case 0x63:
            return VK_HELP;
        case 0x64:
            return VK_F13;
        case 0x65:
            return VK_F14;
        case 0x66:
            return VK_F15;
        case 0x67:
            return VK_F16;
        case 0x68:
            return VK_F17;
        case 0x69:
            return VK_F18;
        case 0x6A:
            return VK_F19;
        case 0x6B:
            return VK_F20;
        case 0x6C:
            return VK_F21;
        case 0x6D:
            return VK_F22;
        case 0x6E:
            return VK_F23;
        case 0x6F:
            return VK_OEM_PA3;
        case 0x71:
            return VK_OEM_RESET;
        case 0x73:
            return VK_ABNT_C1;
        case 0x76:
            return VK_F24;
        case 0x7B:
            return VK_OEM_PA1;
        case 0x7C:
            return VK_TAB;
        case 0x7E:
            return VK_ABNT_C2;
        default:
            return UNKNOWN;
    }
}

enum keycode get_keycode(uint8_t scancode) {
    switch (current_keyboard_layout) {
        case De:
            return get_de_keycode(scancode);
        case Us:
            //TODO US Layout: http://kbdlayout.info/kbdus/virtualkeys
            printf("ERROR: US Keyboard not yet supported!");
            return UNKNOWN;
        default:
            // http://kbdlayout.info/KBDGR/virtualkeys
            printf("ERROR: Unknown Keyboard Layout!");
            return UNKNOWN;
    }
}

char* keycode_to_string(enum keycode keycode) {
    switch (keycode) {
        case VK_A:
            return "a";
        case VK_B:
            return "b";
        case VK_C:
            return "c";
        case VK_D:
            return "d";
        case VK_E:
            return "e";
        case VK_F:
            return "f";
        case VK_G:
            return "g";
        case VK_H:
            return "h";
        case VK_I:
            return "i";
        case VK_J:
            return "j";
        case VK_K:
            return "k";
        case VK_L:
            return "l";
        case VK_M:
            return "m";
        case VK_N:
            return "n";
        case VK_O:
            return "o";
        case VK_P:
            return "p";
        case VK_Q:
            return "q";
        case VK_R:
            return "r";
        case VK_S:
            return "s";
        case VK_T:
            return "t";
        case VK_U:
            return "u";
        case VK_V:
            return "v";
        case VK_W:
            return "w";
        case VK_X:
            return "x";
        case VK_Y:
            return "y";
        case VK_Z:
            return "z";
        case VK_0:
            return "0";
        case VK_1:
            return "1";
        case VK_2:
            return "2";
        case VK_3:
            return "3";
        case VK_4:
            return "4";
        case VK_5:
            return "5";
        case VK_6:
            return "6";
        case VK_7:
            return "7";
        case VK_8:
            return "8";
        case VK_9:
            return "9";
        case VK_OEM_102:
            return "<";
        case VK_OEM_5:
            return "^";
        case VK_OEM_4:
            return "ß";
        case VK_OEM_6:
            return "´";
        case VK_OEM_PLUS:
            return "+";
        case VK_OEM_2:
            return "#";
        case VK_OEM_COMMA:
            return ",";
        case VK_OEM_PERIOD:
            return ".";
        case VK_OEM_MINUS:
            return "-";
        case VK_SPACE:
            return " ";
        case VK_RETURN:
            return "\n";
        case VK_BACK:
            rm_last_char();
            return "";
        default:
            return "";
    }
}

static enum keycode lastcode = UNKNOWN;

static void keyboard_callback(registers_t* regs) {
    uint8_t scancode = port_byte_in(0x60);
    enum keycode code = get_keycode(scancode);
    if(code == lastcode) return;
    lastcode = code;
    if(code != UNKNOWN) {
        char* str = keycode_to_string(code);
        if(str_len(str) == 0) return;
        printf("%s", str);
    }
}

void init_keyboard() {
    register_interrupt_handler(IRQ1, keyboard_callback);
}