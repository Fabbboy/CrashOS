org 0x7C00
bits 16


%define ENDL 0x0D, 0x0A


;
; FAT12 header
; 
jmp short start
nop

bdb_oem:                    db 'MSWIN4.1'           ; 8 bytes
bdb_bytes_per_sector:       dw 512
bdb_sectors_per_cluster:    db 1
bdb_reserved_sectors:       dw 1
bdb_fat_count:              db 2
bdb_dir_entries_count:      dw 0x0E0
bdb_total_sectors:          dw 2880                 ; 2880 * 512 = 1.44MB
bdb_media_descriptor_type:  db 0x0F0                 ; F0 = 3.5" floppy disk
bdb_sectors_per_fat:        dw 9                    ; 9 sectors/fat
bdb_sectors_per_track:      dw 18
bdb_heads:                  dw 2
bdb_hidden_sectors:         dd 0
bdb_large_sector_count:     dd 0

; extended boot record
ebr_drive_number:           db 0                    ; 0x00 floppy, 0x80 hdd, useless
                            db 0                    ; reserved
ebr_signature:              db 0x29
ebr_volume_id:              db 0x12, 0x34, 0x56, 0x78   ; serial number, value doesn't matter
ebr_volume_label:           db 'CRASH    OS'        ; 11 bytes, padded with spaces
ebr_system_id:              db 'FAT12   '           ; 8 bytes

start:
    mov ax, 0
    mov ds, ax
    mov es, ax

    mov ss, ax
    mov sp, 0x7C00

    push es
    push word .after
    retf

.after:
    mov [ebr_drive_number], dl

    mov si, msg_loading
    call puts

    push es
    mov ah, 0x08
    int 13h
    jc floppy_error
    pop es

    and cl, 0x3F
    xor ch, ch
    mov [bdb_sectors_per_track], cx

    inc dh
    mov [bdb_heads], dh

    mov ax, [bdb_sectors_per_fat]
    mov bl, [bdb_fat_count]
    xor bh, bh
    mul bx
    add ax, [bdb_reserved_sectors]
    push ax

    mov ax, [bdb_dir_entries_count]
    shl ax, 5
    xor dx, dx
    div word [bdb_bytes_per_sector]

    test dx, dx
    jz .root_dir_after
    inc ax

.root_dir_after:
    mov cl, al
    pop ax
    mov dl, [ebr_drive_number]
    mov bx, buffer
    call disk_read

    xor bx, bx
    mov di, buffer

.search_kernel:
    mov si, file_stage2_bin
    mov cx, 11
    push di
    repe cmpsb
    pop di
    je .found_kernel

    add di, 32
    inc bx
    cmp bx, [bdb_dir_entries_count]
    jl .search_kernel

    jmp kernel_not_found_error

.found_kernel:
    mov ax, [di + 26]
    mov [stage2_cluster], ax

    mov ax, [bdb_reserved_sectors]
    mov bx, buffer
    mov cl, [bdb_sectors_per_fat]
    mov dl, [ebr_drive_number]
    call disk_read

    mov bx, STAGE2_LOAD_SEGMENT
    mov es, bx
    mov bx, STAGE2_LOAD_OFFSET

.load_kernel_loop:
    mov ax, [stage2_cluster]

    add ax, 31

    mov cl, 1
    mov dl, [ebr_drive_number]
    call disk_read

    add bx, [bdb_bytes_per_sector]

    mov ax, [stage2_cluster]
    mov cx, 3
    mul cx
    mov cx, 2
    div cx

    mov si, buffer
    add si, ax
    mov ax, [ds:si]

    or dx, dx
    jz .even

.odd:
    shr ax, 4
    jmp .next_cluster_after

.even:
    and ax, 0x0FFF

.next_cluster_after:
    cmp ax, 0x0FF8
    jae .read_finish

    mov [stage2_cluster], ax
    jmp .load_kernel_loop

.read_finish:
    mov dl, [ebr_drive_number]

    mov ax, STAGE2_LOAD_SEGMENT
    mov ds, ax
    mov es, ax

    jmp STAGE2_LOAD_SEGMENT:STAGE2_LOAD_OFFSET

    jmp wait_key_and_reboot

    cli
    hlt


floppy_error:
    mov si, msg_read_failed
    call puts
    jmp wait_key_and_reboot

kernel_not_found_error:
    mov si, msg_stage2_not_found
    call puts
    jmp wait_key_and_reboot

wait_key_and_reboot:
    mov ah, 0
    int 16h
    jmp 0FFFFh:0

.halt:
    cli
    hlt

puts:
    push si
    push ax
    push bx

.loop:
    lodsb
    or al, al
    jz .done

    mov ah, 0x0E
    mov bh, 0
    int 0x10

    jmp .loop

.done:
    pop bx
    pop ax
    pop si    
    ret

lba_to_chs:

    push ax
    push dx

    xor dx, dx
    div word [bdb_sectors_per_track]

    inc dx
    mov cx, dx

    xor dx, dx
    div word [bdb_heads]

    mov dh, dl
    mov ch, al
    shl ah, 6
    or cl, ah

    pop ax
    mov dl, al
    pop ax
    ret

disk_read:

    push ax
    push bx
    push cx
    push dx
    push di

    push cx
    call lba_to_chs
    pop ax
    
    mov ah, 0x02
    mov di, 3

.retry:
    pusha
    stc
    int 0x13
    jnc .done

    popa
    call disk_reset

    dec di
    test di, di
    jnz .retry

.fail:
    jmp floppy_error

.done:
    popa

    pop di
    pop dx
    pop cx
    pop bx
    pop ax
    ret

disk_reset:
    pusha
    mov ah, 0
    stc
    int 13h
    jc floppy_error
    popa
    ret


msg_loading:            db 'Loading...', ENDL, 0
msg_read_failed:        db 'Read from disk failed!', ENDL, 0
msg_stage2_not_found:   db 'STAGE2.BIN file not found!', ENDL, 0
file_stage2_bin:        db 'STAGE2  BIN'
stage2_cluster:         dw 0

STAGE2_LOAD_SEGMENT     equ 0x0
STAGE2_LOAD_OFFSET      equ 0x500


times 510-($-$$) db 0
dw 0AA55h

buffer:
