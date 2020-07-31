#armv7 assembly code
main:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
MOV r0, #1
MOV r1, #0
LDR r2, [fp, 0x0]
MOV r2, #0
ADD  r0, r2, #0
ADD  sp, fp, #0
POP {fp}
BX lr
