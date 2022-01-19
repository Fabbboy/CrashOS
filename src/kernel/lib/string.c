#include "string.h"
#include <stddef.h>

const char* strchr(const char* str, char chr)
{
    if (str == NULL)
        return NULL;

    while (*str)
    {
        if (*str == chr)
            return str;

        ++str;
    }

    return NULL;
}

char* strcpy(char* dst, const char* src)
{
    char* origDst = dst;

    if (dst == NULL)
        return NULL;

    if (src == NULL)
    {
        *dst = '\0';
        return dst;
    }

    while (*src)
    {
        *dst = *src;
        ++src;
        ++dst;
    }
    
    *dst = '\0';
    return origDst;
}

unsigned strlen(const char* str)
{
    unsigned len = 0;
    while (*str)
    {
        ++len;
        ++str;
    }

    return len;
}

char* strcat(char* destination, const char* source) {
    strcpy(destination + strlen(destination), source);
    return destination;
}

bool strcmp(const char* first, const char* second) {
    while(*first && (*first == *second)) {
        first++;
        second++;
    }

    return *first - *second == 0;
}

void strrev(char* str) {
    int i, j;
    char a;
    unsigned len = strlen((const char*)str);

    for(i = 0, j = (int) len - 1; i < j; i++, j--) {
        a = str[i];
        str[i] = str[j];
        str[j] = a;
    }
}

char* strlwr(char* str) {
    char* t = str;
    if(!str) return 0;

    while (*t != '\0') {
        if(*t >= 'A' && *t <= 'Z') {
            *t += ('a' - 'A');
        }
        t++;
    }

    return str;
}

char* strupr(char* str) {
    char* t = str;
    if(!str) return 0;

    while (*t != '\0') {
        if(*t >= 'a' && *t <= 'z') {
            *t += ('A' - 'a');
        }
        t++;
    }

    return str;
}