#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string.h>
#include "SymbolTable.h"

extern char* yytext;
extern FILE* yyin;
extern int yylineno;
extern int yyparse();

class ASTTree{
  protected:

    int int_value;  //只可能为int类型
    int num;                      //计数器，可以用来统计形参个数
    int line;       // the number of its line
    int column;
    char* name;     // the name of this AST unit
    char* id;
    char* functype; //函数返回类型
    char* funcptype;//形参类型
    ScopeItem *si;

    ASTTree *lchild;
    ASTTree *rchild;
  
  public:
    ASTTree();
    ASTTree(char *name,int num,int pos,...);
   
    //遍历当前语法树
    void TraverseGrammerTree(int level);

    ASTTree * GetLeftChild();

    ASTTree * GetRightChild();

    void SetLeftChild(ASTTree *LeftAst);

    void SetRightChild(ASTTree *RightAst);

    void SetFuncType(char* type);

    void SetFuncPType(char* ptype);

    void SetID(char* idname);

    char* GetNodeTypeName();

    char* GetID();

    void SetIntValue(int value);

    int GetIntValue();

    ASTTree * GetASTTree();
    //
    void Check() ;
    
    void Emit() ;
};