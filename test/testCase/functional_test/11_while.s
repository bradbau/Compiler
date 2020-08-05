
EXTERN getint getchar getarray putint putchar putarray
.text
.global main
main:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
MOV r0, #0
ADD  r1, r0, #0
MOV r2, #3
ADD  r3, r2, #0
L0:
ADD  r4, r3, #0
MOV r5, #0
CMP r4, r5
BGT L1
B L2
L1:
ADD  r6, r1, #0
ADD  r8, r3, #0
ADD  r9, r6, r8
ADD  r1, r9, #0
ADD  r10, r3, #0
MOV r10, #1
LDR r4, [fp, #0x0]
SUB r4, r4, r10
LDR r4, [fp, #0x0]
ADD  r3, r4, #0
B L0
L2:
ADD  r4, r1, #0
ADD  r0, r4, #0
ADD  sp, fp, #0
POP {fp}
BX lr
