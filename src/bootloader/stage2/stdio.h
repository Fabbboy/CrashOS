#pragma once
#include <stdint.h>

void clear_screen();
void putc(char c);
void puts(const char* str);
void printf(const char* fmt, ...);

__attribute__((unused)) void print_buffer(const char* msg, const void* buffer, uint32_t count);
