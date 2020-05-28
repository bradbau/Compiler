#include<stdio.h>
#include<stdlib.h>
#include <string>
#include"TACCode.h"
using namespace std;

typedef enum {R0, R1,R2, R3,R4,R5,R6,  // 这一部分是通用寄存器
      R7, // syscall 
    R8,R9,R10
    ,R11 //帧指针 frame pointer
    ,R12 //Intra Procedural Call
    ,R13 //Stack Pointer
    ,R14//Link Register
    ,R15//Program Counter
    ,CPSR//Current Program Status Register 
    } Register;

typedef struct RegDepictorEntry
{
        int filled;         // Imply if the register is allocated
        int used;           // Tag for LRU algorithm
        Scope variable;     // The variable in register if there is
    
} RegDepictorEntry;
extern int darg;
extern int marg;

int AllocateLocal(LocalScope localvariable, int offset);


class Arms {
  private:
    
    Register lastUsed;

    typedef enum { ForRead, ForWrite } Reason;
    //保存指令
    string *st;
    string *pre;
    string *next;

    

 public:
    
    Arms();
    
    //获取reg,应该比较复杂，可能需要更多参数
    Register GetRegister(Scope variable);
    //产生指令
    void GenerateObjectCode(TACCode* entrance);
    //更新reg
    void SpillRegister(Register reg);
    void SpillAllDirtyRegisters();
    void SpillForEndFunction();

    void EmitCallInstr(Location *dst, const char *fn, bool isL);
    

    //一系列用于优化的函数，从学长那里copy，目前不知道要怎么优化所以不知道怎么写
    static void Emit();
    
    void EmitLoadConstant(Location *dst, int val);
    void EmitLoadStringConstant(Location *dst, const char *str);
    void EmitLoadLabel(Location *dst, const char *label);

    void EmitLoad(Location *dst, Location *reference, int offset);
    void EmitStore(Location *reference, Location *value, int offset);
    void EmitCopy(Location *dst, Location *src);
    
    void EmitBinaryOp(BinaryOp::OpCode code, Location *dst, 
			    Location *op1, Location *op2);

    void EmitLabel(const char *label);
    void EmitGoto(const char *label);
    void EmitIfZ(Location *test, const char*label);
    void EmitReturn(Location *returnVal);
    
    void EmitBeginFunction(int frameSize);
    void EmitEndFunction();

    void EmitParam(Location *arg);
    void EmitLCall(Location *result, const char* label);
    void EmitACall(Location *result, Location *fnAddr);
    void EmitPopParams(int bytes);
    
    void EmitVTable(const char *label, List<const char*> *methodLabels);

    void EmitPreamble();
};
