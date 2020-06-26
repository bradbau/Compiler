
#ifndef TAC_H
#define TAC_H

#include<malloc.h>
#include<stdarg.h>
#include <iostream>
#include <vector>

#include "IndirectTripleOperand.h"
#include "IndirectTriple.h"
#include "AST.h"
#include "stack.h"

typedef unsigned int Label;

typedef struct TACCode
{
    int line;
    four code;
    struct TACCode* prev;
    struct TACCode* next;
} TACCode;

typedef struct basic_block {
    TACCode* begin;
    TACCode* end;
    vector <basic_block*> next;
} basic_block;

class TAC{
public:
    TAC() {};
    TACCode* BuildTAC(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack);// 初始化一个TAC，也就是创建语法树对应的三地址码序列
    TACCode* MergeTACItem(int num, ...);
    TACCode* TranslateExp(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, ScopeItem place);
    TACCode* TranslateCondition(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, unsigned int label_true, unsigned int label_false);
    TACCode* TranslateArgs(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack);
    TACCode* TranslateExps(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack);
    TACCode* TranslateStmt(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, Label continuevalue, Label breakvalue);
    TACCode* TranslateInitVal(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, ScopeItem place);
    basic_block* TAC::DivideBlock(TACCode* entrance);
    basic_block* TAC::SearchBlock(basic_block* head, Label label);
    ScopeStack* stack;
    //void DisplayTACItem(TACItem* entrance);

    //以下是对外接口

    //IndirectTriple nextLine();//在生成汇编时返回下一行
    //int LineNumber();//代码总行数
};
void DisplayTACCode(TACCode* entrance);
#endif
