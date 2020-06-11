#include<stdio.h>
#include<malloc.h>
#include<stdarg.h>
#include "stack.h"

typedef enum TACOperandKind
{
    VARIABLE,
    ADDRESSS,
    INTEGERCONST,
    FUNCTION,
    LABEL
} TACOperandKind;

typedef struct TACOperand
{
    TACOperandKind kind;
    union
    {
        int intvalue;
        int labelvalue;
        Scope variable;
        Scope function;
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
    TACOpKind opkind;
    TACOperand dest;
    TACOperand firstsrc;
    TACOperand secondsrc;
} TAC;

typedef struct TACCode
{
    int line;
    TAC code;
    struct TACCode* prev;
    struct TACCode* next;
} TACCode;

typedef unsigned int Label;

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