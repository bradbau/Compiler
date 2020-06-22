#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string>
//#include<iostream>
//#include"hashtable.h"
using namespace std;

extern char* yytext;
extern FILE* yyin;
extern int yylineno;
extern int yyparse();

class ASTTree{
  protected:

    int int_value;  //只可能为int类型
    //int place;                     //存放（临时）变量在符号表的位置序号
    //char Etrue[15],Efalse[15];       //对布尔表达式的翻译时，真假转移目标的标号
    //char Snext[15];               //结点对应语句S执行后的下一条语句位置标号
    //struct codenode *code;          //该结点中间代码链表头指针
    //int type;                      //用以标识表达式结点的类型
    //int offset;                     //偏移量
    //int width;                     //占数据字节数
    int num;                      //计数器，可以用来统计形参个数
    int line;       // the number of its line
    int column;
    string name;     // the name of this AST unit
    string id;
    string functype; //函数返回类型
    string funcptype;//形参类型
    string formatstring;
    //ScopeItem si;//目前没想明白有什么用


    ASTTree *lchild;
    ASTTree *rchild;
  
  public:
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

    string GetString();

    ASTTree * GetASTTree();
    //
    void Check() ;
    
    void Emit() ;
};
