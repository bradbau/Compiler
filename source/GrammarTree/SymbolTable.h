/* utf-8 */

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <string>
#include<stdio.h>
#include<stdlib.h>
#include "AST.h"
using namespace std;

typedef enum SysYCategory
{ 
    Variable,
    Function,
    Block,
    ConstVariable,
    Array,
} SysYCategory;

typedef enum ScopeType
{ 
    Global,
    Formal,
    Local
} ScopeType;

// Define scope 
struct ScopeItem{
    ScopeType stype;
    string name;
    string type; //for example: int void
    SysYCategory category; //for example: Variable Function
    ScopeItem *depictor;
    ScopeItem *next;
    int offset;
    int reg;
};

ScopeItem* addIntoScope(ScopeType stype, ScopeItem* pre_si, string name, SysYCategory category, string type, ScopeItem* depictor);
//ScopeItem* mergeScope(ScopeItem *s1, ScopeItem *s2);
ScopeItem* mergeScope(ASTTree *t1, ASTTree *t2);

#endif