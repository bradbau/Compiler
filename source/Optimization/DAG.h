/* utf-8 */

#ifndef DAG_H
#define DAG_H

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
#include<string>



using namespace std;

enum NodeType  // 操作数类型
{
    VARIABLE,       //变量
    ADDRESSS,       //地址
    INTEGERCONST,   //整形常量
    FUNCTION,       //函数
    LABEL,           //我们的label应该是用于标记间接三元式的在数组中的位置，用来作为取三元式值的索引
    OPERATOR
};


typedef struct Node
{
    NodeType SaveType; //操作符的成员类型
    int value;               //值
    int labelvalue;
    TACOperatorType optype;  //运算符类型
    vector <ScopeItem*> id;
    vector <Node*> id;
} Node;



#endif