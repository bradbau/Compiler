;armv7 assembly code
.text
main:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
BL getint
MOV r0, r0
ADD  r1, r0, #0
BL getint
MOV r2, r0
ADD  r3, r2, #0
BL getint
MOV r4, r0
ADD  r5, r4, #0
ADD  r6, r1, #0
ADD  r8, r3, #0
ADD  r9, r5, #0
MUL r10, r8, r9
STRLDR r10, [fp, 0x0]
ADD  r10, r6, r10
STRLDR r10, [fp, 0x0]
ADD  r10, r10, #0
STRLDR r10, [fp, 0x0]
ADD  r10, r10, #0
STRLDR r10, [fp, 0x0]
ADD  r0, r10, #0
ADD  sp, fp, #0
POP {fp}
BX lr
