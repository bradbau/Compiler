/* utf-8 */

#include "SymbolTable.h"
using namespace std;

ScopeItem* addIntoScope(ScopeType stype, ScopeItem* pre_si, string name, SysYCategory category, string type, ScopeItem* depictor){
    ScopeItem *si = new ScopeItem;
    si->stype = stype;
    si->name = name;
    si->type = type;
    si->category = category;
    si->depictor = depictor;
    si->next = pre_si;
    return si;
}

/*
ScopeItem* mergeScope(ScopeItem * s1, ScopeItem *s2){
    ScopeItem *temp = s1;
    if(!s1){
        return s2;
    }
    while(temp->next){
        temp = temp->next;
    }
    temp->next = s2;
    return s1;
}
*/

ScopeItem* mergeScope(ASTTree *t1, ASTTree *t2){
    if(t2 == NULL){
        return t1->si;
    }
    ScopeItem *temp = t1->si;
    if(!temp){
        return t2->si;
    }
     while(temp->next){
        temp = temp->next;
    }
    temp->next = t2->si;
    return t1->si;
}