.text
.global main
main:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
MOV r0, #10
ADD  r1, r0, #0
MOV r2, #20
ADD  r3, r2, #0
ADD  r4, r1, #0
ADD  r5, r3, #0
ADD  r6, r4, r5
ADD  r8, r6, #0
ADD  r9, r8, #0
ADD  r0, r9, #0
ADD  sp, fp, #0
POP {fp}
BX lr
