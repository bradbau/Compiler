#armv7 assembly code
main:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
MOV r0, #10
ADD  r1, r0, #0
MOV r2, #10
LDR r3, [fp, 0x0]
ADD  r3, r2, #0
LDR r4, [fp, 0x0]
MOV r4, #0
ADD  r0, r4, #0
ADD  sp, fp, #0
POP {fp}
BX lr
