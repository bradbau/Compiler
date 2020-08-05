#ifndef ARM_H
#define ARM_H

#define DEBUG

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
using std::runtime_error;

#define FUNCSTACKSIZE 64

typedef struct RegisterEntry
//寄存器描述符，用于描述15个寄存器的状态
{
      bool filled;         // 是否使用
      int tag;           // Tag for LRU algorithm
      
      
            ScopeItem* variable;     // 存储的变量对象
            ARRAY_ADDR* array_addr;//数组对象
      
      //int instantNum; 不一定有用，记录寄存器内容的具体值
} RegisterEntry;





class ARM {
private:
      list<ARMInstruction*> InsList; //生成的汇编代码序列
      RegisterEntry regs[15];// 用户可用寄存器

      CalculateInstruction* StackSubHandler=NULL;//用来保存函数中为局部变量分配空间的语句的句柄 sub sp sp imm
      
      Register GetRegister(ScopeItem* variable); //分配或者获取已经分配的空余寄存器
      Register GetRegister(ARRAY_ADDR* array_addr); //分配或者获取已经分配的空余寄存器
      Register GetRegisterNoLoad(ScopeItem* variable); //分配或者获取已经分配的空余寄存器
      Register GetRegisterNoLoad(ARRAY_ADDR* array_addr); //分配或者获取已经分配的空余寄存器
      
      int FindRegister(ScopeItem* variable);//查找存有对应变量的寄存器
      int FindRegister(ARRAY_ADDR* array_addr);//查找存有对应变量的寄存器
      
      int LoadInstantToRegister(int instantNum);//加载一个一次性的立即数到空寄存器中，不统计内容
      void EmptyRegister();//清空用户使用寄存器
      //void AllocateHeap(ScopeItem & variable, int &offset);//给变量在堆中分配地址

      void AllocateStack(ScopeItem * variable, int &offset);//给变量在栈中分配地址


      void StoreRegister(int RegisterNum);//将这个寄存器内的变量保存到它内部offset指向的内存地址
      
      

public:

      ARM(TACCode* entrance,  ScopeItem *GlobalItemHead, vector<ScopeItem> &stack);
     
      string toString();//生成汇编文本


};

      bool operator==(ScopeItem t1, ARRAY_ADDR t2);
      bool operator==(ARRAY_ADDR t1, ScopeItem t2);


#endif
