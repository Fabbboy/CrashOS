#pragma once
#include <stdint.h>

//Define screenwidtrh
#define SCREEN_WIDTH 80
#define SCREEN_HEIGHT 25


void put_color(int x, int y, uint8_t color);
char get_chr(int x, int y);
uint8_t get_color(int x, int y);
int getLength(int line);

void set_cursor(int x, int y);
void set_last_char_cursor();
void clear_screen();
void putc(char c);

int last_chr_x(int line);

void rm_chr(int x, int y);
void rm_color(int x, int y);
void rm_last_char();

__attribute__((unused)) void rm_chrs(uint32_t amount);
void rm_line(int line);
void rm_last_line();

void puts(const char* str);
void printf(const char* fmt, ...);
void println();

void arrow_right();
void arrow_left();


__attribute__((unused)) void print_buffer(const char* msg, const void* buffer, uint32_t count);
