;armv7 assembly code
.text
doubleWhile:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
MOV r0, #5
ADD  r1, r0, #0
MOV r2, #7
ADD  r3, r2, #0
L0:
ADD  r4, r1, #0
MOV r5, #100
CMP r4, r5, 
BLT L1
B L2
L1:
ADD  r6, r1, #0
MOV r8, #30
ADD  r9, r6, r8
ADD  r1, r9, #0
L3:
ADD  r10, r3, #0
MOV r10, #100
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
CMP r10, r10, 
BLT L4
B L5
L4:
ADD  r10, r3, #0
MOV r10, #6
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
ADD  r10, r10, r10
STRLDR r10, [fp, 0x0]
ADD  r3, r10, #0
B L3
L5:
ADD  r10, r3, #0
MOV r10, #100
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
SUB r10, r10, r10
STRLDR r10, [fp, 0x0]
ADD  r3, r10, #0
B L0
L2:
ADD  r10, r3, #0
STRLDR r10, [fp, 0x0]
ADD  r10, r10, #0
STRLDR r10, [fp, 0x0]
ADD  r0, r10, #0
ADD  sp, fp, #0
POP {fp}
BX lr
main:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
BL doubleWhile
STRLDR r10, [fp, 0x0]
MOV r10, r0
ADD  r0, r10, #0
ADD  sp, fp, #0
POP {fp}
BX lr
