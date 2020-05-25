parser: SysY.l SysY.y grammartree.h
	flex SysY.l        
	bison -d -v SysY.y
	g++ grammartree.cpp SysY.tab.c -lfl -ly -o parser

.PHONY: clean
clean:
	rm parser SysY.tab.c SysY.tab.h lex.yy.cc
