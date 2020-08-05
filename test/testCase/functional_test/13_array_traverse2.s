
EXTERN getint getchar getarray putint putchar putarray
.text
.global main
main:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
MOV r0, #0
ADD  r1, r0, #0
MOV r2, #0
ADD  r3, r2, #0
MOV r4, #0
ADD  r5, r4, #0
MOV r6, #0
L0:
ADD  r8, r1, #0
MOV r9, #3
CMP r8, r9
BLT L1
B L2
L1:
L3:
ADD  r10, r3, #0
MOV r10, #3
LDR r10, [fp, #0x0]
LDR r10, [fp, #0x0]
CMP r10, r10
BLT L4
B L5
L4:
L6:
ADD  r10, r5, #0
MOV r10, #3
LDR r10, [fp, #0x0]
LDR r10, [fp, #0x0]
CMP r10, r10
BLT L7
B L8
L7:
ADD  r10, r6, #0
ADD  r10, r5, #0
MOV r10, #3
ADD  r10, r3, #0
LDR r10, [fp, #0x0]
LDR r10, [fp, #0x0]
MUL r10, r10, r10
LDR r10, [fp, #0x0]
ADD  r10, r10, r10
MOV r10, #3
LDR r10, [fp, #0x0]
LDR r10, [fp, #0x0]
MUL r10, r10, r10
ADD  r10, r1, #0
LDR r10, [fp, #0x0]
LDR r10, [fp, #0x0]
MUL r10, r10, r10
LDR r10, [fp, #0x0]
ADD  r10, r10, r10
LDR r10, [fp, #0x0]
ADD  r10, r10, #0
ADD  r10, r6, #0
MOV r10, #1
LDR r10, [fp, #0x0]
LDR r10, [fp, #0x0]
ADD  r10, r10, r10
LDR r10, [fp, #0x0]
ADD  r6, r10, #0
ADD  r10, r5, #0
MOV r10, #1
LDR r10, [fp, #0x0]
LDR r10, [fp, #0x0]
ADD  r10, r10, r10
LDR r10, [fp, #0x0]
ADD  r5, r10, #0
B L6
L8:
ADD  r10, r3, #0
MOV r10, #1
LDR r10, [fp, #0x0]
LDR r10, [fp, #0x0]
ADD  r10, r10, r10
LDR r10, [fp, #0x0]
ADD  r3, r10, #0
B L3
L5:
ADD  r10, r1, #0
MOV r10, #1
LDR r10, [fp, #0x0]
LDR r10, [fp, #0x0]
ADD  r10, r10, r10
LDR r10, [fp, #0x0]
ADD  r1, r10, #0
B L0
L2:
MOV r10, #0
ADD  r0, r10, #0
ADD  sp, fp, #0
POP {fp}
BX lr
