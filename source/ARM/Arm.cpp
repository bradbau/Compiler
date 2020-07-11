#include"Arm.h"
#include"ArmInstruction.h"


ARM::ARM(TACCode* entrance){//根据输入的中间代码完成初始化，生成目标代码

    //初始化代码


    //中间代码翻译

    while(entrance){
        Quadruple code= entrance->code;
        switch(code.optype){

            case ASSIGN: 
                //赋值，目的操作数可以是变量也可以是内存地址，
                //code.dest一直是variable类型，没有别的类型
                {
                    assert(code.dest==VARIABLE);
                    if(code.firstOp.Type== VARIABLE){ 
                        //变量赋值

                        //添加指令元素
                        CalculateInstruction InsItem;
                        InsItem.setType(InstrcuctionType::ADD);//这里也可以用mov
                        InsItem.setRd(GetRegister(code.dest.Data.variable));
                        InsItem.setfirstOp(GetRegister(code.firstOp.Data.variable));
                        InsItem.setsecondOp(0, 1);
                        //插入指令序列
                        InsList.push_back(InsItem);
                    }
                    else if(code.firstOp.Type== INTEGERCONST){
                        //常量赋值


                        //添加指令元素
                        CalculateInstruction InsItem;
                        InsItem.setType(InstrcuctionType::ADD);//这里也可以用mov
                        InsItem.setRd(GetRegister(code.dest.Data.variable));
                        InsItem.setfirstOp(GetRegister(code.firstOp.Data.variable));
                        InsItem.setsecondOp(0, 1);
                        //插入指令序列
                        InsList.push_back(InsItem);
                    }
                    else{
                        //错误处理
                    }
                    break;
                }
            case ADD:
                //变量与常量相加
                //第一个和第二个操作数的类型固定
                {
                    assert(code.dest.Type = VARIABLE);
                    assert(code.firstOp.Type = VARIABLE);
                    assert(code.secondOp.Type = VARIABLE);

                    //添加指令元素
                    CalculateInstruction InsItem;
                    InsItem.setType(InstrcuctionType::ADD);
                    InsItem.setRd(GetRegister(code.dest.Data.variable));
                    InsItem.setfirstOp(GetRegister(code.firstOp.Data.variable)); //第二操作数是变量
                    InsItem.setsecondOp(GetRegister(code.secondOp.Data.variable), 0);//寄存器


                    InsList.push_back(InsItem);
                    break;
                }
                
                
            case SUB:
            {
                assert(code.dest.Type = VARIABLE);
                assert(code.firstOp.Type = VARIABLE);
                assert(code.secondOp.Type = VARIABLE);
                    
                //添加指令元素
                CalculateInstruction InsItem;
                InsItem.setType(InstrcuctionType::SUB);
                InsItem.setRd(GetRegister(code.dest.Data.variable));
                InsItem.setfirstOp(GetRegister(code.firstOp.Data.variable)); //第二操作数是变量
                InsItem.setsecondOp(GetRegister(code.secondOp.Data.variable), 0);//寄存器


                InsList.push_back(InsItem);


                break;
            }
            case MUL:
            {
                assert(code.dest.Type = VARIABLE);
                assert(code.firstOp.Type = VARIABLE);
                assert(code.secondOp.Type = VARIABLE);

                CalculateInstruction InsItem;
                InsItem.setType(InstrcuctionType::MUL);
                InsItem.setRd(GetRegister(code.dest.Data.variable));
                InsItem.setfirstOp(GetRegister(code.firstOp.Data.variable)); //第二操作数是变量
                InsItem.setsecondOp(GetRegister(code.secondOp.Data.variable), 0);//寄存器


                InsList.push_back(InsItem);

                break;
            }
            case DIV:

            {
                assert(code.dest.Type = VARIABLE);
                assert(code.firstOp.Type = VARIABLE);
                assert(code.secondOp.Type = VARIABLE);
                break;

                CalculateInstruction InsItem;
                InsItem.setType(InstrcuctionType::SDIV);// 在31位以内时用有符号除法没有溢出限制
                InsItem.setRd(GetRegister(code.dest.Data.variable));
                InsItem.setfirstOp(GetRegister(code.firstOp.Data.variable)); //第二操作数是变量
                InsItem.setsecondOp(GetRegister(code.secondOp.Data.variable), 0);//寄存器


                InsList.push_back(InsItem);
            }
            case MOD:
            {
                assert(code.dest.Type = VARIABLE);
                assert(code.firstOp.Type = VARIABLE);
                assert(code.secondOp.Type = VARIABLE);

                CalculateInstruction InsItem;
                InsItem.setType(InstrcuctionType::SUB);
                InsItem.setRd(GetRegister(code.dest.Data.variable));
                InsItem.setfirstOp(GetRegister(code.firstOp.Data.variable)); //第二操作数是变量
                InsItem.setsecondOp(GetRegister(code.secondOp.Data.variable), 0);//寄存器


                InsList.push_back(InsItem);

                break;
            }
            case FUNCTIONDF:
            {
                //函数标记指令
                
                


                break;
            }
            case PARAM:
            {
                break;
            }
            case LABELDF:
            {
                break;
            }
            case IFLTGOTO:
            {
                break;
            }
            case IFLEGOTO:
            {
                break;
            }
            case IFGTGOTO:
            {
                break;
            }
            case IFGEGOTO:
            {
                break;
            }
            case IFEQGOTO:
            {
                break;
            }
            case IFNEQGOTO:
            {
                break;
            }
            case GOTO:   //关于goto的贴近arm的缩减稍后进行
            {
                break;
            }
            case RETURN:
            {
                break;
            }
            case ARG:
            {
                break;
            }
            case CALLASSIGN:
            {
                break;
            }
            case CALL:
            {
                break;
            }
            
        }
    }

}

ARMInstruction::Register ARM::GetRegister(ScopeItem* variable){
    //分配空余寄存器，可用寄存器有r0-r10 
    if(variable->stype==ScopeType::Formal){
        ARMInstruction::Register goal;
        //找到保存有该变量的寄存器
        if((goal=FinfRegister(variable))!=-1){
            regs[goal].tag++;
            return goal;
        }
        else{
            //首先寻找空寄存器
            for(ARMInstruction::Register item: ARMInstruction::userReg){
                if(regs[item].filled==false){
                    regs[item].filled=true;
                    regs[item].tag=1;
                    regs[item].ScopeItem=variable;
                    variable
                    return item;
                }
            }
            //没有空寄存器，用lru腾出一个寄存器
            //这个查找的效率是O(n)
            int minTag=1000;//无穷大
            for(ARMInstruction::Register item: ARMInstruction::userReg){
                if(regs[item].tag<minTag){
                    goal=item;
                    regs[item].tag=minTag;
                }
            }
            //保存这个寄存器中的数据至内存

            //分配寄存器给输入变量
            regs[item].tag=1;
            regs[item].ScopeItem=variable;


        }
    }   
    else if(variable->stype==ScopeType::Local){
        //对于不同作用域中的变量

    }
    else{
        //出错
    }
}

//Register ARM::GetRegister(ScopeItem* variable);//分配空余寄存器
ARMInstruction::Register  ARM::FinfRegister(ScopeItem* variable);//查找存有对应变量的寄存器, 没有则返回-1
