#include "TAC.h"
#include "SymbolTable.h"
#include "stack.h"
#include "AST.h"

unsigned int temp_num = 0;
unsigned int label_num = 0;
typedef unsigned int Label;

TAC:: MergeTACItem(int num, ...)
{
    int i = 1;
    va_list codeli st;
    TACCode* entrance;
    TACCode* tmp;
    va_start(codelist, num); // Init the variable parameter list 
    while ((entrance = va_arg(codelist, TACCode*)) == NULL && i < num)
        i += 1;
    while (i < num)
    {
        // First, previous linklist's last element's "next" points to new linklist's first element
        if ((entrance->prev->next = va_arg(codelist, TACCode*)) == NULL)
        {
            /*printf("3 test i:%d num:%d\n", i, num);*/
            i += 1;
        }
        else
        {
            // Then, save the pointer to new linklist's last element 
            tmp = entrance->prev->next->prev;
            // Next, new linklist's first element's "prev" points to previous linklist's last element
            entrance->prev->next->prev = entrance->prev;
            // Finaly, previous linklist's first element's "prev" points to new linklist's last element
            entrance->prev = tmp;
            i += 1;
        }
    }
    return entrance;
}

TAC::TranslateInitVal(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, ScopeItem place) {
    if (!tree->lchild) {
        return NULL;    //不知道对不对
    }
    else if (!tree->lchild->rchild) {
        return TranslateExp(tree->lchild, scopeItem, stack, place));
    }
    else {
        //数组赋值
    }
}

TAC::TranslateStmt(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, Label continuevalue, Label breakvalue) {
    if (tree->name == "Empty_Stmt") {
        return NULL;
    }
    else if (tree->name == "IF_Stmt") {
        Label label1 = label_num++;
        Label label2 = label_num++;
        ASTTree* cond = tree->lchild;
        ASTTree* stmt = tree->lchild->rchild;
        scopeItem.depictor = GetStackTop(stack)->depictor;
        TACCode* code1 = TranslateCondition(cond, scopeItem, stack, label1, label2);
        scopeItem.depictor = GetStackTop(stack)->depictor;
        TACCode* code2 = TranslateStmt(stmt, scopeItem, stack);
        TACCode* code3 = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code4 = (TACCode*)malloc(sizeof(TACCode));
        code3->code.opkind = LABELDF;
        code3->code.dest.kind = LABEL;
        code3->code.dest.labelvalue = label1;
        code3->line = tree->lchild->line;
        code3->prev = code3;
        code4->code.opkind = LABELDF;
        code4->code.dest.kind = LABEL;
        code4->code.dest.labelvalue = label2;
        code4->line = tree->lchild->line;
        code4->prev = code4;
        return MergeTACItem(4, code1, code3, code2, code4);
    }
    else if (tree->name == "IF_ELSE_Stmt") {
        Label label1 = label_num++;
        Label label2 = label_num++;
        ASTTree* cond = tree->lchild;
        ASTTree* stmt = tree->lchild->rchild;
        scopeItem = GetStackTop(stack);
        TACCode* code1 = TranslateCondition(cond, scopeItem, stack, label1, label2);
        scopeItem = GetStackTop(stack);
        TACCode* code2 = TranslateStmt(stmt, scopeItem, stack);
        TACCode* code3 = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code4 = (TACCode*)malloc(sizeof(TACCode));
        code3->code.opkind = LABELDF;
        code3->code.dest.kind = LABEL;
        code3->code.dest.labelvalue = label1;
        code3->line = tree->lchild->line;
        code3->prev = code3;
        code4->code.opkind = LABELDF;
        code4->code.dest.kind = LABEL;
        code4->code.dest.labelvalue = label2;
        code4->line = tree->lchild->line;
        code4->prev = code4;
        Label label3 = label_num++;
        scopeItem = GetStackTop(stack);
        TACCode* code5 = TranslateStmt(stmt->rchild, scopeItem, stack);
        TACCode* code6 = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code7 = (TACCode*)malloc(sizeof(TACCode));
        code6->code.opkind = GOTO;
        code6->code.dest.kind = LABEL;
        code6->code.dest.labelvalue = label3;
        code6->line = tree->lchild->line;
        code6->prev = code6;
        code7->code.opkind = LABELDF;
        code7->code.dest.kind = LABEL;
        code7->code.dest.labelvalue = label3;
        code7->line = tree->lchild->line;
        code7->prev = code7;
        return MergeTACItem(7, code1, code3, code2, code6, code4, code5, code7);
    }
    else if (tree->name == "While_Stmt") {
        Label label1 = label_num++;
        Label label2 = label_num++;
        Label label3 = label_num++;
        ASTTree* cond = tree->lchild;
        ASTTree* stmt = tree->lchild->rchild;
        TACCode* code1 = (TACCode*)malloc(sizeof(TACCode));
        scopeItem = GetStackTop(stack);
        TACCode* code2 = TranslateCondition(cond, scopeItem, stack, label2, label3);
        TACCode* code3 = (TACCode*)malloc(sizeof(TACCode));
        scopeItem = GetStackTop(stack);
        TACCode* code4 = TranslateStmt(stmt, scopeItem, stack, label1, label3);
        TACCode* code5 = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code6 = (TACCode*)malloc(sizeof(TACCode));
        code1->code.opkind = LABELDF;
        code1->code.dest.kind = LABEL;
        code1->code.dest.labelvalue = label1;
        code1->line = tree->lchild->line;
        code1->prev = code1;
        code3->code.opkind = LABELDF;
        code3->code.dest.Type = LABEL;
        code3->code.dest.labelvalue = label2;
        code3->line = tree->lchild->line;
        code3->prev = code3;
        code5->code.opkind = GOTO;
        code5->code.dest.kind = LABEL;
        code5->code.dest.labelvalue = label1;
        code5->line = tree->lchild->line;
        code5->prev = code5;
        code6->code.opkind = LABELDF;
        code6->code.dest.kind = LABEL;
        code6->code.dest.labelvalue = label3;
        code6->line = tree->lchild->line;
        code6->prev = code6;
        return MergeTACItem(6, code1, code2, code3, code4, code5, code6);
    }
    else if (tree->name == "Break_Stmt") {
        TACCode* code1 = (TACCode*)malloc(sizeof(TACCode));
        code1->code.opkind = GOTO;
        code1->code.dest.kind = LABEL;
        code1->code.dest.labelvalue = breakvalue;
        return code1;
    }
    else if (tree->name == "Continue_Stmt") {
        TACCode* code1 = (TACCode*)malloc(sizeof(TACCode));
        code1->code.opkind = GOTO;
        code1->code.dest.kind = LABEL;
        code1->code.dest.labelvalue = continuevalue;
        return code1;
    }
    else if (tree->name == "Return_Stmt") {
        ASTTree* expr = tree->lchild;
        string cache;
        Scope new_temp;
        TACCode* code1;
        TACCode* code2 = (TACCode*)malloc(sizeof(TACCode));
        sprintf(cache, "_t%d", temp_num++);
        new_temp = addIntoScope(Local, tree->si, cache, Variable, "temp" , NULL);
        scopeItem = GetStackTop(stack);
        code1 = TranslateExp(expr, new_temp, stack, new_temp);
        code2->code.opkind = RETURN;
        code2->code.dest.kind = VARIABLE;
        code2->code.dest.variable = new_temp;
        code2->line = tree->lchild->line;
        code2->prev = code2;
        return MergeTACItem(2, code1, code2);
    }
}

TAC::TranslateExps(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack)
{
    if (tree==NULL) {
        return NULL;
    }
    else
    {
        string cache;
        ScopeItem new_temp;
        TACCode* code1, * code2;
        sprintf(cache, "_t%d", temp_num++);
        new_temp = addIntoScope(tree->si->stype, tree->si, cache, Variable, "temp", NULL);
        scopeItem = GetStackTop(stack);
        code1 = TranslateExps(tree->lchild, new_temp, stack);
        scopeItem = GetStackTop(stack);
        code2 = TranslateExp(tree->lchild->rchild, new_temp, stack, new_temp);
        return MergeTACItem(2, code1, code2);
    }
}

TAC::TranslateExp(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, Scope place)
{
    if (tree->name=="IntConst")
    {
        TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.opkind = ASSIGN;
        tmp->code.dest.kind = VARIABLE;
        tmp->code.dest.variable = place;
        tmp->code.firstsrc.kind = INTEGERCONST;
        tmp->code.firstsrc.intvalue = tree->int_value;
        tmp->line = tree->line;
        tmp->prev = tmp;
        return tmp;
    }
    else if (tree->name == "LVal_EXP"){
        TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.opkind = ASSIGN;
        tmp->code.dest.kind = VARIABLE;
        tmp->code.dest.variable = place;
        tmp->code.firstsrc.kind = VARIABLE;
        tmp->code.firstsrc.variable = tree->si;
        tmp->line = tree->lchild->line;
        tmp->prev = tmp;
        return tmp;
    }
    else if (tree->name == "funcall")
    {
        Scope variable;
        Scope function = TraverseScopeStack(*stack, tree->lchild->GetID());
        Scope origin = GetStackTop(stack);
        ASTTree* actuals = tree->lchild->rchild;
        scopeItem = origin;
        scopeItem = GetStackTop(stack);
        TACCode* code1 = TranslateArgs(actuals, scopeItem, stack);
        ScopeItem current = GetStackTop(stack);
        TACCode* code2 = NULL;
        TACCode* code3 = NULL;
        TACCode* tmp = NULL;
        variable.type = ScopeLocal;
        while (current != origin && current != NULL)
        {
            if (code2 == NULL)
            {
                code2 = (TACCode*)malloc(sizeof(TACCode));
                code2->code.opkind = ARG;
                code2->code.dest.kind = VARIABLE;
                variable.localscope = current;
                code2->code.dest.variable = variable;
                code2->line = tree->lchild->line;
                code2->prev = code2;
            }
            else
            {
                tmp = (TACCode*)malloc(sizeof(TACCode));
                tmp->code.opkind = ARG;
                tmp->code.dest.kind = VARIABLE;
                variable.localscope = current;
                tmp->code.dest.variable = variable;
                tmp->line = tree->lchild->line;
                tmp->prev = tmp;
                code2 = MergeTACItem(2, code2, tmp);
            }
            current = current->next;
        }
        code3 = (TACCode*)malloc(sizeof(TACCode));
        code3->code.opkind = CALLASSIGN;
        code3->code.dest.kind = VARIABLE;
        code3->code.dest.variable = place;
        code3->code.firstsrc.kind = FUNCTION;
        code3->code.firstsrc.function = function;
        code3->line = tree->lchild->line;
        code3->prev = code3;
        return MergeTACItem(3, code1, code2, code3);
    }
    else if (tree->name == "OPPLUS_Exp") {
        string cache;
        Scope new_temp;
        TACCode* tmp;
        sprintf(cache, "_t%d", temp_num++);
        new_temp = addIntoScope(tree->si->stype, tree->si, cache, Variable, "temp", NULL);
        tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.opkind = ADD;
        tmp->code.dest.kind = VARIABLE;
        tmp->code.dest.variable = place;
        tmp->code.firstsrc.kind = INTEGERCONST;
        tmp->code.firstsrc.intvalue = 0;
        tmp->code.secondsrc.kind = VARIABLE;
        tmp->code.secondsrc.variable = new_temp;
        tmp->line = tree->lchild->line;
        tmp->prev = tmp;
        scopeItem = GetStackTop(stack);
        return MergeTACItem(2, TranslateExp(tree->lchild, new_temp, stack, new_temp), tmp);
    }
    else if (tree->name == "OPMINUS_Exp") {
        string cache;
        Scope new_temp;
        TACCode* tmp;
        sprintf(cache, "_t%d", temp_num++);
        new_temp = addIntoScope(tree->si->stype, tree->si, cache, Variable, "temp", NULL);
        tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.opkind = SUB;
        tmp->code.dest.kind = VARIABLE;
        tmp->code.dest.variable = place;
        tmp->code.firstsrc.kind = INTEGERCONST;
        tmp->code.firstsrc.intvalue = 0;
        tmp->code.secondsrc.kind = VARIABLE;
        tmp->code.secondsrc.variable = new_temp;
        tmp->line = tree->lchild->line;
        tmp->prev = tmp;
        scopeItem = GetStackTop(stack);
        return MergeTACItem(2, TranslateExp(tree->lchild, new_temp, stack, new_temp), tmp);
    }
    else if (tree->name == "OPNOT_Exp"){
        Label label1 = label_num++;
        Label label2 = label_num++;
        TACCode* code0 = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code1;
        TACCode* code2 = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code3 = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code4 = (TACCode*)malloc(sizeof(TACCode));
        code0->code.opkind = ASSIGN;
        code0->code.dest.kind = VARIABLE;
        code0->code.dest.variable = place;
        code0->code.firstsrc.kind = INTEGERCONST;
        code0->code.firstsrc.intvalue = 0;
        code0->line = tree->lchild->line;
        code0->prev = code0;
        scopeItem = GetStackTop(stack);
        code1 = TranslateCondition(tree, scopeItem, stack, label1, label2);
        code2->code.opkind = LABELDF;
        code2->code.dest.kind = LABEL;
        code2->code.dest.labelvalue = label1;
        code2->line = tree->lchild->line;
        code2->prev = code2;
        code3->code.opkind = ASSIGN;
        code3->code.dest.kind = VARIABLE;
        code3->code.dest.variable = place;
        code3->code.firstsrc.kind = INTEGERCONST;
        code3->code.firstsrc.intvalue = 1;
        code3->line = tree->lchild->line;
        code3->prev = code3;
        code4->code.opkind = LABELDF;
        code4->code.dest.kind = LABEL;
        code4->code.dest.labelvalue = label2;
        code4->line = tree->lchild->line;
        code4->prev = code4;
        return MergeTACItem(5, code0, code1, code2, code3, code4);
    }
    else if (tree->name == "MulExp" || tree->name == "DIVIDEExp"
    || tree->name == "PLUSExp" || tree->name == "MINUSExp"
    || tree->name == "MODExp") {
        string cache1, cache2;
        Scope new_temp1, new_temp2;
        TACCode* code1, * code2, * code3;
        sprintf(cache1, "_t%d", temp_num++);
        sprintf(cache2, "_t%d", temp_num++);
        new_temp1 = addIntoScope(tree->lchild->si->stype, tree->lchild->si, cache1, Variable, "temp", NULL);
        new_temp1 = addIntoScope(tree->lchild->rchild->si->stype, tree->lchild->rchild->si, cache2, Variable, "temp", NULL);
        scopeItem = GetStackTop(stack);
        code1 = TranslateExp(tree->lchild, new_temp2, stack, new_temp1);
        scopeItem = GetStackTop(stack);
        code2 = TranslateExp(tree->lchild->rchild, new_temp2, stack, new_temp2);
        code3 = (TACCode*)malloc(sizeof(TACCode));
        if (tree->name == "PLUSExp")
            code3->code.opkind = ADD;
        else if (tree->name == "MINUSExp")
            code3->code.opkind = SUB;
        else if (tree->name == "MulExp")
            code3->code.opkind = MUL;
        else if (tree->name == "DIVIDEExp")
            code3->code.opkind = DIV;
        else if (tree->name == "MODExp")
            code3->code.opkind = MOD;
        code3->code.dest.kind = VARIABLE;
        code3->code.dest.variable = place;
        code3->code.firstsrc.kind = VARIABLE;
        code3->code.firstsrc.variable = new_temp1;
        code3->code.secondsrc.kind = VARIABLE;
        code3->code.secondsrc.variable = new_temp2;
        code3->line = tree->line;
        code3->prev = code3;
        return MergeTACItem(3, code1, code2, code3);
    }
    else if (tree->name == "(Exp)")
    {
        string cache;
        ScopeItem new_temp;
        TACCode* tmp;
        sprintf(cache, "_t%d", temp_num++);
        new_temp = addIntoScope(tree->lchild->si->stype, tree->lchild->si, cache, Variable, "temp", NULL);
        tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.opkind = ASSIGN;
        tmp->code.dest.kind = VARIABLE;
        tmp->code.dest.variable = place;
        tmp->code.firstsrc.kind = VARIABLE;
        tmp->code.firstsrc.variable = new_temp;
        tmp->line = tree->line;
        tmp->prev = tmp;
        scopeItem = GetStackTop(stack);
        return MergeTACItem(2, TranslateExp(tree->lchild, new_temp, stack, new_temp), tmp);
    }
    return NULL;
}

TAC::TranslateArgs(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack)
{
    if (tree->line == -1)
        return NULL;
    else
    {
        scopeItem = GetStackTop(stack);
        return TranslateExps(tree->lchild, scopeItem, stack);
    }
}

TAC::TranslateCondition(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack, unsigned int label_true, unsigned int label_false)
{
    if (tree->name=="Cond_And")
    {
        Label label = label_num++;
        scopeItem = GetStackTop(stack);
        TACCode* code1 = TranslateCondition(tree->lchild, scopeItem, stack, label, label_false);
        scopeItem = GetStackTop(stack);
        TACCode* code2 = TranslateCondition(tree->lchild->rchild->rchild, scopeItem, stack, label_true, label_false);
        TACCode* code3 = (TACCode*)malloc(sizeof(TACCode));
        code3->code.opkind = LABELDF;
        code3->code.dest.kind = LABEL;
        code3->code.dest.labelvalue = label;
        code3->line = tree->lchild->rchild->line;
        code3->prev = code3;
        return MergeTACItem(3, code1, code3, code2);
    }
    else if (tree->name=="Cond_Or")
    {
        Label label = label_num++;
        scopeItem = GetStackTop(stack);
        TACCode* code1 = TranslateCondition(tree->lchild, scopeItem, stack, label_true, label);
        scopeItem = GetStackTop(stack);
        TACCode* code2 = TranslateCondition(tree->lchild->rchild->rchild, scopeItem, stack, label_true, label_false);
        TACCode* code3 = (TACCode*)malloc(sizeof(TACCode));
        code3->code.opkind = LABELDF;
        code3->code.dest.kind = LABEL;
        code3->code.dest.labelvalue = label;
        code3->line = tree->lchild->rchild->line;
        code3->prev = code3;
        return MergeTACItem(3, code1, code3, code2);
    }
    else
    {
        string cache1, cache2;
        Scope new_temp1, new_temp2;
        TACCode* code1, * code2, * code3, * code4;
        sprintf(cache1, "_t%d", temp_num++);
        sprintf(cache2, "_t%d", temp_num++);
        new_temp1 = addIntoScope(tree->lchild->si->stype, tree->lchild->si, cache, Variable, "temp", NULL);
        new_temp2 = addIntoScope(tree->lchild->rchild->rchild->si->stype, tree->lchild->rchild->rchild->si, cache, Variable, "temp", NULL);
        scopeItem = GetStackTop(stack);
        code1 = TranslateExp(tree->lchild, new_temp2, stack, new_temp1);
        scopeItem = GetStackTop(stack);
        code2 = TranslateExp(tree->lchild->rchild->rchild, new_temp2, stack, new_temp2);
        code3 = (TACCode*)malloc(sizeof(TACCode));
        code3->code.dest.kind = LABEL;
        code3->code.dest.labelvalue = label_true;
        code3->code.firstsrc.kind = VARIABLE;
        code3->code.firstsrc.variable = new_temp1;
        code3->code.secondsrc.kind = VARIABLE;
        code3->code.secondsrc.variable = new_temp2;
        code3->line = tree->lchild->rchild->line;
        code3->prev = code3;
        if (tree->lchild->name == "OPLIGHT")
            code3->code.opkind = IFLTGOTO;
        else if (tree->lchild->name== "OPLIGHTEQ")
            code3->code.opkind = IFLEGOTO;
        else if (tree->lchild->name == "OPGREAT")
            code3->code.opkind = IFGTGOTO;
        else if (tree->lchild->name == "OPGREATEQ")
            code3->code.opkind = IFGEGOTO;
        else if (tree->lchild->name == "OPEQUAL")
            code3->code.opkind = IFEQGOTO;
        else if (tree->lchild->name == "OPNOTEQUAL")
            code3->code.opkind = IFNEQGOTO;
        else
            code3= TranslateExp(tree->lchild, new_temp2, stack, new_temp2);
        code4 = (TACCode*)malloc(sizeof(TACCode));
        code4->code.opkind = GOTO;
        code4->code.dest.kind = LABEL;
        code4->code.dest.labelvalue = label_false;
        code4->line = tree->line;
        code4->prev = code4;
        return MergeTACCode(4, code1, code2, code3, code4);
    }
}

TAC:: TAC(ASTTree* tree, ScopeItem scopeItem, ScopeStack* stack)
{
    if (tree == NULL)
        return NULL;
    if (tree->name == "Compiler")
    {
        PushScopeStack(stack, scopeItem);
        return TAC(tree->lchild, scopeItem, stack);
    }
    else if (tree->name == "CompUnits") {
        if (tree->lchild != NULL)
            return MergeTACItem(2, TAC(tree->lchild, scopeItem, stack), TAC(tree->lchild->rchild, scopeItem, stack));
        else
            return NULL;
    }
    else if (tree->name == "FuncDef")
    {
        TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
        TACCode* formalcode = NULL;
        TACCode* bodycode = NULL;
        //生成四元式部分
        tmp->code.opkind = FUNCTIONDF;
        tmp->code.dest.kind = FUNCTION;
        tmp->code.dest.function = TraverseScopeStack(*stack, tree->GetID()); //根据ID找到对应的作用域
        tmp->line = tree->line;
        tmp->prev = tmp;
        formalcode = TAC(tree->lchild, scopeItem, stack);                    //形参四元式
        bodycode = TAC(tree->lchild->rchild, scopeItem, stack);              //函数体四元式
        //作用域栈操作部分
        PushScopeStack(stack, tree->lchild->si);
        PushScopeStack(stack, tree->lchild->rchild->si);
        return MergeTACItem(3, tmp, formalcode, bodycode);  //合并四元式
    }
    else if (tree->name == "FuncFParams") {
        if (tree->lchild == NULL) {
            return NULL;
        }
        else if (tree->lchild->rchild == NULL) {
            return TAC(tree->lchild, scopeItem, stack);
        }
        else {
            return MergeTACItem(2, TranslateExp(tree->lchild, scopeItem, stack, TraverseScopeStack(*stack, tree->lchild->GetID())), TranslateExps(tree->lchild->rchild, scopeItem, stack));
        }
    }
    else if (tree->name == "FuncFParam") {
        //暂时没管数组
        TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.opkind = PARAM;
        tmp->code.dest.kind = VARIABLE;
        tmp->code.dest.variable = tree->si;
        tmp->line = tree->line;
        tmp->prev = tmp;
        if (tree->lchild) {
            return MergeTACItem(2, tmp, TAC(tree->lchild, scopeItem, stack));
            //数组操作先这样写，不知道行不行
        }
        else {
            return tmp;
        }
    }
    else if (tree->name == "ConstDecl") {
        return MergeTACItem(2, TAC(tree->lchild, scopeItem, stack), TAC(tree->lchild->rchild, scopeItem, stack));
    }
    else if (tree->name == "VarDecl") {
        return MergeTACItem(2, TAC(tree->lchild, scopeItem, stack), TAC(tree->lchild->rchild, scopeItem, stack));
    }
    else if (tree->name == "ConstDefs") {
        return MergeTACItem(2, TAC(tree->lchild, scopeItem, stack), TAC(tree->lchild->rchild, scopeItem, stack));
    }
    else if (tree->name == "VarDefs") {
        return MergeTACItem(2, TAC(tree->lchild, scopeItem, stack), TAC(tree->lchild->rchild, scopeItem, stack));
    }
    else if (tree->name == "ConstOpassign") {
        //没考虑数组
        return TranslateInitVal(tree->lchild->rchild, scopeItem, stack, TraverseScopeStack(*stack, tree->lchild->GetID()));
    }
    else if (tree->name == "VarOPassign") {
        //没考虑数组
        return TranslateInitVal(tree->lchild->rchild, scopeItem, stack, TraverseScopeStack(*stack, tree->lchild->GetID()));
    }
    else if (tree->name == "IDENTIFIER") {
        TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.opkind = PARAM;
        tmp->code.dest.kind = VARIABLE;
        tmp->code.dest.variable = TraverseScopeStack(*stack, tree->GetID());
        tmp->line = tree->line;
        tmp->prev = tmp;
        return tmp;
    }
    else if (tree->name == "FuncRParams") {
        return MergeTACItem(2, TranslateExp(tree->lchild, scopeItem, stack, TraverseScopeStack(*stack, tree->lchild->GetID())), TranslateExps(tree->lchild->rchild, scopeItem, stack));
    }
    else if (tree->name == "ArrayDec") {
        //数组没写
    }
    else if (tree->name == "ArrayExps") {
        //数组没写
    }
    else if (tree->name == "BlockItems") {
        return MergeTACItem(2, TAC(tree->lchild, scopeItem, stack), TAC(tree->lchild->rchild, scopeItem, stack));
    }
    else if (tree->name == "Exp_Stmt") {
        scopeItem.depictor = GetStackTop(stack)->depictor;
        return TranslateExp(tree->lchild, scopeItem, stack, NULL);
    }
    else if (tree->name == "Block_Stmt") {
        return TAC(tree->lchild, scopeItem, stack);
    }
    else if (tree->name == "Block") {
        int flag = 0;
        // Judge if this block is function body
        if (tree->si != GetStackTop(stack)) {
            flag = 1;
            PushScopeStack(stack, tree->si);
        }
        TACCode* BlockItems = (TACCode*)malloc(sizeof(TACCode));
        BlockItems = TAC(tree->lchild, scopeItem, stack);
        Scope top;
        if (flag == 1) {
            PopScopeStack(stack, &top);
        }
        return BlockItems;
    }
    else if (tree->name == "Lval_Opassign_Stmt") {
        return TranslateExp(tree->lchild->rchild, tree->lchild->rchild->si, stack, tree->lchild->si);
    }
    else if (tree->name == "Empty_Stmt") {
        return NULL;
    }
    else if (tree->name == "IF_Stmt") {
        return TranslateStmt(tree, scopeItem, stack, -1, -1);
    }
    else if (tree->name == "IF_ELSE_Stmt") {
        return TranslateStmt(tree, scopeItem, stack, -1, -1);
    }
    else if (tree->name == "While_Stmt") {
        return TranslateStmt(tree, scopeItem, stack, -1, -1);
    }
    else if (tree->name == "Break_Stmt") {
        return TranslateStmt(tree, scopeItem, stack, -1, -1);
    }
    else if (tree->name == "Continue_Stmt") {
        return TranslateStmt(tree, scopeItem, stack, -1, -1);
    }
    else if (tree->name == "Return_Stmt") {
        return TranslateStmt(tree, scopeItem, stack, -1, -1);
    }
}
 
void DisplayTACCode(TACCode* entrance)
{
    int line = 1;
    TACCode* tmp = entrance;
    char cache[10];
    printf(" No  Source Position\tTACCode\n");
    printf("_______________________________________\n");
    printf("  0  (at line   0)\tCALL main\n");
    while (tmp)
    {
        if (tmp->code.opkind == ASSIGN)
        {
            // Notice: no matter variable is in which scopeItem, the scopeItem entry always has "name" attribute
            printf("%3d  (at line %3d)\t%s := ", line, tmp->line, tmp->code.dest.variable.localscope->name);
            if (tmp->code.firstsrc.kind == VARIABLE)
                printf("%s\n", tmp->code.firstsrc.variable.localscope->name);
            else if (tmp->code.firstsrc.kind == ADDRESSS)
                printf("*%s\n", tmp->code.firstsrc.variable.localscope->name);
            else if (tmp->code.firstsrc.kind == INTEGERCONST)
                printf("#%d\n", tmp->code.firstsrc.intvalue);
            else if (tmp->code.firstsrc.kind == FLOATCONST)
                printf("#%d\n", tmp->code.firstsrc.floatvalue);
        }
        else if (tmp->code.opkind == ADD | tmp->code.opkind == SUB | tmp->code.opkind == MUL | tmp->code.opkind == DIV)
        {
            // Notice: no matter variable  is in which scopeItem, the scopeItem entry always has "name" attribute
            printf("%3d  (at line %3d)\t%s := ", line, tmp->line, tmp->code.dest.variable.localscope->name);
            if (tmp->code.firstsrc.kind == VARIABLE)
                printf("%s ", tmp->code.firstsrc.variable.localscope->name);
            else if (tmp->code.firstsrc.kind == ADDRESSS)
                printf("*%s ", tmp->code.firstsrc.variable.localscope->name);
            else if (tmp->code.firstsrc.kind == INTEGERCONST)
                printf("#%d ", tmp->code.firstsrc.intvalue);
            else if (tmp->code.firstsrc.kind == FLOATCONST)
                printf("#%d ", tmp->code.firstsrc.floatvalue);
            switch (tmp->code.opkind)
            {
            case ADD:
                printf("+ ");
                break;
            case SUB:
                printf("- ");
                break;
            case MUL:
                printf("* ");
                break;
            case DIV:
                printf("/ ");
                break;
            }
            if (tmp->code.secondsrc.kind == VARIABLE)
                printf("%s\n", tmp->code.secondsrc.variable.localscope->name);
            else if (tmp->code.secondsrc.kind == ADDRESSS)
                printf("*%s\n", tmp->code.secondsrc.variable.localscope->name);
            else if (tmp->code.secondsrc.kind == INTEGERCONST)
                printf("#%d\n", tmp->code.secondsrc.intvalue);
            else if (tmp->code.secondsrc.kind == FLOATCONST)
                printf("#%d\n", tmp->code.secondsrc.floatvalue);
        }
        else if (tmp->code.opkind == FUNCTIONDF)
            printf("\n%3d  (at line %3d)\tFUNCTION %s :\n", line, tmp->line, tmp->code.dest.function.classscope->name);
        else if (tmp->code.opkind == PARAM)
            printf("%3d  (at line %3d)\tPARAM %s\n", line, tmp->line, tmp->code.dest.variable.formalscope->name);
        else if (tmp->code.opkind == LABELDF)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            printf("%3d  (at line %3d)\tLABEL %s :\n", line, tmp->line, cache);
        }
        else if (tmp->code.opkind == IFLTGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            printf("%3d  (at line %3d)\tIF %s < %s GOTO %s\n",
                line, tmp->line, tmp->code.firstsrc.variable.localscope->name, tmp->code.secondsrc.variable.localscope->name, cache);
        }
        else if (tmp->code.opkind == IFLEGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            printf("%3d\nIF %s <= %s GOTO %s\n",
                line, tmp->line, tmp->code.firstsrc.variable.localscope->name, tmp->code.secondsrc.variable.localscope->name, cache);
        }
        else if (tmp->code.opkind == IFGTGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            printf("%3d  (at line %3d)\tIF %s > %s GOTO %s\n",
                line, tmp->line, tmp->code.firstsrc.variable.localscope->name, tmp->code.secondsrc.variable.localscope->name, cache);
        }
        else if (tmp->code.opkind == IFGEGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            printf("%3d  (at line %3d)\tIF %s >= %s GOTO %s\n",
                line, tmp->line, tmp->code.firstsrc.variable.localscope->name, tmp->code.secondsrc.variable.localscope->name, cache);
        }
        else if (tmp->code.opkind == IFEQGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            printf("%3d  (at line %3d)\tIF %s = %s GOTO %s\n",
                line, tmp->line, tmp->code.firstsrc.variable.localscope->name, tmp->code.secondsrc.variable.localscope->name, cache);
        }
        else if (tmp->code.opkind == IFNEQGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            printf("%3d  (at line %3d)\tIF %s != ", line, tmp->line, tmp->code.firstsrc.variable.localscope->name);
            if (tmp->code.secondsrc.kind == VARIABLE)
                printf("%s ", tmp->code.secondsrc.variable.localscope->name);
            else if (tmp->code.secondsrc.kind == INTEGERCONST)
                printf("%d ", tmp->code.secondsrc.intvalue);
            printf("GOTO %s\n", cache);
        }
        else if (tmp->code.opkind == GOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.labelvalue);
            printf("%3d  (at line %3d)\tGOTO %s\n", line, tmp->line, cache);
        }
        else if (tmp->code.opkind == RETURN)
        {
            printf("%3d  (at line %3d)\tRETURN %s\n", line, tmp->line, tmp->code.dest.variable.localscope->name);
        }
        else if (tmp->code.opkind == ARG)
        {
            printf("%3d  (at line %3d)\tARG %s\n", line, tmp->line, tmp->code.dest.variable.localscope->name);
        }
        else if (tmp->code.opkind == CALLASSIGN)
        {
            printf("%3d  (at line %3d)\t%s := CALL %s\n", line, tmp->line, tmp->code.dest.variable.localscope->name, tmp->code.firstsrc.function.localscope->name);
        }
        else if (tmp->code.opkind == CALL)
        {
            printf("%3d  (at line %3d)\tCALL %s\n", line, tmp->line, tmp->code.dest.function.localscope->name);
        }
        tmp = tmp->next;
        line += 1;
    }
}

int main(int argc, char** argv)
{
    if (argc > 1)
    {
        if (!(yyin = fopen(argv[1], "r"))
        {
            perror(argv[1]);
            return 1;
        }
    }
    yyparse();
    return 0;
}
