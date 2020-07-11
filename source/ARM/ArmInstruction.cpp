#include"ArmInstruction.h"


//~~~~~~~~~~~~~~~~~ class ARMInstruction ~~~~~~~~~~~~~~~~~~~~~~~~~~~

void ARMInstruction::setType(InstrcuctionType type){
    //设置类型
    this->type=type;
}

void ARMInstruction::setRd(Register Rd){
    //设置目标寄存器
    this->Rd=Rd;
}

void ARMInstruction::setfirstOp(Register firstOp){
    //设置第一寄存器
}
void ARMInstruction::setsecondtOp(Register secondtOp, int op2Type){
    //设置第二寄存器
    switch(op2Type){
        case 0:{
            this->op2.reg2=secondtOp;
            break;

        }
        case 1:{
            this->op2.instantNum=secondtOp;
            break;
        }

    }
}






//~~~~~~~~~~~~~~~~~~~end of class ARMInstruction~~~~~~~~~~~~~~~~~




//~~~~~~~~~~~~~~~~~~ mem Instruction~~~~~~~~~~~~~~~~~~~~~~


void MemoryInstruction(InstrcuctionType type, Register rd, Register op1, Register op2, int op2Type){
    // 产生一个内存相关指令
    


    switch(op2Type){
        case 0:{
            break;

        }
        case 1:{
            break;

        }
        case 2:{
            this->type=type;
            this->rd=rd;
            this->op1=op1;
            this->op2.instantNum=offset;
            this->op2Type=2;
            break;
        }
    }
}



//~~~~~~~~~~~~~~ end of mem Instruction~~~~~~~~~~~~~~~~~~~~