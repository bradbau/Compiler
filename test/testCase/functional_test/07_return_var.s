;armv7 assembly code
.text
main:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
MOV r0, #10
ADD  r1, r0, #0
ADD  r2, r1, #0
ADD  r0, r2, #0
ADD  sp, fp, #0
POP {fp}
BX lr
