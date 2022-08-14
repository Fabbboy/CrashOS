#pragma once
#include "stdint.h"

//Define NULL
#ifndef NULL
#define NULL 0
#endif


void* memcpy(void* dst, const void* src, uint16_t num);
void* memset(void* ptr, int value, uint16_t num);
int memcmp(const void* ptr1, const void* ptr2, uint16_t num);

void paging_init();
void __attribute__((cdecl)) loadPageDirectory(unsigned int*);
void __attribute__((cdecl)) enablePaging();

void* malloc(uint32_t size);
void free(void* ptr);
void mapMemory();
