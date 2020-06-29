#ifndef QUADRUPLEOPERAND_H
#define QUADRUPLEOPERAND_H


#include "../SymbolTable/SymbolTable.h"

typedef enum
{
    VARIABLE,       //变量
    ADDRESSS,       //地址
    INTEGERCONST,   //整形常量
    FUNCTION,       //函数
    LABEL           //我们的label应该是用于标记间接三元式的在数组中的位置，用来作为取三元式值的索引
} TACOperandType;  // 操作数类型;





/*

这种组织方式看起来更加简洁，并且
typedef union
    {
        int value;       //整形值，可以用于保存
        int labelvalue;
        ScopeItem variable;     //
        ScopeItem function;     //
    } TACOperandData;
    

    TACOperandType Type; //本操作符的成员
    TACOperandData Data; //操作符数据
*/
    

/*

QuadrupleOperand::QuadrupleOperand() {};
    //这里要不要将union的成员缩减为两个
    //整型值初始化
QuadrupleOperand::QuadrupleOperand(TACOperandType Type, int value);
    //Scope初始化
QuadrupleOperand::QuadrupleOperand(TACOperandType Type, ScopeItem item);
*/


typedef struct {
    TACOperandType Type; //本操作符的成员
    union
    {
        int value;       //整形值，可以用于保存
        int labelvalue;
        ScopeItem variable;     //
        ScopeItem function;     //
    };

}QuadrupleOperand;
#endif