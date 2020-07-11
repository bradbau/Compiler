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
void ARMInstruction::setsecondtOp(Register firstOp){
    this->op2.reg2=secondtOp;
    this->op2Type=0;
}
void ARMInstruction::setsecondtOp(Register secondtOp, int op2Type){
    //设置第二寄存器
    switch(op2Type){
        case 0:{
            this->op2.reg2=secondtOp;
            this->op2Type=op2Type;
            break;

        }
        case 1:{
            this->op2.instantNum=secondtOp;
            this->op2Type=op2Type;
            break;
        }

    }
}






//~~~~~~~~~~~~~~~~~~~end of class ARMInstruction~~~~~~~~~~~~~~~~~




//~~~~~~~~~~~~~~~~~~ mem Instruction~~~~~~~~~~~~~~~~~~~~~~


void MemoryInstruction(InstrcuctionType type, Register rd, Register op1, Register op2, int op2Type, int instantEffect){
    // 产生一个内存相关指令
    


    switch(op2Type){
        case 0:{
            //寄存器
            break;

        }
        case 1:{
            //立即数
            this->type=type;
            this->rd=rd;
            this->op1=op1;
            this->op2.instantNum=offset;
            this->op2Type=2;
            this->instantEffect=instantEffect;
            break;

        }
        case 2:{
            
            break;
        }
    }
}



//~~~~~~~~~~~~~~ end of mem Instruction~~~~~~~~~~~~~~~~~~~~