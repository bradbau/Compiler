#include "stack.h"
#include <stdlib.h>
using namespace std;

ScopeStack* Stack(){
    ScopeStack* stack;
    stack->base = (ScopeItem*)malloc(STACK_INIT_SIZE * sizeof(ScopeItem));
    stack->top = stack->base;
    stack->stacksize = STACK_INIT_SIZE;
    stack->length = 0;
    return stack;
}

void DestroyScopeStack(ScopeStack* stack){
    if(stack->base){
        free(stack->base);
    }
    stack->base = NULL;
    stack->top = NULL;
    return;
}

int ScopeStackLength(ScopeStack* stack){
    return stack->length;
}

void PushScopeStack(ScopeStack* stack, ScopeItem si){
    //当一开始开辟的栈空间满了之后，需要对空间进行扩展
    if(stack->length >= stack->stacksize){
        stack->base = (ScopeItem*)realloc(stack->base, (stack->stacksize + STACKINCREMENT) * sizeof(ScopeItem));
        stack->top = stack->base + stack->stacksize;
        stack->stacksize += STACKINCREMENT;
    }
    *stack->top = si;
    stack->top ++;
    stack->length ++;
    return;
}

void PopScopeStack(ScopeStack* stack, ScopeItem* si){
    stack->top --;
    *si = *stack->top;
    stack->length --;
    return;
}

ScopeItem* GetStackTopp(ScopeStack* stack){
    return stack->top - 1;
}

//在符号表中查找指定名字的符号，如果找到了，返回对应Scopetem的指针，若没找到返回空
ScopeItem* TraverseScopeStack(ScopeStack* stack, string name){
    ScopeItem* temp = stack->top;
    ScopeItem* result;
    if(temp == stack->base){
        //栈为空
        //如果没有找到，返回NULL
        result = NULL;
        return result;
    }
    while(--temp >= stack->base){
        result = temp;
        while(result){
            if(result->name == name){
                return result;
            }
            result = result->next;
        }
    }
    return result;
}