/* utf-8 */

#ifndef AST_H
#define AST_H

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string>
#include "SymbolTable.h"
using namespace std;

extern char* yytext; 
extern FILE* yyin;
extern int yylineno;
extern int yyparse();


class ASTTree{
  private:

    int int_value;  //只可能为int类型
    int num;        //计数器，可以用来统计形参个数
    int line;       // the number of its line
    int column;
    string name;     // the name of this AST unit
    string id;
    string functype; //函数返回类型
    string funcptype;//形参类型

    //merge dev-cjw(begin)
    string formatstring;
    //merge dev-cjw(end)

    ASTTree *lchild;
    ASTTree *rchild;
  
  public:
    ScopeItem *si;  //  符号表指针
    ASTTree();
    ASTTree(string name,int num,int pos,...);
   
    //遍历当前语法树
    void TraverseGrammerTree(int level);

    ASTTree * GetLeftChild();

    ASTTree * GetRightChild();

    void SetLeftChild(ASTTree *LeftAst);

    void SetRightChild(ASTTree *RightAst);

    void SetFuncType(string type);

    void SetFuncPType(string ptype);

    void SetID(string idname);

    string GetNodeTypeName();

    string GetID();

    void SetIntValue(int value);

    int GetIntValue();

    //merge dev-cjw(begin)
    string GetString();
    //merge dev-cjw(end)

    ASTTree * GetASTTree();
    
    void Check() ;
    
    void Emit() ;
};

#endif