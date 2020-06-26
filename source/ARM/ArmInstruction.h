#ifndef ARMINSTRUCTION_H
#define ARMINSTRUCTION_H

#include<String>


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

typedef enum{
        MOV,//	Move data	
        MVN,//	Move and negate
        ADD,//	Addition	
        SUB,//	Subtraction	
        MUL,//	Multiplication	
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
    union op2
    {
        Register reg2; // 
        int instantNum;//立即数
    }

public:



    virtual String toString()=0; //本类型为抽象类

}

class CalculateInstruction: public ARMInstruction// 计算类型的指令
{
public:
    void CalculateInstruction();// 产生一个计算指令
    
    String toString();

}

class ControlInstruction: public ARMInstruction
{
public:
    void ControlInstruction();// 产生一个控制指令
    
    String toString();

}

class MemoryInstruction: public ARMInstruction//内存相关指令
{

public:
    typedef enum{
        no, ia, ib, da, db
    } MemSfx;//内存相关后缀
private:
    //这里添加内存指令相关的信息
    bool multipleSource;//如果为真就表示在op1和op2寄存器之外加{}符号，表示多个寄存器连续操作


public:
    void MemoryInstruction();// 产生一个内存相关指令
    
    String toString();

}









#endif // !ARMINSTRUCTION_H
