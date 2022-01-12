#include "stdio.h"
#include "x86.h"

#include <stdarg.h>
#include <stdbool.h>

const unsigned SCREEN_WIDTH = 80;
const unsigned SCREEN_HEIGHT = 25;
const uint8_t DEFAULT_COLOR = 0x7;

uint8_t* g_ScreenBuffer = (uint8_t*)0xB8000;
int g_ScreenX = 0, g_ScreenY = 0;

void put_chr(uint8_t x, uint8_t y, char c)
{
    g_ScreenBuffer[2 * (y * SCREEN_WIDTH + x)] = c;
}

void put_color(uint8_t x, uint8_t y, uint8_t color)
{
    g_ScreenBuffer[2 * (y * SCREEN_WIDTH + x) + 1] = color;
}

char get_chr(uint8_t x, uint8_t y)
{
    return (char) g_ScreenBuffer[2 * (y * SCREEN_WIDTH + x)];
}

uint8_t get_color(uint8_t x, uint8_t y)
{
    return g_ScreenBuffer[2 * (y * SCREEN_WIDTH + x) + 1];
}

void set_cursor(uint8_t x, uint8_t y)
{
    uint8_t pos = y * SCREEN_WIDTH + x;

    x86_outb(0x3D4, 0x0F);
    x86_outb(0x3D5, (uint8_t)(pos & 0xFF));
    x86_outb(0x3D4, 0x0E);
    x86_outb(0x3D5, (uint8_t)((pos >> 8) & 0xFF));
}

void clear_screen()
{
    for (int y = 0; y < SCREEN_HEIGHT; y++)
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            put_chr(x, y, '\0');
            put_color(x, y, DEFAULT_COLOR);
        }

    g_ScreenX = 0;
    g_ScreenY = 0;
    set_cursor(g_ScreenX, g_ScreenY);
}

void scrollback(int lines)
{
    for (int y = lines; y < SCREEN_HEIGHT; y++)
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            put_chr(x, y - lines, get_chr(x, y));
            put_color(x, y - lines, get_color(x, y));
        }

    for (uint8_t y = SCREEN_HEIGHT - lines; y < SCREEN_HEIGHT; y++)
        for (uint8_t x = 0; x < SCREEN_WIDTH; x++)
        {
            put_chr(x, y, '\0');
            put_color(x, y, DEFAULT_COLOR);
        }

    g_ScreenY -= lines;
}

#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
void putc(char c)
{
    switch (c)
    {
        case '\n':
            g_ScreenX = 0;
            g_ScreenY++;
            break;

        case '\t':
            for (int i = 0; i < 4 - (g_ScreenX % 4); i++)
                putc(' ');
            break;

        case '\r':
            g_ScreenX = 0;
            break;

        default:
            put_chr(g_ScreenX, g_ScreenY, c);
            g_ScreenX++;
            break;
    }

    if (g_ScreenX >= SCREEN_WIDTH)
    {
        g_ScreenY++;
        g_ScreenX = 0;
    }
    if (g_ScreenY >= SCREEN_HEIGHT)
        scrollback(1);

    set_cursor(g_ScreenX, g_ScreenY);
}
#pragma clang diagnostic pop

uint8_t last_chr_x(int line)
{
    unsigned int res = SCREEN_WIDTH;

    while(get_chr(res, line) == '\0' && res >= 0)
        res--;

    return res;
}

void rm_chr(uint8_t x, uint8_t y)
{
    g_ScreenBuffer[2 * (y * SCREEN_WIDTH + x)] = '\0';
}

void rm_color(uint8_t x, uint8_t y)
{
    g_ScreenBuffer[2 * (y * SCREEN_WIDTH + x) + 1] = DEFAULT_COLOR;
}

__attribute__((unused)) void rm_chrs(uint32_t amount)
{
    for(int i = 0; i < amount; i++)
    {
        g_ScreenX--;
        if(g_ScreenX < 0)
        {
            g_ScreenY--;
            g_ScreenX = last_chr_x(g_ScreenY) + 1;
        }

        rm_chr(g_ScreenX, g_ScreenY);
        rm_color(g_ScreenX, g_ScreenY);
    }

    set_cursor(g_ScreenX, g_ScreenY);
}

void rm_line(uint8_t line)
{
    for(uint8_t i = SCREEN_WIDTH; i >= 0; i--)
        put_chr(i, line, '\0');
}

void rm_last_line()
{
    rm_line(g_ScreenY);
    g_ScreenY--;
    g_ScreenX = last_chr_x(g_ScreenY) + 1;

    set_cursor(g_ScreenX, g_ScreenY);
}

void puts(const char* str)
{
    while(*str)
    {
        putc(*str);
        str++;
    }
}

const char g_HexChars[] = "0123456789abcdef";

void printf_unsigned(unsigned long long number, int radix)
{
    char buffer[32];
    int pos = 0;

    // convert number to ASCII
    do 
    {
        unsigned long long rem = number % radix;
        number /= radix;
        buffer[pos++] = g_HexChars[rem];
    } while (number > 0);

    // print number in reverse order
    while (--pos >= 0)
        putc(buffer[pos]);
}

void printf_signed(long long number, int radix)
{
    if (number < 0)
    {
        putc('-');
        printf_unsigned(-number, radix);
    }
    else printf_unsigned(number, radix);
}

#define PRINTF_STATE_NORMAL         0
#define PRINTF_STATE_LENGTH         1
#define PRINTF_STATE_LENGTH_SHORT   2
#define PRINTF_STATE_LENGTH_LONG    3
#define PRINTF_STATE_SPEC           4

#define PRINTF_LENGTH_DEFAULT       0
#define PRINTF_LENGTH_SHORT_SHORT   1
#define PRINTF_LENGTH_SHORT         2
#define PRINTF_LENGTH_LONG          3
#define PRINTF_LENGTH_LONG_LONG     4

void printf(const char* fmt, ...)
{
    va_list args;
    va_start(args, fmt);

    int state = PRINTF_STATE_NORMAL;
    int length = PRINTF_LENGTH_DEFAULT;
    int radix = 10;
    bool sign = false;
    bool number = false;

    while (*fmt)
    {
        switch (state)
        {
            case PRINTF_STATE_NORMAL:
                switch (*fmt)
                {
                    case '%':   state = PRINTF_STATE_LENGTH;
                                break;
                    default:    putc(*fmt);
                                break;
                }
                break;

            case PRINTF_STATE_LENGTH:
                switch (*fmt)
                {
                    case 'h':   length = PRINTF_LENGTH_SHORT;
                                state = PRINTF_STATE_LENGTH_SHORT;
                                break;
                    case 'l':   length = PRINTF_LENGTH_LONG;
                                state = PRINTF_STATE_LENGTH_LONG;
                                break;
                    default:    goto PRINTF_STATE_SPEC_;
                }
                break;

            case PRINTF_STATE_LENGTH_SHORT:
                if (*fmt == 'h')
                {
                    length = PRINTF_LENGTH_SHORT_SHORT;
                    state = PRINTF_STATE_SPEC;
                }
                else goto PRINTF_STATE_SPEC_;
                break;

            case PRINTF_STATE_LENGTH_LONG:
                if (*fmt == 'l')
                {
                    length = PRINTF_LENGTH_LONG_LONG;
                    state = PRINTF_STATE_SPEC;
                }
                else goto PRINTF_STATE_SPEC_;
                break;

            case PRINTF_STATE_SPEC:
            PRINTF_STATE_SPEC_:
                switch (*fmt)
                {
                    case 'c':   putc((char)va_arg(args, int));
                                break;

                    case 's':   
                                puts(va_arg(args, const char*));
                                break;

                    case '%':   putc('%');
                                break;

                    case 'd':
                    case 'i':   radix = 10; sign = true; number = true;
                                break;

                    case 'u':   radix = 10; sign = false; number = true;
                                break;

                    case 'X':
                    case 'x':
                    case 'p':   radix = 16; sign = false; number = true;
                                break;

                    case 'o':   radix = 8; sign = false; number = true;
                                break;

                    // ignore invalid spec
                    default:    break;
                }

                if (number)
                {
                    if (sign)
                    {
                        switch (length)
                        {
                        case PRINTF_LENGTH_SHORT_SHORT:
                        case PRINTF_LENGTH_SHORT:
                        case PRINTF_LENGTH_DEFAULT:     printf_signed(va_arg(args, int), radix);
                                                        break;

                        case PRINTF_LENGTH_LONG:        printf_signed(va_arg(args, long), radix);
                                                        break;

                        case PRINTF_LENGTH_LONG_LONG:   printf_signed(va_arg(args, long long), radix);
                                                        break;
                        }
                    }
                    else
                    {
                        switch (length)
                        {
                        case PRINTF_LENGTH_SHORT_SHORT:
                        case PRINTF_LENGTH_SHORT:
                        case PRINTF_LENGTH_DEFAULT:     printf_unsigned(va_arg(args, unsigned int), radix);
                                                        break;
                                                        
                        case PRINTF_LENGTH_LONG:        printf_unsigned(va_arg(args, unsigned  long), radix);
                                                        break;

                        case PRINTF_LENGTH_LONG_LONG:   printf_unsigned(va_arg(args, unsigned  long long), radix);
                                                        break;
                        }
                    }
                }

                // reset state
                state = PRINTF_STATE_NORMAL;
                length = PRINTF_LENGTH_DEFAULT;
                radix = 10;
                sign = false;
                break;
        }

        fmt++;
    }

    va_end(args);
}

void print_buffer(const char* msg, const void* buffer, uint32_t count)
{
    const uint8_t* u8Buffer = (const uint8_t*)buffer;
    
    puts(msg);
    for (uint16_t i = 0; i < count; i++)
    {
        putc(g_HexChars[u8Buffer[i] >> 4]);
        putc(g_HexChars[u8Buffer[i] & 0xF]);
    }
    puts("\n");
}
