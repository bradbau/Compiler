
EXTERN getint getchar getarray putint putchar putarray
.text
.global main
main:
PUSH {fp}
ADD  fp, sp, #0
SUB sp, sp, #0
MOV r0, #0
ADD  r0, r0, #0
ADD  sp, fp, #0
POP {fp}
BX lr
