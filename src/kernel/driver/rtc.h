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
} time_t;

void CMOS_read(unsigned char array[]);
void CMOS_write(unsigned char array[]);
time_t get_current_date();
void print_time(time_t time);
void print_current_time();
void rtc_install();