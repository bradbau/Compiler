
#ifndef TAC_H
#define TAC_H

#include<malloc.h>
#include<stdarg.h>
#include <iostream>
#include <vector>
#include <stack>

#include "IndirectTripleOperand.h"
#include "IndirectTriple.h"

class TAC :
{
public:
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
        vector <TACCode*> next;
    } basic_block;

    TAC(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack) {};// 初始化一个TAC，也就是创建语法树对应的三地址码序列
    MergeTACItem(int num, ...);
    TranslateExp(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, Scope place);
    TranslateCondition(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, unsigned int label_true, unsigned int label_false);
    TranslateArgs(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack);
    TranslateExps(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack);
    TranslateStmt(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack);
    TranslateInitVal(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, Scope place);
    DivideBlock(TACCode codelist);
    //void DisplayTACItem(TACItem* entrance);

    //以下是对外接口

    //IndirectTriple nextLine();//在生成汇编时返回下一行
    //int LineNumber();//代码总行数
}

#endif
