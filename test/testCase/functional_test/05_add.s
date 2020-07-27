#armv7 assembly code
main:
PUSH {fp}
ADD  fp, sp, #0
SUB fp, fp, #64
LDR r0, [fp, 0x0]
MOV r0, 10
LDR r1, [fp, 0x0]
ADD  r1, r0, #0
LDR r2, [fp, 0x0]
MOV r2, 20
ADD  r1, r2, #0
LDR r3, [fp, 0x0]
ADD  r3, r1, #0
LDR r4, [fp, 0x0]
ADD  r4, r1, #0
LDR r5, [fp, 0x0]
ADD  r5, r3, r4
ADD  r1, r5, #0
LDR r6, [fp, 0x0]
ADD  r6, r8, #0
ADD  r0, r6, #0
ADD  sp, fp, #0
POP {fp}
BX lr
