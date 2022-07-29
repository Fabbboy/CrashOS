#include <stdbool.h>
#include "rtc.h"
#include "../i686/io.h"
#include "../video/stdio.h"
#include "../i686/isr.h"
#include "../i686/irq.h"

time_t global_time;
bool is_bcd;

int get_update_in_progress_flag() {
    outb(CMOS_CMD_PORT, 0x0A);
    return inb(CMOS_DATA_PORT) & 0x80;
}

unsigned char read_RTC_register(int reg) {
    outb(CMOS_CMD_PORT, reg);
    return inb(CMOS_DATA_PORT);
}

void write_RTC_register(int reg, unsigned char value) {
    outb(CMOS_CMD_PORT, reg);
    outb(CMOS_DATA_PORT, value);
}

void CMOS_read(unsigned char array[]) {
    for(unsigned char index = 0; index < 128; index++) {
        i686_DisableInterrupts();
        array[index] = read_RTC_register(index);
        i686_EnableInterrupts();
    }
}

void CMOS_write(unsigned char array[]) {
    for(unsigned char index = 0; index < 128; index++) {
        i686_DisableInterrupts();
        write_RTC_register(index, array[index]);
        i686_EnableInterrupts();
    }
}

void rtc_read() {
    unsigned char last_second;
    unsigned char last_minute;
    unsigned char last_hour;
    unsigned char last_day;
    unsigned char last_month;
    unsigned char last_year;
    unsigned char last_century;
    unsigned char registerB;


    while (get_update_in_progress_flag());
    global_time.second = read_RTC_register(0x00);
    global_time.minute = read_RTC_register(0x02);
    global_time.hour = read_RTC_register(0x04);
    global_time.day = read_RTC_register(0x07);
    global_time.month = read_RTC_register(0x08);
    global_time.year = read_RTC_register(0x09);
    global_time.century = read_RTC_register(0x32);

    do {
        last_second = global_time.second;
        last_minute = global_time.minute;
        last_hour = global_time.hour;
        last_day = global_time.day;
        last_month = global_time.month;
        last_year = global_time.year;
        last_century = global_time.century;

        while (get_update_in_progress_flag());
        global_time.second = read_RTC_register(0x00);
        global_time.minute = read_RTC_register(0x02);
        global_time.hour = read_RTC_register(0x04);
        global_time.day = read_RTC_register(0x07);
        global_time.month = read_RTC_register(0x08);
        global_time.year = read_RTC_register(0x09);
        global_time.century = read_RTC_register(0x32);

    } while ((last_second != global_time.second) || (last_minute != global_time.minute) || (last_hour != global_time.hour) ||
             (last_day != global_time.day) || (last_month != global_time.month) || (last_year != global_time.year) ||
             (last_century != global_time.century));

    registerB = read_RTC_register(0x0B);

    if(!(registerB & 0x04)) {
        global_time.second = (global_time.second & 0x0F) + ((global_time.second / 16) * 10);
        global_time.minute = (global_time.minute & 0x0F) + ((global_time.minute / 16) * 10);
        global_time.hour = ( (global_time.hour & 0x0F) + (((global_time.hour & 0x70) / 16) * 10) ) | (global_time.hour & 0x80);
        global_time.day = (global_time.day & 0x0F) + ((global_time.day / 16) * 10);
        global_time.month = (global_time.month & 0x0F) + ((global_time.month / 16) * 10);
        global_time.year = (global_time.year & 0x0F) + ((global_time.year / 16) * 10);
        global_time.century = (global_time.century & 0x0F) + ((global_time.century / 16) * 10);
    }

    if(!(registerB & 0x02) && (global_time.hour & 0x80)) {
        global_time.hour = ((global_time.hour & 0x7F) + 12) % 24;
    }

    global_time.year += global_time.century * 100;
}

time_t get_current_date() {
    return global_time;
}

void print_time(time_t time) {
    printf("UTC Time: %d:%d:%d\n", time.hour, time.minute, time.second);
    printf("Date: %d.%d.%d\n", time.day, time.month, time.year);
}

void print_current_time() {
    print_time(global_time);
}

unsigned char bcd2bin(unsigned char bcd)
{
    return ((bcd >> 4) * 10) + (bcd & 0x0F);
}

void rtc_handler(Registers* registers) {
    if(read_RTC_register(0x0C) & 0x10) {
        if(is_bcd){
            global_time.second = bcd2bin(read_RTC_register(0x00));
            global_time.minute = bcd2bin(read_RTC_register(0x02));
            global_time.hour = bcd2bin(read_RTC_register(0x04));
            global_time.month = bcd2bin(read_RTC_register(0x08));
            global_time.year = bcd2bin(read_RTC_register(0x09));
            global_time.day = bcd2bin(read_RTC_register(0x07));
        }else {
            global_time.second = read_RTC_register(0x00);
            global_time.minute = read_RTC_register(0x02);
            global_time.hour = read_RTC_register(0x04);
            global_time.month = read_RTC_register(0x08);
            global_time.year = read_RTC_register(0x09);
            global_time.day = read_RTC_register(0x07);
        }
    }
}

void rtc_install() {
    unsigned char status;

    status = read_RTC_register(0x0B);
    status |= 0x02;         //24-hour clock
    status |= 0x10;         //update ended interrupts
    status &= ~0x20;        // no alarm interrupts
    status &= ~0x40;        // no periodic interrupt
    is_bcd = !(status & 0x04);
    write_RTC_register(0x0B, status);

    read_RTC_register(0x0C);

    rtc_read();

    IRQ_RegisterHandler(8, rtc_handler);
    printf("RTC installed!\n");
}