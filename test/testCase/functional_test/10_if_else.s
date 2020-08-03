;armv7 assembly code
.text
main:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
MOV r0, #10
ADD  r1, r0, #0
ADD  r2, r1, #0
MOV r3, #0
CMP r2, r3, 
BGT L0
B L1
L0:
MOV r4, #1
ADD  r0, r4, #0
ADD  sp, fp, #0
POP {fp}
BX lr
B L2
L1:
MOV r5, #0
ADD  r0, r5, #0
ADD  sp, fp, #0
POP {fp}
BX lr
L2:
