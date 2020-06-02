#include<stdio.h>
#include"hashtable.h"
using namespace std;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 20

extern int smerror;

typedef enum ScopeType
{
    ScopeLocal,
    ScopeFormal,
    ScopeGlobal,
    ScopeNone
} ScopeType;

typedef struct Scope
{
    ScopeType type;
    ScopeItem si;
} Scope;

typedef struct ScopeStack
{
    Scope* base;
    Scope* top;
    int stacksize;
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
       ScopeStack();
       
       void DestroyScopeStack();
       int ScopeStackLength();
       void PushScopeStack(Scope scope);
       void PopScopeStack();
       Scope* GetStackTop();
       Scope TraverseScopeStack(char* name);

      ExprType* GetExprType(GrammarTree tree);
      void SameNameTrial(ClassScope classscope, GrammarTree tree);
      /*Traverse the grammar tree and operate the scope stack at the same time to do trial*/
      void ScopeTrial(GrammarTree tree, Scope scope);
}

