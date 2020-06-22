#include "stack.h"
#include <stdlib.h>
using namespace std;

Stack::Stack(){
    stack->base = (ScopeItem*)malloc(STACK_INIT_SIZE * sizeof(ScopeItem));
    stack->top = stack->base;
    stack->stacksize = STACK_INIT_SIZE;
    stack->length = 0;
    return;
}

void Stack::DestroyScopeStack(){
    if(stack->base){
        free(stack->base);
    }
    stack->base = NULL;
    stack->top = NULL;
    return;
}

int Stack::ScopeStackLength(){
    return stack->length;
}

void Stack::PushScopeStack(ScopeItem si){
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

void Stack::PopScopeStack(ScopeItem* si){
    stack->top --;
    *si = *stack->top;
    stack->length --;
    return;
}

ScopeItem* Stack::GetStackTop(){
    return stack->top - 1;
}

//在符号表中查找指定名字的符号，如果找到了，返回对应Scopetem的指针，若没找到返回空
ScopeItem* Stack::TraverseScopeStack(string name){
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
    result = NULL;
    return result;
}