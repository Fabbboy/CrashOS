global outb
outb:
    [bits 32]
    mov dx, [esp + 4]
    mov al, [esp + 8]
    out dx, al
    ret

global outw
outw:
    [bits 32]
    mov dx, [esp + 4]
    mov ax, [esp + 8]
    out dx, ax
    ret

global outl
outl:
    [bits 32]
    mov dx, [esp + 4]
    mov eax, [esp + 8]
    out dx, eax
    ret

global inb
inb:
    [bits 32]
    mov dx, [esp + 4]
    xor eax, eax
    in al, dx
    ret

global inw
inw:
    [bits 32]
    mov dx, [esp + 4]
    xor eax, eax
    in ax, dx
    ret

global inl
inl:
    [bits 32]
    mov dx, [esp + 4]
    xor eax, eax
    in eax, dx
    ret

global i686_Panic
i686_Panic:
    cli
    hlt

global i686_EnableInterrupts
i686_EnableInterrupts:
    sti
    ret

global i686_DisableInterrupts
i686_DisableInterrupts:
    cli
    ret