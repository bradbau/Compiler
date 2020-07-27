#include"Arm.h"




ARM::ARM(TACCode* entrance, ScopeItem &scopeItem){
    //根据输入的中间代码和符号表结构完成初始化，生成目标代码, 
    #ifdef DEBUG
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"build assembly code"<<endl;

    #endif // DEBUG

    //初始化代码


    //中间代码翻译

    while(entrance){
        Quadruple code= entrance->code;
        switch(code.optype){

            case ASSIGN: 
            #ifdef DEBUG
            cout<<"tec type ASSIGN"<<endl;
            #endif // DEBUG
                //赋值，目的操作数可以是变量也可以是内存地址，
                //code.dest一直是variable类型，没有别的类型
                {
                    assert(code.dest.Type==VARIABLE);
                    if(code.firstOp.Type== VARIABLE){ 
                        //变量赋值
                        CalculateInstruction* InsItem=new CalculateInstruction(INSADD, GetRegister(code.dest.Data.variable),GetRegister(code.firstOp.Data.variable), 0, 1 );
                        InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                    }
                    else if(code.firstOp.Type== INTEGERCONST){
                        //常量赋值

                        //如果是小于255的常量直接用mov，大于255的用ldr伪指令
                        if(code.firstOp.Data.value>0&& code.firstOp.Data.value<255){
                            CalculateInstruction* InsItem= new CalculateInstruction(INSMOV, GetRegister(code.dest.Data.variable),  code.firstOp.Data.value, 1);
                            InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                        }
                        else{
                            MemoryInstruction* MemItem= new MemoryInstruction(INSLDR, GetRegister(code.dest.Data.variable), code.firstOp.Data.value, 1);
                        }
                        
                    }
                    else{
                        //错误处理
                    }
                    break;
                }
            case ADD:
            #ifdef DEBUG
            cout<<"tac type ADD"<<endl;
            #endif // DEBUG
                //变量与常量相加
                //第一个和第二个操作数的类型固定
                {
                    assert(code.dest.Type == VARIABLE);
                    assert(code.firstOp.Type == VARIABLE);
                    assert(code.secondOp.Type == VARIABLE);
                    CalculateInstruction* InsItem=new CalculateInstruction(INSADD, GetRegister(code.dest.Data.variable), GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.variable), 0);
                    InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                    break;
                }
                
                
            case SUB:
            {
                #ifdef DEBUG
                cout<<"tac type SUB"<<endl;
                #endif // DEBUG
                assert(code.dest.Type = VARIABLE);
                assert(code.firstOp.Type = VARIABLE);
                assert(code.secondOp.Type = VARIABLE);
                CalculateInstruction* InsItem=new CalculateInstruction(INSSUB, GetRegister(code.dest.Data.variable), GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.variable), 0);
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));


                break;
            }
            case MUL:
            {
                #ifdef DEBUG
                cout<<"tac type MUL"<<endl;
                #endif // DEBUG
                assert(code.dest.Type = VARIABLE);
                assert(code.firstOp.Type = VARIABLE);
                assert(code.secondOp.Type = VARIABLE);
                CalculateInstruction* InsItem= new CalculateInstruction(INSMUL, GetRegister(code.dest.Data.variable), GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.variable), 0);
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));

                break;
            }
            case DIV:
            {
                #ifdef DEBUG
                cout<<"tac type DIV"<<endl;
                #endif // DEBUG
                assert(code.dest.Type = VARIABLE);
                assert(code.firstOp.Type = VARIABLE);
                assert(code.secondOp.Type = VARIABLE);
                CalculateInstruction* InsItem=new CalculateInstruction(INSSDIV, GetRegister(code.dest.Data.variable), GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.variable), 0);
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
            }
            case MOD:
            {
                #ifdef DEBUG
                cout<<"tac type MOD"<<endl;
                #endif // DEBUG
                //添加取模运算
                assert(code.dest.Type = VARIABLE);
                assert(code.firstOp.Type = VARIABLE);
                assert(code.secondOp.Type = VARIABLE);
                CalculateInstruction* InsItem=new CalculateInstruction(INSSDIV, GetRegister(code.dest.Data.variable), GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.variable), 0);
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                InsItem=new CalculateInstruction(INSMUL,  GetRegister(code.dest.Data.variable),  GetRegister(code.dest.Data.variable), GetRegister(code.secondOp.Data.variable), 0);
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                InsItem=new CalculateInstruction(INSSUB, GetRegister(code.dest.Data.variable),  GetRegister(code.firstOp.Data.variable), GetRegister(code.dest.Data.variable), 0);
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                break;
            }
            case FUNCTIONDF:
            {
                #ifdef DEBUG
                cout<<"tac type FUNCTIONDF"<<endl;
                #endif // DEBUG
                //函数标记指令
                //ScopeItem localvariable=;

                LabelInstruction* InsItem1= new LabelInstruction(code.dest.Data.function->name);
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem1)); //函数名标签
                
                //进入函数通用语句
                MemoryInstruction* InsItem2= new MemoryInstruction(INSPUSH,  R11);
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem2));//push r11

                
                CalculateInstruction* InsItem3= new CalculateInstruction(INSADD, R11, R13, 0, 1);
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem3)); //add    r11, sp, #0

                //栈移动实在有参数函数的调用发生时执行的
                //InsItem3=new CalculateInstruction(INSSUB, R11, R11, FUNCSTACKSIZE, 1);
                //InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem3));//sub    sp, sp, #FUNCSTACKSIZE

               
                //传入参数的处理
                int i=0;
                int offset=0;//函数堆栈大小
                while(entrance->next->code.optype==PARAM){
                    entrance=entrance->next;
                    if(i<4){
                        //函数参数在四个以内就用寄存器r0到r3传参
                        entrance->code.dest.Data.variable->reg=i;
                        regs[i].variable.reg=i;
                        offset+=4;
                    }
                    else{
                        entrance->code.dest.Data.variable->offset=(i - 3) * 4;// 这里没有溯源到符号表，应该溯源到符号表，那么是否应该把四元式里的variable改回到指针指向符号表内容
                    }
                    ++i;

                }




                
                AllocateStack(code.dest.Data.function, offset );



            

                
                


                break;
            }
            case PARAM:
            {
                #ifdef DEBUG
                cout<<"tac type PARAM"<<endl;
                #endif // DEBUG
                break;
            }
            case LABELDF:
            {   
                #ifdef DEBUG
                cout<<"tac type LABELDF"<<endl;
                #endif // DEBUG
                LabelInstruction* InsItem=new LabelInstruction("L"+to_string(code.dest.Data.labelvalue));
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                break;
            }
            case IFLTGOTO:
            {   
                #ifdef DEBUG
                cout<<"tac type IFLT"<<endl;
                #endif // DEBUG
                assert(code.firstOp.Type==VARIABLE);
                assert(code.secondOp.Type==VARIABLE);
                //加载元素并比较，然后加上跳转指令
                CalculateInstruction* InsItem1=new CalculateInstruction(INSCMP, GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.variable),0 );
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem1));
                ControlInstruction* InsItem2=new ControlInstruction(INSB, "L"+to_string(code.dest.Data.labelvalue), LT);
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem2));

                break;
            }
            case IFLEGOTO:
            {
                #ifdef DEBUG
                cout<<"tac type IFLE"<<endl;
                #endif // DEBUG
                assert(code.firstOp.Type==VARIABLE);
                assert(code.secondOp.Type==VARIABLE);
                //加载元素并比较，然后加上跳转指令
                CalculateInstruction* InsItem1=new CalculateInstruction(INSCMP, GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.variable),0 );
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem1));
                ControlInstruction* InsItem2=new ControlInstruction(INSB, "L"+to_string(code.dest.Data.labelvalue), LE);
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem2));
                break;
            }
            case IFGTGOTO:
            {
                #ifdef DEBUG
                cout<<"tac type IFGT"<<endl;
                #endif // DEBUG
                assert(code.firstOp.Type==VARIABLE);
                assert(code.secondOp.Type==VARIABLE);
                //加载元素并比较，然后加上跳转指令
                CalculateInstruction* InsItem1=new CalculateInstruction(INSCMP, GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.variable),0 );
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem1));
                ControlInstruction* InsItem2=new ControlInstruction(INSB, "L"+to_string(code.dest.Data.labelvalue), GT);
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem2));
                break;
            }
            case IFGEGOTO:
            {
                #ifdef DEBUG
                cout<<"tac type IFGE"<<endl;
                #endif // DEBUG
                assert(code.firstOp.Type==VARIABLE);
                assert(code.secondOp.Type==VARIABLE);
                //加载元素并比较，然后加上跳转指令
                CalculateInstruction* InsItem1=new CalculateInstruction(INSCMP, GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.variable),0 );
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem1));
                ControlInstruction* InsItem2=new ControlInstruction(INSB, "L"+to_string(code.dest.Data.labelvalue), GE);
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem2));
                break;
            }
            case IFEQGOTO:
            {
                #ifdef DEBUG
                cout<<"tac type IFEQ"<<endl;
                #endif // DEBUG
                assert(code.firstOp.Type==VARIABLE);
                assert(code.secondOp.Type==VARIABLE);
                //加载元素并比较，然后加上跳转指令
                CalculateInstruction* InsItem1=new CalculateInstruction(INSCMP, GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.variable),0 );
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem1));
                ControlInstruction* InsItem2=new ControlInstruction(INSB, "L"+to_string(code.dest.Data.labelvalue), EQ);
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem2));

                break;
            }
            case IFNEQGOTO:
            {
                #ifdef DEBUG
                cout<<"tac type IFNEQ"<<endl;
                #endif // DEBUG
                assert(code.firstOp.Type==VARIABLE);
                assert(code.secondOp.Type==VARIABLE);
                //加载元素并比较，然后加上跳转指令
                CalculateInstruction* InsItem1=new CalculateInstruction(INSCMP, GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.variable),0 );
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem1));
                ControlInstruction* InsItem2=new ControlInstruction(INSB, "L"+to_string(code.dest.Data.labelvalue), NE);
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem2));
                break;
            }
            case GOTO:   //关于goto的贴近arm的缩减稍后进行
            {
                #ifdef DEBUG
                cout<<"tac type GOTO"<<endl;
                #endif // DEBUG
                assert(code.dest.Type==LABEL);
                ControlInstruction* InsItem= new ControlInstruction(INSB, "L"+to_string(code.dest.Data.labelvalue), AL);
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                break;
            }
            case RETURN:
            {
                #ifdef DEBUG
                cout<<"tac type RETURN"<<endl;
                #endif // DEBUG
                assert(code.dest.Type==VARIABLE);

                if(code.dest.Type==VARIABLE){
                    //返回值放在r0寄存器中

                    CalculateInstruction* InsItem1=new CalculateInstruction(INSADD, R0,GetRegister(code.dest.Data.variable), 0, 1);
                    InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem1));
                    //函数结尾状态恢复
                    InsItem1= new CalculateInstruction(INSADD,R13, R11, 0,1);
                    InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem1));//栈指针恢复
                    MemoryInstruction* InsItem2=new MemoryInstruction(INSPOP, R11);
                    InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem2));//帧指针恢复
                    ControlInstruction* InsItem3= new ControlInstruction(INSBX, R14);
                    InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem3));//返回lr寄存器中保存的地址
                }
                
                
                break;
            }
            case ARG:
            {
                #ifdef DEBUG
                cout<<"tac type ARG"<<endl;
                #endif // DEBUG
                break;
            }
            case CALLASSIGN:
            {
                #ifdef DEBUG
                cout<<"tac type CALLASSIGN"<<endl;
                #endif // DEBUG
                //函数调用
                //保存寄存器状态

                


                //传入参数
                int i=0;
                int offset=0;
                TACCode* arg=entrance;
                while(arg->prev->code.optype==ARG){
                    arg = arg->prev;
                    if(i<4){
                        CalculateInstruction* InsItem1= new CalculateInstruction(INSMOV, (Register)i, GetRegister(arg->code.dest.Data.variable), 0);
                        InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem1));
                    }
                    else{
                        MemoryInstruction* MemItem=new MemoryInstruction(INSSTR, GetRegister(arg->code.dest.Data.variable),  R13, (i - 4) * 4, 1, 0 );
                        InsList.push_back(dynamic_cast<ARMInstruction*>(MemItem));

                    }
                    i++;
                }

                //改变sp值

                //跳转指令
                ControlInstruction* ConItem=new ControlInstruction(INSBL, code.firstOp.Data.function->name, AL);
                InsList.push_back(dynamic_cast<ARMInstruction*>(ConItem));

                //返回值赋值
                CalculateInstruction* CalItem= new CalculateInstruction(INSMOV,GetRegister(code.dest.Data.variable), R0, 0);
                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                break;
            }
            case CALL:
            {   
                #ifdef DEBUG
                cout<< "tac type CALL"<<endl;
                #endif // DEBUG
                //函数调用
                //保存寄存器状态

                


                //传入参数
                int i=0;
                TACCode* arg=entrance;
                while(arg->prev->code.optype==ARG){
                    arg = arg->prev;
                    if(i<4){
                        CalculateInstruction* InsItem1= new CalculateInstruction(INSMOV, (Register)i, GetRegister(arg->code.dest.Data.variable), 0);
                        InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem1));
                    }
                    else{
                        MemoryInstruction* MemItem=new MemoryInstruction(INSSTR, GetRegister(arg->code.dest.Data.variable),  R13, (i - 4) * 4, 1, 0 );
                        InsList.push_back(dynamic_cast<ARMInstruction*>(MemItem));

                    }
                    i++;
                }

                //改变sp值

                //跳转返回调用代码
                ControlInstruction* ConItem=new ControlInstruction(INSBL, code.firstOp.Data.function->name, AL);
                InsList.push_back(dynamic_cast<ARMInstruction*>(ConItem));

                

                break;
            }
            
        }
        entrance=entrance->next;
    }

}

Register ARM::GetRegister(ScopeItem* variable){
    //分配空余寄存器，可用寄存器有r0-r10 
    if(variable->stype==ScopeType::Formal ||variable->stype==ScopeType:: Local|| variable->stype==ScopeType::Global){
        int goal;
        //找到保存有该变量的寄存器
        if((goal=FinfRegister(variable))!=-1){
            regs[goal].tag++;
            return (Register)goal;
        }
        else{
            //寻找空寄存器
            for(Register item: userReg){
                if(regs[item].filled==false){
                    regs[item].filled=true;
                    regs[item].tag=1;
                    regs[item].variable=*variable;
                    
                    //插入ld指令,加载数据
                    #ifdef DEBUG
                    cout<<"findregister: insldr rd="<<item<< ",r1="<<R11<<",r2 offset="<<variable->offset<<",op2type=1, insefft=0"   <<endl;
                    #endif // DEBUG
                    MemoryInstruction* MemItem=new MemoryInstruction(INSLDR,(Register)item,  R11, variable->offset , 1, 0);
                    InsList.push_back(dynamic_cast<ARMInstruction*>(MemItem));

                    return item;
                }
            }
            //没有空寄存器，用lru腾出一个寄存器
            //这个查找的效率是O(n)
            int minTag=1000;//无穷大
            for(Register item: userReg){
                if(regs[item].tag<minTag){
                    goal=item;
                    regs[item].tag=minTag;
                }
            }
            //保存这个寄存器中的数据至内存
            MemoryInstruction* MemItem=new MemoryInstruction(INSSTR, (Register)goal, R11, variable->offset, 1, 0);
            InsList.push_back(dynamic_cast<ARMInstruction*>(MemItem));
            //分配寄存器给输入变量
            regs[goal].tag=1;
            regs[goal].variable=*variable;
            #ifdef DEBUG
                    cout<<"findregister: insldr rd="<<goal<< ",r1="<<R11<<",r2 offset="<<variable->offset<<",op2type=1, insefft=0" <<  endl;
            #endif // DEBUG
            MemItem=  new MemoryInstruction(INSLDR,(Register)goal,  R11, variable->offset , 1, 0);
            InsList.push_back(dynamic_cast<ARMInstruction*>(MemItem));
            return (Register)goal;
        }
    }   
    else if(variable->stype==ScopeType::Local){
        //对于不同作用域中的变量
        for(Register item: userReg){
            
        }
    }
    else{
        //错误处理

    }
}

//Register ARM::GetRegister(ScopeItem* variable);//分配空余寄存器
int  ARM::FinfRegister(ScopeItem* variable){
    //查找存有对应变量的寄存器, 没有则返回-1
    for(Register item: userReg){
        if(regs[item].variable==*variable){
            return item;
        }
    }
    return -1;
}

void ARM::EmptyRegister(){
    for(Register item: userReg){
        regs[item].filled=false;
        regs[item].tag=0;
        
    }
}


void ARM::AllocateStack(ScopeItem * variable, int &offset){
    //给变量在栈中分配地址
    while(variable!=NULL){
        if(variable->category==SysYCategory::Variable){
            variable->offset=-offset;
            offset=offset+ 4;
        }
        else if(variable->category==SysYCategory::Block){
            AllocateStack(variable->depictor, offset);
            
        }
        else if(variable->category==SysYCategory::Array){
            //数组
        }
        variable=variable->next;
    }
}

string ARM::toString(){
    //生成汇编文本
    //遍历指令序列，依次调用tostring方法然后串联

    string CodeString="#armv7 assembly code\n";
    for(auto iter: InsList){
        CodeString+=iter->toString();
    }
    return CodeString;


}


