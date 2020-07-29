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
MOV r2, #0
ADD  r0, r2, #0
ADD  sp, fp, #0
POP {fp}
BX lr
