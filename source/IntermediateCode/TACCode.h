#include<stdio.h>
#include<malloc.h>
#include<stdarg.h>
#include "stack.h"
#include <iostream>
#include <vector>

using namespace std;

typedef enum TACOperandKind
{
    VARIABLE,       //变量
    ADDRESSS,       //地址
    INTEGERCONST,   //常数
    FUNCTION,       //函数定义
    LABEL           //标号定义
} TACOperandKind;

typedef struct TACOperand
{
    TACOperandKind kind;
    union
    {
        int intvalue;       //常量值
        int labelvalue;     //标号
        int seq;            //三元式序号
        Scope variable;     //变量
        Scope function;     //函数
    };
} TACOperand;

typedef enum TACOpKind
{
    ASSIGN,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    FUNCTIONDF,
    PARAM,
    LABELDF,
    IFLTGOTO,
    IFLEGOTO,
    IFGTGOTO,
    IFGEGOTO,
    IFEQGOTO,
    IFNEQGOTO,
    GOTO,
    RETURN,
    ARG,
    CALLASSIGN,
    CALL
} TACOpKind;

typedef struct TAC
{
    int seq;                //三元式序号（先放着看看有没有用，没用再删掉）
    TACOpKind opkind;       //运算符
    TACOperand firstsrc;    //第一操作数
    TACOperand secondsrc;   //第二操作数
} TAC;

typedef struct TACCode
{
    int line;
    TAC code;
    struct TACCode* prev;
    struct TACCode* next;
} TACCode;

typedef unsigned int Label; //标号值

class TACCodeItem{
    private:
        TACCode *tc;

    public:
        TACCode(){}
        TACCode* MergeTACCode(int num, ...);
        TranslateExpr(GrammarTree tree, Scope scope, ScopeStack* stack, Scope place);
        TranslateCondition(GrammarTree tree, Scope scope, ScopeStack* stack, unsigned int label_true, unsigned int label_false);
        TranslateArgs(GrammarTree tree, Scope scope, ScopeStack* stack);
        TranslateExprs(GrammarTree tree, Scope scope, ScopeStack* stack);
        TranslateStmt(GrammarTree tree, Scope scope, ScopeStack* stack);
        GenerateInterCode(GrammarTree tree, Scope scope, ScopeStack* stack); 
        void DisplayTACCode(TACCode* entrance);

}

vector <int> code_table;        //定义间接码表（动态数组）
vector <TACOperand> TAC_table;  //定义三元式表（动态数组）