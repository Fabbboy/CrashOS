#include "rtc.h"
#include "../i686/io.h"

unsigned char second;
unsigned char minute;
unsigned char hour;
unsigned char day;
unsigned char month;
unsigned int year;
unsigned char century;

int get_update_in_progress_flag() {
    outb(CMOS_CMD_PORT, 0x0A);
    return inb(CMOS_DATA_PORT) & 0x80;
}

unsigned char get_RTC_register(int reg) {
    outb(CMOS_CMD_PORT, reg);
    return inb(CMOS_DATA_PORT);
}

void CMOS_read(unsigned char array[]) {
    for(unsigned char index = 0; index < 128; index++) {
        i686_DisableInterrupts();
        array[index] = get_RTC_register(index);
        i686_EnableInterrupts();
    }
}

void CMOS_write(unsigned char array[]) {
    for(unsigned char index = 0; index < 128; index++) {
        i686_DisableInterrupts();
        outb(CMOS_CMD_PORT, index);
        outb(CMOS_DATA_PORT, array[index]);
        i686_EnableInterrupts();
    }
}

void read_rtc() {
    unsigned char last_second;
    unsigned char last_minute;
    unsigned char last_hour;
    unsigned char last_day;
    unsigned char last_month;
    unsigned char last_year;
    unsigned char last_century;
    unsigned char registerB;


    while (get_update_in_progress_flag());
    second = get_RTC_register(0x00);
    minute = get_RTC_register(0x02);
    hour = get_RTC_register(0x04);
    day = get_RTC_register(0x07);
    month = get_RTC_register(0x08);
    year = get_RTC_register(0x09);
    century = get_RTC_register(0x32);

    do {
        last_second = second;
        last_minute = minute;
        last_hour = hour;
        last_day = day;
        last_month = month;
        last_year = year;
        last_century = century;

        while (get_update_in_progress_flag());
        second = get_RTC_register(0x00);
        minute = get_RTC_register(0x02);
        hour = get_RTC_register(0x04);
        day = get_RTC_register(0x07);
        month = get_RTC_register(0x08);
        year = get_RTC_register(0x09);
        century = get_RTC_register(0x32);

    } while ((last_second != second) || (last_minute != minute) || (last_hour != hour) ||
             (last_day != day) || (last_month != month) || (last_year != year) ||
             (last_century != century));

    registerB = get_RTC_register(0x0B);

    if(!(registerB & 0x04)) {
        second = (second & 0x0F) + ((second / 16) * 10);
        minute = (minute & 0x0F) + ((minute / 16) * 10);
        hour = ( (hour & 0x0F) + (((hour & 0x70) / 16) * 10) ) | (hour & 0x80);
        day = (day & 0x0F) + ((day / 16) * 10);
        month = (month & 0x0F) + ((month / 16) * 10);
        year = (year & 0x0F) + ((year / 16) * 10);
        century = (century & 0x0F) + ((century / 16) * 10);
    }

    if(!(registerB & 0x02) && (hour & 0x80)) {
        hour = ((hour & 0x7F) + 12) % 24;
    }

    year += century * 100;
}

Date get_current_date() {
    read_rtc();
    Date date = {
            second, minute, hour, day, month, year, century
    };
    return date;
}