#include"ScopeStack_stl.h"
#include <iostream>

ScopeItem& TraverseScopeStack(vector<ScopeItem> stack, string name){
    vector<ScopeItem>::iterator iter;
    ScopeItem* result = NULL;
    for(iter= stack.end()-1; iter!=stack.begin(); iter--){   
        if (iter[0].name == name) {
            cout << "123" << endl;
            return (*iter);
        }
        result = iter[0].next;
        while (result) {
            if (result->name == name) {
                cout << "456" << endl;
                return *result;
            }
            cout << "789" << endl;
            result = result->next;
        }
    }   
    if (iter[0].name == name) {
        return *iter;
    }
    result = iter[0].next;
    while (result) {
        if (result->name == name) {
            return *result;
        }
        result = result->next;
    }
    
    throw std::runtime_error("TraverseScopeStack no result");
}