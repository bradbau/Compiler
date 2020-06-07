/* utf-8 */
#include "SymbolTable.h"

// void ScopeItem::ScopeItem(ScopeType stype, string name, string type, SysYCategory category){
//     this->stype = stype;
//     this->name = name;
//     this->type = type;
//     this->category = category;
// }

// void ScopeItem::setDepictor(ScopeItem *depictor){
//     this->depictor = depictor;
// }
    
// void ScopeItem::setOffset(int offset){
//     this->offset = offset;
// }
    
// void ScopeItem::setReg(int reg){
//     this->reg = reg;
// }

// ScopeType ScopeItem::getStype(){
//     return this->stype;
// }

// string ScopeItem::getName(){
//     return this->name;
// }

// string ScopeItem::getType(){
//     return this->type;
// }

// SysYCategory ScopeItem::getCategory(){
//     return this->category;
// }

// Hashtable* ScopeItem::getDepictor(){
//     return this->depictor;
// }

// int ScopeItem::getOffset(){
//     return this->offset;
// }

// int ScopeItem::getReg(){
//     return this->reg;
// }

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