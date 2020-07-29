#armv7 assembly code
func1:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
LDR r0, [fp, 0x0]
MOV r0, #1
LDR r1, [fp, 0x0]
ADD  r1, r0, #0
LDR r2, [fp, 0x0]
ADD  r2, r1, #0
ADD  r0, r2, #0
ADD  sp, fp, #0
POP {fp}
BX lr
func2:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
LDR r3, [fp, 0x0]
MOV r3, #2
ADD  r1, r3, #0
LDR r4, [fp, 0x0]
ADD  r4, r1, #0
ADD  r0, r4, #0
ADD  sp, fp, #0
POP {fp}
BX lr
func3:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
LDR r5, [fp, 0x0]
MOV r5, #4
ADD  r1, r5, #0
LDR r6, [fp, 0x0]
ADD  r6, r1, #0
ADD  r0, r6, #0
ADD  sp, fp, #0
POP {fp}
BX lr
func4:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
LDR r8, [fp, 0x0]
MOV r8, #8
LDR r9, [fp, 0x0]
ADD  r9, r8, #0
LDR r10, [fp, 0x0]
ADD  r10, r9, #0
ADD  r1, r10, #0
STRLDR r10, [fp, 0x0]
MOV r10, #16
ADD  r9, r10, #0
STRLDR r10, [fp, 0x0]
ADD  r10, r1, #0
STRLDR r10, [fp, 0x0]
ADD  r10, r9, #0
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
ADD  r10, r10, r10
STRLDR r10, [fp, 0x0]
ADD  r1, r10, #0
STRLDR r10, [fp, 0x0]
ADD  r10, r1, #0
ADD  r0, r10, #0
ADD  sp, fp, #0
POP {fp}
BX lr
main:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
STRLDR r10, [fp, 0x0]
MOV r10, #32
ADD  r1, r10, #0
STRLDR r10, [fp, 0x0]
MOV r10, #32
ADD  r9, r10, #0
STRLDR r10, [fp, 0x0]
MOV r10, #32
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
ADD  r10, r10, #0
BL func1
STRLDR r10, [fp, 0x0]
MOV r10, r0
BL func2
STRLDR r10, [fp, 0x0]
MOV r10, r0
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
ADD  r10, r10, r10
BL func3
STRLDR r10, [fp, 0x0]
MOV r10, r0
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
ADD  r10, r10, r10
BL func4
STRLDR r10, [fp, 0x0]
MOV r10, r0
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
ADD  r10, r10, r10
STRLDR r10, [fp, 0x0]
ADD  r10, r1, #0
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
ADD  r10, r10, r10
STRLDR r10, [fp, 0x0]
ADD  r10, r9, #0
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
ADD  r10, r10, r10
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
ADD  r10, r10, #0
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
STRLDR r10, [fp, 0x0]
ADD  r10, r10, r10
STRLDR r10, [fp, 0x0]
ADD  r0, r10, #0
ADD  sp, fp, #0
POP {fp}
BX lr
