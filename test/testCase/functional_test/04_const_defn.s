;armv7 assembly code
.text
MOV r0, #4
main:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
ADD  r1, r0, #0
ADD  r0, r1, #0
ADD  sp, fp, #0
POP {fp}
BX lr
