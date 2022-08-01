#pragma once

#include <stdint.h>

void x86_Disk_Read(uint32_t target_address, uint32_t LBA, uint8_t sector_count);
void x86_Disk_Write(uint32_t LBA, uint8_t sector_count, uint32_t* bytes);