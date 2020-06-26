#ifndef ARM_H
#define ARM_H



#include<stdio.h>
#include<stdlib.h>
#include <string>
#include<list>
#include"TAC.h"
#include"ARMInstruction.h"


typedef struct RegDepictorEntry
//寄存器描述符，用于描述15个寄存器的状态
{
      int filled;         // 是否使用
      int used;           // Tag for LRU algorithm
      Scope variable;     // 存储的变量对象
      
} RegDepictorEntry;





class ARM {
private:
      list<ARMInstruction> ARMInsList; //生成的汇编代码序列
      

public:
      ARM();//


      String toString();






};

#endif