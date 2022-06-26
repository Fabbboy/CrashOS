#pragma once

#define PIT_FREQUENZY           1193182
#define PIT_COUNTER0            0x40
#define PIT_CMD                 0x43

void pit_install();
void pit_wait(int ticks);