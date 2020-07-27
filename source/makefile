
.PHONY: clean strip
# 设定编译对象
COMPILER = compiler
PRODUCTS = $(COMPILER) 
default: $(PRODUCTS)

# 定义工具链
CC= g++
LD = g++
LEX = flex
YACC = bison




# We want debugging and most warnings, but lex/yacc generate some
# static symbols we don't use, so turn off unused warnings to avoid clutter
# Also STL has some signed/unsigned comparisons we want to suppress
CFLAGS = -g -Wall -Wno-unused -Wno-sign-compare  ${INCLUDES}

# The -d flag tells lex to set up for debugging. Can turn on/off by
# setting value of global yy_flex_debug inside the scanner itself
LEXFLAGS = -d

# The -d flag tells yacc to generate header with token types
# The -v flag writes out a verbose description of the states and conflicts
# The -t flag turns on debugging capability
# The -y flag means imitate yacc's output file naming conventions
YACCFLAGS = -dvty

# Link with standard C library, math library, and lex library
LIBS = -lc -lm -ll -lfl #-ly


#sources 所有含有源代码的目录
SRCS_DIR= ./GrammarTree   ./SymbolTable ./IntermediateCode #Generated  # ObjectCode
#INCLUDE_DIR=GrammarTree SymbolTable IntermediateCode Generated  # ObjectCode

SRCS=$(wildcard  ./GrammarTree/*.c ./SymbolTable/*.c ./IntermediateCode/*.c *.c)  $(wildcard ./GrammarTree/*.cpp ./SymbolTable/*.cpp ./IntermediateCode/*.cpp *.cpp)
INCLUDES=-I./GrammarTree   -I./SymbolTable -I./IntermediateCode #${wildcard ./GrammarTree/*.h ./SymbolTable/*.h ./IntermediateCode/*.h *.h}
# OBJS can deal with either .cc or .c files listed in SRCS
#OBJS = y.tab.o lex.yy.o $(patsubst %.cpp, %.o, $(filter %.cpp,$(SRCS))) $(patsubst %.c, %.o, $(filter %.c, $(SRCS)))

JUNK =  *.o lex.yy.c  y.tab.c y.tab.h 





	## 目标编译器编译
$(COMPILER) : SysY.l  SysY.y ./GrammarTree/AST.h ./SymbolTable/SymbolTable.h ./SymbolTable/ScopeStack_stl.h ./IntermediateCode/Quadruple.h ./IntermediateCode/QuadrupleOperand.h ./IntermediateCode/TAC.h ./ObjectCode/Arm.h ./ObjectCode/ArmInstruction.h 
	$(YACC) $(YACCFLAGS) SysY.y 
	$(LEX) $(LEXFLAGS) SysY.l
	$(CC)   ./GrammarTree/AST.cpp  ./SymbolTable/SymbolTable.cpp ./SymbolTable/ScopeStack_stl.cpp ./IntermediateCode/TAC.cpp ./ObjectCode/Arm.cpp ./ObjectCode/ArmInstruction.cpp lex.yy.c  y.tab.c   ${CFLAGS} -o $@



# This target is to build small for testing (no debugging info), removes
# all intermediate products, too
strip : $(PRODUCTS)
	strip $(PRODUCTS)
	rm -rf $(JUNK)



clean:
	rm -f $(JUNK) y.output $(PRODUCTS)