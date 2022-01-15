%macro x86_EnterRealMode 0
    [bits 32]
    jmp word 18h:.pmode16

.pmode16:
    [bits 16]
    mov eax, cr0
    and al, ~1
    mov cr0, eax

    jmp word 00h:.rmode

.rmode:
    mov ax, 0
    mov ds, ax
    mov ss, ax

    sti

%endmacro


%macro x86_EnterProtectedMode 0
    cli

    mov eax, cr0
    or al, 1
    mov cr0, eax

    jmp dword 08h:.pmode


.pmode:
    [bits 32]
    mov ax, 0x10
    mov ds, ax
    mov ss, ax

%endmacro

%macro LinearToSegOffset 4

    mov %3, %1
    shr %3, 4
    mov %2, %4
    mov %3, %1
    and %3, 0xf

%endmacro


global x86_outb
x86_outb:
    [bits 32]
    mov dx, [esp + 4]
    mov al, [esp + 8]
    out dx, al
    ret

global x86_inb
x86_inb:
    [bits 32]
    mov dx, [esp + 4]
    xor eax, eax
    in al, dx
    ret


global x86_Disk_GetDriveParams
x86_Disk_GetDriveParams:
    [bits 32]
    push ebp
    mov ebp, esp

    x86_EnterRealMode

    [bits 16]
    push es
    push bx
    push esi
    push di

    mov dl, [bp + 8]
    mov ah, 08h
    mov di, 0
    mov es, di
    stc
    int 13h

    mov eax, 1
    sbb eax, 0

    LinearToSegOffset [bp + 12], es, esi, si
    mov [es:si], bl

    mov bl, ch
    mov bh, cl
    shr bh, 6
    inc bx

    LinearToSegOffset [bp + 16], es, esi, si
    mov [es:si], bx

    xor ch, ch
    and cl, 3Fh

    LinearToSegOffset [bp + 20], es, esi, si
    mov [es:si], cx

    mov cl, dh
    inc cx

    LinearToSegOffset [bp + 24], es, esi, si
    mov [es:si], cx

    pop di
    pop esi
    pop bx
    pop es

    push eax

    x86_EnterProtectedMode

    [bits 32]

    pop eax

    mov esp, ebp
    pop ebp
    ret


global x86_Disk_Reset
x86_Disk_Reset:
    [bits 32]
    push ebp
    mov ebp, esp


    x86_EnterRealMode

    mov ah, 0
    mov dl, [bp + 8]
    stc
    int 13h

    mov eax, 1
    sbb eax, 0

    push eax

    x86_EnterProtectedMode

    pop eax

    mov esp, ebp
    pop ebp
    ret


global x86_Disk_Read
x86_Disk_Read:
    push ebp
    mov ebp, esp

    x86_EnterRealMode

    push ebx
    push es

    mov dl, [bp + 8]

    mov ch, [bp + 12]
    mov cl, [bp + 13]
    shl cl, 6

    mov al, [bp + 16]
    and al, 3Fh
    or cl, al

    mov dh, [bp + 20]

    mov al, [bp + 24]

    LinearToSegOffset [bp + 28], es, ebx, bx

    mov ah, 02h
    stc
    int 13h

    mov eax, 1
    sbb eax, 0

    pop es
    pop ebx

    push eax

    x86_EnterProtectedMode

    pop eax

    mov esp, ebp
    pop ebp
    ret