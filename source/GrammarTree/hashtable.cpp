/* utf-8 */
#include "hashtable.h"

void ScopeItem::ScopeItem(ScopeType stype, string name, string type, SysYCategory category){
    this->stype = stype;
    this->name = name;
    this->type = type;
    this->category = category;
}

void ScopeItem::setDepictor(Hashtable *depictor){
    this->depictor = depictor;
}
    
void ScopeItem::setOffset(int offset){
    this->offset = offset;
}
    
void ScopeItem::setReg(int reg){
    this->reg = reg;
}

ScopeType ScopeItem::getStype(){
    return this->stype;
}

string ScopeItem::getName(){
    return this->name;
}

string ScopeItem::getType(){
    return this->type;
}

SysYCategory ScopeItem::getCategory(){
    return this->category;
}

Hashtable* ScopeItem::getDepictor(){
    return this->depictor;
}

int ScopeItem::getOffset(){
    return this->offset;
}

int ScopeItem::getReg(){
    return this->reg;
}

ScopeItem* addIntoHashTable(ScopeType stype, ScopeItem* pre_si, string name, SysYCategory category, string type, Hashtable* depictor){
    ScopeItem si = new ScopeItem(stype, name, type, category);
    si.setDepictor(depictor);
    pre_si->self_hashtable->Enter(name, &si);
    return &si;
}