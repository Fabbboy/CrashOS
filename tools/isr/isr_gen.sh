#!/usr/bin/env bash

set -e

# vars
ISRS_GEN_C="isr_gen.c"
ISRS_GEN_ASM="isr_gen.asm"

rm $ISRS_GEN_C
rm $ISRS_GEN_ASM

ISRS_WITH_ERROR_CODE="8 10 11 12 13 14 17 21 29 30"


# Generate Assembly file

for i in $(seq 0 255); do
  if echo "$ISRS_WITH_ERROR_CODE" | grep -q "\b${i}\b"; then
    echo "ISR_ERRORCODE ${i}" >> $ISRS_GEN_ASM
  else
    echo "ISR_NOERRORCODE ${i}" >> $ISRS_GEN_ASM
  fi
done

# Generate C file

for i in $(seq 0 255); do
  echo "void __attribute__((cdecl)) i686_ISR${i}();" >> $ISRS_GEN_C
done

echo "" >> $ISRS_GEN_C
echo "void i686_ISR_InitializeGates() {" >> $ISRS_GEN_C

for i in $(seq 0 255); do
  echo "    i686_IDT_SetGate(${i}, i686_ISR${i}, i686_GDT_CODE_SEGMENT, IDT_FLAG_RING0 | IDT_FLAG_GATE_32BIT_INT);" >> $ISRS_GEN_C
done

echo "}" >> $ISRS_GEN_C