#armv7 assembly code
main:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
BL 
LDR r0, [fp, 0x0]
MOV r0, r0
LDR r1, [fp, 0x0]
ADD  r1, r0, #0
BL 
LDR r2, [fp, 0x0]
MOV r2, r0
LDR r3, [fp, 0x0]
ADD  r3, r2, #0
LDR r4, [fp, 0x0]
ADD  r4, r1, #0
LDR r5, [fp, 0x0]
ADD  r5, r3, #0
CMP r4, r5, 
BEQ L0
B L1
L0:
LDR r6, [fp, 0x0]
MOV r6, #1
ADD  r0, r6, #0
ADD  sp, fp, #0
POP {fp}
BX lr
B L2
L1:
LDR r8, [fp, 0x0]
MOV r8, #0
ADD  r0, r8, #0
ADD  sp, fp, #0
POP {fp}
BX lr
L2:
