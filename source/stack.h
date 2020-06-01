#include<stdio.h>
#include"hashtable.h"
#include "grammartree.h"
using namespace std;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 20

extern int smerror;
//表类别
typedef enum ScopeType
{//可能需要修改
    ScopeLocal,
    ScopeFormal,
    ScopeGlobal,
    ScopeNone
} ScopeType;
//作用域
typedef struct Scope
{
    ScopeType type;
    Hashtable si;
} Scope;
//作用域栈
typedef struct ScopeStack
{
    Scope* base;//底部
    Scope* top; //顶部
    int stacksize;//大小
} ScopeStack;

typedef struct ExprType
{
    SysYCategory category;
    char* type;
} ExprType;

class Stack{
    private:
       ScopeStack* ss;
    public:
       //void InitScopeStack(ScopeStack* stack);的实现
       Stack();
       //销毁
       void DestroyScopeStack();
       //长度
       int ScopeStackLength();
       //入栈
       void PushScopeStack(Scope scope);
       //出栈
       void PopScopeStack();
       //顶部作用域
       Scope* GetStackTop();
       //根据名字返回所属作用域
       Scope TraverseScopeStack(char* name);
      //
      //ExprType* GetExprType(ASTTree tree);
      //是否重名
      void SameNameTrial(Scope scope, ASTTree tree);
      /*Traverse the grammar tree and operate the scope stack at the same time to do trial*/
      void ScopeTrial(ASTTree tree, Scope scope);
}

