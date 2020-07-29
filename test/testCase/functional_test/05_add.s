#armv7 assembly code
main:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
LDR r0, [fp, 0x0]
MOV r0, #10
LDR r1, [fp, 0x0]
ADD  r1, r0, #0
LDR r2, [fp, 0x0]
MOV r2, #20
LDR r3, [fp, 0x0]
ADD  r3, r2, #0
LDR r4, [fp, 0x0]
ADD  r4, r1, #0
LDR r5, [fp, 0x0]
ADD  r5, r3, #0
LDR r6, [fp, 0x0]
ADD  r6, r4, r5
LDR r8, [fp, 0x0]
ADD  r8, r6, #0
LDR r9, [fp, 0x0]
ADD  r9, r8, #0
ADD  r0, r9, #0
ADD  sp, fp, #0
POP {fp}
BX lr
