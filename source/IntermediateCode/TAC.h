

#ifndef TAC_H
#define TAC_H



#include<malloc.h>
#include<stdarg.h>
#include <iostream>
#include <vector>
#include <stack>

#include "IndirectTripleOperator.h"
#include "IndirectTriple.h"





class TAC{
    private:
    vector <int> code_table;        //定义间接码表（动态数组）
    vector <IndirectTriple> TAC_table;  //定义三元式表（动态数组）


    public:
        TAC(GrammarTree tree, Scope scope, ScopeStack* stack){};// 初始化一个TAC，也就是创建语法树对应的
        TACItem* MergeTACItem(int num, ...);
        TranslateExpr(GrammarTree tree, Scope scope, ScopeStack* stack, Scope place);
        TranslateCondition(GrammarTree tree, Scope scope, ScopeStack* stack, unsigned int label_true, unsigned int label_false);
        TranslateArgs(GrammarTree tree, Scope scope, ScopeStack* stack);
        TranslateExprs(GrammarTree tree, Scope scope, ScopeStack* stack);
        TranslateStmt(GrammarTree tree, Scope scope, ScopeStack* stack);
        void DisplayTACItem(TACItem* entrance);

}



#endif 