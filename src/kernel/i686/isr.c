#include "isr.h"
#include "../video/stdio.h"
#include "idt.h"
#include "gdt.h"
#include <stddef.h>
#include "io.h"
#include "irq.h"

#pragma region IDTGates

void __attribute__((cdecl)) i686_ISR0();
void __attribute__((cdecl)) i686_ISR1();
void __attribute__((cdecl)) i686_ISR2();
void __attribute__((cdecl)) i686_ISR3();
void __attribute__((cdecl)) i686_ISR4();
void __attribute__((cdecl)) i686_ISR5();
void __attribute__((cdecl)) i686_ISR6();
void __attribute__((cdecl)) i686_ISR7();
void __attribute__((cdecl)) i686_ISR8();
void __attribute__((cdecl)) i686_ISR9();
void __attribute__((cdecl)) i686_ISR10();
void __attribute__((cdecl)) i686_ISR11();
void __attribute__((cdecl)) i686_ISR12();
void __attribute__((cdecl)) i686_ISR13();
void __attribute__((cdecl)) i686_ISR14();
void __attribute__((cdecl)) i686_ISR15();
void __attribute__((cdecl)) i686_ISR16();
void __attribute__((cdecl)) i686_ISR17();
void __attribute__((cdecl)) i686_ISR18();
void __attribute__((cdecl)) i686_ISR19();
void __attribute__((cdecl)) i686_ISR20();
void __attribute__((cdecl)) i686_ISR21();
void __attribute__((cdecl)) i686_ISR22();
void __attribute__((cdecl)) i686_ISR23();
void __attribute__((cdecl)) i686_ISR24();
void __attribute__((cdecl)) i686_ISR25();
void __attribute__((cdecl)) i686_ISR26();
void __attribute__((cdecl)) i686_ISR27();
void __attribute__((cdecl)) i686_ISR28();
void __attribute__((cdecl)) i686_ISR29();
void __attribute__((cdecl)) i686_ISR30();
void __attribute__((cdecl)) i686_ISR31();
void __attribute__((cdecl)) i686_ISR32();
void __attribute__((cdecl)) i686_ISR33();
void __attribute__((cdecl)) i686_ISR34();
void __attribute__((cdecl)) i686_ISR35();
void __attribute__((cdecl)) i686_ISR36();
void __attribute__((cdecl)) i686_ISR37();
void __attribute__((cdecl)) i686_ISR38();
void __attribute__((cdecl)) i686_ISR39();
void __attribute__((cdecl)) i686_ISR40();
void __attribute__((cdecl)) i686_ISR41();
void __attribute__((cdecl)) i686_ISR42();
void __attribute__((cdecl)) i686_ISR43();
void __attribute__((cdecl)) i686_ISR44();
void __attribute__((cdecl)) i686_ISR45();
void __attribute__((cdecl)) i686_ISR46();
void __attribute__((cdecl)) i686_ISR47();
void __attribute__((cdecl)) i686_ISR48();
void __attribute__((cdecl)) i686_ISR49();
void __attribute__((cdecl)) i686_ISR50();
void __attribute__((cdecl)) i686_ISR51();
void __attribute__((cdecl)) i686_ISR52();
void __attribute__((cdecl)) i686_ISR53();
void __attribute__((cdecl)) i686_ISR54();
void __attribute__((cdecl)) i686_ISR55();
void __attribute__((cdecl)) i686_ISR56();
void __attribute__((cdecl)) i686_ISR57();
void __attribute__((cdecl)) i686_ISR58();
void __attribute__((cdecl)) i686_ISR59();
void __attribute__((cdecl)) i686_ISR60();
void __attribute__((cdecl)) i686_ISR61();
void __attribute__((cdecl)) i686_ISR62();
void __attribute__((cdecl)) i686_ISR63();
void __attribute__((cdecl)) i686_ISR64();
void __attribute__((cdecl)) i686_ISR65();
void __attribute__((cdecl)) i686_ISR66();
void __attribute__((cdecl)) i686_ISR67();
void __attribute__((cdecl)) i686_ISR68();
void __attribute__((cdecl)) i686_ISR69();
void __attribute__((cdecl)) i686_ISR70();
void __attribute__((cdecl)) i686_ISR71();
void __attribute__((cdecl)) i686_ISR72();
void __attribute__((cdecl)) i686_ISR73();
void __attribute__((cdecl)) i686_ISR74();
void __attribute__((cdecl)) i686_ISR75();
void __attribute__((cdecl)) i686_ISR76();
void __attribute__((cdecl)) i686_ISR77();
void __attribute__((cdecl)) i686_ISR78();
void __attribute__((cdecl)) i686_ISR79();
void __attribute__((cdecl)) i686_ISR80();
void __attribute__((cdecl)) i686_ISR81();
void __attribute__((cdecl)) i686_ISR82();
void __attribute__((cdecl)) i686_ISR83();
void __attribute__((cdecl)) i686_ISR84();
void __attribute__((cdecl)) i686_ISR85();
void __attribute__((cdecl)) i686_ISR86();
void __attribute__((cdecl)) i686_ISR87();
void __attribute__((cdecl)) i686_ISR88();
void __attribute__((cdecl)) i686_ISR89();
void __attribute__((cdecl)) i686_ISR90();
void __attribute__((cdecl)) i686_ISR91();
void __attribute__((cdecl)) i686_ISR92();
void __attribute__((cdecl)) i686_ISR93();
void __attribute__((cdecl)) i686_ISR94();
void __attribute__((cdecl)) i686_ISR95();
void __attribute__((cdecl)) i686_ISR96();
void __attribute__((cdecl)) i686_ISR97();
void __attribute__((cdecl)) i686_ISR98();
void __attribute__((cdecl)) i686_ISR99();
void __attribute__((cdecl)) i686_ISR100();
void __attribute__((cdecl)) i686_ISR101();
void __attribute__((cdecl)) i686_ISR102();
void __attribute__((cdecl)) i686_ISR103();
void __attribute__((cdecl)) i686_ISR104();
void __attribute__((cdecl)) i686_ISR105();
void __attribute__((cdecl)) i686_ISR106();
void __attribute__((cdecl)) i686_ISR107();
void __attribute__((cdecl)) i686_ISR108();
void __attribute__((cdecl)) i686_ISR109();
void __attribute__((cdecl)) i686_ISR110();
void __attribute__((cdecl)) i686_ISR111();
void __attribute__((cdecl)) i686_ISR112();
void __attribute__((cdecl)) i686_ISR113();
void __attribute__((cdecl)) i686_ISR114();
void __attribute__((cdecl)) i686_ISR115();
void __attribute__((cdecl)) i686_ISR116();
void __attribute__((cdecl)) i686_ISR117();
void __attribute__((cdecl)) i686_ISR118();
void __attribute__((cdecl)) i686_ISR119();
void __attribute__((cdecl)) i686_ISR120();
void __attribute__((cdecl)) i686_ISR121();
void __attribute__((cdecl)) i686_ISR122();
void __attribute__((cdecl)) i686_ISR123();
void __attribute__((cdecl)) i686_ISR124();
void __attribute__((cdecl)) i686_ISR125();
void __attribute__((cdecl)) i686_ISR126();
void __attribute__((cdecl)) i686_ISR127();
void __attribute__((cdecl)) i686_ISR128();
void __attribute__((cdecl)) i686_ISR129();
void __attribute__((cdecl)) i686_ISR130();
void __attribute__((cdecl)) i686_ISR131();
void __attribute__((cdecl)) i686_ISR132();
void __attribute__((cdecl)) i686_ISR133();
void __attribute__((cdecl)) i686_ISR134();
void __attribute__((cdecl)) i686_ISR135();
void __attribute__((cdecl)) i686_ISR136();
void __attribute__((cdecl)) i686_ISR137();
void __attribute__((cdecl)) i686_ISR138();
void __attribute__((cdecl)) i686_ISR139();
void __attribute__((cdecl)) i686_ISR140();
void __attribute__((cdecl)) i686_ISR141();
void __attribute__((cdecl)) i686_ISR142();
void __attribute__((cdecl)) i686_ISR143();
void __attribute__((cdecl)) i686_ISR144();
void __attribute__((cdecl)) i686_ISR145();
void __attribute__((cdecl)) i686_ISR146();
void __attribute__((cdecl)) i686_ISR147();
void __attribute__((cdecl)) i686_ISR148();
void __attribute__((cdecl)) i686_ISR149();
void __attribute__((cdecl)) i686_ISR150();
void __attribute__((cdecl)) i686_ISR151();
void __attribute__((cdecl)) i686_ISR152();
void __attribute__((cdecl)) i686_ISR153();
void __attribute__((cdecl)) i686_ISR154();
void __attribute__((cdecl)) i686_ISR155();
void __attribute__((cdecl)) i686_ISR156();
void __attribute__((cdecl)) i686_ISR157();
void __attribute__((cdecl)) i686_ISR158();
void __attribute__((cdecl)) i686_ISR159();
void __attribute__((cdecl)) i686_ISR160();
void __attribute__((cdecl)) i686_ISR161();
void __attribute__((cdecl)) i686_ISR162();
void __attribute__((cdecl)) i686_ISR163();
void __attribute__((cdecl)) i686_ISR164();
void __attribute__((cdecl)) i686_ISR165();
void __attribute__((cdecl)) i686_ISR166();
void __attribute__((cdecl)) i686_ISR167();
void __attribute__((cdecl)) i686_ISR168();
void __attribute__((cdecl)) i686_ISR169();
void __attribute__((cdecl)) i686_ISR170();
void __attribute__((cdecl)) i686_ISR171();
void __attribute__((cdecl)) i686_ISR172();
void __attribute__((cdecl)) i686_ISR173();
void __attribute__((cdecl)) i686_ISR174();
void __attribute__((cdecl)) i686_ISR175();
void __attribute__((cdecl)) i686_ISR176();
void __attribute__((cdecl)) i686_ISR177();
void __attribute__((cdecl)) i686_ISR178();
void __attribute__((cdecl)) i686_ISR179();
void __attribute__((cdecl)) i686_ISR180();
void __attribute__((cdecl)) i686_ISR181();
void __attribute__((cdecl)) i686_ISR182();
void __attribute__((cdecl)) i686_ISR183();
void __attribute__((cdecl)) i686_ISR184();
void __attribute__((cdecl)) i686_ISR185();
void __attribute__((cdecl)) i686_ISR186();
void __attribute__((cdecl)) i686_ISR187();
void __attribute__((cdecl)) i686_ISR188();
void __attribute__((cdecl)) i686_ISR189();
void __attribute__((cdecl)) i686_ISR190();
void __attribute__((cdecl)) i686_ISR191();
void __attribute__((cdecl)) i686_ISR192();
void __attribute__((cdecl)) i686_ISR193();
void __attribute__((cdecl)) i686_ISR194();
void __attribute__((cdecl)) i686_ISR195();
void __attribute__((cdecl)) i686_ISR196();
void __attribute__((cdecl)) i686_ISR197();
void __attribute__((cdecl)) i686_ISR198();
void __attribute__((cdecl)) i686_ISR199();
void __attribute__((cdecl)) i686_ISR200();
void __attribute__((cdecl)) i686_ISR201();
void __attribute__((cdecl)) i686_ISR202();
void __attribute__((cdecl)) i686_ISR203();
void __attribute__((cdecl)) i686_ISR204();
void __attribute__((cdecl)) i686_ISR205();
void __attribute__((cdecl)) i686_ISR206();
void __attribute__((cdecl)) i686_ISR207();
void __attribute__((cdecl)) i686_ISR208();
void __attribute__((cdecl)) i686_ISR209();
void __attribute__((cdecl)) i686_ISR210();
void __attribute__((cdecl)) i686_ISR211();
void __attribute__((cdecl)) i686_ISR212();
void __attribute__((cdecl)) i686_ISR213();
void __attribute__((cdecl)) i686_ISR214();
void __attribute__((cdecl)) i686_ISR215();
void __attribute__((cdecl)) i686_ISR216();
void __attribute__((cdecl)) i686_ISR217();
void __attribute__((cdecl)) i686_ISR218();
void __attribute__((cdecl)) i686_ISR219();
void __attribute__((cdecl)) i686_ISR220();
void __attribute__((cdecl)) i686_ISR221();
void __attribute__((cdecl)) i686_ISR222();
void __attribute__((cdecl)) i686_ISR223();
void __attribute__((cdecl)) i686_ISR224();
void __attribute__((cdecl)) i686_ISR225();
void __attribute__((cdecl)) i686_ISR226();
void __attribute__((cdecl)) i686_ISR227();
void __attribute__((cdecl)) i686_ISR228();
void __attribute__((cdecl)) i686_ISR229();
void __attribute__((cdecl)) i686_ISR230();
void __attribute__((cdecl)) i686_ISR231();
void __attribute__((cdecl)) i686_ISR232();
void __attribute__((cdecl)) i686_ISR233();
void __attribute__((cdecl)) i686_ISR234();
void __attribute__((cdecl)) i686_ISR235();
void __attribute__((cdecl)) i686_ISR236();
void __attribute__((cdecl)) i686_ISR237();
void __attribute__((cdecl)) i686_ISR238();
void __attribute__((cdecl)) i686_ISR239();
void __attribute__((cdecl)) i686_ISR240();
void __attribute__((cdecl)) i686_ISR241();
void __attribute__((cdecl)) i686_ISR242();
void __attribute__((cdecl)) i686_ISR243();
void __attribute__((cdecl)) i686_ISR244();
void __attribute__((cdecl)) i686_ISR245();
void __attribute__((cdecl)) i686_ISR246();
void __attribute__((cdecl)) i686_ISR247();
void __attribute__((cdecl)) i686_ISR248();
void __attribute__((cdecl)) i686_ISR249();
void __attribute__((cdecl)) i686_ISR250();
void __attribute__((cdecl)) i686_ISR251();
void __attribute__((cdecl)) i686_ISR252();
void __attribute__((cdecl)) i686_ISR253();
void __attribute__((cdecl)) i686_ISR254();
void __attribute__((cdecl)) i686_ISR255();

void i686_ISR_InitializeGates() {
    i686_IDT_SetGate(0, i686_ISR0, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(1, i686_ISR1, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(2, i686_ISR2, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(3, i686_ISR3, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(4, i686_ISR4, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(5, i686_ISR5, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(6, i686_ISR6, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(7, i686_ISR7, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(8, i686_ISR8, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(9, i686_ISR9, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(10, i686_ISR10, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(11, i686_ISR11, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(12, i686_ISR12, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(13, i686_ISR13, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(14, i686_ISR14, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(15, i686_ISR15, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(16, i686_ISR16, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(17, i686_ISR17, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(18, i686_ISR18, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(19, i686_ISR19, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(20, i686_ISR20, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(21, i686_ISR21, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(22, i686_ISR22, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(23, i686_ISR23, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(24, i686_ISR24, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(25, i686_ISR25, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(26, i686_ISR26, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(27, i686_ISR27, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(28, i686_ISR28, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(29, i686_ISR29, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(30, i686_ISR30, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(31, i686_ISR31, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(32, i686_ISR32, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(33, i686_ISR33, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(34, i686_ISR34, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(35, i686_ISR35, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(36, i686_ISR36, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(37, i686_ISR37, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(38, i686_ISR38, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(39, i686_ISR39, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(40, i686_ISR40, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(41, i686_ISR41, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(42, i686_ISR42, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(43, i686_ISR43, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(44, i686_ISR44, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(45, i686_ISR45, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(46, i686_ISR46, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(47, i686_ISR47, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(48, i686_ISR48, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(49, i686_ISR49, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(50, i686_ISR50, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(51, i686_ISR51, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(52, i686_ISR52, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(53, i686_ISR53, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(54, i686_ISR54, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(55, i686_ISR55, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(56, i686_ISR56, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(57, i686_ISR57, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(58, i686_ISR58, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(59, i686_ISR59, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(60, i686_ISR60, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(61, i686_ISR61, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(62, i686_ISR62, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(63, i686_ISR63, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(64, i686_ISR64, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(65, i686_ISR65, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(66, i686_ISR66, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(67, i686_ISR67, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(68, i686_ISR68, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(69, i686_ISR69, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(70, i686_ISR70, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(71, i686_ISR71, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(72, i686_ISR72, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(73, i686_ISR73, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(74, i686_ISR74, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(75, i686_ISR75, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(76, i686_ISR76, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(77, i686_ISR77, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(78, i686_ISR78, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(79, i686_ISR79, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(80, i686_ISR80, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(81, i686_ISR81, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(82, i686_ISR82, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(83, i686_ISR83, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(84, i686_ISR84, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(85, i686_ISR85, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(86, i686_ISR86, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(87, i686_ISR87, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(88, i686_ISR88, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(89, i686_ISR89, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(90, i686_ISR90, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(91, i686_ISR91, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(92, i686_ISR92, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(93, i686_ISR93, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(94, i686_ISR94, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(95, i686_ISR95, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(96, i686_ISR96, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(97, i686_ISR97, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(98, i686_ISR98, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(99, i686_ISR99, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(100, i686_ISR100, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(101, i686_ISR101, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(102, i686_ISR102, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(103, i686_ISR103, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(104, i686_ISR104, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(105, i686_ISR105, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(106, i686_ISR106, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(107, i686_ISR107, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(108, i686_ISR108, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(109, i686_ISR109, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(110, i686_ISR110, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(111, i686_ISR111, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(112, i686_ISR112, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(113, i686_ISR113, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(114, i686_ISR114, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(115, i686_ISR115, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(116, i686_ISR116, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(117, i686_ISR117, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(118, i686_ISR118, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(119, i686_ISR119, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(120, i686_ISR120, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(121, i686_ISR121, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(122, i686_ISR122, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(123, i686_ISR123, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(124, i686_ISR124, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(125, i686_ISR125, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(126, i686_ISR126, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(127, i686_ISR127, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(128, i686_ISR128, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(129, i686_ISR129, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(130, i686_ISR130, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(131, i686_ISR131, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(132, i686_ISR132, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(133, i686_ISR133, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(134, i686_ISR134, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(135, i686_ISR135, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(136, i686_ISR136, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(137, i686_ISR137, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(138, i686_ISR138, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(139, i686_ISR139, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(140, i686_ISR140, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(141, i686_ISR141, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(142, i686_ISR142, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(143, i686_ISR143, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(144, i686_ISR144, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(145, i686_ISR145, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(146, i686_ISR146, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(147, i686_ISR147, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(148, i686_ISR148, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(149, i686_ISR149, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(150, i686_ISR150, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(151, i686_ISR151, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(152, i686_ISR152, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(153, i686_ISR153, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(154, i686_ISR154, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(155, i686_ISR155, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(156, i686_ISR156, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(157, i686_ISR157, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(158, i686_ISR158, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(159, i686_ISR159, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(160, i686_ISR160, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(161, i686_ISR161, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(162, i686_ISR162, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(163, i686_ISR163, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(164, i686_ISR164, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(165, i686_ISR165, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(166, i686_ISR166, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(167, i686_ISR167, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(168, i686_ISR168, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(169, i686_ISR169, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(170, i686_ISR170, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(171, i686_ISR171, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(172, i686_ISR172, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(173, i686_ISR173, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(174, i686_ISR174, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(175, i686_ISR175, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(176, i686_ISR176, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(177, i686_ISR177, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(178, i686_ISR178, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(179, i686_ISR179, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(180, i686_ISR180, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(181, i686_ISR181, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(182, i686_ISR182, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(183, i686_ISR183, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(184, i686_ISR184, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(185, i686_ISR185, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(186, i686_ISR186, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(187, i686_ISR187, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(188, i686_ISR188, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(189, i686_ISR189, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(190, i686_ISR190, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(191, i686_ISR191, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(192, i686_ISR192, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(193, i686_ISR193, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(194, i686_ISR194, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(195, i686_ISR195, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(196, i686_ISR196, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(197, i686_ISR197, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(198, i686_ISR198, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(199, i686_ISR199, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(200, i686_ISR200, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(201, i686_ISR201, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(202, i686_ISR202, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(203, i686_ISR203, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(204, i686_ISR204, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(205, i686_ISR205, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(206, i686_ISR206, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(207, i686_ISR207, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(208, i686_ISR208, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(209, i686_ISR209, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(210, i686_ISR210, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(211, i686_ISR211, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(212, i686_ISR212, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(213, i686_ISR213, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(214, i686_ISR214, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(215, i686_ISR215, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(216, i686_ISR216, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(217, i686_ISR217, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(218, i686_ISR218, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(219, i686_ISR219, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(220, i686_ISR220, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(221, i686_ISR221, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(222, i686_ISR222, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(223, i686_ISR223, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(224, i686_ISR224, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(225, i686_ISR225, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(226, i686_ISR226, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(227, i686_ISR227, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(228, i686_ISR228, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(229, i686_ISR229, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(230, i686_ISR230, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(231, i686_ISR231, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(232, i686_ISR232, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(233, i686_ISR233, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(234, i686_ISR234, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(235, i686_ISR235, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(236, i686_ISR236, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(237, i686_ISR237, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(238, i686_ISR238, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(239, i686_ISR239, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(240, i686_ISR240, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(241, i686_ISR241, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(242, i686_ISR242, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(243, i686_ISR243, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(244, i686_ISR244, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(245, i686_ISR245, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(246, i686_ISR246, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(247, i686_ISR247, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(248, i686_ISR248, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(249, i686_ISR249, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(250, i686_ISR250, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(251, i686_ISR251, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(252, i686_ISR252, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(253, i686_ISR253, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(254, i686_ISR254, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
    i686_IDT_SetGate(255, i686_ISR255, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);
}

#pragma endregion

ISRHandler g_ISRHandlers[256];

static const char* const g_Exceptions[] = {
        "Divide by zero error",
        "Debug",
        "Non-maskable Interrupt",
        "Breakpoint",
        "Overflow",
        "Bound Range Exceeded",
        "Invalid Opcode",
        "Device Not Available",
        "Double Fault",
        "Coprocessor Segment Overrun",
        "Invalid TSS",
        "Segment Not Present",
        "Stack-Segment Fault",
        "General Protection Fault",
        "Page Fault",
        "",
        "x87 Floating-Point Exception",
        "Alignment Check",
        "Machine Check",
        "SIMD Floating-Point Exception",
        "Virtualization Exception",
        "Control Protection Exception",
        "",
        "",
        "",
        "",
        "",
        "",
        "Hypervisor Injection Exception",
        "VMM Communication Exception",
        "Security Exception",
        ""
};

void i686_ISR_Initialize() {
    i686_ISR_InitializeGates();
    for(int i = 0; i < 256; i++) {
        i686_IDT_EnableGate(i);
    }
}

void i686_ISR_RegisterHandler(int interrupt, ISRHandler handler) {
    g_ISRHandlers[interrupt] = handler;
}

void i686_ISR_UnregisterHandler(int interrupt) {
    g_ISRHandlers[interrupt] = 0;
}

void print_regs(Registers* regs) {
    printf("Registers: \n");
    printf("  eax=%x  ebx=%x  ecx=%x  edx=%x  esi=%x  edi=%x\n",
           regs->eax, regs->ebx, regs->ecx, regs->edx, regs->esi, regs->edi);
    printf("  esp=%x  ebp=%x  eip=%x  eflags=%x  cs=%x  ds=%x  ss=%x\n",
           regs->esp, regs->ebp, regs->eip, regs->eflags, regs->cs, regs->ds, regs->ss);
    printf("  interrupt=%x  errorcode=%x\n", regs->interrupt, regs->error);
}

void __attribute__((cdecl)) i686_ISR_Handler(Registers* regs) {
    if(g_ISRHandlers[regs->interrupt] != NULL) {
        g_ISRHandlers[regs->interrupt](regs);
        if(regs->interrupt >= 32 && regs->interrupt <= 47) {
            PIC_sendEOI(regs->interrupt - 32);
        }
    } else if(regs->interrupt >= 48) {
        printf("Unhandled interrupt %d!\n", regs->interrupt);
    } else if(regs->interrupt >= 32) {
        if(regs->interrupt != 32) printf("Interrupt: %i\n", regs->interrupt);
        PIC_sendEOI(regs->interrupt - 32);
    } else {
        printf("Unhandled exception %d %s\n", regs->interrupt, g_Exceptions[regs->interrupt]);
        print_regs(regs);

        printf("KERNEL PANIC!\n");
        i686_Panic();
    }
}