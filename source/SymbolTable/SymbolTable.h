/* utf-8 */
#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <string>
#include<stdio.h>
#include<stdlib.h>
#include <vector>
#include "../GrammarTree/AST.h"
class ASTTree; 

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
    struct ScopeItem* prev;
    struct ScopeItem *next;
    int offset;
    int reg;
    //下面的两项记录数组信息（数组内情向量）
    //ASTTree* len;//数组的长度（数组第一维的长度。对于这样的数组array[][2],我们规定其len为0）
    struct ScopeItem *array_depictor;
    vector<ASTTree*> len;//记录数组的长度的变长数组,每一项都是指向可以表示那一维长度的EXP节点的指针（对于这样的数组array[][2],我们规定其第一维len为NULL）
    int dim;//数组的维数
}ScopeItem;

ScopeItem* addIntoScope(ScopeType stype, ScopeItem* pre_si, string name, SysYCategory category, string type, ScopeItem* depictor);
ScopeItem* mergeScope(ScopeItem* t1, ScopeItem* t2);
void displayGlobal(ScopeItem* t);
void displayFormal(ScopeItem* t, string tablename);
void displayLocal(ScopeItem* t, string tablename);

bool operator==(ScopeItem t1, ScopeItem t2);//重载操作符，判断两个scopeitem是否相等
#endif