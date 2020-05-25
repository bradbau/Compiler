#include "grammartree.h"
#include <cstring>
#include<iostream>
using namespace std;
ASTTree::ASTTree(char* name, int num, ...) {
    int i;
    char* cache;
    va_list variables;       
    ASTTree *tmp = new ASTTree();
    this->name = name;
    //this->si = null;
    va_start(variables, num);           // Init the variable parameter list
    if (num > 0)
    {
        tmp = va_arg(variables, ASTTree*);
        this->lchild = tmp;
        this->line = tmp->line;      // Current grammar unit's line number is equal to its left child's
        this->column = tmp->column;      // Current grammar unit's line number is equal to its left child's
        for (i = 0; i < num - 1; i++)
        {                               // Brothers
            tmp->rchild = va_arg(variables, ASTTree*);
            tmp = tmp->rchild;
        }
        // Modify the line number when reduce using rule "Stmt->SimpleStmt" and SimpleStmt is Epsilon
        if (!strcmp(this->lchild->name, "SimpleStmt") && this->lchild->line == -1)
            this->line = this->lchild->rchild->line;
    }
    else
    {   // This grammar unit is terminal or void rule
        this->line = va_arg(variables, int);
        if (this->line != -1)
            this->column = va_arg(variables, int);
        if (!strcmp(this->name, "IDENTIFIER"))
        {
            cache = (char *)malloc(sizeof(char) * strlen(yytext));
            strcpy(cache, yytext);
            this->id = cache;
        }
        else  if (!strcmp(this->name, "CONSTANTINTD"))
        {
            this->int_value = atoi(yytext);
        }
        else  if (!strcmp(this->name, "CONSTANTINTH"))
        {
            this->int_value = strtol(yytext, NULL, 16);
        }
        else  if (!strcmp(this->name, "CONSTANOCT"))
        {
            this->int_value = strtol(yytext, NULL, 8);
        }
        
    }

}

void ASTTree::TraverseGrammerTree(int level)
{
    int i;
    if (!this)
    {
        for (i = 0; i < level; i++)
            printf("  ");
        if (this->line != -1)
        {
            // Not void rule
            printf("%s", this->name);
           if (!strcmp(this->name, "CONSTANTINTD"))
                printf(": %d\n", this->int_value);
            else if (!strcmp(this->name, "CONSTANTINTH"))
                printf(": %d\n", this->int_value);
            else if (!strcmp(this->name, "CONSTANTOCT"))
                printf(": %d\n", this->int_value);
            else
                printf(" (%d)\n", this->line);
        }
        else
            printf("%s (Epsilon)\n", this->name);
        this->lchild->TraverseGrammerTree( level + 1);
        this->rchild->TraverseGrammerTree(level);
    }
}

ASTTree* ASTTree::GetASTTree(){
    return this;
}

ASTTree * ASTTree::GetLeftChild(){
    return this->lchild;
}

ASTTree * ASTTree::GetRightChild(){
    return this->rchild;
};

void ASTTree::SetLeftChild(ASTTree *LeftAst){
    this->lchild = LeftAst;
};
    
void ASTTree::SetRightChild(ASTTree *RightAst){
    this->rchild = RightAst;
};