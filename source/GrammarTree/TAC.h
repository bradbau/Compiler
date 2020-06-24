
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
    vector <TACCode*> next;
} basic_block;

class TAC{
public:
    TAC() {};
    TACCode* BuildTAC(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack);// ��ʼ��һ��TAC��Ҳ���Ǵ����﷨����Ӧ������ַ������
    TACCode* MergeTACItem(int num, ...);
    TACCode* TranslateExp(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, ScopeItem place);
    TACCode* TranslateCondition(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, unsigned int label_true, unsigned int label_false);
    TACCode* TranslateArgs(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack);
    TACCode* TranslateExps(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack);
    TACCode* TranslateStmt(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, Label continuevalue, Label breakvalue);
    TACCode* TranslateInitVal(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, ScopeItem place);
    TACCode* DivideBlock(TACCode codelist);
    ScopeStack* stack;
    //void DisplayTACItem(TACItem* entrance);

    //�����Ƕ���ӿ�

    //IndirectTriple nextLine();//�����ɻ��ʱ������һ��
    //int LineNumber();//����������
};
void DisplayTACCode(TACCode* entrance);
#endif
