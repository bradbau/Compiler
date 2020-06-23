
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

    TAC(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack) {};// ��ʼ��һ��TAC��Ҳ���Ǵ����﷨����Ӧ������ַ������
    MergeTACItem(int num, ...);
    TranslateExp(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, Scope place);
    TranslateCondition(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, unsigned int label_true, unsigned int label_false);
    TranslateArgs(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack);
    TranslateExps(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack);
    TranslateStmt(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack);
    TranslateInitVal(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, Scope place);
    DivideBlock(TACCode codelist);
    //void DisplayTACItem(TACItem* entrance);

    //�����Ƕ���ӿ�

    //IndirectTriple nextLine();//�����ɻ��ʱ������һ��
    //int LineNumber();//����������
}

#endif
