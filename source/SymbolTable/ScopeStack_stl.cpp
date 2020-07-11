#include"ScopeStack_stl.h"


ScopeItem* TraverseScopeStack(vector<ScopeItem> stack, string name){
    for(auto iter= stack.cbegin(); iter!=stack.cend(); iter++){
        if(iter->name==name){
            return &(*iter);
        }
    }
    return null;
}