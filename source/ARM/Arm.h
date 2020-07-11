#ifndef ARM_H
#define ARM_H



#include<stdio.h>
#include<stdlib.h>
#include <string>
#include<list>
#include <assert.h>
#include"../IntermediateCode/TAC.h"
#include"ARMInstruction.h"


using ARMInstruction::Register;
using ARMInstruction::InstrcuctionType;
using ARMInstruction::userReg;


typedef struct 
//寄存器描述符，用于描述15个寄存器的状态
{
      bool filled;         // 是否使用
      int tag;           // Tag for LRU algorithm
      ScopeItem* variable;     // 存储的变量对象
      
} RegisterEntry;





class ARM {
private:
      list<ARMInstruction> InsList; //生成的汇编代码序列
      RegisterEntry[15] regs;// 用户可用寄存器

public:
      

};

ARM::ARM();//
ARM::ARM(TACCode* entrance);
Register ARM::GetRegister(ScopeItem* variable);//分配空余寄存器
Register ARM::FinfRegister(ScopeItem* variable);//查找存有对应变量的寄存器


String ARM::toString();//生成汇编文本



#endif