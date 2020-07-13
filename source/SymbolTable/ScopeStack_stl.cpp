#include"ScopeStack_stl.h"


ScopeItem* TraverseScopeStack(vector<ScopeItem> stack, string name){
    for(auto iter= stack.begin(); iter!=stack.end(); iter++){
        if(iter->name==name){
            return &(*iter);
        }
    }
    return NULL;
}