#include"ArmInstruction.h"


//~~~~~~~~~~~~~~~~~ class ARMInstruction ~~~~~~~~~~~~~~~~~~~~~~~~~~~



void ARMInstruction::setType(InstrcuctionType type){
    //设置类型
    this->type=type;
}




void ARMInstruction::setRd(int rd){
    //设置目标寄存器
    this->rd=(Register)rd;
}


void ARMInstruction::setOp1(int op1){
    //设置第一寄存器
    this->op1=(Register)op1;
}

void ARMInstruction::setOp2(int op2){
    this->op2=op2;

}

void ARMInstruction::setOp1Type(int op1Type){
    this->op1Type=op1Type;
}
void ARMInstruction::setOp2Type(int op2Type){
    //设置第二寄存器
    this->op2Type=op2Type;
}

void ARMInstruction::setConditionExe(int ConditionExe){
    this->ConditionExe= (ConditionFlag)ConditionExe;
}






//~~~~~~~~~~~~~~~~~~~end of class ARMInstruction~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~
CalculateInstruction::CalculateInstruction(InstrcuctionType type, Register rd, int op1, int op2, int op2Type){
    ARMInstruction::setType(type);
    ARMInstruction::setRd(rd);
    ARMInstruction::setOp1(op1);
    ARMInstruction::setOp2Type(op2Type);
    ARMInstruction::setOp2(op2);
}


CalculateInstruction::CalculateInstruction(InstrcuctionType type, Register rd, int op1, int op1Type){
    //cmp rd r1
    ARMInstruction::setType(type);
    ARMInstruction::setRd(rd);
    ARMInstruction::setOp1(op1);
    ARMInstruction::setOp1Type(op1Type);
    ARMInstruction::setOp2(-1);
    ARMInstruction::setOp2Type(-1);
    
}

string CalculateInstruction::toString(){
    char * buf;
    buf=(char*)malloc(64*sizeof(char));
    switch(ARMInstruction::getType()){
        case INSMOV:{
            //所有的mov指令都是两个寄存器
            string InsHead="MOV";
            if(ARMInstruction::getConditionExe()!=0){//条件执行后缀
                InsHead=InsHead+ConditionName[ARMInstruction::getConditionExe()];
            }
            if(ARMInstruction::getOp1Type()==0){ //op1是寄存器
                sprintf(buf, " %s, %s", RegName[ARMInstruction::getRd()], RegName[ARMInstruction::getOp1()]);
            }
            else{//op1是立即数
                sprintf(buf, " %s, %d", RegName[ARMInstruction::getRd()], ARMInstruction::getOp1());
            }
            
            InsHead=InsHead+buf;
            return InsHead;
            
        }
        case INSADD:{
            //add指令有立即数相加和寄存器内容相加

            string InsHead="ADD ";
            if(ARMInstruction::getConditionExe()!=0){//条件执行后缀
                InsHead=InsHead+ConditionName[ARMInstruction::getConditionExe()];
            }
            if(ARMInstruction::getOp2Type()==0){//寄存器
                sprintf(buf, " %s, %s, %s", RegName[ARMInstruction::getRd()], RegName[ARMInstruction::getOp1()], RegName[ARMInstruction::getOp2()]);
            }
            else if(ARMInstruction::getOp2Type()==1) { //立即数
                sprintf(buf, " %s, %s, #%d", RegName[ARMInstruction::getRd()], RegName[ARMInstruction::getOp1()], ARMInstruction::getOp2());
            }
            else {
                //可能会增加类型
            }
            
            return InsHead;
        }
        case INSSUB:{
            string InsHead="SUB";
            if(ARMInstruction::getConditionExe()!=0){//条件执行后缀
                InsHead=InsHead+ConditionName[ARMInstruction::getConditionExe()];
            }
            if(ARMInstruction::getOp2Type()==0){//寄存器
                sprintf(buf, " %s, %s, %s", RegName[ARMInstruction::getRd()], RegName[ARMInstruction::getOp1()], RegName[ARMInstruction::getOp2()]);
            }
            else if(ARMInstruction::getOp2Type()==1) { //立即数
                sprintf(buf, " %s, %s, #%d", RegName[ARMInstruction::getRd()], RegName[ARMInstruction::getOp1()], ARMInstruction::getOp2());
            }
            else {
                //可能会增加类型
            }
            return InsHead;
        }
        case INSMUL:{
            string InsHead="MUL";
            if(ARMInstruction::getConditionExe()!=0){//条件执行后缀
                InsHead=InsHead+ConditionName[ARMInstruction::getConditionExe()];
            }
            if(ARMInstruction::getOp2Type()==0){//寄存器
                sprintf(buf, " %s, %s, %s", RegName[ARMInstruction::getRd()], RegName[ARMInstruction::getOp1()], RegName[ARMInstruction::getOp2()]);
            }
            else if(ARMInstruction::getOp2Type()==1) { //立即数
                sprintf(buf, " %s, %s, #%d", RegName[ARMInstruction::getRd()], RegName[ARMInstruction::getOp1()], ARMInstruction::getOp2());
            }
            else {
                //可能会增加类型
            }
            return InsHead;
        }
        case INSSDIV:{
            string InsHead="SDIV";
            if(ARMInstruction::getConditionExe()!=0){//条件执行后缀
                InsHead=InsHead+ConditionName[ARMInstruction::getConditionExe()];
            }
            if(ARMInstruction::getOp2Type()==0){//寄存器
                sprintf(buf, " %s, %s, %s", RegName[ARMInstruction::getRd()], RegName[ARMInstruction::getOp1()], RegName[ARMInstruction::getOp2()]);
            }
            else if(ARMInstruction::getOp2Type()==1) { //立即数
                sprintf(buf, " %s, %s, #%d", RegName[ARMInstruction::getRd()], RegName[ARMInstruction::getOp1()], ARMInstruction::getOp2());
            }
            else {
                //可能会增加类型
            }
            return InsHead;
        }
        case INSCMP:{
            string InsHead="CMP";
            if(ARMInstruction::getConditionExe()!=0){//条件执行后缀
                InsHead=InsHead+ConditionName[ARMInstruction::getConditionExe()];
            }
            sprintf(buf, " %s, %s, %s", RegName[ARMInstruction::getRd()], RegName[ARMInstruction::getOp1()]);
            InsHead=InsHead+buf;
            return InsHead;
        }
        default:{
            //错误处理
        }
    }
}

//~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~ControlInstruction


ControlInstruction::ControlInstruction(InstrcuctionType type,  string label, ConditionFlag ConditionExe){
    setType(type);
    this->label=label;
    setConditionExe(ConditionExe);
    
}


/*
bx lr # bx r14


*/

ControlInstruction::ControlInstruction(InstrcuctionType type, Register rd){
    setType(type);
    setRd(rd);
}


string ControlInstruction::toString(){
    char * buf;
    buf=(char*)malloc(64*sizeof(char));
    switch(this->ARMInstruction::getType()){
        case INSB:{
            string InsHead="B";
            if(ARMInstruction::getConditionExe()!=0){//条件执行后缀
                InsHead=InsHead+ConditionName[ARMInstruction::getConditionExe()];
            }
            InsHead=InsHead+" ";
            InsHead+=label;
            return InsHead;

        }
        case INSBL:{
            string InsHead="BL";
            if(ARMInstruction::getConditionExe()!=0){//条件执行后缀
                InsHead=InsHead+ConditionName[ARMInstruction::getConditionExe()];
            }
            InsHead=InsHead+" ";
            InsHead+=label;
            return InsHead;
        }
        case INSBX:{
            string InsHead="BX";
            if(ARMInstruction::getConditionExe()!=0){//条件执行后缀
                InsHead=InsHead+ConditionName[ARMInstruction::getConditionExe()];
            }
            sprintf(buf, " %s", RegName[ARMInstruction::getRd()]);
            InsHead+=buf;
            return InsHead;
        }
        case INSBLX:{
            //这个指令目标可以是label也可以是寄存器 暂放
            //错误处理
            break;
        }
        default:{
            //错误处理
        }
    }
}

//~~~~~~~~~~~~~~~~~~~ end of ControlInstruction

//~~~~~~~~~~~~~~~~~~ mem Instruction~~~~~~~~~~~~~~~~~~~~~~


MemoryInstruction::MemoryInstruction(InstrcuctionType type, Register rd, int op1, int op2, int op2Type, int instantEffect){
    // 产生一个内存相关指令
    


    switch(ARMInstruction::getOp2Type()){
        case 0:{
            //寄存器
            setType(type);

            setRd(rd);
            setOp1(op1);
            setOp2Type(op2Type);
            setOp2(op2);


        }
        case 1:{
            //立即数
            setType(type);
            setRd(rd);
            setOp1(op1);  
            setOp2(op2);
            setOp2Type(2);
            this->instantEffect=instantEffect;


        }
        case 2:{
            break;

        }
    }
}

 MemoryInstruction::MemoryInstruction(InstrcuctionType type, Register rd, int op1, int op1Type){
    //普通的寄存器str ldr操作， op2=-1
    if(type==INSLDR||type==INSSTR){
        setType(type);
        setRd(rd);
        setOp1(op1);
        setOp1Type(op1Type);
        setOp2(-1);
    }
    else{
        
        //错误处理
    }
    
 }

MemoryInstruction::MemoryInstruction(InstrcuctionType type, Register rd){
    //push pop专用指令生成
    if(type==INSPUSH|| type==INSPOP){
        setType(type);
        setRd(rd);
        setOp1(-1);
        setOp2(-1);
    }
    else{
        
        //错误处理
    }
}

string MemoryInstruction::toString(){
    char * buf;
    buf=(char*)malloc(64*sizeof(char));
    string InsHead;
    switch(ARMInstruction::getType()){
        case INSPUSH:{
            InsHead="PUSH";
            if(ARMInstruction::getConditionExe()!=0){//条件执行后缀
                InsHead=InsHead+ConditionName[ARMInstruction::getConditionExe()];
            }
            InsHead+=" {";
            InsHead+=RegName[ARMInstruction::getRd()];
            if(ARMInstruction::getOp1()>=0){
                sprintf(buf, ", %s", RegName[ARMInstruction::getOp1()]);
                InsHead+=buf;
            }
            if(ARMInstruction::getOp2()>=0){
                //目前没有这种指令
                if(multipleSource==0){
                    break;
                }
                else if(multipleSource==1){
                    break;
                }
            }


            InsHead+="}";
        }
        case INSPOP:{
            InsHead="POP";
            if(ARMInstruction::getConditionExe()!=0){//条件执行后缀
                InsHead=InsHead+ConditionName[ARMInstruction::getConditionExe()];
            }
            InsHead+=" {";
            InsHead+=RegName[ARMInstruction::getRd()];
            if(ARMInstruction::getOp1()>=0){
                sprintf(buf, ", %s", RegName[ARMInstruction::getOp1()]);
                InsHead+=buf;
            }
            if(ARMInstruction::getOp2()>=0){
                //目前没有这种指令
                if(multipleSource==0){
                    break;
                }
                else if(multipleSource==1){
                    break;
                }
            }


            InsHead+="}";
        }
        case INSSTR:{
            InsHead="STR";
            if(addrMod>=0){
                InsHead=InsHead+MemSuffixName[addrMod];
            }
            if(ARMInstruction::getConditionExe()!=0){//条件执行后缀
                InsHead=InsHead+ConditionName[ARMInstruction::getConditionExe()];
            }
            if(ARMInstruction::getOp2Type()==0){
                sprintf(buf," %s, [%s, %s]",  RegName[ARMInstruction::getRd()], ARMInstruction::getOp1(), ARMInstruction::getOp2());
                InsHead+=buf;
            }
            else{//op2Type==1
                if(instantEffect==0){

                }
                else if(instantEffect==1){

                }
                else if(instantEffect==2){

                }
                else{
                    //错误处理
                }
            }

        }
        case INSLDR:{
            InsHead="LDR";
            if(addrMod>=0){
                InsHead=InsHead+MemSuffixName[addrMod];
            }
            if(ARMInstruction::getConditionExe()!=0){//条件执行后缀
                InsHead=InsHead+ConditionName[ARMInstruction::getConditionExe()];
            }
            if(ARMInstruction::getOp1Type()==0){
                
                if(ARMInstruction::getOp2Type()==0){
                    sprintf(buf," %s, [%s, %s]",  RegName[ARMInstruction::getRd()],  RegName[ARMInstruction::getOp1()], RegName[ARMInstruction::getOp2()]);
                    InsHead+=buf;
                }
                else{//op2Type==1
                    if(instantEffect==0){

                    }
                    else if(instantEffect==1){

                    }
                    else if(instantEffect==2){

                    }
                    else{
                        //错误处理
                    }
                }
            }
            else{
                //op1Type==1
                //ldr rd, =const
                sprintf(buf," %s, =0x%x",  RegName[ARMInstruction::getRd()], ARMInstruction::getOp1());
                InsHead+=buf;
            }

            
        }
        case INSSTM:{


        }
        case INSLDM:{

        }
        default:{
            //错误处理
            break;
        }

    }
    return InsHead;
}


//~~~~~~~~~~~~~~ end of mem Instruction~~~~~~~~~~~~~~~~~~~~



//~~~~~~~~~~~~~~~~~`  label ins~~~~~~~~~~~~~~~~~~~



LabelInstruction::LabelInstruction(string content){
    this->content=content;
}
string LabelInstruction::toString(){
    //指向该标记的完整指令字符串

    return content+":";
}