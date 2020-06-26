#ifndef STACK_H
#define STACK_H

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
typedef struct ScopeItem
{
    ScopeType type;
    ScopeItem si;
} ScopeItem;
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

ScopeStack* Stack();
void DestroyScopeStack(ScopeStack* stack);
int ScopeStackLength(ScopeStack* stack);
void PushScopeStack(ScopeStack* stack, ScopeItem scope);
void PopScopeStack(ScopeStack* stack, ScopeItem* si);
ScopeItem* GetStackTopp(ScopeStack* stack);
ScopeItem* TraverseScopeStack(ScopeStack* stack, string name);

#endif