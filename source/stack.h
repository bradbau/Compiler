#include<stdio.h>
#include"SymbolTable.h"
#include <string>
using namespace std;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 20

extern int smerror;

/*
typedef enum ScopeType
{
    ScopeLocal,
    ScopeFormal,
    ScopeGlobal,
    ScopeNone
} ScopeType;
*/

/*
typedef struct Scope
{
    ScopeType type;
    ScopeItem si;
} Scope;
*/

typedef struct ScopeStack
{
    ScopeItem* base;
    ScopeItem* top;
    int stacksize;//栈最大的大小
    int length;//栈中目前元素个数
} ScopeStack;

typedef struct ExprType
{
    SysYCategory category;
    char* type;
} ExprType;

class Stack{
    private:
       ScopeStack* stack;
    public:
       Stack();
       void DestroyScopeStack();
       int ScopeStackLength();
       void PushScopeStack(ScopeItem scope);
       void PopScopeStack(ScopeItem* si);
       ScopeItem* GetStackTop();
       ScopeItem* TraverseScopeStack(string name);
      /*ExprType* GetExprType(GrammarTree tree);*/
      //void SameNameTrial(ClassScope classscope, GrammarTree tree);
      /*Traverse the grammar tree and operate the scope stack at the same time to do trial*/
      //void ScopeTrial(GrammarTree tree, Scope scope);
};

