
EXTERN getint getchar getarray putint putchar putarray
.text
.global main
main:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
MOV r0, #0
MOV r1, #0
L0:
ADD  r2, r0, #0
MOV r3, #3
MOV r4, #4
ADD  r5, r3, r4
MOV r6, #2
SUB r8, r5, r6
CMP r2, r8
BLE L1
B L2
L1:
ADD  r9, r0, #0
L3:
ADD  r10, r9, #0
MOV r10, #0
LDR r10, [fp, #0x0]
LDR r10, [fp, #0x0]
CMP r10, r10
BGE L4
B L5
L4:
ADD  r10, r9, #0
MOV r10, #4
LDR r10, [fp, #0x0]
LDR r10, [fp, #0x0]
CMP r10, r10
BLT L8
B L7
L8:
ADD  r10, r0, #0
ADD  r10, r9, #0
LDR r10, [fp, #0x0]
LDR r10, [fp, #0x0]
SUB r10, r10, r10
MOV r10, #3
LDR r10, [fp, #0x0]
LDR r10, [fp, #0x0]
CMP r10, r10
BLT L6
B L7
L6:
ADD  r10, r1, #0
ADD  r10, r9, #0
MOV r10, #4
ADD  r10, r0, #0
LDR r10, [fp, #0x0]
LDR r10, [fp, #0x0]
MUL r10, r10, r10
LDR r10, [fp, #0x0]
ADD  r10, r10, r10
LDR r10, [fp, #0x0]
ADD  r10, r10, #0
MOV r10, #1
ADD  r1, r10, #0
L7:
ADD  r10, r9, #0
MOV r10, #1
LDR r10, [fp, #0x0]
LDR r10, [fp, #0x0]
SUB r10, r10, r10
LDR r10, [fp, #0x0]
ADD  r9, r10, #0
B L3
L5:
ADD  r10, r0, #0
MOV r10, #1
LDR r10, [fp, #0x0]
LDR r10, [fp, #0x0]
ADD  r10, r10, r10
LDR r10, [fp, #0x0]
ADD  r0, r10, #0
B L0
L2:
MOV r10, #0
ADD  r0, r10, #0
ADD  sp, fp, #0
POP {fp}
BX lr
