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
MOV r2, 10
ADD  r3, r2, #0
LDR r3, [fp, 0x0]
ADD  r0, r3, #0
ADD  sp, fp, #0
POP {fp}
BX lr
