#ifndef INDIRECTTRIPLEOPERAND_H
#define INDIRECTTRIPLEOPERAND_H

class IndirectTripleOperand{
public: 
enum TACOperandType  // 操作数类型
    {
        VARIABLE,       //变量
        ADDRESSS,       //地址
        INTEGERCONST,   //整形常量
        FUNCTION,       //函数
        LABEL           //我们的label应该是用于标记间接三元式的在数组中的位置，用来作为取三元式值的索引
    };


    private://私有数据成员
        TACOperandType Type; //本操作符的成员
        union
        {
            int value;       //整形值，可以用于保存
            Scope variable;     //
            Scope function;     //
        };


public:

    
    int GetValue();//获取三元式操作数的值,通过switch操作判断Type数据域然后返回内部值

}



#endif // !INDIRECTTRIPLEOPERAND_H
