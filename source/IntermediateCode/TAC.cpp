#include "TAC.h"





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

TACCode*  TranslateInitVal(ASTTree* tree, ScopeItem &offset, int &layer, ScopeItem &scopeItem, vector<ScopeItem> &stack, ScopeItem place, unsigned int &temp_num, unsigned int &label_num) {
    TACCode* code1, * code2, * code3;
    if (tree->name == "AutoInitVal") {
         string cache1 = "_t" + to_string(temp_num++);
         ScopeItem* new_temp1 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache1, Variable, "temp", NULL);
         stack.pop_back();
         stack.push_back(*new_temp1);
         code1 = TranslateExp(place.array_depictor->len[layer], *new_temp1, stack, *new_temp1, temp_num, label_num);  //第一维
         for (int k = layer + 1; k < place.array_depictor->dim; k++) {      //把后面每一维的Exp都乘起来
            string cache2 = "_t" + to_string(temp_num++);
            ScopeItem* new_temp2 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache2, Variable, "temp", NULL);
            stack.pop_back();
            stack.push_back(*new_temp2);
            code2= TranslateExp(place.array_depictor->len[k], *new_temp2, stack, *new_temp2, temp_num, label_num);  //第后面维
            code3 = (TACCode*)malloc(sizeof(TACCode));
            code3->code.optype = MUL;
            code3->code.dest.Type = VARIABLE;
            code3->code.dest.Data.variable = new_temp1;
            code3->code.firstOp.Type = VARIABLE;
            code3->code.firstOp.Data.variable = new_temp1;
            code3->code.secondOp.Type = VARIABLE;
            code3->code.secondOp.Data.variable = new_temp2;
            code3->line = tree->line;
            code3->prev = code3;
            code1= MergeTACItem(3, code1, code2, code3);
        }
         TACCode* code4, * code5, * code6, * code7, * code8, * code9;
         code4 = (TACCode*)malloc(sizeof(TACCode));
         code5 = (TACCode*)malloc(sizeof(TACCode));
         code6 = (TACCode*)malloc(sizeof(TACCode));
         code7 = (TACCode*)malloc(sizeof(TACCode));
         code8 = (TACCode*)malloc(sizeof(TACCode));
         code9 = (TACCode*)malloc(sizeof(TACCode));
         string cache3 = "_t" + to_string(temp_num++);
         ScopeItem* new_temp3 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache3, Variable, "temp", NULL);
         stack.pop_back();
         stack.push_back(*new_temp3);
         code4->code.optype = ASSIGN;
         code4->code.dest.Type = VARIABLE;
         code4->code.dest.Data.variable = new_temp3;
         code4->code.firstOp.Type = VARIABLE;
         code4->code.firstOp.Data.variable = new ScopeItem;
         *code4->code.firstOp.Data.variable = offset;
         Label label1 = label_num++;
         code5->code.optype = LABELDF;
         code5->code.dest.Type = LABEL;
         code5->code.dest.Data.labelvalue = label1;
         code6->code.optype = ASSIGN;
         code6->code.dest.Type = ARRAY;
         code6->code.dest.Data.array_add = new ARRAY_ADD;
         code6->code.dest.Data.array_add->array_si = new ScopeItem;
         *code6->code.dest.Data.array_add->array_si = place;
         code6->code.dest.Data.array_add->deviation = new_temp3;
         code6->code.firstOp.Type = INTEGERCONST;
         code6->code.firstOp.Data.value = 0;
         code7->code.optype = ADD;
         code7->code.dest.Type = VARIABLE;
         code7->code.dest.Data.variable = new_temp3;
         code7->code.firstOp.Type = VARIABLE;
         code7->code.firstOp.Data.variable = new_temp3;
         code7->code.secondOp.Type = INTEGERCONST;
         code7->code.secondOp.Data.value = 1;
         code8->code.optype = IFLTGOTO;
         code8->code.dest.Type = LABEL;
         code8->code.dest.Data.labelvalue = label1;
         code8->code.firstOp.Type = VARIABLE;
         code8->code.firstOp.Data.variable = new_temp3;
         code8->code.secondOp.Type = VARIABLE;
         code8->code.secondOp.Data.variable = new_temp1; 
         code9->code.optype = ADD;
         code9->code.dest.Type = VARIABLE;
         code9->code.dest.Data.variable = new ScopeItem;
         *code9->code.dest.Data.variable = offset;
         code9->code.firstOp.Type = VARIABLE;
         code9->code.firstOp.Data.variable = new ScopeItem;
         *code9->code.firstOp.Data.variable = offset;
         code9->code.secondOp.Type = VARIABLE;
         code9->code.secondOp.Data.variable = new_temp1;
         code4->line = tree->line;
         code4->prev = code4;
         code5->line = tree->line;
         code5->prev = code5;
         code6->line = tree->line;
         code6->prev = code6;
         code7->line = tree->line;
         code7->prev = code7;
         code8->line = tree->line;
         code8->prev = code8;
         code9->line = tree->line;
         code9->prev = code9;
         return MergeTACItem(6, code1, code4, code5, code6, code7, code8, code9);
        
    }
    else if (tree->name== "ExpInitval") {  //ok
        code1 = (TACCode*)malloc(sizeof(TACCode));
        code1->code.optype = ADD;
        code1->code.dest.Type = VARIABLE;
        code1->code.dest.Data.variable = new ScopeItem;
        *code1->code.dest.Data.variable = offset;
        code1->code.firstOp.Type = VARIABLE;
        code1->code.firstOp.Data.variable = new ScopeItem;
        *code1->code.firstOp.Data.variable = offset;
        code1->code.secondOp.Type = INTEGERCONST;
        code1->code.secondOp.Data.value = 1;
        code1->line = tree->line;
        code1->prev = code1;
        string cache1 = "_t" + to_string(temp_num++);
        ScopeItem* new_temp1 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache1, Variable, "temp", NULL);
        stack.pop_back();
        stack.push_back(*new_temp1);
        code3 = TranslateExp(tree->lchild, *new_temp1, stack, *new_temp1, temp_num, label_num);
        cout <<tree->lchild->lchild->int_value<< endl;
        code2 = (TACCode*)malloc(sizeof(TACCode));
        code2->code.optype = ASSIGN;
        code2->code.dest.Type = ARRAY;
        code2->code.dest.Data.array_add = new ARRAY_ADD;
        code2->code.dest.Data.array_add->array_si = new ScopeItem;
        *code2->code.dest.Data.array_add->array_si = place;
        code2->code.dest.Data.array_add->deviation = new ScopeItem;
        *code2->code.dest.Data.array_add->deviation = offset;
        code2->code.firstOp.Type = VARIABLE;
        code2->code.firstOp.Data.variable = new_temp1;
        code2->line = tree->line;
        code2->prev = code2;
        return  MergeTACItem(3, code3, code2, code1);
    }
    else {
        string cache1 = "_t" + to_string(temp_num++);
        ScopeItem* new_temp1 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache1, Variable, "temp", NULL);
        stack.pop_back();
        stack.push_back(*new_temp1);
        code1 = TranslateExp(place.array_depictor->len[layer], *new_temp1, stack, *new_temp1, temp_num, label_num);  //第一维
        for (int k = layer + 1; k < place.array_depictor->dim; k++) {      //把后面每一维的Exp都乘起来
            string cache2 = "_t" + to_string(temp_num++);
            ScopeItem* new_temp2 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache2, Variable, "temp", NULL);
            stack.pop_back();
            stack.push_back(*new_temp2);
            code2 = TranslateExp(place.array_depictor->len[k], *new_temp2, stack, *new_temp2, temp_num, label_num);  //第后面维
            code3 = (TACCode*)malloc(sizeof(TACCode));
            code3->code.optype = MUL;
            code3->code.dest.Type = VARIABLE;
            code3->code.dest.Data.variable = new_temp1;
            code3->code.firstOp.Type = VARIABLE;
            code3->code.firstOp.Data.variable = new_temp1;
            code3->code.secondOp.Type = VARIABLE;
            code3->code.secondOp.Data.variable = new_temp2;
            code3->line = tree->line;
            code3->prev = code3;
            code1 = MergeTACItem(3, code1, code2, code3);
        }
        TACCode* code4, * code5, * code6, * code7, * code8, * code9, * code10, * code11, * code12, * code13;
        code4 = (TACCode*)malloc(sizeof(TACCode));
        code7 = (TACCode*)malloc(sizeof(TACCode));
        code8 = (TACCode*)malloc(sizeof(TACCode));
        code9 = (TACCode*)malloc(sizeof(TACCode));
        code10 = (TACCode*)malloc(sizeof(TACCode));
        code11 = (TACCode*)malloc(sizeof(TACCode));
        code12 = (TACCode*)malloc(sizeof(TACCode));
        code13 = (TACCode*)malloc(sizeof(TACCode));
        string cache3 = "_t" + to_string(temp_num++);
        ScopeItem* new_temp3 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache3, Variable, "temp", NULL);
        stack.pop_back();
        stack.push_back(*new_temp3);
        code4->code.optype = ASSIGN;
        code4->code.dest.Type = VARIABLE;
        code4->code.dest.Data.variable = new_temp3;
        code4->code.firstOp.Type = VARIABLE;
        code4->code.firstOp.Data.variable = new ScopeItem;
        *code4->code.firstOp.Data.variable = offset;                        //new_temp3=offset前
        layer += 1;             //增加级数
        code5 = TranslateInitVal(tree->lchild, offset, layer, scopeItem, stack, place, temp_num, label_num);
        code6 = TranslateInitValList(tree->lchild->rchild, offset, layer, scopeItem, stack, place, temp_num, label_num);
        Label label1 = label_num++;
        Label label2 = label_num++;
        code7->code.optype = LABELDF;
        code7->code.dest.Type = LABEL;
        code7->code.dest.Data.labelvalue = label1;
        string cache4 = "_t" + to_string(temp_num++);
        ScopeItem* new_temp4 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache4, Variable, "temp", NULL);
        stack.pop_back();
        stack.push_back(*new_temp4);
        code8->code.optype = SUB;
        code8->code.dest.Type = VARIABLE;
        code8->code.dest.Data.variable = new_temp4;
        code8->code.firstOp.Type = VARIABLE;
        code8->code.firstOp.Data.variable = new ScopeItem;
        *code8->code.firstOp.Data.variable = offset;                      
        code8->code.secondOp.Type = VARIABLE;
        code8->code.secondOp.Data.variable = new_temp3;
        code9->code.optype = IFEQGOTO;
        code9->code.dest.Type = LABEL;
        code9->code.dest.Data.labelvalue = label2;
        code9->code.firstOp.Type = VARIABLE;
        code9->code.firstOp.Data.variable = new_temp4;
        code9->code.secondOp.Type = VARIABLE;
        code9->code.secondOp.Data.variable = new_temp1;
        code10->code.optype = ADD;
        code10->code.dest.Type = VARIABLE;
        code10->code.dest.Data.variable = new ScopeItem;
        *code10->code.dest.Data.variable = offset;
        code10->code.firstOp.Type = VARIABLE;
        code10->code.firstOp.Data.variable = new ScopeItem;
        *code10->code.firstOp.Data.variable = offset;
        code10->code.secondOp.Type = INTEGERCONST;
        code10->code.secondOp.Data.value = 1;
        code11->code.optype = ASSIGN;
        code11->code.dest.Type = ARRAY;
        code11->code.dest.Data.array_add = new ARRAY_ADD;
        code11->code.dest.Data.array_add->array_si = new ScopeItem;
        *code11->code.dest.Data.array_add->array_si = place;
        code11->code.dest.Data.array_add->deviation = new ScopeItem;
        *code11->code.dest.Data.array_add->deviation = offset;
        code11->code.firstOp.Type = INTEGERCONST;
        code11->code.firstOp.Data.value = 0;
        code12->code.optype = GOTO;
        code12->code.dest.Type = LABEL;
        code12->code.dest.Data.labelvalue = label1;
        code13->code.optype = LABELDF;
        code13->code.dest.Type = LABEL;
        code13->code.dest.Data.labelvalue = label2;
        code4->line = tree->line;
        code4->prev = code4;
        code7->line = tree->line;
        code7->prev = code7;
        code8->line = tree->line;
        code8->prev = code8;
        code9->line = tree->line;
        code9->prev = code9;
        code10->line = tree->line;
        code10->prev = code10;
        code11->line = tree->line;
        code11->prev = code11;
        code12->line = tree->line;
        code12->prev = code12;
        code13->line = tree->line;
        code13->prev = code13;
        return MergeTACItem(11, code1, code4, code5, code6, code7, code8, code9, code11, code10, code12, code13);   //我原地爆炸
    }
}

TACCode* TranslateInitValList(ASTTree* tree, ScopeItem& offset, int& layer, ScopeItem& scopeItem, vector<ScopeItem>& stack, ScopeItem place, unsigned int& temp_num, unsigned int& label_num) {
    if (tree == NULL) {
        return NULL;
    }
    else {
        return MergeTACItem(2, TranslateInitVal(tree->lchild, offset, layer, scopeItem, stack, place, temp_num, label_num), TranslateInitValList(tree->lchild->rchild, offset, layer, scopeItem, stack, place, temp_num, label_num));
    }
}

TACCode* TranslateLvalAssign(ASTTree* tree, ScopeItem& scopeItem, vector<ScopeItem>& stack, ScopeItem place, unsigned int& temp_num, unsigned int& label_num) {

    TACCode* code1, * code2;
    if (tree->lchild->rchild->lchild == NULL) {
        code1 = (TACCode*)malloc(sizeof(TACCode));
        code1->code.optype = ASSIGN;
        code1->code.dest.Type = VARIABLE;
        code1->code.dest.Data.variable = new ScopeItem;
        *(code1->code.dest.Data.variable) = TraverseScopeStack(stack, tree->lchild->GetID());
        code1->code.firstOp.Type = VARIABLE;
        code1->code.firstOp.Data.variable = new ScopeItem;
        *code1->code.firstOp.Data.variable = place;
        code1->line = tree->line;
        code1->prev = code1;
        return code1;
    }
    else {
        code1 = (TACCode*)malloc(sizeof(TACCode));
        code1->code.optype = ASSIGN;
        code1->code.dest.Type = ARRAY;
        code1->code.dest.Data.array_add = new ARRAY_ADD;
        code1->code.dest.Data.array_add->array_si = new ScopeItem;
        *(code1->code.dest.Data.array_add->array_si) = TraverseScopeStack(stack, tree->lchild->GetID());
        //ScopeItem* scope = GetStackTopp(stack);
        ARRAY_CODE arrayexp = TranslateArrayExps(tree->lchild->rchild, 0, tree->lchild->GetID(), scopeItem, stack, temp_num, label_num);
        code2 = arrayexp.code;
        code1->code.dest.Data.array_add->deviation = arrayexp.deviation;
        code1->code.firstOp.Data.variable = new ScopeItem;
        code1->code.firstOp.Type = VARIABLE;
        *code1->code.firstOp.Data.variable = place;
        code1->line = tree->line;
        code1->prev = code1;
        return MergeTACItem(2, code2, code1);
    }
}

ARRAY_CODE TranslateArrayExps(ASTTree* tree, int leng, string arrayname, ScopeItem& scopeItem, vector<ScopeItem>& stack, unsigned int& temp_num, unsigned int& label_num) {
    ARRAY_CODE arrayexp;
    TACCode* code1, * code2, * code3, * code4, * code5;
    string cache1 = "_t" + to_string(temp_num++);
    string cache2 = "_t" + to_string(temp_num++);
    ScopeItem* deviation = addIntoScope(stack.back().stype, stack.back().address, cache1, Variable, "temp", NULL);
    stack.pop_back();
    stack.push_back(*deviation);
    ScopeItem* size = addIntoScope(stack.back().stype, stack.back().address, cache2, Variable, "temp", NULL);
    stack.pop_back();
    stack.push_back(*size);
    if (tree->lchild == NULL) {
        arrayexp.code = NULL;
        arrayexp.deviation = NULL;
        arrayexp.size = NULL;
        return arrayexp;
    }
    if (tree->lchild->rchild->lchild == NULL) {     //卒
        string cache3 = "_t" + to_string(temp_num++);
        ScopeItem* new_temp = addIntoScope(stack.back().stype, stack.back().address, cache3, Variable, "temp", NULL);
        stack.pop_back();
        stack.push_back(*new_temp);
        code3 = TranslateExp(tree->lchild, *new_temp, stack, *new_temp, temp_num, label_num);
        string cache5 = "_t" + to_string(temp_num++);
        ScopeItem* new_temp3 = addIntoScope(stack.back().stype, stack.back().address, cache5, Variable, "temp", NULL);
        stack.pop_back();
        stack.push_back(*new_temp3);
        if (leng != 0) {
            ASTTree* lenexp = TraverseScopeStack(stack, arrayname).array_depictor->len[leng];
            code5 = TranslateExp(lenexp, *new_temp3, stack, *new_temp3, temp_num, label_num);
            code3->line = tree->line;
            code3->prev = code3;
            code5->line = tree->line;
            code5->prev = code5;
            arrayexp.code = MergeTACItem(2, code3, code5);
            arrayexp.deviation = new_temp;
            arrayexp.size = new_temp3;
            return arrayexp;
        }
        else {                      //第一维不用算长度
            arrayexp.code = code3;
            arrayexp.deviation = new_temp;
            arrayexp.size = NULL;
            return arrayexp;
        }

       
    }
    arrayexp = TranslateArrayExps(tree->lchild->rchild, leng + 1, arrayname, scopeItem, stack, temp_num, label_num);
    string cache3 = "_t" + to_string(temp_num++);
    ScopeItem* new_temp = addIntoScope(stack.back().stype, stack.back().address, cache3, Variable, "temp", NULL);
    stack.pop_back();
    stack.push_back(*new_temp);
    code3 = TranslateExp(tree->lchild, *new_temp, stack, *new_temp, temp_num, label_num);
    code1 = (TACCode*)malloc(sizeof(TACCode));
    code1->code.dest.Type = VARIABLE;
    code1->code.dest.Data.variable = deviation;
    code1->code.optype = MUL;
    code1->code.firstOp.Type = VARIABLE;
    code1->code.firstOp.Data.variable = new_temp;
    code1->code.secondOp.Type = VARIABLE;
    code1->code.secondOp.Data.variable = arrayexp.size;
    code2 = (TACCode*)malloc(sizeof(TACCode));
    code2->code.dest.Type = VARIABLE;
    code2->code.dest.Data.variable = deviation;
    code2->code.optype = ADD;
    code2->code.firstOp.Type = VARIABLE;
    code2->code.firstOp.Data.variable = deviation;
    code2->code.secondOp.Type = VARIABLE;
    code2->code.secondOp.Data.variable = arrayexp.deviation;   //计算偏移地址
    string cache4 = "_t" + to_string(temp_num++);
    ScopeItem* new_temp2 = addIntoScope(stack.back().stype, stack.back().address, cache4, Variable, "temp", NULL);
    stack.pop_back();
    stack.push_back(*new_temp2);
    if (leng != 0) {
        code4 = (TACCode*)malloc(sizeof(TACCode));
        code4->code.dest.Type = VARIABLE;
        code4->code.dest.Data.variable = size;
        code4->code.optype = MUL;
        code4->code.firstOp.Type = VARIABLE;
        code4->code.firstOp.Data.variable = arrayexp.size;
        code4->code.secondOp.Type = VARIABLE;
        string cache5 = "_t" + to_string(temp_num++);
        ScopeItem* new_temp3 = addIntoScope(stack.back().stype, stack.back().address, cache5, Variable, "temp", NULL);
        stack.pop_back();
        stack.push_back(*new_temp3);
        ASTTree* lenexp = TraverseScopeStack(stack, arrayname).array_depictor->len[leng];
        code5 = TranslateExp(lenexp, *new_temp3, stack, *new_temp3, temp_num, label_num);
        //我死了，怎么这么复杂，还要找符号表里面这一维的长度
        code4->code.secondOp.Data.variable = new_temp3;  //找到数组在符号表中的位置
        code1->line = tree->line;                       //prev和line赋值
        code1->prev = code1;
        code2->line = tree->line;
        code2->prev = code2;
        code3->line = tree->line;
        code3->prev = code3;
        code4->line = tree->line;
        code4->prev = code4;
        code5->line = tree->line;
        code5->prev = code5;
        arrayexp.code = MergeTACItem(6, arrayexp.code, code3, code1, code2, code5, code4);
        arrayexp.deviation = deviation;
        arrayexp.size = size;
        return arrayexp;
    }
    else {
        code1->line = tree->line;                       //prev和line赋值
        code1->prev = code1;
        code2->line = tree->line;
        code2->prev = code2;
        code3->line = tree->line;
        code3->prev = code3;
        arrayexp.code = MergeTACItem(4, arrayexp.code, code3, code1, code2);
        arrayexp.deviation = deviation;
        arrayexp.size = NULL;       //第一维不用计算长度
        return arrayexp;
    }
    
}

TACCode*  TranslateStmt(ASTTree* tree, ScopeItem &scopeItem, vector<ScopeItem> &stack, Label continuevalue, Label breakvalue,unsigned int &temp_num, unsigned int &label_num) {
    if (tree->name == "Empty_Stmt") {
        return NULL;
    }
    else if (tree->name == "IF_Stmt") {
        Label label1 = label_num++;
        Label label2 = label_num++;
        ASTTree* cond = tree->lchild;
        ASTTree* stmt = tree->lchild->rchild;
        //scopeItem = GetStackTopp(stack);
        TACCode* code1 = TranslateCondition(cond, stack.back(), stack, label1, label2, temp_num, label_num);
        //scopeItem = GetStackTopp(stack);
        TACCode* code2 = TranslateStmt(stmt, stack.back(), stack, continuevalue, breakvalue, temp_num, label_num);
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
        //scopeItem = GetStackTopp(stack);
        TACCode* code1 = TranslateCondition(cond, stack.back(), stack, label1, label2, temp_num, label_num);
        //scopeItem = GetStackTopp(stack);
        TACCode* code2 = TranslateStmt(stmt, stack.back(), stack, continuevalue, breakvalue, temp_num, label_num);
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
        //scopeItem = GetStackTopp(stack);
        TACCode* code5 = TranslateStmt(stmt->rchild, stack.back(), stack, continuevalue, breakvalue, temp_num, label_num);
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
        //scopeItem = GetStackTopp(stack);
        TACCode* code2 = TranslateCondition(cond, stack.back(), stack, label2, label3, temp_num, label_num);
        TACCode* code3 = (TACCode*)malloc(sizeof(TACCode));
        //scopeItem = GetStackTopp(stack);
        TACCode* code4 = TranslateStmt(stmt, stack.back(), stack, label1, label3, temp_num, label_num);
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
        code1->prev = code1;
        return code1;
    }
    else if (tree->name == "Continue_Stmt") {
        TACCode* code1 = (TACCode*)malloc(sizeof(TACCode));
        code1->code.optype = GOTO;
        code1->code.dest.Type = LABEL;
        code1->code.dest.Data.labelvalue = continuevalue;
        code1->prev = code1;
        return code1;
    }
    else if (tree->name == "Return_Stmt") {
        ASTTree* expr = tree->lchild;
        if (expr == NULL) {
            return NULL;
        }
        string cache;
        TACCode* code1;
        TACCode* code2 = (TACCode*)malloc(sizeof(TACCode));
        cache = "_t" + to_string(temp_num++);
        //作用域操作
        //
        //ScopeItem* scope = GetStackTopp(stack);
        ScopeItem* new_temp= addIntoScope(Local, stack.back().address, cache, Variable, "temp" , NULL);
        stack.pop_back();
        stack.push_back(*new_temp);
        code1 = TranslateExp(expr, *new_temp, stack, *new_temp, temp_num, label_num);
        code2->code.optype = RETURN;
        code2->code.dest.Type = VARIABLE;
        code2->code.dest.Data.variable = new_temp;
        code2->line = tree->lchild->line;
        code2->prev = code2;
        return MergeTACItem(2, code1, code2);
    }
    else if (tree->name == "Block_Stmt") {
        return BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num);
    }
}

TACCode*  TranslateExps(ASTTree* tree, ScopeItem &scopeItem, vector<ScopeItem> &stack, unsigned int &temp_num, unsigned int &label_num){
    if (tree==NULL) {
        return NULL;
    }
    else
    {
        string cache;

        TACCode* code1, * code2;
        cache = "_t" + to_string(temp_num++);
        //ScopeItem* scope = GetStackTopp(stack);
        ScopeItem *new_temp = addIntoScope(Local, stack.back().address, cache, Variable, "temp", NULL);
        stack.pop_back();
        stack.push_back(*new_temp);
        code1 = TranslateExp(tree->lchild, *new_temp, stack, *new_temp, temp_num, label_num);
        code2 = TranslateExps(tree->lchild->rchild, scopeItem, stack, temp_num, label_num);
        return MergeTACItem(2, code1, code2);
    }
}

TACCode*  TranslateExp(ASTTree* tree, ScopeItem &scopeItem, vector<ScopeItem> &stack, ScopeItem place, unsigned int &temp_num, unsigned int &label_num){
    if (tree->name=="IntConst")   //ok
    {
        TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.optype = ASSIGN;
        tmp->code.dest.Type = VARIABLE;
        tmp->code.dest.Data.variable = new ScopeItem;
        *(tmp->code.dest.Data.variable) = place;
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
        tmp->code.dest.Data.variable = new ScopeItem;
        *(tmp->code.dest.Data.variable) = place;
        ScopeItem result = TraverseScopeStack(stack, tree->lchild->lchild->GetID());
        if (result.category == VARIABLE) {     //如果不是数组
            tmp->code.firstOp.Type = VARIABLE;
            tmp->code.firstOp.Data.variable = new ScopeItem;
            *(tmp->code.firstOp.Data.variable) = TraverseScopeStack(stack, tree->lchild->lchild->GetID());
            tmp->line = tree->line;
            tmp->prev = tmp;
            return tmp;
        }
        else {  //数组
            tmp->code.firstOp.Type = ARRAY;
            tmp->code.firstOp.Data.array_add = new ARRAY_ADD;
            tmp->code.firstOp.Data.array_add->array_si = new ScopeItem;
            *(tmp->code.firstOp.Data.array_add->array_si) = TraverseScopeStack(stack, tree->lchild->lchild->GetID());
            ARRAY_CODE arrays = TranslateArrayExps(tree->lchild->lchild->rchild, 0, tree->lchild->lchild->GetID(), scopeItem, stack, temp_num, label_num);
            tmp->code.firstOp.Data.array_add->deviation = arrays.deviation;
            tmp->line = tree->line;
            tmp->prev = tmp;
            return MergeTACItem(2, arrays.code, tmp);
        }
    }
    else if (tree->name == "funcall")
    {
        ScopeItem function = TraverseScopeStack(stack, tree->lchild->GetID());
        ScopeItem* origin = stack.back().address;
        ASTTree* actuals = tree->lchild->rchild;
        TACCode* code1 = TranslateFuncRParams(actuals, stack.back(), stack, temp_num, label_num);
        TACCode* code2 = NULL;
        TACCode* tmp = NULL;
        code2 = (TACCode*)malloc(sizeof(TACCode));
        code2->code.optype = CALLASSIGN;
        code2->code.dest.Type = VARIABLE;
        code2->code.dest.Data.variable = new ScopeItem;
        *(code2->code.dest.Data.variable)=place;
        code2->code.firstOp.Type = FUNCTION;
        code2->code.firstOp.Data.function  = new ScopeItem;
        *(code2->code.firstOp.Data.function)= function;
        code2->line = tree->lchild->line;
        code2->prev = code2;
        return MergeTACItem(2, code1, code2);
    }
    else if (tree->name == "OPPLUS_Exp") {
        string cache;
        TACCode* tmp;
        cache = "_t" + to_string(temp_num++);
        //ScopeItem* scope = GetStackTopp(stack);
        ScopeItem *new_temp = addIntoScope(Local, stack.back().address, cache, Variable, "temp", NULL);
        stack.pop_back();
        stack.push_back(*new_temp);
        tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.optype = ADD;
        tmp->code.dest.Type = VARIABLE;
        tmp->code.dest.Data.variable = new ScopeItem;
        *(tmp->code.dest.Data.variable)= place;
        tmp->code.firstOp.Type = INTEGERCONST;
        tmp->code.firstOp.Data.value = 0;
        tmp->code.secondOp.Type = VARIABLE;
        tmp->code.secondOp.Data.variable = new_temp;
        tmp->line = tree->lchild->line;
        tmp->prev = tmp;
        return MergeTACItem(2, TranslateExp(tree->lchild, *new_temp, stack, *new_temp, temp_num, label_num), tmp);
    }
    else if (tree->name == "OPMINUS_Exp") {
        string cache;
        TACCode* tmp;
        cache = "_t" + to_string(temp_num++);
        //ScopeItem* scope = GetStackTopp(stack);
        ScopeItem *new_temp = addIntoScope(Local, stack.back().address, cache, Variable, "temp", NULL);
        stack.pop_back();
        stack.push_back(*new_temp);
        tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.optype = SUB;
        tmp->code.dest.Type = VARIABLE;
        tmp->code.dest.Data.variable = new ScopeItem;
        *(tmp->code.dest.Data.variable)= place;
        tmp->code.firstOp.Type = INTEGERCONST;
        tmp->code.firstOp.Data.value = 0;
        tmp->code.secondOp.Type = VARIABLE;
        tmp->code.secondOp.Data.variable = new_temp;
        tmp->line = tree->lchild->line;
        tmp->prev = tmp;
        return MergeTACItem(2, TranslateExp(tree->lchild, *new_temp, stack, *new_temp, temp_num, label_num), tmp);
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
        code0->code.dest.Data.variable =  new ScopeItem;
        *(code0->code.dest.Data.variable)=place;
        code0->code.firstOp.Type = INTEGERCONST;
        code0->code.firstOp.Data.value = 0;
        code0->line = tree->lchild->line;
        code0->prev = code0;
        code1 = TranslateCondition(tree, scopeItem, stack, label2, label1, temp_num, label_num);
        code2->code.optype = LABELDF;
        code2->code.dest.Type = LABEL;
        code2->code.dest.Data.labelvalue = label1;
        code2->line = tree->lchild->line;
        code2->prev = code2;
        code3->code.optype = ASSIGN;
        code3->code.dest.Type = VARIABLE;
        code3->code.dest.Data.variable =  new ScopeItem;
        *(code3->code.dest.Data.variable)= place;
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
    || tree->name == "PLUSExp" || tree->name == "MINUSExp" || tree->name == "MODExp") {
    string cache1, cache2;
    TACCode* code1, * code2, * code3;
    cache1 = "_t" + to_string(temp_num++);
    cache2 = "_t" + to_string(temp_num++);
    ScopeItem* new_temp1 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache1, Variable, "temp", NULL);
    stack.pop_back();
    stack.push_back(*new_temp1);
    ScopeItem* new_temp2 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache2, Variable, "temp", NULL);
    stack.pop_back();
    stack.push_back(*new_temp2);
    code1 = TranslateExp(tree->lchild, *new_temp2, stack, *new_temp1, temp_num, label_num);
    code2 = TranslateExp(tree->lchild->rchild, *new_temp2, stack, *new_temp2, temp_num, label_num);
    code3 = (TACCode*)malloc(sizeof(TACCode));
    if (tree->name == "PLUSExp")
        code3->code.optype = ADD;
    else if (tree->name == "MINUSExp")
        code3->code.optype = SUB;
    else if (tree->name == "MulExp")
        code3->code.optype = MUL;
    else if (tree->name == "DIVIDEExp")
        code3->code.optype = DIV;
    else if (tree->name == "MODExp") {
        code3->code.optype = MOD;
    }
    code3->code.dest.Type = VARIABLE;
    code3->code.dest.Data.variable = new ScopeItem;
    *(code3->code.dest.Data.variable) = place;
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
    ScopeItem* new_temp = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache, Variable, "temp", NULL);
    stack.pop_back();
    stack.push_back(*new_temp);
    tmp = (TACCode*)malloc(sizeof(TACCode));
    tmp->code.optype = ASSIGN;
    tmp->code.dest.Type = VARIABLE;
    tmp->code.dest.Data.variable = new ScopeItem;
    *(tmp->code.dest.Data.variable) = place;
    tmp->code.firstOp.Type = VARIABLE;
    tmp->code.firstOp.Data.variable = new_temp;
    tmp->line = tree->line;
    tmp->prev = tmp;
    //scopeItem = GetStackTopp(stack);
    return MergeTACItem(2, TranslateExp(tree->lchild, *new_temp, stack, *new_temp, temp_num, label_num), tmp);
    }
    return NULL;
}

TACCode* TranslateFuncRParams(ASTTree* tree, ScopeItem& scopeItem, vector<ScopeItem>& stack, unsigned int& temp_num, unsigned int& label_num) {
    if (tree == NULL) {
        return NULL;
    }
    if (tree->line == -1)
        return NULL;
    else
    {

        string cache1 = "_t" + to_string(temp_num++);
        TACCode* code2 = (TACCode*)malloc(sizeof(TACCode));
        if (tree->lchild->name != "LVal_EXP" || TraverseScopeStack(stack, tree->lchild->lchild->GetID()).category == VARIABLE) {
            ScopeItem* new_temp1 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache1, Variable, "temp", NULL);
            stack.pop_back();
            stack.push_back(*new_temp1);
            code2->code.optype = ARG;
            code2->code.dest.Type = VARIABLE;
            code2->code.dest.Data.variable = new ScopeItem;
            *(code2->code.dest.Data.variable) = *new_temp1;
            code2->line = tree->lchild->line;
            code2->prev = code2;
            return MergeTACItem(3, TranslateExp(tree->lchild, *new_temp1, stack, *new_temp1, temp_num, label_num), TranslateFuncRParams(tree->lchild->rchild, scopeItem, stack, temp_num, label_num), code2);
        }
        else {
            code2->code.optype = ARG;
            code2->code.dest.Type = ARRAY;
            code2->code.dest.Data.array_add = new ARRAY_ADD;
            code2->code.dest.Data.array_add->array_si = new ScopeItem;
            *code2->code.dest.Data.array_add->array_si = TraverseScopeStack(stack, tree->lchild->lchild->GetID());
            TACCode* code3, * code4, * code5;
            string cache1 = "_t" + to_string(temp_num++);
            ScopeItem* new_temp1;
            if (TraverseScopeStack(stack, tree->lchild->lchild->GetID()).array_depictor->len[0] == NULL){   //该数组为函数形参
                code3 = NULL;
                new_temp1 = NULL;
            }
            else {
                new_temp1 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache1, Variable, "temp", NULL);
                stack.pop_back();
                stack.push_back(*new_temp1);
                code3 = TranslateExp(TraverseScopeStack(stack, tree->lchild->lchild->GetID()).array_depictor->len[0], *new_temp1, stack, *new_temp1, temp_num, label_num);  //第一维
                for (int k = 1; k < TraverseScopeStack(stack, tree->lchild->lchild->GetID()).array_depictor->dim; k++) {      //把后面每一维的Exp都乘起来
                    string cache2 = "_t" + to_string(temp_num++);
                    ScopeItem* new_temp2 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache2, Variable, "temp", NULL);
                    stack.pop_back();
                    stack.push_back(*new_temp2);
                    code4 = TranslateExp(TraverseScopeStack(stack, tree->lchild->lchild->GetID()).array_depictor->len[k], *new_temp2, stack, *new_temp2, temp_num, label_num);  //第后面维
                    code5 = (TACCode*)malloc(sizeof(TACCode));
                    code5->code.optype = MUL;
                    code5->code.dest.Type = VARIABLE;
                    code5->code.dest.Data.variable = new_temp1;
                    code5->code.firstOp.Type = VARIABLE;
                    code5->code.firstOp.Data.variable = new_temp1;
                    code5->code.secondOp.Type = VARIABLE;
                    code5->code.secondOp.Data.variable = new_temp2;
                    code5->line = tree->line;
                    code5->prev = code5;
                    code3 = MergeTACItem(3, code3, code4, code5);
                }
            }
            code2->code.dest.Data.array_add->deviation = new_temp1;
            code2->line = tree->line;
            code2->prev = code2;
            return MergeTACItem(3, code3, TranslateFuncRParams(tree->lchild->rchild, scopeItem, stack, temp_num, label_num), code2);
        } 
    }
}

TACCode*  TranslateCondition(ASTTree* tree, ScopeItem &scopeItem, vector<ScopeItem> &stack, unsigned int label_true, unsigned int label_false, unsigned int &temp_num, unsigned int &label_num){
    if (tree->name=="Cond_And")
    {
        Label label = label_num++;
        TACCode* code1 = TranslateCondition(tree->lchild, scopeItem, stack, label, label_false, temp_num, label_num);
        TACCode* code2 = TranslateCondition(tree->lchild->rchild, scopeItem, stack, label_true, label_false, temp_num, label_num);
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
        //peItem = GetStackTopp(stack);
        TACCode* code1 = TranslateCondition(tree->lchild, stack.back(), stack, label_true, label, temp_num, label_num);
        //scopeItem = GetStackTopp(stack);
        TACCode* code2 = TranslateCondition(tree->lchild->rchild, stack.back(), stack, label_true, label_false, temp_num, label_num);
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
            ScopeItem* new_temp1 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache1, Variable, "temp", NULL);
            stack.pop_back();
            stack.push_back(*new_temp1);
            code1= TranslateRelExp(tree->lchild, scopeItem, stack, *new_temp1, label_true, label_false, temp_num, label_num);
            cache2 = "_t" + to_string(temp_num++);
            ScopeItem* new_temp2 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache2, Variable, "temp", NULL);
            stack.pop_back();
            stack.push_back(*new_temp2);
            //PushScopeStack(stack, *new_temp2);     //把new_temp2作为栈顶
            //scopeItem = GetStackTopp(stack);
            code2 = TranslateExp(tree->lchild->lchild->rchild, *new_temp2, stack, *new_temp2, temp_num, label_num);
            code3 = (TACCode*)malloc(sizeof(TACCode));
            code3->code.dest.Type = LABEL;
            code3->code.dest.Data.labelvalue = label_true;
            code3->code.firstOp.Type = VARIABLE;
            code3->code.firstOp.Data.variable = new_temp1;
            code3->code.secondOp.Type = VARIABLE;
            code3->code.secondOp.Data.variable = new_temp2;
            code3->line = tree->lchild->line;
            code3->prev = code3;
            if (tree->lchild->name == "OPLIGHT")
               code3->code.optype = IFLTGOTO;
            else if (tree->lchild->name == "OPLIGHTEQ")
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
               code3 = TranslateExp(tree->lchild, *new_temp2, stack, *new_temp2, temp_num, label_num);
            code4 = (TACCode*)malloc(sizeof(TACCode));
            code4->code.optype = GOTO;
            code4->code.dest.Type = LABEL;
            code4->code.dest.Data.labelvalue = label_false;
            code4->line = tree->line;
            code4->prev = code4;
            return MergeTACItem(4, code1, code2, code3, code4);
        }
        else {//为EXP
            ScopeItem  top2;
            string cache3;
            cache3 = "_t" + to_string(temp_num++);
            ScopeItem *new_temp3 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache3, Variable, "temp", NULL);
            stack.pop_back();
            stack.push_back(*new_temp3);
            code1 = TranslateExp(tree->lchild, *new_temp3, stack, *new_temp3, temp_num, label_num);
            code2 = (TACCode*)malloc(sizeof(TACCode));
            code2->code.optype = IFNEQGOTO;
            code2->code.dest.Type = LABEL;
            code2->code.dest.Data.labelvalue = label_true;
            code2->code.firstOp.Type = VARIABLE;
            code2->code.firstOp.Data.variable = new_temp3;
            code2->code.secondOp.Type = INTEGERCONST;
            code2->code.secondOp.Data.value = 0;
            code2->line = tree->lchild->line;
            code2->prev = code2;
            code3 = (TACCode*)malloc(sizeof(TACCode));
            code3->code.optype = GOTO;
            code3->code.dest.Type = LABEL;
            code3->code.dest.Data.labelvalue = label_false;
            code3->line = tree->line;
            code3->prev = code3;
            return MergeTACItem(3, code1, code2, code3);
        }
    }
}

TACCode* TranslateRelExp(ASTTree* tree, ScopeItem& scopeItem, vector<ScopeItem>& stack, ScopeItem place, unsigned int label_true, unsigned int label_false, unsigned int& temp_num, unsigned int& label_num) {
    string cache1, cache2;
    ScopeItem top;
    TACCode* code1, * code2, * code3, * code4;
    if (tree->name == "OPLIGHT" || tree->name == "OPGREAT" || tree->name == "OPGREATEQ" ||
        tree->name == "OPLIGHTEQ" || tree->name == "OPEQUAL" || tree->name == "OPNOTEQUAL") {
        cache1 = "_t" + to_string(temp_num++);
        cache2 = "_t" + to_string(temp_num++);
        if (tree->lchild->name == "OPLIGHT" || tree->lchild->name == "OPGREAT" || tree->lchild->name == "OPGREATEQ" ||
            tree->lchild->name == "OPLIGHTEQ" || tree->lchild->name == "OPEQUAL" || tree->lchild->name == "OPNOTEQUAL") {
            ScopeItem* new_temp1 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache1, Variable, "temp", NULL);
            stack.pop_back();
            stack.push_back(*new_temp1);
            //PopScopeStack(stack, &top);
            ScopeItem* new_temp2 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache2, Variable, "temp", NULL);
            stack.pop_back();
            stack.push_back(*new_temp2);
            code1= TranslateRelExp(tree->lchild, scopeItem, stack, *new_temp1, label_true, label_false, temp_num, label_num);
        }
        else {
            code1= TranslateExp(tree->lchild, scopeItem, stack, place, temp_num, label_num);
        }
        return code1;
    }
}

TACCode*   BuildTAC(ASTTree* tree, ScopeItem &scopeItem, vector<ScopeItem> &stack,  unsigned int &temp_num, unsigned int &label_num){
    if (tree == NULL)
        return NULL;
    if (tree->name == "Compiler")
    {
        //PushScopeStack(stack, *scopeItem);
        stack.push_back(scopeItem);
        return BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num);
    }
    else if (tree->name == "CompUnits") {
        if (tree->lchild != NULL) {
            return MergeTACItem(2, BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num), BuildTAC(tree->lchild->rchild, scopeItem, stack, temp_num, label_num));
        }
        else
            return NULL;
    }
    else if (tree->name == "FuncDef")
    {
        bool flag = 0;
        TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
        TACCode* formalcode = NULL;
        TACCode* bodycode = NULL;
        //生成四元式部分
        tmp->code.optype = FUNCTIONDF;
        tmp->code.dest.Type = FUNCTION;
        tmp->code.dest.Data.function = new ScopeItem;
        *(tmp->code.dest.Data.function) = TraverseScopeStack(stack, tree->GetID());//根据ID找到对应的作用域
        tmp->line = tree->line;
        tmp->prev = tmp;
        //作用域栈操作部分
        /*
        if (tree->si) {
            flag = 1;
            stack.push_back(*(tree->si));
        }
        if (tree->lchild->si->category != NOParam|| tree->lchild->si->depictor) {
            //PushScopeStack(stack, *tree->lchild->si);
            stack.push_back(*tree->lchild->si);
            stack.push_back(*tree->lchild->si->depictor);
            flag = 1;
        }
        formalcode = BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num);                    //形参四元式
        bodycode = BuildTAC(tree->lchild->rchild, scopeItem, stack, temp_num, label_num);              //函数体四元式
        if (flag) {
            stack.pop_back();
            stack.pop_back();
        }*/
        if (tree->lchild->si->category != NOParam || tree->lchild->si->depictor) {
            //PushScopeStack(stack, *tree->lchild->si);
            stack.push_back(*mergeScope(tree->lchild->si, tree->lchild->si->depictor));
            flag = 1;
        }
        formalcode = BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num);                    //形参四元式
        bodycode = BuildTAC(tree->lchild->rchild, scopeItem, stack, temp_num, label_num);              //函数体四元式
        if (flag)
            stack.pop_back();
        return MergeTACItem(3, tmp, formalcode, bodycode);  //合并四元式
    }
    else if (tree->name == "FuncFParams") {
        /*
        if (tree->lchild == NULL) {
            return NULL;
        }
        else if (tree->lchild->rchild == NULL) {
            return BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num);
        }
        else {
        */
        return MergeTACItem(2, BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num), BuildTAC(tree->lchild->rchild, scopeItem, stack, temp_num, label_num));
        //}
    }
    else if (tree->name == "FuncFParam") { //非数组形参
        TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
        tmp->code.optype = PARAM;
        tmp->code.dest.Type = VARIABLE;
        tmp->code.dest.Data.variable = tree->si;
        tmp->code.dest.Data.variable = new ScopeItem;
        *(tmp->code.dest.Data.variable)=*(tree->si);
        tmp->line = tree->line;
        tmp->prev = tmp;
        return tmp;
    }
    else if (tree->name == "ArrayFuncFParam") { //数组形参
        TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
        TACCode* code1, * code2, * code3;
        tmp->code.optype = PARAM;
        tmp->code.dest.Type = ARRAY;
        tmp->code.dest.Data.array_add = new ARRAY_ADD;
        tmp->code.dest.Data.array_add->array_si = tree->si;//开始求数组空间
        string cache1 = "_t" + to_string(temp_num++);
        ScopeItem* new_temp1 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache1, Variable, "temp", NULL);
        stack.pop_back();
        stack.push_back(*new_temp1);
        if (tree->si->array_depictor->dim > 1) {
            code1 = TranslateExp(tree->si->array_depictor->len[1], *new_temp1, stack, *new_temp1, temp_num, label_num);  //第一维
            for (int k = 2; k < tree->si->array_depictor->dim; k++) {      //把后面每一维的Exp都乘起来
                string cache2 = "_t" + to_string(temp_num++);
                ScopeItem* new_temp2 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache2, Variable, "temp", NULL);
                stack.pop_back();
                stack.push_back(*new_temp2);
                code2 = TranslateExp(tree->si->array_depictor->len[k], *new_temp2, stack, *new_temp2, temp_num, label_num);  //第后面维
                code3 = (TACCode*)malloc(sizeof(TACCode));
                code3->code.optype = MUL;
                code3->code.dest.Type = VARIABLE;
                code3->code.dest.Data.variable = new_temp1;
                code3->code.firstOp.Type = VARIABLE;
                code3->code.firstOp.Data.variable = new_temp1;
                code3->code.secondOp.Type = VARIABLE;
                code3->code.secondOp.Data.variable = new_temp2;
                code3->line = tree->line;
                code3->prev = code3;
                code1 = MergeTACItem(3, code1, code2, code3);
            }
            tmp->code.dest.Data.array_add->deviation = new_temp1;
            tmp->line = tree->line;
            tmp->prev = tmp;
            return MergeTACItem(2, code1, tmp);
        }
        else {
            TACCode* tmp = (TACCode*)malloc(sizeof(TACCode));
            tmp->code.optype = PARAM;
            tmp->code.dest.Type = ARRAY;
            tmp->code.dest.Data.array_add = new ARRAY_ADD;
            tmp->code.dest.Data.array_add->array_si = tree->si;//开始求数组空间
            tmp->code.dest.Data.array_add->deviation = NULL;        //a[]作为参数,deviation为NULL
            tmp->line = tree->line;
            tmp->prev = tmp;
            return tmp;
        }


        
    }
    else if (tree->name == "NOFParam") {
        return NULL;
    }
    else if (tree->name == "ConstDecl") {
        return MergeTACItem(2, BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num), BuildTAC(tree->lchild->rchild, scopeItem, stack, temp_num, label_num));
    }
    else if (tree->name == "VarDecl") {//ok
        return MergeTACItem(2, BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num), BuildTAC(tree->lchild->rchild, scopeItem, stack, temp_num, label_num));
    }
    else if (tree->name == "ConstDefs") {
        return MergeTACItem(2, BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num), BuildTAC(tree->lchild->rchild, scopeItem, stack, temp_num, label_num));
    }
    else if (tree->name == "VarDefs") {//ok
        return MergeTACItem(2, BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num), BuildTAC(tree->lchild->rchild, scopeItem, stack, temp_num, label_num));
    }
    else if (tree->name == "ConstOpassign") {
        if (tree->lchild->rchild->name == "ExpInitval") {
            return  MergeTACItem(2, BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num), TranslateExp(tree->lchild->rchild->lchild, scopeItem, stack, TraverseScopeStack(stack, tree->lchild->GetID()), temp_num, label_num));
        }
        else {
            string cache1 = "_t" + to_string(temp_num++);
            ScopeItem* new_temp1 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache1, Variable, "temp", NULL);
            stack.pop_back();
            stack.push_back(*new_temp1);
            TACCode* codex = (TACCode*)malloc(sizeof(TACCode));
            codex->code.optype = ASSIGN;
            codex->code.dest.Type = VARIABLE;
            codex->code.dest.Data.variable = new_temp1;
            codex->code.firstOp.Type = INTEGERCONST;
            codex->code.firstOp.Data.value = 0;
            codex->line = tree->line;
            codex->prev = codex;
            int layer = 0;
            return MergeTACItem(3, BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num), codex, TranslateInitVal(tree->lchild->rchild, *new_temp1, layer, scopeItem, stack, TraverseScopeStack(stack, tree->lchild->GetID()), temp_num, label_num));
        }
    }
    else if (tree->name == "VarOPassign") {     //ok
        if (tree->lchild->rchild->name== "ExpInitval") {

            return  MergeTACItem(2, BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num), TranslateExp(tree->lchild->rchild->lchild, scopeItem, stack, TraverseScopeStack(stack, tree->lchild->GetID()), temp_num, label_num));
        }
        else {
            string cache1 = "_t" + to_string(temp_num++);
            ScopeItem* new_temp1 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache1, Variable, "temp", NULL);
            stack.pop_back();
            stack.push_back(*new_temp1);
            TACCode* codex = (TACCode*)malloc(sizeof(TACCode));
            codex->code.optype = ASSIGN;
            codex->code.dest.Type = VARIABLE;
            codex->code.dest.Data.variable = new_temp1;
            codex->code.firstOp.Type = INTEGERCONST;
            codex->code.firstOp.Data.value = 0;
            codex->line = tree->line;
            codex->prev = codex;
            int layer = 0;
            return MergeTACItem(3, BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num), codex, TranslateInitVal(tree->lchild->rchild, *new_temp1, layer, scopeItem, stack, TraverseScopeStack(stack, tree->lchild->GetID()), temp_num, label_num));
        }
    }
    else if (tree->name == "IDENTIFIER") {      //ok
        return NULL;
    }
    else if (tree->name == "FuncRParams") {
        return MergeTACItem(2, TranslateExp(tree->lchild, scopeItem, stack, TraverseScopeStack(stack, tree->lchild->GetID()), temp_num, label_num), TranslateExps(tree->lchild->rchild, scopeItem, stack, temp_num, label_num));
    }
    else if (tree->name == "ArrayDec") {
        return NULL;            //数组定义返回NULL
    }
    else if (tree->name == "ArrayExps") {
        if (tree->lchild == NULL)
        {
            return NULL;
        }
        else {
            cout << "我自闭了为啥到这了" << endl;
            //数组没写
        }
    }
    else if (tree->name == "BlockItems") {
        return MergeTACItem(2, BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num), BuildTAC(tree->lchild->rchild, scopeItem, stack, temp_num, label_num));
    }
    else if (tree->name == "Exp_Stmt") {
        ScopeItem variable;
        ScopeItem function = TraverseScopeStack(stack, tree->lchild->lchild->GetID());
        ScopeItem* origin = stack.back().address;
        ASTTree* actuals = tree->lchild->lchild->rchild;
        //scopeItem = GetStackTopp(stack);
        TACCode* code1 = TranslateFuncRParams(actuals, stack.back(), stack, temp_num, label_num);
        ScopeItem* current = stack.back().address;
        TACCode* code2 = NULL;
        TACCode* code3 = NULL;
        TACCode* tmp = NULL;
        /*
        variable.type = Local;
        while (!(*current == *origin) && current != NULL)
        {
            if (code2 == NULL)
            {
                code2 = (TACCode*)malloc(sizeof(TACCode));
                code2->code.optype = ARG;
                code2->code.dest.Type = VARIABLE;
                variable.depictor = current;
                code2->code.dest.Data.variable = new ScopeItem;
                *(code2->code.dest.Data.variable)= variable;
                code2->line = tree->lchild->lchild->line;
                code2->prev = code2;
            }
            else
            {
                tmp = (TACCode*)malloc(sizeof(TACCode));
                tmp->code.optype = ARG;
                tmp->code.dest.Type = VARIABLE;
                variable.depictor = current;
                tmp->code.dest.Data.variable  = new ScopeItem;
                *(tmp->code.dest.Data.variable)= variable;
                tmp->line = tree->lchild->lchild->line;
                tmp->prev = tmp;
                code2 = MergeTACItem(2, code2, tmp);
            }
            current = current->next;
        }*/
        code3 = (TACCode*)malloc(sizeof(TACCode));
        code3->code.optype = CALL;
        code3->code.dest.Type = FUNCTION;
        code3->code.dest.Data.variable = new ScopeItem;
        *(code3->code.dest.Data.variable)= function;
        code3->line = tree->lchild->lchild->line;
        code3->prev = code3;
        return MergeTACItem(2, code1, code3);
    }
    else if (tree->name == "Block_Stmt") {
        return BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num);
    }
    else if (tree->name == "Block") {
        int flag = 0;
        // Judge if this block is function body
        if (tree->si != NULL && !(*(tree->si) == (ScopeItem)stack.back())) {
            flag = 1;
            //PushScopeStack(stack, *tree->si);
            stack.push_back(*(tree->si));
        }
        TACCode* BlockItems = (TACCode*)malloc(sizeof(TACCode));
        BlockItems = BuildTAC(tree->lchild, scopeItem, stack, temp_num, label_num);
        ScopeItem top;
        if (flag == 1) {
            //PopScopeStack(stack, &top);
            stack.pop_back();
        }
        return BlockItems;
    }
    else if (tree->name == "Lval_Opassign_Stmt") {
        string cache1, cache2;
        TACCode* code1, * code2;
        cache1 = "_t" + to_string(temp_num++);
        ScopeItem *new_temp1 = addIntoScope((*(&stack)->end()).stype, stack.back().address, cache1, Variable, "temp", NULL);
        stack.pop_back();
        stack.push_back(*new_temp1);
        code1 = TranslateExp(tree->lchild->rchild, *new_temp1, stack, *new_temp1, temp_num, label_num);
        code2 = TranslateLvalAssign(tree->lchild, *new_temp1, stack, *new_temp1, temp_num, label_num);
        return MergeTACItem(2, code1, code2);


        //return TranslateExp(tree->lchild->rchild, *(tree->lchild->rchild->si), stack, *(tree->lchild->si), temp_num, label_num);
    }
    else if (tree->name == "Empty_Stmt") {
        return NULL;
    }
    else if (tree->name == "IF_Stmt") {
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
            if (tmp->code.dest.Type == ARRAY) {
                printf("%3d  (at line %3d)\t%s[%s] := ", line, tmp->line, tmp->code.dest.Data.array_add->array_si->name.c_str(), tmp->code.dest.Data.array_add->deviation->name.c_str());
                if (tmp->code.firstOp.Type == VARIABLE)
                    printf("%s\n", tmp->code.firstOp.Data.variable->name.c_str());
                else if (tmp->code.firstOp.Type == ARRAY)
                    printf("%s[%s]\n", tmp->code.firstOp.Data.array_add->array_si->name.c_str(), tmp->code.firstOp.Data.array_add->deviation->name.c_str());
                else if (tmp->code.firstOp.Type == ADDRESSS)
                    printf("*%s\n", tmp->code.firstOp.Data.variable->name.c_str());
                else if (tmp->code.firstOp.Type == INTEGERCONST)
                    printf("#%d\n", tmp->code.firstOp.Data.value);
            }
            else {
                // Notice: no matter variable is in which scopeItem, the scopeItem entry always has "name" attribute
                printf("%3d  (at line %3d)\t%s := ", line, tmp->line, tmp->code.dest.Data.variable->name.c_str());
                if (tmp->code.firstOp.Type == VARIABLE)
                    printf("%s\n", tmp->code.firstOp.Data.variable->name.c_str());
                else if (tmp->code.firstOp.Type == ARRAY)
                    printf("%s[%s]\n", tmp->code.firstOp.Data.array_add->array_si->name.c_str(), tmp->code.firstOp.Data.array_add->deviation->name.c_str());
                else if (tmp->code.firstOp.Type == ADDRESSS)
                    printf("*%s\n", tmp->code.firstOp.Data.variable->name.c_str());
                else if (tmp->code.firstOp.Type == INTEGERCONST)
                    printf("#%d\n", tmp->code.firstOp.Data.value);
            }
        }
        else if (tmp->code.optype == ADD | tmp->code.optype == SUB | tmp->code.optype == MUL | tmp->code.optype == DIV | tmp->code.optype == MOD)
        {
            // Notice: no matter variable  is in which scopeItem, the scopeItem entry always has "name" attribute
            printf("%3d  (at line %3d)\t%s := ", line, tmp->line, tmp->code.dest.Data.variable->name.c_str());
            if (tmp->code.firstOp.Type == VARIABLE)
                printf("%s ", tmp->code.firstOp.Data.variable->name.c_str());
            else if (tmp->code.firstOp.Type == ARRAY)
                printf("%s[%s]\n", tmp->code.firstOp.Data.array_add->array_si->name.c_str(), tmp->code.firstOp.Data.array_add->deviation->name.c_str());
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
                case MOD:
                    printf("%% ");
                    break;
            }
            if (tmp->code.secondOp.Type == VARIABLE)
                printf("%s\n", tmp->code.secondOp.Data.variable->name.c_str());
            else if (tmp->code.secondOp.Type == ARRAY)
                printf("%s[%s]\n", tmp->code.secondOp.Data.array_add->array_si->name.c_str(), tmp->code.secondOp.Data.array_add->deviation->name.c_str());
            else if (tmp->code.secondOp.Type == ADDRESSS)
                printf("*%s\n", tmp->code.secondOp.Data.variable->name.c_str());
            else if (tmp->code.secondOp.Type == INTEGERCONST)
                printf("#%d\n", tmp->code.secondOp.Data.value);
        }
        else if (tmp->code.optype == FUNCTIONDF)
            printf("\n%3d  (at line %3d)\tFUNCTION %s :\n", line, tmp->line, tmp->code.dest.Data.function->name.c_str());
        else if (tmp->code.optype == PARAM) {
            if(tmp->code.dest.Type == VARIABLE)
                printf("%3d  (at line %3d)\tPARAM %s\n", line, tmp->line, tmp->code.dest.Data.variable->name.c_str());
            else {
                if (tmp->code.dest.Data.array_add->deviation == NULL) {
                    printf("%3d  (at line %3d)\tPARAM %s[]\n", line, tmp->line, tmp->code.dest.Data.array_add->array_si->name.c_str());
                }
                else
                    printf("%3d  (at line %3d)\tPARAM %s[][%s]\n", line, tmp->line, tmp->code.dest.Data.array_add->array_si->name.c_str(), tmp->code.dest.Data.array_add->deviation->name.c_str());
            }
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
            if(tmp->code.dest.Type==VARIABLE)
                printf("%3d  (at line %3d)\tARG %s\n", line, tmp->line, tmp->code.dest.Data.variable->name.c_str());
            else {
                if (tmp->code.dest.Data.array_add->deviation == NULL) {     //形参数组作为实参
                    printf("%3d  (at line %3d)\tARG %s[]\n", line, tmp->line, tmp->code.dest.Data.array_add->array_si->name.c_str());
                }
                else
                    printf("%3d  (at line %3d)\tARG %s[%s]\n", line, tmp->line, tmp->code.dest.Data.array_add->array_si->name.c_str(), tmp->code.dest.Data.array_add->deviation->name.c_str());
            } 
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
