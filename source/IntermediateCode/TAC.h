
#ifndef TAC_H
#define TAC_H

#include<malloc.h>
#include<stdarg.h>
#include <iostream>
#include <vector>

#include "QuadrupleOperand.h"
#include "Quadruple.h"
#include "AST.h"
#include "../SymbolTable/ScopeStack.h"

typedef unsigned int Label;

typedef struct TACCode
{
    int line; //在源代码中的行数
    Quadruple code;
    struct TACCode* prev;
    struct TACCode* next;
} TACCode;


//这个结构说明基本快通过首位节点的索引确定
/*
typedef struct basic_block {
    TACCode* begin;
    TACCode* end;
    vector <basic_block*> next;
} basic_block;
*/


    TACCode* BuildTAC(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack);// ��ʼ��һ��TAC��Ҳ���Ǵ����﷨����Ӧ������ַ������
    TACCode* MergeTACItem(int num, ...);
    TACCode* TranslateExp(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, ScopeItem place);
    TACCode* TranslateCondition(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, unsigned int label_true, unsigned int label_false);
    TACCode* TranslateArgs(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack);
    TACCode* TranslateExps(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack);
    TACCode* TranslateStmt(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, Label continuevalue, Label breakvalue);
    TACCode* TranslateInitVal(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, ScopeItem place);

    void DisplayTACCode(TACCode* entrance);
#endif
