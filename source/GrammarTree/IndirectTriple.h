#ifndef INDIRECTTRIPLE_H
#define INDIRECTTRIPLE_H



#include"IndirectTripleOperand.h"


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


class four {



public:
    TACOperatorType optype;       //运算符
    fourOperand dest;
    fourOperand firstOp;    //
    fourOperand secondOp;   //
    four() {
        this.dest = new fourOperand();
        this.firstOp = new fourOperand();
        this.secondOp = new fourOperand();
    };


    //公有方法，就是对外的接口
        //IndirectTriple(int seq,TACOperatorType optype, IndirectTripleOperand firstOp,IndirectTripleOperand secondOp);
        //int getSeq();//返回本语句的序号
};

#endif // !INDIRECTTRIPLE_H

