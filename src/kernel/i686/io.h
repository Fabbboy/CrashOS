#pragma once
#include <stdint.h>

void __attribute__((cdecl)) outb(uint16_t port, uint8_t value);
void __attribute__((cdecl)) outw(uint16_t port, uint16_t value);
void __attribute__((cdecl)) outl(uint16_t port, uint32_t value);
uint8_t __attribute__((cdecl)) inb(uint16_t port);
uint16_t __attribute__((cdecl)) inw(uint16_t port);
uint32_t __attribute__((cdecl)) inl(uint16_t port);
uint8_t __attribute__((cdecl)) i686_EnableInterrupts();
uint8_t __attribute__((cdecl)) i686_DisableInterrupts();

void i686_iowait();
void __attribute__((cdecl)) i686_Panic();