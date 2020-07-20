#include"ScopeStack_stl.h"
#include <iostream>

ScopeItem TraverseScopeStack(vector<ScopeItem> stack, string name){
    vector<ScopeItem>::iterator iter;
    ScopeItem* result = NULL;
    for(iter= stack.end(); iter!=stack.begin(); iter--){      
        if (iter[0].name == name) {
            return iter[0];
        }
        result = iter[0].next;
        while (result) {
            cout << name << endl;
            cout << "ßÀßÀßÀßÀßÀCCDÊÇ" << endl;
            cout << result->name << endl;
            if (result->name == name) {
                cout << "CCCCCCDÊÇ" << endl;
                return *result;
            }
            result = result->next;
        }
    }   
    if (iter[0].name == name) {
        cout << "iter[0]" << endl;
        cout << name << endl;
        return iter[0];
    }
    result = iter[0].next;
    while (result) {
        if (result->name == name) {
            cout << (*result).name << endl;
            cout << name << endl;
            return *result;
        }
        result = result->next;
    }
    cout << "TraverseScopeStack no result" << endl;
    ScopeItem scopeItem;
    return scopeItem;
}