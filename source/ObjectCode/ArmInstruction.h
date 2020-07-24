#ifndef ARMINSTRUCTION_H
#define ARMINSTRUCTION_H

#include<string>
using std::string;


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
        INSMOV,//	Move data	
        INSMVN,//	Move and negate
        INSADD,//	Addition	
        INSSUB,//	Subtraction	
        INSMUL,//	Multiplication	
        INSSDIV,// signed divition
        INSLSL,//	Logical Shift Left	
        INSLSR,//	Logical Shift Right	
        INSASR,//	Arithmetic Shift Right	
        INSROR,//	Rotate Right	
        INSCMP,//	Compare	BX	
        INSAND,//	Bitwise AND	
        INSORR,//	Bitwise OR	
        INSEOR,//	Bitwise XOR


	    INSLDR,//	Load
        INSSTR,//	Store
        INSLDM,//	Load Multiple
        INSSTM,//	Store Multiple
        INSPUSH,//	Push on Stack
        INSPOP,//	Pop off Stack


        INSB	,//Branch
        INSBL,//	Branch with Link
        INSBX,//Branch and eXchange
        INSBLX,//	Branch with Link and eXchange


        INSSVC,//	System Call


        INSADR //取地址操作



    }InstrcuctionType;


typedef enum {
    AL,
    EQ,
    NE,
    CS,  // HS
    CC,//      C清零        无符号数小于       LO
    MI,//    N置位        负数               ML
    PL,//      N清零        正数或零
    VS,//     V置位        溢出
    VC,//      V清零        未溢出
    HI,//      C置位Z清零      无符号数大于
    LS,//      C清零Z置位      无符号数小于或等于
    GE,//      N等于V      带符号数大于或等于
    LT,//      N不等于V      带符号数小于
    GT,//      Z清零且（N等于V)  带符号数大于
    LE,//
} ConditionFlag;

constexpr static Register userReg[10]={R0, R1,R2, R3,R4,R5,R6, R8,R9,R10};

    constexpr static char MemSuffixName[4][3]={
        "ia", "ib","da", "db"
    };

//~~~~~~~~~~~~~~~~~ class ARMInstruction ~~~~~~~~~~~~~~~~~~~~~~~~~~~

class ARMInstruction{
    //所有指令的基类

public:


    


const char RegName[16][10]={
    "r0","r1","r2","r3","r4","r5","r6","r7","r8","r9","r10",
    "fp","r12","sp","lr","pc"
};

const char ConditionName[15][3]={
    "AL",
    "EQ",
    "NE",
    "CS",  // HS
    "CC",//      C清零        无符号数小于       LO
    "MI",//    N置位        负数               ML
    "PL",//      N清零        正数或零
    "VS",//     V置位        溢出
    "VC",//      V清零        未溢出
    "HI",//      C置位Z清零      无符号数大于
    "LS",//      C清零Z置位      无符号数小于或等于
    "GE",//      N等于V      带符号数大于或等于
    "LT",//      N不等于V      带符号数小于
    "GT",//      Z清零且（N等于V)  带符号数大于
    "LE",//
};

private:
    InstrcuctionType type;
    bool flagsuffix; //对应指令中是否有s标记，用来说明指令是否根据结果设置条件位
    ConditionFlag ConditionExe;
    Register rd;//目标寄存器
    
    int op1;
    int op1Type=0;
    int op2Type=0;// 0 1 代表寄存器，立即数
    int op2;


public:

    virtual string toString()=0; //纯虚函数，本类型为抽象类


    InstrcuctionType  getType(){return type;}
    int  getRd(){return rd;}
    int  getOp1(){return op1;}
    int  getOp2(){return op2;}
    int getOp1Type(){return op1Type;}
    int getOp2Type(){return op2Type;}
    bool getFlagsuffix(){return flagsuffix;}
    ConditionFlag getConditionExe(){return ConditionExe;}


    void  setType(InstrcuctionType type);//设置类型
    void  setRd(int rd);//设置目标寄存器
    void  setOp1(int op1);//设置第一寄存器
    void  setOp2(int op2);//设置第二寄存器
    void setOp1Type(int op1Type);
    void  setOp2Type(int op2Type);
    void  setConditionExe(int ConditionExe);
};








//~~~~~~~~~~~~~~~~~~~~~~end of class ARMInstruction~~~~~~~~~~~~~~~~~~~~~~~~~~~



class CalculateInstruction: public ARMInstruction// 计算类型的指令
{
public:
    CalculateInstruction();// 产生一个计算指令
    CalculateInstruction(InstrcuctionType type, Register rd, int op1, int op2, int op2Type);
    CalculateInstruction(InstrcuctionType type, Register rd, int op1, int op1Type);//mov cmp
    string toString();

};

//~~~~~~~~~~~~~~~~~~~~~~ControlInstruction~~~~~~~~~~~~~~~~~~~~~~~~~~~

/*
两种跳转方式
1.mov pc, <跳转地址〉 这种算计算指令
这种向程序计数器PC直接写跳转地址，能在4GB连续空间内任意跳转。
2.通过 B BL BLX BX 可以完成在当前指令向前或者向后32MB的地址空间的跳转

BL Label  当程序无条件跳转到标号 Label 处执行时，同时将当前的 PC 值保存到 R14 中

函数跳转之前，通过压栈保存fp lr 

目前还缺少一个目标标识，


*/

class ControlInstruction: public ARMInstruction
{
private:
    string label;
public:
    //void ControlInstruction();// 产生一个控制指令
    ControlInstruction(InstrcuctionType type, Register rd);
    ControlInstruction(InstrcuctionType type, string label, ConditionFlag ConditionExe);
    string toString();
    string getLabel(){return label;}
};


//~~~~~~~~~~~~~~~~~~~~~~~~~~~end of ControlInstruction~~~~~~~~~~~~~~~~~


class MemoryInstruction: public ARMInstruction//内存相关指令
{
    /*内存相关指令的格式

    1. 指令操作码 ldr str ldm stm push pop 

    2. 操作数类型 
    - Ra, [Rb, imm] 以第一操作数的寄存器内容作为偏移量基址的
    - r0, [pc, #12] 以pc为基址的
    - Ra, [Rb, Rc] 寄存器内容为偏移量
    -*Ra, [Rb, Rc, <shifter>] 包含移位运算的寄存器为偏移量

    stmfd sp!, {r0-r9, lr} 满递减入栈,给寄存器r0-r9,lr压栈,sp不断减4
    ldmfd sp!, {r0-r9, pc} 满递减出栈,给寄存器r0-r9出栈，并使程序跳转回函
    3. 后缀
    instantEffect 决定第二操作数的立即数类型：偏移量，改变第一操作数的偏移量，只改变第一操作数
    多

    */

public:
    typedef enum{
        ia, ib, da, db
    } MemSuffix;//内存相关后缀

private:
    //这里添加内存指令相关的信息
    int multipleSource;//如果为真就表示在op1和op2寄存器之外加{}符号，表示多个寄存器连续操作
    int instantEffect; // 取值0 1 2 决定第二操作数的立即数类型：偏移量，改变第一操作数的偏移量，只改变第一操作数
    MemSuffix addrMod;//地址模式，默认为0 ，一般对
public:
    MemoryInstruction();// 产生一个内存相关指令
    MemoryInstruction(InstrcuctionType type, Register rd);//push pop专用指令生成
    MemoryInstruction(InstrcuctionType type, Register rd, int op1, int op1Type);//普通的寄存器str ldr操作， op2=-1
    MemoryInstruction(InstrcuctionType type, Register rd, int op1, int op2, int op2Type, int instantEffect);// 产生一个内存相关指令
    
    string toString();
    int getMultipleSource(){return (int)multipleSource;}
    int getInstantEffect(){return instantEffect;}
    MemSuffix getAddrMod(){return addrMod;}

    void setInstantEffect(int instantEffect){this->instantEffect=instantEffect;}

};

//~~~~~~~~~~~~~~~~~~~~~~~~~



class LabelInstruction: public ARMInstruction
{
    //这个类可以表示标记，函数名或者label，也可以表示目标为这个标记的跳转指令

private:
    std::string content;//标记字符串
   

public:
    LabelInstruction(string content); 

    string getContent(){return content;}// 生成标记字符串
    string toString();//指向该标记的完整指令字符串


};









#endif // !ARMINSTRUCTION_H
