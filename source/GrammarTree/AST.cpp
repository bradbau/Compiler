/* utf-8 */

#include "AST.h"
#include <cstring>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;
extern char* yytext;

ASTTree::ASTTree(string name, int num, int pos ,...) {
    //printf("gouzao !!!\n");
    int i;
    va_list variables;       
    ASTTree *tmp;
    this->si = NULL;
    //printf("~~~\n");
    //printf("~~~~~~\n");
    //printf("%s",name);
    // char* tmpcache = (char *)malloc(sizeof(char) * strlen(name));
    // strcpy(tmpcache, yytext);
    this->name = name;
    //this->si = null;
    //printf("%s",this->name);
    va_start(variables, pos);           // Init the variable parameter list
    if (num > 0)
    {
        tmp = va_arg(variables, ASTTree*);
        this->lchild = tmp;
        this->line = tmp->line;      // Current grammar unit's line number is equal to its left child's
        //this->column = tmp->column;      // Current grammar unit's line number is equal to its left child's
        for (i = 0; i < num - 1; i++)
        {                               // Brothers
            tmp->rchild = va_arg(variables, ASTTree*);
            tmp = tmp->rchild;
        }
        
    }
    else
    {   // This grammar unit is terminal or void rule
        this->line = pos;
        if (this->line != -1){
            //printf("get coloum\n");
            this->column = va_arg(variables, int);
            //printf("%d",this->column);
        }
            
        if (this->name == "IDENTIFIER")
        {
            //printf("%s\n",yytext);
            string cache(yytext);
            this->id = cache;
        }
        else  if (this->name == "CONSTANTINTD")
        {
            this->int_value = atoi(yytext);
        }
        else  if (this->name == "CONSTANTINTH")
        {
            this->int_value = strtol(yytext, NULL, 16);
        }
        else  if (this->name == "CONSTANOCT")
        {
            this->int_value = strtol(yytext, NULL, 8);
        }
         //printf("name:%s\n",this->name);
    }
    va_end(variables);

}
ASTTree::ASTTree(){}
void ASTTree::TraverseGrammerTree(int level)
{
    int i;
    
        //printf("%s",this->name);//printf("tra!\n");
        for (i = 0; i < level; i++)
            printf(" ");
        if (this->line != -1)
        {
          for (i = 0; i < level; i++)
            printf(" ");
            // Not void rule
            cout << this->name;
           if (this->name == "CONSTANTINTD")
                printf(": %d\n", this->int_value);
            else if (this->name == "CONSTANTINTH")
                printf(": %d\n", this->int_value);
            else if (this->name == "CONSTANTOCT")
                printf(": %d\n", this->int_value);
            else if (this->name == "IDENTIFIER")
                cout << " " << this->id;
            else
                printf(" (%d)\n", this->line);
        }
        else 
            ;
            //printf("%s (Epsilon)\n", this->name);
        //printf("leftc\n");
        if(this->lchild)
            this->lchild->TraverseGrammerTree(level + 1);
        //printf("rightc\n");
        if(this->rchild)
           this->rchild->TraverseGrammerTree(level);
    
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

void ASTTree::SetFuncType(string type){
    this->functype = type;
};

void ASTTree::SetID(string idname){
    this->id = idname;
};

string ASTTree::GetNodeTypeName(){
    return this->name;
};
string ASTTree::GetID(){
    return this->id;
};

void ASTTree::SetIntValue(int value){
    this->int_value = value;
};

int ASTTree::GetIntValue(){
    return this->int_value;
};

void ASTTree::SetFuncPType(string ptype){
    this->funcptype = ptype;
};

void Si(ASTTree* tree) {
    if (tree == NULL) {
        return;
    }/*
    if (tree->lchild) {
        if (tree->lchild->si == NULL) {
            tree->lchild->si = tree->si;
        }
    }
    if (tree->rchild) {
        if (tree->rchild->si == NULL) {
            tree->rchild->si = tree->si;
        }
    }*/
};