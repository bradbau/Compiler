.text
.global main
main:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
MOV r0, #10
L0:
ADD  r1, r0, #0
MOV r2, #0
CMP r1, r2
BGT L1
B L2
L1:
ADD  r3, r0, #0
MOV r4, #1
SUB r5, r3, r4
ADD  r0, r5, #0
ADD  r6, r0, #0
MOV r8, #5
CMP r6, r8
BEQ L3
B L4
L3:
B L-1
L4:
B L0
L2:
ADD  r9, r0, #0
ADD  r0, r9, #0
ADD  sp, fp, #0
POP {fp}
BX lr
