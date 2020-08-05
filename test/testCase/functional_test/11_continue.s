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
MOV r4, #5
CMP r3, r4
BGT L3
B L4
L3:
ADD  r5, r0, #0
MOV r6, #1
SUB r8, r5, r6
ADD  r0, r8, #0
B L-1
L4:
ADD  r9, r0, #0
ADD  r0, r9, #0
ADD  sp, fp, #0
POP {fp}
BX lr
B L0
L2:
ADD  r10, r0, #0
ADD  r0, r10, #0
ADD  sp, fp, #0
POP {fp}
BX lr
