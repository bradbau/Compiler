#armv7 assembly code
if_if_Else:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
LDR r0, [fp, 0x0]
MOV r0, #5
LDR r1, [fp, 0x0]
ADD  r1, r0, #0
LDR r2, [fp, 0x0]
MOV r2, #10
LDR r3, [fp, 0x0]
ADD  r3, r2, #0
LDR r4, [fp, 0x0]
ADD  r4, r1, #0
LDR r5, [fp, 0x0]
MOV r5, #5
CMP r4, r5, 
BEQ L0
B L1
L0:
LDR r6, [fp, 0x0]
ADD  r6, r3, #0
LDR r8, [fp, 0x0]
MOV r8, #10
CMP r6, r8, 
BEQ L2
B L3
L2:
L3:
B L4
L1:
L4:
LDR r9, [fp, 0x0]
ADD  r9, r1, #0
LDR r10, [fp, 0x0]
ADD  r10, r9, #0
ADD  r0, r10, #0
ADD  sp, fp, #0
POP {fp}
BX lr
main:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
BL if_if_Else
STRLDR r10, [fp, 0x0]
MOV r10, r0
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
ADD  r10, r10, #0
STRLDR r10, [fp, 0x0]
ADD  r0, r10, #0
ADD  sp, fp, #0
POP {fp}
BX lr
