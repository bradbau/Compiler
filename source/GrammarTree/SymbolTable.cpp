/* utf-8 */

#include "SymbolTable.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
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


/*
ScopeItem* mergeScope(ScopeItem *t1, ScopeItem *t2){
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
*/

void displayGlobal(ScopeItem* t){
    vector<pair<ScopeItem*, string> > FormalScope;
    /*if(t == NULL){
        cout << "Global tree node does not exist\n";
        return;
    }*/
    ScopeItem* s = t;
    cout.setf(ios::left);
    cout << "\n\n===========================================================\n";
    cout << "Global\n";
    cout << setw(15) << "ID" << setw(15) << "category" << setw(15) << "type" << setw(15) << "depictor\n";
    cout << "         \n";
    while(s != NULL){
        if(s->stype != Global){
            cout << "scope type is wrong\n";
            return;
        }
        cout << setw(15) << s->name;
        switch (s->category)
        {
        case Variable:
            cout << setw(15) << "Variable" ;
            break;
        case Function:
            cout << setw(15) << "Function";
            break;
        case Block:
            cout << setw(15) << "Block";
            break;
        case ConstVariable:
            cout << setw(15) << "ConstVariable";
            break;
        case Array:
            cout << setw(15) << "Array";
            break;
        case NOParam:
            cout << setw(15) << "NOParam";
            break;
        default:
            break;
        }
        cout << setw(15) << s->type;
        if(s->depictor == NULL){
            cout << setw(15) << "NULL" << endl;
        }else{
            cout << setw(15) << "NOT NULL" << endl;
            //将指向Formal的指针暂缓斯存储在vector中，等Global全都打印完再打印Formal
            FormalScope.push_back(make_pair(s->depictor, s->name));
        }
        s = s->next;
    }
    //打印Formal
    for(int i=0; i<FormalScope.size(); i++){
        displayFormal(FormalScope[i].first, FormalScope[i].second);
    }
}

void displayFormal(ScopeItem* t, string tablename){
    /*if(t == NULL){
        cout << tablename << "Formal tree node does not exist\n";
        return;
    }*/
    cout.setf(ios::left);
    ScopeItem* s = t;
    ScopeItem* temp = s;
    cout << "===========================================================\n";
    cout << "Formal:" << tablename << "\n";
    cout << setw(15) << "ID" << setw(15) << "category" << setw(15) << "type" << setw(15) << "depictor\n";
    cout << "        \n";
    while(s != NULL){
        if(s->stype != Formal){
            cout << "scope type is wrong\n";
            return;
        }
        cout << setw(15) << s->name;
        switch (s->category)
        {
        case Variable:
            cout << setw(15) << "Variable" ;
            break;
        case Function:
            cout << setw(15) << "Function";
            break;
        case Block:
            cout << setw(15) << "Block";
            break;
        case ConstVariable:
            cout << setw(15) << "ConstVariable";
            break;
        case Array:
            cout << setw(15) << "Array";
            break;
        case NOParam:
            cout << setw(15) << "NOParam";
            break;
        default:
            break;
        }
        cout << setw(15) << s->type;
        if(s->depictor == NULL){
            cout << setw(15) << "NULL" << endl;
        }else{
            cout << setw(15) << "NOT NULL" << endl;
        }
        s = s->next;
    }
    //打印此Formal作用域对应的Local域
    //由于Formal作用域每一项的depictor都一样，所以直接用第一项的即可
    displayLocal(temp->depictor, tablename);
}

void displayLocal(ScopeItem* t, string tablename){
    vector<pair<ScopeItem*, string> > EmbedScope;
    /*if(t == NULL){
        cout << "Local tree node does not exist\n";
        return;
    }*/
    ScopeItem* s = t;
    cout.setf(ios::left);
    cout << "===========================================================\n";
    cout << "Local:" << tablename << "\n";
    cout << setw(15) << "ID" << setw(15) << "category" << setw(15) << "type" << setw(15) << "depictor\n";
    cout << "        \n";
    while(s != NULL){
        if(s->stype != Local){
            cout << "scope type is wrong\n";
            return;
        }
        cout << setw(15) << s->name;
        switch (s->category)
        {
        case Variable:
            cout << setw(15) << "Variable" ;
            break;
        case Function:
            cout << setw(15) << "Function";
            break;
        case Block:
            cout << setw(15) << "Block";
            break;
        case ConstVariable:
            cout << setw(15) << "ConstVariable";
            break;
        case Array:
            cout << setw(15) << "Array";
            break;
        case NOParam:
            cout << setw(15) << "NOParam";
            break;
        default:
            break;
        }
        cout << setw(15) << s->type;
        if(s->depictor == NULL){
            cout << setw(15) << "NULL" << endl;
        }else{
            cout << setw(15) << "NOT NULL" << endl;
            //将指向内嵌域的指针暂缓斯存储在vector中，等Local全都打印完再打印内嵌域
            EmbedScope.push_back(make_pair(s->depictor, "block"));
        }
        s = s->next;
    }
    //打印Embed
    for(int i=0; i<EmbedScope.size(); i++){
        displayLocal(EmbedScope[i].first, EmbedScope[i].second);
    }
}