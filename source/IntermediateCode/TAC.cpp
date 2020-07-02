#include "TAC.h"

//#include "stack.h"
//#include "AST.h"



TACCode*   MergeTACItem(int num, ...){
    int i = 1;
    va_list codelist;
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

TACCode*  TranslateInitVal(ASTTree* tree, ScopeItem* scopeItem, ScopeStack* stack, ScopeItem* place,  unsigned int &temp_num, unsigned int &label_num) { 
    if (!tree->lchild) {
        return NULL;    //不知道对不对
    }
    else if (!tree->lchild->rchild) {  //ok
        return TranslateExp(tree->lchild, scopeItem, stack, place, temp_num, label_num);
    }
    else {
        //数组赋值
    }
}


TACCode*  TranslateStmt(ASTTree* tree, ScopeItem* scopeItem, ScopeStack* stack, Label continuevalue, Label breakvalue,unsigned int &temp_num, unsigned int &label_num) {
    if (tree->name == "Empty_Stmt") {
        return NULL;
    }
    else if (tree->name == "IF_Stmt") {
        Label label1 = label_num++;
        Label label2 = label_num++;
        ASTTree* cond = tree->lchild;
        ASTTree* stmt = tree->lchild->rchild;
        scopeItem = GetStackTopp(stack);
        TACCode* code1 = TranslateCondition(cond, scopeItem, stack, label1, label2, temp_num, label_num);
        scopeItem = GetStackTopp(stack);
        TACCode* code2 = TranslateStmt(stmt, scopeItem, stack, continuevalue, breakvalue, temp_num, label_num);
        TACCode* code3 = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code4 = (TACCode*)malloc(sizeof(TACCode));
        code3->code.optype = LABELDF;
        code3->code.dest.Type = LABEL;
        code3->code.dest.Data.labelvalue = label1;
        code3->line = tree->lchild->line;
        code3->prev = code3;
        code4->code.optype = LABELDF;
        code4->code.dest.Type = LABEL;
        code4->code.dest.Data.labelvalue = label2;
        code4->line = tree->lchild->line;
        code4->prev = code4;
        return MergeTACItem(4, code1, code3, code2, code4);
    }
    else if (tree->name == "IF_ELSE_Stmt") {
        Label label1 = label_num++;
        Label label2 = label_num++;
        ASTTree* cond = tree->lchild;
        ASTTree* stmt = tree->lchild->rchild;
        scopeItem = GetStackTopp(stack);
        TACCode* code1 = TranslateCondition(cond, scopeItem, stack, label1, label2, temp_num, label_num);
        scopeItem = GetStackTopp(stack);
        TACCode* code2 = TranslateStmt(stmt, scopeItem, stack, continuevalue, breakvalue, temp_num, label_num);
        TACCode* code3 = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code4 = (TACCode*)malloc(sizeof(TACCode));
        code3->code.optype = LABELDF;
        code3->code.dest.Type = LABEL;
        code3->code.dest.Data.labelvalue = label1;
        code3->line = tree->lchild->line;
        code3->prev = code3;
        code4->code.optype = LABELDF;
        code4->code.dest.Type = LABEL;
        code4->code.dest.Data.labelvalue = label2;
        code4->line = tree->lchild->line;
        code4->prev = code4;
        Label label3 = label_num++;
        scopeItem = GetStackTopp(stack);
        TACCode* code5 = TranslateStmt(stmt->rchild, scopeItem, stack, continuevalue, breakvalue, temp_num, label_num);
        TACCode* code6 = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code7 = (TACCode*)malloc(sizeof(TACCode));
        code6->code.optype = GOTO;
        code6->code.dest.Type = LABEL;
        code6->code.dest.Data.labelvalue = label3;
        code6->line = tree->lchild->line;
        code6->prev = code6;
        code7->code.optype = LABELDF;
        code7->code.dest.Type = LABEL;
        code7->code.dest.Data.labelvalue = label3;
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
        scopeItem = GetStackTopp(stack);
        TACCode* code2 = TranslateCondition(cond, scopeItem, stack, label2, label3, temp_num, label_num);
        TACCode* code3 = (TACCode*)malloc(sizeof(TACCode));
        scopeItem = GetStackTopp(stack);
        TACCode* code4 = TranslateStmt(stmt, scopeItem, stack, label1, label3, temp_num, label_num);
        TACCode* code5 = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code6 = (TACCode*)malloc(sizeof(TACCode));
        code1->code.optype = LABELDF;
        code1->code.dest.Type = LABEL;
        code1->code.dest.Data.labelvalue = label1;
        code1->line = tree->lchild->line;
        code1->prev = code1;
        code3->code.optype = LABELDF;
        code3->code.dest.Type = LABEL;
        code3->code.dest.Data.labelvalue = label2;
        code3->line = tree->lchild->line;
        code3->prev = code3;
        code5->code.optype = GOTO;
        code5->code.dest.Type = LABEL;
        code5->code.dest.Data.labelvalue = label1;
        code5->line = tree->lchild->line;
        code5->prev = code5;
        code6->code.optype = LABELDF;
        code6->code.dest.Type = LABEL;
        code6->code.dest.Data.labelvalue = label3;
        code6->line = tree->lchild->line;
        code6->prev = code6;
        return MergeTACItem(6, code1, code2, code3, code4, code5, code6);
    }
    else if (tree->name == "Break_Stmt") {
        TACCode* code1 = (TACCode*)malloc(sizeof(TACCode));
        code1->code.optype = GOTO;
        code1->code.dest.Type = LABEL;
        code1->code.dest.Data.labelvalue = breakvalue;
        return code1;
    }
    else if (tree->name == "Continue_Stmt") {
        TACCode* code1 = (TACCode*)malloc(sizeof(TACCode));
        code1->code.optype = GOTO;
        code1->code.dest.Type = LABEL;
        code1->code.dest.Data.labelvalue = continuevalue;
        return code1;
    }
    else if (tree->name == "Return_Stmt") {
        ASTTree* expr = tree->lchild;
        string cache;
        
        TACCode* code1;
        TACCode* code2 = (TACCode*)malloc(sizeof(TACCode));
        cache = "_t" + to_string(temp_num++);
        //作用域操作
        //
        ScopeItem* scope = GetStackTopp(stack);
        ScopeItem* new_temp= addIntoScope(Local, scope, cache, Variable, "temp" , NULL);

        code1 = TranslateExp(expr, new_temp, stack, new_temp, temp_num, label_num);
        code2->code.optype = RETURN;
        code2->code.dest.Type = VARIABLE;
        code2->code.dest.Data.variable = new_temp;
        code2->line = tree->lchild->line;
        code2->prev = code2;
        return MergeTACItem(2, code1, code2);
    }
}

TACCode*  TranslateExps(ASTTree* tree, ScopeItem* scopeItem, ScopeStack* stack, unsigned int &temp_num, unsigned int &label_num){
    if (tree==NULL) {
        return NULL;
    }
    else
    {
        string cache;

        TACCode* code1, * code2;
        cache = "_t" + to_string(temp_num++);
        ScopeItem* scope = GetStackTopp(stack);
        ScopeItem *new_temp = addIntoScope(Local, scope, cache, Variable, "temp", NULL);
        code1 = TranslateExps(tree->lchild, new_temp, stack, temp_num, label_num);
        code2 = TranslateExp(tree->lchild->rchild, new_temp, stack, new_temp, temp_num, label_num);
        return MergeTACItem(2, code1, code2);
    }
}

TACCode*  TranslateExp(ASTTree* tree, ScopeItem* scopeItem, ScopeStack* stack, ScopeItem* place, unsigned int &temp_num, unsigned int &label_num){
    if (tree->name=="IntConst")   //ok
    {
        TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.optype = ASSIGN;
        tmp->code.dest.Type = VARIABLE;
        

        tmp->code.dest.Data.variable = place;
        tmp->code.firstOp.Type = INTEGERCONST;
        tmp->code.firstOp.Data.value = tree->lchild->int_value;
        tmp->line = tree->line;
        tmp->prev = tmp;
        return tmp;
    }
    else if (tree->name == "LVal_EXP"){
        TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.optype = ASSIGN;
        tmp->code.dest.Type = VARIABLE;
        tmp->code.dest.Data.variable = place;
        tmp->code.firstOp.Type = VARIABLE;
        tmp->code.firstOp.Data.variable = (ScopeItem*)malloc(sizeof(ScopeItem));
        *(tmp->code.firstOp.Data.variable)=*(tree->si);
        tmp->line = tree->lchild->line;
        tmp->prev = tmp;
        return tmp;
    }
    else if (tree->name == "funcall")
    {
        ScopeItem variable;
        ScopeItem function = *TraverseScopeStack(stack, tree->lchild->GetID());
        ScopeItem* origin = GetStackTopp(stack);
        ASTTree* actuals = tree->lchild->rchild;
        scopeItem = GetStackTopp(stack);
        TACCode* code1 = TranslateArgs(actuals, scopeItem, stack, temp_num, label_num);
        ScopeItem* current = GetStackTopp(stack);
        TACCode* code2 = NULL;
        TACCode* code3 = NULL;
        TACCode* tmp = NULL;
        variable.type = Local;
        while (&current != &origin && current != NULL)
        {
            if (code2 == NULL)
            {
                code2 = (TACCode*)malloc(sizeof(TACCode));
                code2->code.optype = ARG;
                code2->code.dest.Type = VARIABLE;
                variable.depictor = current;
                code2->code.dest.Data.variable = (ScopeItem*)malloc(sizeof(ScopeItem));
                *(code2->code.dest.Data.variable)= variable;
                code2->line = tree->lchild->line;
                code2->prev = code2;
            }
            else
            {
                tmp = (TACCode*)malloc(sizeof(TACCode));
                tmp->code.optype = ARG;
                tmp->code.dest.Type = VARIABLE;
                variable.depictor = current;
                tmp->code.dest.Data.variable  = (ScopeItem*)malloc(sizeof(ScopeItem));
                *(tmp->code.dest.Data.variable)= variable;

                tmp->line = tree->lchild->line;
                tmp->prev = tmp;
                code2 = MergeTACItem(2, code2, tmp);
            }
            current = current->next;
        }
        code3 = (TACCode*)malloc(sizeof(TACCode));
        code3->code.optype = CALLASSIGN;
        code3->code.dest.Type = VARIABLE;
        code3->code.dest.Data.variable = place;
        code3->code.firstOp.Type = FUNCTION;
        code3->code.firstOp.Data.function  = (ScopeItem*)malloc(sizeof(ScopeItem));
        *(code3->code.firstOp.Data.function)= function;

        code3->line = tree->lchild->line;
        code3->prev = code3;
        return MergeTACItem(3, code1, code2, code3);
    }
    else if (tree->name == "OPPLUS_Exp") {
        string cache;
        TACCode* tmp;
        cache = "_t" + to_string(temp_num++);
        ScopeItem* scope = GetStackTopp(stack);
        ScopeItem *new_temp = addIntoScope(Local, scope, cache, Variable, "temp", NULL);
        tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.optype = ADD;
        tmp->code.dest.Type = VARIABLE;
        tmp->code.dest.Data.variable = place;
        tmp->code.firstOp.Type = INTEGERCONST;
        tmp->code.firstOp.Data.value = 0;
        tmp->code.secondOp.Type = VARIABLE;
        tmp->code.secondOp.Data.variable = new_temp;
        tmp->line = tree->lchild->line;
        tmp->prev = tmp;
        scopeItem = GetStackTopp(stack);
        return MergeTACItem(2, TranslateExp(tree->lchild, new_temp, stack, new_temp, temp_num, label_num), tmp);
    }
    else if (tree->name == "OPMINUS_Exp") {
        string cache;
        TACCode* tmp;
        cache = "_t" + to_string(temp_num++);
        ScopeItem* scope = GetStackTopp(stack);
        ScopeItem *new_temp = addIntoScope(Local, scope, cache, Variable, "temp", NULL);
        tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.optype = SUB;
        tmp->code.dest.Type = VARIABLE;
        tmp->code.dest.Data.variable = place;
        tmp->code.firstOp.Type = INTEGERCONST;
        tmp->code.firstOp.Data.value = 0;
        tmp->code.secondOp.Type = VARIABLE;
        tmp->code.secondOp.Data.variable = new_temp;
        tmp->line = tree->lchild->line;
        tmp->prev = tmp;
        scopeItem = GetStackTopp(stack);
        return MergeTACItem(2, TranslateExp(tree->lchild, new_temp, stack, new_temp, temp_num, label_num), tmp);
    }
    else if (tree->name == "OPNOT_Exp"){
        Label label1 = label_num++;
        Label label2 = label_num++;
        TACCode* code0 = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code1;
        TACCode* code2 = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code3 = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code4 = (TACCode*)malloc(sizeof(TACCode));
        code0->code.optype = ASSIGN;
        code0->code.dest.Type = VARIABLE;
        code0->code.dest.Data.variable = place;
        code0->code.firstOp.Type = INTEGERCONST;
        code0->code.firstOp.Data.value = 0;
        code0->line = tree->lchild->line;
        code0->prev = code0;
        scopeItem = GetStackTopp(stack);
        code1 = TranslateCondition(tree, scopeItem, stack, label1, label2, temp_num, label_num);
        code2->code.optype = LABELDF;
        code2->code.dest.Type = LABEL;
        code2->code.dest.Data.labelvalue = label1;
        code2->line = tree->lchild->line;
        code2->prev = code2;
        code3->code.optype = ASSIGN;
        code3->code.dest.Type = VARIABLE;
        code3->code.dest.Data.variable = place;
        code3->code.firstOp.Type = INTEGERCONST;
        code3->code.firstOp.Data.value = 1;
        code3->line = tree->lchild->line;
        code3->prev = code3;
        code4->code.optype = LABELDF;
        code4->code.dest.Type = LABEL;
        code4->code.dest.Data.labelvalue = label2;
        code4->line = tree->lchild->line;
        code4->prev = code4;
        return MergeTACItem(5, code0, code1, code2, code3, code4);
    }
    else if (tree->name == "MulExp" || tree->name == "DIVIDEExp"
    || tree->name == "PLUSExp" || tree->name == "MINUSExp"
    || tree->name == "MODExp") {
        string cache1, cache2;

        TACCode* code1, * code2, * code3;
        cache1 = "_t" + to_string(temp_num++);
        cache2 = "_t" + to_string(temp_num++);
        ScopeItem *new_temp1 = addIntoScope(tree->lchild->si->stype, tree->lchild->si, cache1, Variable, "temp", NULL);
        ScopeItem *new_temp2 = addIntoScope(tree->lchild->rchild->si->stype, tree->lchild->rchild->si, cache2, Variable, "temp", NULL);
        scopeItem = GetStackTopp(stack);
        code1 = TranslateExp(tree->lchild, new_temp2, stack, new_temp1, temp_num, label_num);
        scopeItem = GetStackTopp(stack);
        code2 = TranslateExp(tree->lchild->rchild, new_temp2, stack, new_temp2, temp_num, label_num);
        code3 = (TACCode*)malloc(sizeof(TACCode));
        if (tree->name == "PLUSExp")
            code3->code.optype = ADD;
        else if (tree->name == "MINUSExp")
            code3->code.optype = SUB;
        else if (tree->name == "MulExp")
            code3->code.optype = MUL;
        else if (tree->name == "DIVIDEExp")
            code3->code.optype = DIV;
        else if (tree->name == "MODExp")
            code3->code.optype = MOD;
        code3->code.dest.Type = VARIABLE;
        code3->code.dest.Data.variable = place;
        code3->code.firstOp.Type = VARIABLE;
        code3->code.firstOp.Data.variable = new_temp1;
        code3->code.secondOp.Type = VARIABLE;
        code3->code.secondOp.Data.variable = new_temp2;
        code3->line = tree->line;
        code3->prev = code3;
        return MergeTACItem(3, code1, code2, code3);
    }
    else if (tree->name == "(Exp)")
    {
        string cache;
        TACCode* tmp;
        cache = "_t" + to_string(temp_num++);
        ScopeItem *new_temp = addIntoScope(tree->lchild->si->stype, tree->lchild->si, cache, Variable, "temp", NULL);
        tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.optype = ASSIGN;
        tmp->code.dest.Type = VARIABLE;
        tmp->code.dest.Data.variable = place;
        tmp->code.firstOp.Type = VARIABLE;
        tmp->code.firstOp.Data.variable = new_temp;
        tmp->line = tree->line;
        tmp->prev = tmp;
        scopeItem = GetStackTopp(stack);
        return MergeTACItem(2, TranslateExp(tree->lchild, new_temp, stack, new_temp, temp_num, label_num), tmp);
    }
    return NULL;
}

TACCode*  TranslateArgs(ASTTree* tree, ScopeItem* scopeItem, ScopeStack* stack, unsigned int &temp_num, unsigned int &label_num){
    if (tree->line == -1)
        return NULL;
    else
    {
        scopeItem = GetStackTopp(stack);
        return TranslateExps(tree->lchild, scopeItem, stack, temp_num, label_num);
    }
}

TACCode*  TranslateCondition(ASTTree* tree, ScopeItem* scopeItem, ScopeStack* stack, unsigned int label_true, unsigned int label_false, unsigned int &temp_num, unsigned int &label_num){
    if (tree->name=="Cond_And")
    {
        Label label = label_num++;
        scopeItem = GetStackTopp(stack);
        TACCode* code1 = TranslateCondition(tree->lchild, scopeItem, stack, label, label_false, temp_num, label_num);
        scopeItem = GetStackTopp(stack);
        TACCode* code2 = TranslateCondition(tree->lchild->rchild->rchild, scopeItem, stack, label_true, label_false, temp_num, label_num);
        TACCode* code3 = (TACCode*)malloc(sizeof(TACCode));
        code3->code.optype = LABELDF;
        code3->code.dest.Type = LABEL;
        code3->code.dest.Data.labelvalue = label;
        code3->line = tree->lchild->rchild->line;
        code3->prev = code3;
        return MergeTACItem(3, code1, code3, code2);
    }
    else if (tree->name=="Cond_Or")
    {
        Label label = label_num++;
        scopeItem = GetStackTopp(stack);
        TACCode* code1 = TranslateCondition(tree->lchild, scopeItem, stack, label_true, label, temp_num, label_num);
        scopeItem = GetStackTopp(stack);
        TACCode* code2 = TranslateCondition(tree->lchild->rchild->rchild, scopeItem, stack, label_true, label_false, temp_num, label_num);
        TACCode* code3 = (TACCode*)malloc(sizeof(TACCode));
        code3->code.optype = LABELDF;
        code3->code.dest.Type = LABEL;
        code3->code.dest.Data.labelvalue = label;
        code3->line = tree->lchild->rchild->line;
        code3->prev = code3;
        return MergeTACItem(3, code1, code3, code2);
    }
    else
    {
        string cache1, cache2;
        ScopeItem top;
        TACCode* code1, * code2, * code3, * code4;
        if (tree->lchild->name == "OPLIGHT" || tree->lchild->name == "OPGREAT" || tree->lchild->name == "OPGREATEQ" ||
            tree->lchild->name == "OPLIGHTEQ" || tree->lchild->name == "OPEQUAL" || tree->lchild->name == "OPNOTEQUAL") {
            cache1 = "_t" + to_string(temp_num++);
            cache2 = "_t" + to_string(temp_num++);
            ScopeItem* first = GetStackTopp(stack);
            ScopeItem *new_temp1 = addIntoScope(first->stype, first, cache1, Variable, "temp", NULL);
            PopScopeStack(stack, &top);
            ScopeItem *new_temp2 = addIntoScope(first->stype, new_temp1, cache2, Variable, "temp", NULL);
            PushScopeStack(stack, *new_temp2);     //把new_temp2作为栈顶
            scopeItem = GetStackTopp(stack);
            code1 = TranslateExp(tree->lchild, new_temp2, stack, new_temp1, temp_num, label_num);
            scopeItem = GetStackTopp(stack);
            code2 = TranslateExp(tree->lchild->rchild->rchild, new_temp2, stack, new_temp2, temp_num, label_num);
            code3 = (TACCode*)malloc(sizeof(TACCode));
            code3->code.dest.Type = LABEL;
            code3->code.dest.Data.labelvalue = label_true;
            code3->code.firstOp.Type = VARIABLE;
            code3->code.firstOp.Data.variable = new_temp1;
            code3->code.secondOp.Type = VARIABLE;
            code3->code.secondOp.Data.variable = new_temp2;
            code3->line = tree->lchild->rchild->line;
            code3->prev = code3;
            if (tree->lchild->name == "OPLIGHT")
                code3->code.optype = IFLTGOTO;
            else if (tree->lchild->name == "OPLIGHTEQ" )
                code3->code.optype = IFLEGOTO;
            else if (tree->lchild->name == "OPGREAT")
                code3->code.optype = IFGTGOTO;
            else if (tree->lchild->name == "OPGREATEQ")
                code3->code.optype = IFGEGOTO;
            else if (tree->lchild->name == "OPEQUAL")
                code3->code.optype = IFEQGOTO;
            else if (tree->lchild->name == "OPNOTEQUAL")
                code3->code.optype = IFNEQGOTO;
            else
                code3 = TranslateExp(tree->lchild, new_temp2, stack, new_temp2, temp_num, label_num);
            code4 = (TACCode*)malloc(sizeof(TACCode));
            code4->code.optype = GOTO;
            code4->code.dest.Type = LABEL;
            code4->code.dest.Data.labelvalue = label_false;
            code4->line = tree->line;
            code4->prev = code4;
            return MergeTACItem(4, code1, code2, code3, code4);
        }
        else {
            ScopeItem  top2;
            string cache3;
            ScopeItem *new_temp3 = addIntoScope(scopeItem->stype, scopeItem, cache3, Variable, "temp", NULL);
            PopScopeStack(stack, &top2);
            PushScopeStack(stack, *new_temp3);     //把new_temp3作为栈顶
            return TranslateExp(tree->lchild, new_temp3, stack, new_temp3, temp_num, label_num);
        }
    }
}

TACCode*   BuildTAC(ASTTree* tree, ScopeItem *scopeItem, ScopeStack* stack,  unsigned int &temp_num, unsigned int &label_num){
    if (tree == NULL)
        return NULL;
    if (tree->name == "Compiler")
    {
        cout << "123";
        PushScopeStack(stack, *scopeItem);
        cout << "456";
        return BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num);
    }
    else if (tree->name == "CompUnits") {
        if (tree->lchild != NULL)
            return MergeTACItem(2, BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num), BuildTAC(tree->lchild->rchild, scopeItem, stack, temp_num, label_num));
        else
            return NULL;
    }
    else if (tree->name == "FuncDef")
    {
        TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
        TACCode* formalcode = NULL;
        TACCode* bodycode = NULL;
        //生成四元式部分
        tmp->code.optype = FUNCTIONDF;
        tmp->code.dest.Type = FUNCTION;
        tmp->code.dest.Data.function = TraverseScopeStack(stack, tree->GetID()); //根据ID找到对应的作用域
        tmp->line = tree->line;
        tmp->prev = tmp;
        formalcode = BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num);                    //形参四元式
        bodycode = BuildTAC(tree->lchild->rchild, scopeItem, stack, temp_num, label_num);              //函数体四元式
        //作用域栈操作部分
        if(tree->lchild->si)
            PushScopeStack(stack, *tree->lchild->si);
        if(tree->lchild->rchild->si)
            PushScopeStack(stack, *tree->lchild->rchild->si);
        return MergeTACItem(3, tmp, formalcode, bodycode);  //合并四元式
    }
    else if (tree->name == "FuncFParams") {
        if (tree->lchild == NULL) {
            return NULL;
        }
        else if (tree->lchild->rchild == NULL) {
            return BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num);
        }
        else {
            return MergeTACItem(2, BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num), BuildTAC(tree->lchild->rchild, scopeItem, stack, temp_num, label_num));
        }
    }
    else if (tree->name == "FuncFParam") { //ok
        //暂时没管数组
        TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.optype = PARAM;
        tmp->code.dest.Type = VARIABLE;
        tmp->code.dest.Data.variable = tree->si;
        tmp->code.dest.Data.variable = (ScopeItem*)malloc(sizeof(ScopeItem));
        *(tmp->code.dest.Data.variable)=*(tree->si);
        tmp->line = tree->line;
        tmp->prev = tmp;
        if (tree->lchild) {
            return MergeTACItem(2, tmp, BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num));
            //数组操作先这样写，不知道行不行
        }
        else {
            return tmp;
        }
    }
    else if (tree->name == "ConstDecl") {
        return MergeTACItem(2, BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num), BuildTAC(tree->lchild->rchild, scopeItem, stack, temp_num, label_num));
    }
    else if (tree->name == "VarDecl") {//ok
        cout << "789";
        return MergeTACItem(2, BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num), BuildTAC(tree->lchild->rchild, scopeItem, stack, temp_num, label_num));
    }
    else if (tree->name == "ConstDefs") {
        return MergeTACItem(2, BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num), BuildTAC(tree->lchild->rchild, scopeItem, stack, temp_num, label_num));
    }
    else if (tree->name == "VarDefs") {//ok
        cout << "101112";
        return MergeTACItem(2, BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num), BuildTAC(tree->lchild->rchild, scopeItem, stack, temp_num, label_num));
    }
    else if (tree->name == "ConstOpassign") {
        //没考虑数组
        return TranslateInitVal(tree->lchild->rchild, scopeItem, stack, TraverseScopeStack(stack, tree->lchild->GetID()), temp_num, label_num);
    }
    else if (tree->name == "VarOPassign") {     //ok
        //没考虑数组
        return MergeTACItem(2, BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num), TranslateInitVal(tree->lchild->rchild, scopeItem, stack, TraverseScopeStack(stack, tree->lchild->GetID()), temp_num, label_num));
    }
    else if (tree->name == "IDENTIFIER") {      //ok
        cout << "131415";
        TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.optype = PARAM;
        tmp->code.dest.Type = VARIABLE;
        tmp->code.dest.Data.variable = TraverseScopeStack(stack, tree->GetID());
        tmp->line = tree->line;
        tmp->prev = tmp;
        return tmp;
    }
    else if (tree->name == "FuncRParams") {
        return MergeTACItem(2, TranslateExp(tree->lchild, scopeItem, stack, TraverseScopeStack(stack, tree->lchild->GetID()), temp_num, label_num), TranslateExps(tree->lchild->rchild, scopeItem, stack, temp_num, label_num));
    }
    else if (tree->name == "ArrayDec") {
        //数组没写
    }
    else if (tree->name == "ArrayExps") {
        //数组没写
    }
    else if (tree->name == "BlockItems") {
        return MergeTACItem(2, BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num), BuildTAC(tree->lchild->rchild, scopeItem, stack, temp_num, label_num));
    }
    else if (tree->name == "Exp_Stmt") {
        scopeItem = GetStackTopp(stack);
        return TranslateExp(tree->lchild, scopeItem, stack, scopeItem, temp_num, label_num);//这里不知道第四个参数会不会出问题
    }
    else if (tree->name == "Block_Stmt") {
        return BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num);
    }
    else if (tree->name == "Block") {
        int flag = 0;
        // Judge if this block is function body
        if (tree->si != NULL && tree->si != GetStackTopp(stack)) {
            flag = 1;
            PushScopeStack(stack, *tree->si);
        }
        TACCode* BlockItems = (TACCode*)malloc(sizeof(TACCode));
        BlockItems = BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num);
        ScopeItem top;
        if (flag == 1) {
            PopScopeStack(stack, &top);
        }
        return BlockItems;
    }
    else if (tree->name == "Lval_Opassign_Stmt") {
        return TranslateExp(tree->lchild->rchild, tree->lchild->rchild->si, stack, tree->lchild->si, temp_num, label_num);
    }
    else if (tree->name == "Empty_Stmt") {
        return NULL;
    }
    else if (tree->name == "IF_Stmt") {
        cout << "pigpigpig" << endl;
        return TranslateStmt(tree, scopeItem, stack, -1, -1, temp_num, label_num);
    }
    else if (tree->name == "IF_ELSE_Stmt") {
        return TranslateStmt(tree, scopeItem, stack, -1, -1, temp_num, label_num);
    }
    else if (tree->name == "While_Stmt") {
        return TranslateStmt(tree, scopeItem, stack, -1, -1, temp_num, label_num);
    }
    else if (tree->name == "Break_Stmt") {
        return TranslateStmt(tree, scopeItem, stack, -1, -1, temp_num, label_num);
    }
    else if (tree->name == "Continue_Stmt") {
        return TranslateStmt(tree, scopeItem, stack, -1, -1, temp_num, label_num);
    }
    else if (tree->name == "Return_Stmt") {
        return TranslateStmt(tree, scopeItem, stack, -1, -1, temp_num, label_num);
    }
}
 
void DisplayTACCode(TACCode* entrance)
{
    int line = 1;
    TACCode* tmp = entrance;
    char cache[10];
    printf("\n~~~~TAC~~~~~\n");
    printf(" No  Source Position\tTACCode\n");
    printf("_______________________________________\n");
    printf("  0  (at line   0)\tCALL main\n");
    while (tmp)
    {
        if (tmp->code.optype == ASSIGN)
        {
            // Notice: no matter variable is in which scopeItem, the scopeItem entry always has "name" attribute
            printf("%3d  (at line %3d)\t%s := ", line, tmp->line, tmp->code.dest.Data.variable->name.c_str());
            if (tmp->code.firstOp.Type == VARIABLE)
                printf("%s\n", tmp->code.firstOp.Data.variable->name.c_str());
            else if (tmp->code.firstOp.Type == ADDRESSS)
                printf("*%s\n", tmp->code.firstOp.Data.variable->name.c_str());
            else if (tmp->code.firstOp.Type == INTEGERCONST)
                printf("#%d\n", tmp->code.firstOp.Data.value);
        }
        else if (tmp->code.optype == ADD | tmp->code.optype == SUB | tmp->code.optype == MUL | tmp->code.optype == DIV)
        {
            // Notice: no matter variable  is in which scopeItem, the scopeItem entry always has "name" attribute
            printf("%3d  (at line %3d)\t%s := ", line, tmp->line, tmp->code.dest.Data.variable->name.c_str());
            if (tmp->code.firstOp.Type == VARIABLE)
                printf("%s ", tmp->code.firstOp.Data.variable->name.c_str());
            else if (tmp->code.firstOp.Type == ADDRESSS)
                printf("*%s ", tmp->code.firstOp.Data.variable->name.c_str());
            else if (tmp->code.firstOp.Type == INTEGERCONST)
                printf("#%d ", tmp->code.firstOp.Data.value);
            switch (tmp->code.optype)
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
            if (tmp->code.secondOp.Type == VARIABLE)
                printf("%s\n", tmp->code.secondOp.Data.variable->depictor->name.c_str());
            else if (tmp->code.secondOp.Type == ADDRESSS)
                printf("*%s\n", tmp->code.secondOp.Data.variable->depictor->name.c_str());
            else if (tmp->code.secondOp.Type == INTEGERCONST)
                printf("#%d\n", tmp->code.secondOp.Data.value);
        }
        else if (tmp->code.optype == FUNCTIONDF)
            printf("\n%3d  (at line %3d)\tFUNCTION %s :\n", line, tmp->line, tmp->code.dest.Data.function->name.c_str());
        else if (tmp->code.optype == PARAM) {
            printf("%3d  (at line %3d)\tPARAM %s\n", line, tmp->line, tmp->code.dest.Data.variable->name.c_str());
        }
            
        else if (tmp->code.optype == LABELDF)
        {
            sprintf(cache, "label%d", tmp->code.dest.Data.labelvalue);
            printf("%3d  (at line %3d)\tLABEL %s :\n", line, tmp->line, cache);
        }
        else if (tmp->code.optype == IFLTGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.Data.labelvalue);
            printf("%3d  (at line %3d)\tIF %s < %s GOTO %s\n",
                line, tmp->line, tmp->code.firstOp.Data.variable->name.c_str(), tmp->code.secondOp.Data.variable->name.c_str(), cache);
        }
        else if (tmp->code.optype == IFLEGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.Data.labelvalue);
            printf("%3d (at line %3d)\tIF %s <= %s GOTO %s\n",
                line, tmp->line, tmp->code.firstOp.Data.variable->name.c_str(), tmp->code.secondOp.Data.variable->name.c_str(), cache);
        }
        else if (tmp->code.optype == IFGTGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.Data.labelvalue);
            printf("%3d  (at line %3d)\tIF %s > %s GOTO %s\n",
                line, tmp->line, tmp->code.firstOp.Data.variable->name.c_str(), tmp->code.secondOp.Data.variable->name.c_str(), cache);
        }
        else if (tmp->code.optype == IFGEGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.Data.labelvalue);
            printf("%3d  (at line %3d)\tIF %s >= %s GOTO %s\n",
                line, tmp->line, tmp->code.firstOp.Data.variable->name.c_str(), tmp->code.secondOp.Data.variable->name.c_str(), cache);
        }
        else if (tmp->code.optype == IFEQGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.Data.labelvalue);
            printf("%3d  (at line %3d)\tIF %s = %s GOTO %s\n",
                line, tmp->line, tmp->code.firstOp.Data.variable->name.c_str(), tmp->code.secondOp.Data.variable->name.c_str(), cache);
        }
        else if (tmp->code.optype == IFNEQGOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.Data.labelvalue);
            printf("%3d  (at line %3d)\tIF %s != ", line, tmp->line, tmp->code.firstOp.Data.variable->name.c_str());
            if (tmp->code.secondOp.Type == VARIABLE)
                printf("%s ", tmp->code.secondOp.Data.variable->name.c_str());
            else if (tmp->code.secondOp.Type == INTEGERCONST)
                printf("%d ", tmp->code.secondOp.Data.value);
            printf("GOTO %s\n", cache);
        }
        else if (tmp->code.optype == GOTO)
        {
            sprintf(cache, "label%d", tmp->code.dest.Data.labelvalue);
            printf("%3d  (at line %3d)\tGOTO %s\n", line, tmp->line, cache);
        }
        else if (tmp->code.optype == RETURN)
        {
            printf("%3d  (at line %3d)\tRETURN %s\n", line, tmp->line, tmp->code.dest.Data.variable->name.c_str());
        }
        else if (tmp->code.optype == ARG)
        {
            printf("%3d  (at line %3d)\tARG %s\n", line, tmp->line, tmp->code.dest.Data.variable->name.c_str());
        }
        else if (tmp->code.optype == CALLASSIGN)
        {
            printf("%3d  (at line %3d)\t%s := CALL %s\n", line, tmp->line, tmp->code.dest.Data.variable->name.c_str(), tmp->code.firstOp.Data.function->name.c_str());
        }
        else if (tmp->code.optype == CALL)
        {
            printf("%3d  (at line %3d)\tCALL %s\n", line, tmp->line, tmp->code.dest.Data.function->name.c_str());
        }
        tmp = tmp->next;
        line += 1;
    }
}
