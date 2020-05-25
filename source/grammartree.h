
#ifndef GRAMMARTREE_H
#define GRAMMARTREE_H


#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string>
using namespace std;
//#include<iostream>
//#include"hashtable.h"

extern char* yytext;
extern FILE* yyin;
extern int yylineno;
extern int yyparse();

class ASTTree{
  protected:
    int line;       // the number of its line
    int column;
    char* name;     // the name of this grammar unit
    int int_value;  //只可能为int类型
    string id;
    //ScopeItem si;//目前没想明白有什么用


    ASTTree *lchild;
    ASTTree *rchild;
  
  public:
    ASTTree();
    ASTTree(char* name, int num, ...);
    //创建当前语法树，赋给gt
    void CreateGrammarTree(char* name, int num, ...);
    //遍历当前语法树
    void TraverseGrammerTree(int level);

    ASTTree * GetLeftChild();

    ASTTree * GetRightChild();

    void SetLeftChild(ASTTree *LeftAst);

    void SetRightChild(ASTTree *RightAst);

    ASTTree * GetASTTree();
    //
    void Check() ;
    
    void Emit() ;
};


#endif

