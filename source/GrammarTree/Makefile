parser: SysY.l SysY.y grammartree.h
	flex SysY.l        
	bison -d -v SysY.y
	g++ -o parser   SysY.tab.c lex.yy.c grammartree.cpp  -lfl -ly 

.PHONY: clean
clean:
	rm parser SysY.tab.c SysY.tab.h lex.yy.cc lex.yy.c
