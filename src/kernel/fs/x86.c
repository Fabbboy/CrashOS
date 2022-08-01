#include "x86.h"
#include "../i686/io.h"

#define STATUS_BSY          0x80
#define STATUS_RDY          0x40
#define STATUS_DRQ          0x08
#define STATUS_DF           0x20
#define STATUS_ERR          0x01

#define ATA_DATA_PORT       0x1F0
#define ATA_PORT_1          0x1F2
#define ATA_PORT_2          0x1F3
#define ATA_PORT_3          0x1F4
#define ATA_PORT_4          0x1F5
#define ATA_PORT_5          0x1F6
#define ATA_CMD_PORT        0x1F7

static void ATA_wait_BSY() {
    while (inb(ATA_CMD_PORT) & STATUS_BSY);
}

static void ATA_wait_DRQ() {
    while (!(inb(ATA_CMD_PORT) & STATUS_RDY));
}

void x86_Disk_Read(uint32_t target_address, uint32_t LBA, uint8_t sector_count) {
    ATA_wait_BSY();
    outb(ATA_PORT_5, 0xE0 | ((LBA >> 24) & 0xF));
    outb(ATA_PORT_1, sector_count);
    outb(ATA_PORT_2, (uint8_t) LBA);
    outb(ATA_PORT_3, (uint8_t) (LBA >> 8));
    outb(ATA_PORT_4, (uint8_t) (LBA >> 16));
    outb(ATA_CMD_PORT, 0x20);       // read command

    uint16_t* target = (uint16_t*) target_address;

    for(int j = 0; j < sector_count; j++) {
        ATA_wait_BSY();
        ATA_wait_DRQ();
        for(int i = 0; i < 256; i++) {
            target[i] = inw(ATA_DATA_PORT);
        }

        target += 256;
    }
}

void x86_Disk_Write(uint32_t LBA, uint8_t sector_count, uint32_t* bytes) {
    ATA_wait_BSY();
    outb(ATA_PORT_5, 0xE0 | ((LBA >> 24) & 0xF));
    outb(ATA_PORT_1, sector_count);
    outb(ATA_PORT_2, (uint8_t) LBA);
    outb(ATA_PORT_3, (uint8_t) (LBA >> 8));
    outb(ATA_PORT_4, (uint8_t) (LBA >> 16));
    outb(ATA_CMD_PORT, 0x30);       // write command

    for(int j = 0; j < sector_count; j++) {
        ATA_wait_BSY();
        ATA_wait_DRQ();
        for(int i = 0; i < 256; i++) {
            outl(ATA_DATA_PORT, bytes[i]);
        }

        bytes += 256;
    }
}