#armv7 assembly code
defn:
PUSH {fp}
ADD  fp, sp, #0
SUB fp, fp, #64
LDR r0, [fp, 0x0]
MOV r0, 4
ADD  r0, r0, #0
ADD  sp, fp, #0
POP {fp}
BX lr
main:
PUSH {fp}
ADD  fp, sp, #0
SUB fp, fp, #64
BL defn
LDR r0, [fp, 0x0]
MOV r0, r0
LDR r1, [fp, 0x0]
ADD  r1, r2, #0
ADD  r0, r1, #0
ADD  sp, fp, #0
POP {fp}
BX lr
