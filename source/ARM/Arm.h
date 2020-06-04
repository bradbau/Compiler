#ifndef ARM_H
#define ARM_H



#include<stdio.h>
#include<stdlib.h>
#include <string>
#include<list>
#include"TAC.h"
#include"ARMInstruction.h"


typedef struct RegDepictorEntry
{
        int filled;         // Imply if the register is allocated
        int used;           // Tag for LRU algorithm
        Scope variable;     // The variable in register if there is
    
} RegDepictorEntry;





class ARM {
private:
      list<ARMInstruction> ARMInsList; //生成的汇编代码序列
      

public:
      ARM();//


      String toString();






};

#endif