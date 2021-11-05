#pragma once
#include <stdint.h>

void putcolor(int x, int y, uint8_t color);
char getchr(int x, int y);
uint8_t getcolor(int x, int y);

void setcursor(int x, int y);
void clrscr();
void putc(char c);

int lastchrx(int line);

void rmchr(int x, int y);
void rmcolor(int x, int y);
void rmchrs(uint32_t amount);
void rmline(int line);
void rmlastline();

void puts(const char* str);
void printf(const char* fmt, ...);
void print_buffer(const char* msg, const void* buffer, uint32_t count);
