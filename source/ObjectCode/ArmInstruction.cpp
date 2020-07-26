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
    ARMInstruction::setOp1Type(0);
    ARMInstruction::setOp2(op2);
    ARMInstruction::setOp2Type(op2Type);
    ARMInstruction::setConditionExe(AL);
}


CalculateInstruction::CalculateInstruction(InstrcuctionType type, Register rd, int op1, int op1Type){
    //cmp rd r1
    ARMInstruction::setType(type);
    ARMInstruction::setRd(rd);
    ARMInstruction::setOp1(op1);
    ARMInstruction::setOp1Type(op1Type);
    ARMInstruction::setOp2(-1);
    ARMInstruction::setOp2Type(-1);
    ARMInstruction::setConditionExe(AL);
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
            InsHead=InsHead+"\n";
            return InsHead;
            
        }
        case INSADD:{
            //add指令有立即数相加和寄存器内容相加

            string InsHead="ADD ";
            if(ARMInstruction::getConditionExe()!=0){//条件执行后缀
                InsHead=InsHead+ConditionName[ARMInstruction::getConditionExe()];
            }
            assert(ARMInstruction::getOp1Type()==0);
            assert(ARMInstruction::getRd()>=0&&ARMInstruction::getRd()<=15 );

            if(ARMInstruction::getOp2Type()==0){//寄存器
                sprintf(buf, " %s, %s, %s", RegName[ARMInstruction::getRd()], RegName[ARMInstruction::getOp1()], RegName[ARMInstruction::getOp2()]);

            }
            else if(ARMInstruction::getOp2Type()==1) { //立即数
                sprintf(buf, " %s, %s, #%d", RegName[ARMInstruction::getRd()], RegName[ARMInstruction::getOp1()], ARMInstruction::getOp2());
            }
            else {
                throw std::runtime_error("ADD msg wrong 1\n");
                //可能会增加类型
            }
            InsHead=InsHead+buf;
            InsHead=InsHead+"\n";
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
            InsHead=InsHead+buf;
            InsHead=InsHead+"\n";
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
            InsHead=InsHead+buf;
            InsHead=InsHead+"\n";
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
            InsHead=InsHead+buf;
            InsHead=InsHead+"\n";
            return InsHead;
        }
        case INSCMP:{
            string InsHead="CMP";
            if(ARMInstruction::getConditionExe()!=0){//条件执行后缀
                InsHead=InsHead+ConditionName[ARMInstruction::getConditionExe()];
            }
            sprintf(buf, " %s, %s, %s", RegName[ARMInstruction::getRd()], RegName[ARMInstruction::getOp1()]);
            InsHead=InsHead+buf;
            InsHead=InsHead+"\n";
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
    
    ARMInstruction::setRd(0);
    ARMInstruction::setOp1(-1);
    ARMInstruction::setOp1Type(-1);
    ARMInstruction::setOp2(-1);
    ARMInstruction::setOp2Type(-1);
    
}

/*
bx lr # bx r14


*/

ControlInstruction::ControlInstruction(InstrcuctionType type, Register rd){
    setType(type);
    setRd(rd);

    ARMInstruction::setOp1(-1);
    ARMInstruction::setOp1Type(-1);
    ARMInstruction::setOp2(-1);
    ARMInstruction::setOp2Type(-1);
    ARMInstruction::setConditionExe(AL);
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
            InsHead=InsHead+label;
            InsHead=InsHead+"\n";
            return InsHead;

        }
        case INSBL:{
            string InsHead="BL";
            if(ARMInstruction::getConditionExe()!=0){//条件执行后缀
                InsHead=InsHead+ConditionName[ARMInstruction::getConditionExe()];
            }
            InsHead=InsHead+" ";
            InsHead=InsHead+label;
            InsHead=InsHead+"\n";
            return InsHead;
        }
        case INSBX:{
            string InsHead="BX";
            if(ARMInstruction::getConditionExe()!=0){//条件执行后缀
                InsHead=InsHead+ConditionName[ARMInstruction::getConditionExe()];
            }
            sprintf(buf, " %s\n", RegName[ARMInstruction::getRd()]);
            InsHead=InsHead+buf;
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
            setOp1Type(0);
            
            setOp2(op2);
            setOp2Type(op2Type);
            setConditionExe(AL);
            break;

        }
        case 1:{
            //立即数
            setType(type);
            setRd(rd);
            setOp1(op1);  
            setOp2(op2);
            setOp1Type(0);
            setOp2Type(op2Type);
            this->instantEffect=instantEffect;
            setConditionExe(AL);
            break;
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
       
        setOp2Type(-1);
        setConditionExe(AL);
        this->addrMod=-1;
        this->multipleSource=0;
        this->instantEffect=-1;
    }
    else{
        
        //错误处理
    }
    
 }

MemoryInstruction::MemoryInstruction(InstrcuctionType type, Register rd){
    //push pop简单指令生成
    if(type==INSPUSH|| type==INSPOP){

        setType(type);
        setRd(rd);
        setOp1(-1);
        setOp2(-1);

       
        ARMInstruction::setOp1Type(-1);
        ARMInstruction::setOp2Type(-1);
        ARMInstruction::setConditionExe(AL);


        this->addrMod=-1;
        this->multipleSource=-1;
        this->instantEffect=-1;
    }
    else{
        throw std::runtime_error("MemoryInstruction construct err");
        //错误处理
    }
}

string MemoryInstruction::toString(){
    char * buf;
    buf=(char*)malloc(64*sizeof(char));
    string InsHead;
    switch(ARMInstruction::getType()){
        case INSPUSH:{
            #ifdef DEBUG
            cout<<"push instruction"<<endl;
            assert(ARMInstruction::getOp2()<0);
            #endif // DEBUG
            InsHead="PUSH";
            if(ARMInstruction::getConditionExe()!=0){//条件执行后缀
                InsHead=InsHead+ConditionName[ARMInstruction::getConditionExe()];
            }
            InsHead=InsHead+" {";
            InsHead=InsHead+RegName[ARMInstruction::getRd()];

            if(ARMInstruction::getOp1()>=0){
                sprintf(buf, ", %s", RegName[ARMInstruction::getOp1()]);
                InsHead=InsHead+buf;
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


            InsHead=InsHead+"}\n";
            break;
        }
        case INSPOP:{
            InsHead="POP";
            if(ARMInstruction::getConditionExe()!=0){//条件执行后缀
                InsHead=InsHead+ConditionName[ARMInstruction::getConditionExe()];
            }
            InsHead=InsHead+" {";
            InsHead=InsHead+RegName[ARMInstruction::getRd()];
            if(ARMInstruction::getOp1()>=0){
                sprintf(buf, ", %s", RegName[ARMInstruction::getOp1()]);
                InsHead=InsHead+buf;
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


            InsHead=InsHead+"}\n";
            break;
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
                sprintf(buf," %s, [%s, %s]\n",  RegName[ARMInstruction::getRd()], ARMInstruction::getOp1(), ARMInstruction::getOp2());
                InsHead=InsHead+buf;
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
            break;

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
                    #ifdef DEBUG
                    cout<<"buf contents: "<<buf<<endl;
                    #endif // DEBUG
                    InsHead=InsHead+buf;
                }
                else if(ARMInstruction::getOp2Type()==1){
                    //op2Type==1
                    #ifdef DEBUG
                        cout<<"op2type==1"<<endl;
                    #endif // DEBUG
                    if(instantEffect==0){
                        //直接使用的立即数，不对寄存器内数据产生影响
                        sprintf(buf," %s, [%s, 0x%x]",  RegName[ARMInstruction::getRd()],  RegName[ARMInstruction::getOp1()], ARMInstruction::getOp2());
                        InsHead=InsHead+buf;
                    }
                    else if(instantEffect==1){
                        //改变第一操作数的偏移量
                        sprintf(buf," %s, [%s, 0x%x]!",  RegName[ARMInstruction::getRd()],  RegName[ARMInstruction::getOp1()], ARMInstruction::getOp2());
                        InsHead=InsHead+buf;
                    }
                    else if(instantEffect==2){
                        //只改变第一操作数.不影响计算结果
                        
                        sprintf(buf," %s, [%s], 0x%x",  RegName[ARMInstruction::getRd()],  RegName[ARMInstruction::getOp1()], ARMInstruction::getOp2());
                        InsHead=InsHead+buf;
                    }
                    else{
                        //错误处理
                        throw std::runtime_error("ldr msg wrong 1\n");
                    }
                }
                else{
                    #ifdef DEBUG
                    cout<<"ldr op1="<<ARMInstruction::getOp1()<<endl;
                    #endif // DEBUG
                    sprintf(buf," %s, [%s]",  RegName[ARMInstruction::getRd()],  RegName[ARMInstruction::getOp1()]);
                    InsHead=InsHead+buf;
                }
            }
            else{
                //op1Type==1
                //ldr rd, =const
                #ifdef DEBUG
                cout<<"ldr rd, =const"<<endl;
                
                #endif // DEBUG
                
                sprintf(buf," %s, =0x%x",  RegName[ARMInstruction::getRd()], ARMInstruction::getOp1());
                #ifdef DEBUG
                    cout<<"buf contents: "<<buf<<endl;
                #endif // DEBUG
                InsHead=InsHead+buf;
            }

            InsHead=InsHead+"\n";
            break;
        }
        case INSSTM:{

            break;
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

    ARMInstruction::setType(INSADD);
    ARMInstruction::setRd(0);
    ARMInstruction::setOp1(-1);
    ARMInstruction::setOp1Type(-1);
    ARMInstruction::setOp2(-1);
    ARMInstruction::setOp2Type(-1);
    ARMInstruction::setConditionExe(AL);
}
string LabelInstruction::toString(){
    //指向该标记的完整指令字符串

    return content+":\n";
}