#pragma once

#include "stdbool.h"



const char* strchr(const char* str, char chr);
char* strcpy(char* dst, const char* src);
unsigned strlen(const char* str);
char* strcat(char* destination, const char* source);
bool strcmp(const char* first, const char* second);
void strrev(char* str);
char* strlwr(char* str);
char* strupr(char* str);