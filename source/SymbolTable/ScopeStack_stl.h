#ifndef SCOPESTACK_STL_H
#define SCOPESTACK_STL_H


#include<stdio.h>
#include"SymbolTable.h"
#include <string>
#include<vector>
//using namespace std;
using std::vector;


extern int smerror;




typedef struct ExprType
{
    SysYCategory category;
    char* type;
} ExprType;


ScopeItem TraverseScopeStack(vector<ScopeItem> stack, string name);

#endif