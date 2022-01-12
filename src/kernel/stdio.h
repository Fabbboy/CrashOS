#pragma once
#include <stdint.h>

void put_color(uint8_t x, uint8_t y, uint8_t color);
char get_chr(uint8_t x, uint8_t y);
uint8_t get_color(uint8_t x, uint8_t y);

void set_cursor(uint8_t x, uint8_t y);
void clear_screen();
void putc(char c);

uint8_t last_chr_x(int line);

void rm_chr(uint8_t x, uint8_t y);
void rm_color(uint8_t x, uint8_t y);

__attribute__((unused)) void rm_chrs(uint32_t amount);
void rm_line(uint8_t line);
void rm_last_line();

void puts(const char* str);
void printf(const char* fmt, ...);
void print_buffer(const char* msg, const void* buffer, uint32_t count);
