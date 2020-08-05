#ifndef QUADRUPLE_H
#define QUADRUPLE_H



#include"QuadrupleOperand.h"


/*
本模块描述四元式的一个语句
*/

typedef enum  //操作符类型
{
    ASSIGN,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    FUNCTIONDF,
    PARAM,
    LABELDF,
    IFLTGOTO,
    IFLEGOTO,
    IFGTGOTO,
    IFGEGOTO,
    IFEQGOTO,
    IFNEQGOTO,
    GOTO,    //关于goto的贴近arm的缩减稍后进行
    RETURN,
    ARG,
    CALLASSIGN,
    CALL
} TACOperatorType;



struct Quadruple {
    TACOperatorType optype;       //运算符
    QuadrupleOperand dest;
    QuadrupleOperand firstOp;    //
    QuadrupleOperand secondOp;   //
};



#endif // !QUADRUPLE_H

