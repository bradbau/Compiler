#ifndef INDIRECTTRIPLE_H
#define INDIRECTTRIPLE_H

#include"IndirectTripleOperand.h"

/*
本模块描述间接三元式的一个语句
*/

class IndirectTriple{

public:
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


private:

    int seq;                //三元式序号，可以用于索引语句，其他的语句可以通过这个序号来访问三元式的值

    TACOperatorType optype;       //运算符
    IndirectTripleOprtand firstOp;    //
    IndirectTripleOprtand secondOp;   //


public:
//公有方法，就是对外的接口
    IndirectTriple(int seq,TACOperatorType optype, IndirectTripleOprtand firstOp,IndirectTripleOprtand secondOp);
    int getSeq();//返回本语句的序号
    





}

#endif // !INDIRECTTRIPLE_H

