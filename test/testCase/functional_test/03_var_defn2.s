;armv7 assembly code
.text
main:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
MOV r0, #10
ADD  r1, r0, #0
MOV r2, #5
ADD  r3, r2, #0
ADD  r4, r1, #0
MOV r5, #2
MUL r6, r4, r5
ADD  r8, r3, #0
ADD  r9, r6, r8
MOV r10, #3
STRLDR r10, [fp, 0x0]
ADD  r10, r9, r10
STRLDR r10, [fp, 0x0]
ADD  r10, r10, #0
STRLDR r10, [fp, 0x0]
ADD  r0, r10, #0
ADD  sp, fp, #0
POP {fp}
BX lr
