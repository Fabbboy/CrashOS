#pragma once

#include "stdint.h"

//Bit operations
#define low_16(address) (uint16_t)((address & 0xFFFF))
#define high_16(address) (uint16_t)(((address >> 16) & 0xFFFF))

//Min Max
#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))