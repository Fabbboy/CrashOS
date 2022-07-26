#pragma once

#define CMOS_CMD_PORT       0x70
#define CMOS_DATA_PORT      0x71

typedef struct {
    unsigned char second;
    unsigned char minute;
    unsigned char hour;
    unsigned char day;
    unsigned char month;
    unsigned int year;
    unsigned char century;
} Date;

void CMOS_read(unsigned char array[]);
void CMOS_write(unsigned char array[]);
void read_rtc();
Date get_current_date();