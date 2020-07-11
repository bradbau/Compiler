#ifndef ARMINSTRUCTION_H
#define ARMINSTRUCTION_H

#include<string>
using std::string;

//~~~~~~~~~~~~~~~~~ class ARMInstruction ~~~~~~~~~~~~~~~~~~~~~~~~~~~

class ARMInstruction{
    //所有指令的基类

public:

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
    
const Register userReg[]={R0, R1,R2, R3,R4,R5,R6, R8,R9,R10}


typedef enum{
        MOV,//	Move data	
        MVN,//	Move and negate
        ADD,//	Addition	
        SUB,//	Subtraction	
        MUL,//	Multiplication	
        SDIV,// signed divition
        LSL,//	Logical Shift Left	
        LSR,//	Logical Shift Right	
        ASR,//	Arithmetic Shift Right	
        ROR,//	Rotate Right	
        CMP,//	Compare	BX	
        AND,//	Bitwise AND	
        ORR,//	Bitwise OR	
        EOR,//	Bitwise XOR
	    LDR,//	Load
        STR,//	Store
        LDM,//	Load Multiple
        STM,//	Store Multiple
        PUSH,//	Push on Stack
        POP,//	Pop off Stack
        B	,//Branch
        BL,//	Branch with Link
        BX,//Branch and eXchange
        BLX,//	Branch with Link and eXchange
        SVC,//	System Call


        ADR //取地址操作



    }InstrcuctionType;

private:
    InstrcuctionType type;
    bool flagsuffix; //对应指令中是否有s标记，用来说明指令是否根据结果设置条件位
    Register rd;//目标寄存器
    
    union op1
    {
        Register reg1;
    
    };
    int op2Type;// 0 1 2代表寄存器，立即数，作用于第一操作数的偏移量
    union op2
    {
        Register reg2; // 
        int instantNum;//立即数
    }

public:

    virtual string toString()=0; //纯虚函数，本类型为抽象类

}


void ARMInstruction::setType(InstrcuctionType type);//设置类型
void ARMInstruction::setRd(Register Rd);//设置目标寄存器
void ARMInstruction::setfirstOp(Register firstOp);//设置第一寄存器
void ARMInstruction::setsecondtOp(Register firstOp);//设置第二寄存器



//~~~~~~~~~~~~~~~~~~~~~~end of class ARMInstruction~~~~~~~~~~~~~~~~~~~~~~~~~~~



class CalculateInstruction: public ARMInstruction// 计算类型的指令
{
public:
    void CalculateInstruction();// 产生一个计算指令
    
    string toString();

}



class ControlInstruction: public ARMInstruction
{
public:
    void ControlInstruction();// 产生一个控制指令
    
    string toString();

}

class MemoryInstruction: public ARMInstruction//内存相关指令
{
    /*内存相关指令的格式

    1. 指令类型 ldr str ldm stm


    */

public:
    typedef enum{
        no, ia, ib, da, db
    } MemSfx;//内存相关后缀
private:
    //这里添加内存指令相关的信息
    bool multipleSource;//如果为真就表示在op1和op2寄存器之外加{}符号，表示多个寄存器连续操作


public:
    void MemoryInstruction();// 产生一个内存相关指令
    void MemoryInstruction(InstrcuctionType type, Register rd, Register op1, Register op2, int op2Type);// 产生一个内存相关指令
    
    string toString();

}
class LabelInstruction: public ARMInstruction
{
    //这个类可以表示标记，函数名或者label，也可以表示目标为这个标记的跳转指令

private:
    string content;//标记字符串

public:

    string LabelString(){return content};// 生成标记字符串
    string InstoString();//指向该标记的完整指令字符串


}









#endif // !ARMINSTRUCTION_H
