#include "memory.h"
#include "../video/stdio.h"

//get &__end from linker script
extern uint8_t __end;

void* memcpy(void* dst, const void* src, uint16_t num)
{
    uint8_t* u8Dst = (uint8_t *)dst;
    const uint8_t* u8Src = (const uint8_t *)src;

    for (uint16_t i = 0; i < num; i++)
        u8Dst[i] = u8Src[i];

    return dst;
}

void* memset(void * ptr, int value, uint16_t num)
{
    uint8_t* u8Ptr = (uint8_t *)ptr;

    for (uint16_t i = 0; i < num; i++)
        u8Ptr[i] = (uint8_t)value;

    return ptr;
}

int memcmp(const void* ptr1, const void* ptr2, uint16_t num)
{
    const uint8_t* u8Ptr1 = (const uint8_t *)ptr1;
    const uint8_t* u8Ptr2 = (const uint8_t *)ptr2;

    for (uint16_t i = 0; i < num; i++)
        if (u8Ptr1[i] != u8Ptr2[i])
            return 1;

    return 0;
}

uint32_t page_directory[1024] __attribute__((aligned(4096)));
uint32_t first_page_table[1024] __attribute__((aligned(4096)));

void paging_init() {
    for(int i = 0; i < 1024; i++) {
        page_directory[i] = 0x00000002;
    }

    for(int i = 0; i < 1024; i++) {
        first_page_table[i] = (i * 0x1000) | 3;
    }

    page_directory[0] = ((unsigned int) first_page_table) | 3;

    loadPageDirectory(page_directory);
    enablePaging();
}
void mapMemory(){
    for(int i = 0; i < 1024; i++){
        if(first_page_table[i] != 0){
            printf("%d: %x\n", i, first_page_table[i]);
        }
    }
};


void* malloc(uint32_t size) {
    if (size <= 0){
        printf("malloc: size is 0\n");
    //stop the function withozt returning
    }else {

        void *mem = (void *) &__end;
        for (int i = 0; i < size; i++) {
            memcpy(mem + i, mem, 1);
        }
        return mem;
    }
};
void free(void* ptr){
    for(int i = 0; i < 1024; i++){
        if(first_page_table[i] == (unsigned int)ptr){
            first_page_table[i] = 0;
        }
    }
};

