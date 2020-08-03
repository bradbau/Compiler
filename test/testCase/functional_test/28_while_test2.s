;armv7 assembly code
.text
FourWhile:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
MOV r0, #5
ADD  r1, r0, #0
MOV r2, #6
ADD  r3, r2, #0
MOV r4, #7
ADD  r5, r4, #0
MOV r6, #10
ADD  r8, r6, #0
L0:
ADD  r9, r1, #0
MOV r10, #20
CMP r9, r10, 
BLT L1
B L2
L1:
ADD  r10, r1, #0
MOV r10, #3
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
ADD  r10, r10, r10
STRLDR r10, [fp, 0x0]
ADD  r1, r10, #0
L3:
ADD  r10, r3, #0
MOV r10, #10
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
CMP r10, r10, 
BLT L4
B L5
L4:
ADD  r10, r3, #0
MOV r10, #1
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
ADD  r10, r10, r10
STRLDR r10, [fp, 0x0]
ADD  r3, r10, #0
L6:
ADD  r10, r5, #0
MOV r10, #7
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
CMP r10, r10, 
BEQ L7
B L8
L7:
ADD  r10, r5, #0
MOV r10, #1
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
SUB r10, r10, r10
STRLDR r10, [fp, 0x0]
ADD  r5, r10, #0
L9:
ADD  r10, r8, #0
MOV r10, #20
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
CMP r10, r10, 
BLT L10
B L11
L10:
ADD  r10, r8, #0
MOV r10, #3
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
ADD  r10, r10, r10
STRLDR r10, [fp, 0x0]
ADD  r8, r10, #0
B L9
L11:
ADD  r10, r8, #0
MOV r10, #1
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
SUB r10, r10, r10
STRLDR r10, [fp, 0x0]
ADD  r8, r10, #0
B L6
L8:
ADD  r10, r5, #0
MOV r10, #1
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
ADD  r10, r10, r10
STRLDR r10, [fp, 0x0]
ADD  r5, r10, #0
B L3
L5:
ADD  r10, r3, #0
MOV r10, #2
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
SUB r10, r10, r10
STRLDR r10, [fp, 0x0]
ADD  r3, r10, #0
B L0
L2:
ADD  r10, r1, #0
ADD  r10, r3, #0
ADD  r10, r8, #0
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
ADD  r10, r10, r10
STRLDR r10, [fp, 0x0]
ADD  r10, r10, #0
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
ADD  r10, r10, r10
ADD  r10, r5, #0
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
ADD  r10, r10, r10
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
BL FourWhile
STRLDR r10, [fp, 0x0]
MOV r10, r0
ADD  r0, r10, #0
ADD  sp, fp, #0
POP {fp}
BX lr
