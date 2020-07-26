#ifndef ARM_H
#define ARM_H



#include<stdio.h>
#include<stdlib.h>
#include <string>
#include<list>
#include <assert.h>
#include"../IntermediateCode/TAC.h"
#include"ArmInstruction.h"

using std::string;
using std::list;
using std::cout;
using std::endl;

#define FUNCSTACKSIZE 64

typedef struct RegisterEntry
//寄存器描述符，用于描述15个寄存器的状态
{
      bool filled;         // 是否使用
      int tag;           // Tag for LRU algorithm
      ScopeItem variable;     // 存储的变量对象
      
} RegisterEntry;





class ARM {
private:
      list<ARMInstruction*> InsList; //生成的汇编代码序列
      RegisterEntry regs[15];// 用户可用寄存器


      Register GetRegister(ScopeItem* variable); //分配或者获取已经分配的空余寄存器
      int FinfRegister(ScopeItem* variable);//查找存有对应变量的寄存器
      void EmptyRegister();//清空用户使用寄存器
      //void AllocateHeap(ScopeItem & variable, int &offset);//给变量在堆中分配地址
      void AllocateStack(ScopeItem * variable, int &offset);//给变量在栈中分配地址

public:

      ARM(TACCode* entrance, ScopeItem &scopeItem);
     
      string toString();//生成汇编文本


};




#endif
