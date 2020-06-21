/* utf-8 */
#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <string>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef enum SysYCategory
{ 
    Variable,
    Function,
    Block,
    ConstVariable,
    Array,
    NOParam
} SysYCategory;

typedef enum ScopeType
{ 
    Global,
    Formal,
    Local
} ScopeType;

// Define scope 
typedef struct ScopeItem{
    ScopeType stype;
    string name;
    string type; //for example: TYPEINTEGER
    SysYCategory category; //for example: Variable Function
    struct ScopeItem *depictor;
    struct ScopeItem *next;
    int offset;
    int reg;
}ScopeItem;

ScopeItem* addIntoScope(ScopeType stype, ScopeItem* pre_si, string name, SysYCategory category, string type, ScopeItem* depictor);
ScopeItem* mergeScope(ScopeItem* t1, ScopeItem* t2);
void displayGlobal(ScopeItem* t);
void displayFormal(ScopeItem* t, string tablename);
void displayLocal(ScopeItem* t, string tablename);

#endif