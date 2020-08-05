#include"Arm.h"


bool operator==(ScopeItem t1, ARRAY_ADDR t2){
    return false;
}
bool operator==(ARRAY_ADDR t1, ScopeItem t2){
    return false;
}

ARM::ARM(TACCode* entrance, ScopeItem *GlobalItemHead, vector<ScopeItem> &stack){
    //根据输入的中间代码和符号表结构完成初始化，生成目标代码, 
    #ifdef DEBUG
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"build assembly code"<<endl;

    #endif // DEBUG

    //初始化代码


    StackSubHandler=NULL;

    ScopeItem* GlobalIter=GlobalItemHead;
    int GlobalOffset =0;//或者某个值
    //全局变量空间分配, ，给符号表中的global变量分配
    while(GlobalIter!=NULL){
        if(GlobalIter->stype!=Global){
            cout << "scope type not global\n";
        }
        switch(GlobalIter->category){
            case Variable:{
                //默认等于int
                //在符号表中查找该变量并给他的offset赋值
                
                GlobalIter->offset=GlobalOffset;
                GlobalOffset-=4;

                break;
            }
            case ConstVariable:{

                break;
            }
            case Array:{
                GlobalIter->offset=GlobalOffset;
                //计算数组总长度
                //GlobalOffset-=
                break;
            }
            default:{

            }
        }
        GlobalIter=GlobalIter->next;
    }

    //中间代码翻译

    while(entrance){
        Quadruple code= entrance->code;
        switch(code.optype){

            case ASSIGN: 
            #ifdef DEBUG
            cout<<"tac type ASSIGN"<<endl;
            #endif // DEBUG
                //赋值，目的操作数可以是变量也可以是内存地址，
                //code.dest一直是variable类型，没有别的类型
                {
                    if(code.dest.Type==ARRAY){
                        #ifdef DEBUG
                        cout<<"  assign dest type array"<<endl;
                        #endif // DEBUG
                        //目标是数组元素的赋值
                        //任意寄存器为一个没有保存在寄存器中的数组元素赋值；在已经保存数组对应元素的寄存器中赋值。前者不需要加载过程
                        //然后是否可以延后保存
                        if(code.firstOp.Type==INTEGERCONST){
                            //如果是小于255的常量直接用mov，大于255的用ldr伪指令
                            if(code.firstOp.Data.value>=0&& code.firstOp.Data.value<=255){
                                CalculateInstruction* InsItem= new CalculateInstruction(INSMOV, GetRegisterNoLoad(code.dest.Data.array_addr),  code.firstOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                            }
                            else{
                                MemoryInstruction* MemItem= new MemoryInstruction(INSLDR, GetRegisterNoLoad(code.dest.Data.array_addr), code.firstOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(MemItem));
                            }
                        }
                        else if(code.firstOp.Type==VARIABLE){
                            assert(code.dest.Data.array_addr->array_si!=NULL && code.dest.Data.array_addr->deviation!=NULL);

                            CalculateInstruction* InsItem=new CalculateInstruction(INSADD, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.firstOp.Data.variable), 0, 1 );
                            InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                        }
                        else if(code.firstOp.Type==ARRAY){
                             CalculateInstruction* InsItem=new CalculateInstruction(INSADD, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.firstOp.Data.array_addr), 0, 1 );
                            InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                        }
                        else{
                            //错误处理
                            throw std::runtime_error("not handled in assign");
                        }


                    }
                    else if(code.dest.Type==VARIABLE){
                        if(code.firstOp.Type== VARIABLE){ 
                            //变量赋值
                            CalculateInstruction* InsItem=new CalculateInstruction(INSADD, GetRegisterNoLoad(code.dest.Data.variable),GetRegister(code.firstOp.Data.variable), 0, 1 );
                            InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                        }
                        else if(code.firstOp.Type== INTEGERCONST){
                            //常量赋值
                            //这个常量赋值可能是
                            #ifdef DEBUG
                            cout<<" assign "<<code.firstOp.Data.value<<" to tegister"<<GetRegisterNoLoad(code.dest.Data.variable)<<endl;
                            #endif // DEBUG
                            //如果是小于255的常量直接用mov，大于255的用ldr伪指令
                            if(code.firstOp.Data.value>=0&& code.firstOp.Data.value<=255){
                                CalculateInstruction* InsItem= new CalculateInstruction(INSMOV, GetRegisterNoLoad(code.dest.Data.variable),  code.firstOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                            }
                            else{
                                MemoryInstruction* MemItem= new MemoryInstruction(INSLDR, GetRegisterNoLoad(code.dest.Data.variable), code.firstOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(MemItem));
                            }

                            //如果是函数内部局部变量的声明，需要给分配栈空间
                            //StackSubHandler->setOp2(StackSubHandler->getOp2()+4);//一个整形变量需要4字节空间
                            
                        }
                        else if(code.firstOp.Type== ARRAY){
                            //数组元素赋值
                            //读取数组元素到寄存器中，然后寄存器内容相加
                            CalculateInstruction* CalItem= new CalculateInstruction(INSADD, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.firstOp.Data.array_addr), 0,1);
                            InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));


                        }
                        else{
                            //错误处理
                            throw std::runtime_error("not handled in assign");
                        }
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

                    
                    
                    if(code.dest.Type == VARIABLE){
                        if(code.firstOp.Type == VARIABLE){
                            if(code.secondOp.Type == VARIABLE){
                                CalculateInstruction* InsItem=new CalculateInstruction(INSADD, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                            }
                            else if(code.secondOp.Type == INTEGERCONST){
                                CalculateInstruction* CalItem =new CalculateInstruction(INSADD, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.firstOp.Data.variable), code.secondOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == ARRAY){
                                
                                CalculateInstruction* CalItem=new CalculateInstruction(INSADD, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.array_addr), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                                //这里还有简化余地
                                //CalculateInstruction* CalItem =new CalculateInstruction(INSADD, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.firstOp.Data.variable), , 0);
                                //InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in assign");
                            }
                        }
                        else if(code.firstOp.Type == INTEGERCONST){
                            if(code.secondOp.Type == VARIABLE){
                                //调换位置
                                CalculateInstruction* CalItem =new CalculateInstruction(INSADD, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.secondOp.Data.variable), code.firstOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == INTEGERCONST){
                                //不太可能出现的
                                throw std::runtime_error("not a possible tac");
                            }
                            else if(code.secondOp.Type == ARRAY){
                                //later
                                CalculateInstruction* CalItem=new CalculateInstruction(INSADD, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.secondOp.Data.array_addr), code.firstOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in assign");
                            }
                        }
                        else if(code.firstOp.Type == ARRAY){
                            if(code.secondOp.Type == VARIABLE){
                                    CalculateInstruction* CalItem=new CalculateInstruction(INSADD, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.firstOp.Data.array_addr), GetRegister(code.secondOp.Data.variable), 0);
                                    InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            
                            }
                            else if(code.secondOp.Type == INTEGERCONST){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSADD, GetRegisterNoLoad(code.dest.Data.variable),GetRegister(code.firstOp.Data.array_addr), code.secondOp.Data.value, 1 );
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == ARRAY){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSADD, GetRegisterNoLoad(code.dest.Data.variable),GetRegister(code.firstOp.Data.array_addr), GetRegister(code.secondOp.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));

                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in assign");
                            }
                        }
                        else{
                            //错误处理
                            throw std::runtime_error("not handled in assign");
                        }
                    }
                    else if(code.dest.Type == ARRAY){
                        if(code.firstOp.Type == VARIABLE){
                            if(code.secondOp.Type == VARIABLE){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSADD, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.variable), 0 );
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == INTEGERCONST){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSADD, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.firstOp.Data.variable), code.secondOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));

                            }
                            else if(code.secondOp.Type == ARRAY){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSADD, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.array_addr), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in add");
                            }
                        }
                        else if(code.firstOp.Type == INTEGERCONST){
                            if(code.secondOp.Type == VARIABLE){
                                CalculateInstruction* CalItem =new CalculateInstruction(INSADD, GetRegisterNoLoad(code.dest.Data.array_addr), GetRegister(code.secondOp.Data.variable), code.firstOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == INTEGERCONST){
                                //略过这个
                                throw std::runtime_error("not handled in add");
                            }
                            else if(code.secondOp.Type == ARRAY){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSADD, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.secondOp.Data.array_addr), code.firstOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in assign");
                            }
                        }
                        else if(code.firstOp.Type == ARRAY){
                            if(code.secondOp.Type == VARIABLE){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSADD, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.firstOp.Data.array_addr), GetRegister(code.secondOp.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == INTEGERCONST){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSADD, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.firstOp.Data.array_addr), code.secondOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == ARRAY){
                                //忽略
                                 throw std::runtime_error("not handled in add");
                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in add");
                            }
                        }
                        else{
                            //错误处理
                            throw std::runtime_error("not handled in add");
                        }
                    }
                    
                    
                    
                    
                    
                    break;
                }
                
                
            case SUB:
            #ifdef DEBUG
            cout<<"tac type SUB"<<endl;
            #endif // DEBUG
               {
                    if(code.dest.Type == VARIABLE){
                        if(code.firstOp.Type == VARIABLE){
                            if(code.secondOp.Type == VARIABLE){
                                CalculateInstruction* InsItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                            }
                            else if(code.secondOp.Type == INTEGERCONST){
                                CalculateInstruction* CalItem =new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.firstOp.Data.variable), code.secondOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == ARRAY){
                                
                                CalculateInstruction* CalItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.array_addr), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                                //这里还有简化余地
                                //CalculateInstruction* CalItem =new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.firstOp.Data.variable), , 0);
                                //InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in assign");
                            }
                        }
                        else if(code.firstOp.Type == INTEGERCONST){
                            if(code.secondOp.Type == VARIABLE){
                                //调换位置
                                CalculateInstruction* CalItem =new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.secondOp.Data.variable), code.firstOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == INTEGERCONST){
                                //不太可能出现的
                                throw std::runtime_error("not a possible tac");
                            }
                            else if(code.secondOp.Type == ARRAY){
                                //later
                                CalculateInstruction* CalItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.secondOp.Data.array_addr), code.firstOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in assign");
                            }
                        }
                        else if(code.firstOp.Type == ARRAY){
                            if(code.secondOp.Type == VARIABLE){
                                    CalculateInstruction* CalItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.firstOp.Data.array_addr), GetRegister(code.secondOp.Data.variable), 0);
                                    InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            
                            else if(code.secondOp.Type == INTEGERCONST){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.variable),GetRegister(code.firstOp.Data.array_addr), code.secondOp.Data.value, 1 );
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == ARRAY){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.variable),GetRegister(code.firstOp.Data.array_addr), GetRegister(code.secondOp.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));

                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in assign");
                            }
                        }
                        else{
                            //错误处理
                            throw std::runtime_error("not handled in assign");
                        }
                    }
                    else if(code.dest.Type == ARRAY){
                        if(code.firstOp.Type == VARIABLE){
                            if(code.secondOp.Type == VARIABLE){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.variable), 0 );
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == INTEGERCONST){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.firstOp.Data.variable), code.secondOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));

                            }
                            else if(code.secondOp.Type == ARRAY){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.array_addr), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in add");
                            }
                        }
                        else if(code.firstOp.Type == INTEGERCONST){
                            if(code.secondOp.Type == VARIABLE){
                                CalculateInstruction* CalItem =new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.array_addr), GetRegister(code.secondOp.Data.variable), code.firstOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == INTEGERCONST){
                                //略过这个
                                throw std::runtime_error("not handled in add");
                            }
                            else if(code.secondOp.Type == ARRAY){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.secondOp.Data.array_addr), code.firstOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in assign");
                            }
                        }
                        else if(code.firstOp.Type == ARRAY){
                            if(code.secondOp.Type == VARIABLE){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.firstOp.Data.array_addr), GetRegister(code.secondOp.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == INTEGERCONST){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.firstOp.Data.array_addr), code.secondOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == ARRAY){
                                //忽略
                                 throw std::runtime_error("not handled in add");
                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in add");
                            }
                        }
                        else{
                            //错误处理
                            throw std::runtime_error("not handled in add");
                        }
                    }

                    break;
            }
            case MUL:
            {
                #ifdef DEBUG
                cout<<"tac type MUL"<<endl;
                #endif // DEBUG
                 if(code.dest.Type == VARIABLE){
                        if(code.firstOp.Type == VARIABLE){
                            if(code.secondOp.Type == VARIABLE){
                                CalculateInstruction* InsItem=new CalculateInstruction(INSMUL, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                            }
                            else if(code.secondOp.Type == INTEGERCONST){
                                CalculateInstruction* CalItem =new CalculateInstruction(INSMUL, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.firstOp.Data.variable), code.secondOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == ARRAY){
                                
                                CalculateInstruction* CalItem=new CalculateInstruction(INSMUL, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.array_addr), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                                //这里还有简化余地
                                //CalculateInstruction* CalItem =new CalculateInstruction(INSMUL, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.firstOp.Data.variable), , 0);
                                //InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in assign");
                            }
                        }
                        else if(code.firstOp.Type == INTEGERCONST){
                            if(code.secondOp.Type == VARIABLE){
                                //调换位置
                                CalculateInstruction* CalItem =new CalculateInstruction(INSMUL, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.secondOp.Data.variable), code.firstOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == INTEGERCONST){
                                //不太可能出现的
                                throw std::runtime_error("not a possible tac");
                            }
                            else if(code.secondOp.Type == ARRAY){
                                //later
                                CalculateInstruction* CalItem=new CalculateInstruction(INSMUL, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.secondOp.Data.array_addr), code.firstOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in assign");
                            }
                        }
                        else if(code.firstOp.Type == ARRAY){
                            if(code.secondOp.Type == VARIABLE){
                                    CalculateInstruction* CalItem=new CalculateInstruction(INSMUL, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.firstOp.Data.array_addr), GetRegister(code.secondOp.Data.variable), 0);
                                    InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            
                            else if(code.secondOp.Type == INTEGERCONST){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSMUL, GetRegisterNoLoad(code.dest.Data.variable),GetRegister(code.firstOp.Data.array_addr), code.secondOp.Data.value, 1 );
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == ARRAY){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSMUL, GetRegisterNoLoad(code.dest.Data.variable),GetRegister(code.firstOp.Data.array_addr), GetRegister(code.secondOp.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));

                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in assign");
                            }
                        }
                        else{
                            //错误处理
                            throw std::runtime_error("not handled in assign");
                        }
                    }
                    else if(code.dest.Type == ARRAY){
                        if(code.firstOp.Type == VARIABLE){
                            if(code.secondOp.Type == VARIABLE){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSMUL, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.variable), 0 );
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == INTEGERCONST){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSMUL, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.firstOp.Data.variable), code.secondOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));

                            }
                            else if(code.secondOp.Type == ARRAY){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSMUL, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.array_addr), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in add");
                            }
                        }
                        else if(code.firstOp.Type == INTEGERCONST){
                            if(code.secondOp.Type == VARIABLE){
                                CalculateInstruction* CalItem =new CalculateInstruction(INSMUL, GetRegisterNoLoad(code.dest.Data.array_addr), GetRegister(code.secondOp.Data.variable), code.firstOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == INTEGERCONST){
                                //略过这个
                                throw std::runtime_error("not handled in add");
                            }
                            else if(code.secondOp.Type == ARRAY){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSMUL, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.secondOp.Data.array_addr), code.firstOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in mul");
                            }
                        }
                        else if(code.firstOp.Type == ARRAY){
                            if(code.secondOp.Type == VARIABLE){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSMUL, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.firstOp.Data.array_addr), GetRegister(code.secondOp.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == INTEGERCONST){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSMUL, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.firstOp.Data.array_addr), code.secondOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == ARRAY){
                                //忽略
                                 throw std::runtime_error("not handled in add");
                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in add");
                            }
                        }
                        else{
                            //错误处理
                            throw std::runtime_error("not handled in add");
                        }
                    }
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
                


                if(code.dest.Type == VARIABLE){
                        if(code.firstOp.Type == VARIABLE){
                            if(code.secondOp.Type == VARIABLE){
                                CalculateInstruction* InsItem=new CalculateInstruction(INSSDIV, GetRegister(code.dest.Data.variable), GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSMUL,  GetRegister(code.dest.Data.variable),  GetRegister(code.dest.Data.variable), GetRegister(code.secondOp.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSSUB, GetRegister(code.dest.Data.variable),  GetRegister(code.firstOp.Data.variable), GetRegister(code.dest.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                            }
                            else if(code.secondOp.Type == INTEGERCONST){
                                
                                CalculateInstruction* InsItem=new CalculateInstruction(INSSDIV, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.firstOp.Data.variable), code.secondOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSMUL,  GetRegister(code.dest.Data.variable),  GetRegister(code.dest.Data.variable), code.secondOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSSUB, GetRegister(code.dest.Data.variable),  GetRegister(code.firstOp.Data.variable), GetRegister(code.dest.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                            }
                            else if(code.secondOp.Type == ARRAY){
                                CalculateInstruction* InsItem=new CalculateInstruction(INSSDIV, GetRegister(code.dest.Data.variable), GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.array_addr), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSMUL,  GetRegister(code.dest.Data.variable),  GetRegister(code.dest.Data.variable), GetRegister(code.secondOp.Data.array_addr), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSSUB, GetRegister(code.dest.Data.variable),  GetRegister(code.firstOp.Data.variable), GetRegister(code.dest.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                               
                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in assign");
                            }
                        }
                        else if(code.firstOp.Type == INTEGERCONST){
                            

                            if(code.secondOp.Type == VARIABLE){

                                CalculateInstruction* InsItem=new CalculateInstruction(INSSDIV, GetRegister(code.dest.Data.variable), LoadInstantToRegister(code.firstOp.Data.value), GetRegister(code.secondOp.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSMUL,  GetRegister(code.dest.Data.variable),  GetRegister(code.dest.Data.variable), GetRegister(code.secondOp.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSSUB, GetRegister(code.dest.Data.variable),  LoadInstantToRegister(code.firstOp.Data.value), GetRegister(code.dest.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                            }
                            else if(code.secondOp.Type == INTEGERCONST){
                                //不太可能出现的
                                throw std::runtime_error("not a possible tac");
                            }
                            else if(code.secondOp.Type == ARRAY){

                                CalculateInstruction* InsItem=new CalculateInstruction(INSSDIV, GetRegister(code.dest.Data.variable), LoadInstantToRegister(code.firstOp.Data.value), GetRegister(code.secondOp.Data.array_addr), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSMUL,  GetRegister(code.dest.Data.variable),  GetRegister(code.dest.Data.variable), GetRegister(code.secondOp.Data.array_addr), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSSUB, GetRegister(code.dest.Data.variable),  LoadInstantToRegister(code.firstOp.Data.value), GetRegister(code.dest.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in assign");
                            }
                        }
                        else if(code.firstOp.Type == ARRAY){
                            if(code.secondOp.Type == VARIABLE){

                                    CalculateInstruction* InsItem=new CalculateInstruction(INSSDIV, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.firstOp.Data.array_addr), GetRegister(code.secondOp.Data.variable), 0);
                                    InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                    InsItem=new CalculateInstruction(INSMUL,  GetRegisterNoLoad(code.dest.Data.variable),  GetRegister(code.dest.Data.variable), GetRegister(code.secondOp.Data.variable), 0);
                                    InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                    InsItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.variable),  GetRegister(code.firstOp.Data.array_addr), GetRegister(code.dest.Data.variable), 0);
                                    InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));


                            }
                            
                            else if(code.secondOp.Type == INTEGERCONST){
                                    CalculateInstruction* InsItem=new CalculateInstruction(INSSDIV, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.firstOp.Data.array_addr), LoadInstantToRegister(code.secondOp.Data.value), 0);
                                    InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                    InsItem=new CalculateInstruction(INSMUL,  GetRegisterNoLoad(code.dest.Data.variable),  GetRegister(code.dest.Data.variable), LoadInstantToRegister(code.secondOp.Data.value), 0);
                                    InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                    InsItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.variable),  GetRegister(code.firstOp.Data.array_addr), GetRegister(code.dest.Data.variable), 0);
                                    InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                            }
                            else if(code.secondOp.Type == ARRAY){


                                    CalculateInstruction* InsItem=new CalculateInstruction(INSSDIV, GetRegisterNoLoad(code.dest.Data.variable), GetRegister(code.firstOp.Data.array_addr), GetRegister(code.secondOp.Data.array_addr), 0);
                                    InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                    InsItem=new CalculateInstruction(INSMUL,  GetRegisterNoLoad(code.dest.Data.variable),  GetRegister(code.dest.Data.variable), GetRegister(code.secondOp.Data.array_addr), 0);
                                    InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                    InsItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.variable),  GetRegister(code.firstOp.Data.array_addr), GetRegister(code.dest.Data.variable), 0);
                                    InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));

                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in assign");
                            }
                        }
                        else{
                            //错误处理
                            throw std::runtime_error("not handled in assign");
                        }
                    }
                    else if(code.dest.Type == ARRAY){
                        if(code.firstOp.Type == VARIABLE){
                            if(code.secondOp.Type == VARIABLE){
                                CalculateInstruction* InsItem=new CalculateInstruction(INSSDIV, GetRegisterNoLoad(code.dest.Data.array_addr), GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSMUL,  GetRegisterNoLoad(code.dest.Data.array_addr),  GetRegister(code.dest.Data.array_addr), GetRegister(code.secondOp.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.array_addr),  GetRegister(code.firstOp.Data.variable), GetRegister(code.dest.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                        }
                            else if(code.secondOp.Type == INTEGERCONST){
                                CalculateInstruction* InsItem=new CalculateInstruction(INSSDIV, GetRegisterNoLoad(code.dest.Data.array_addr), GetRegister(code.firstOp.Data.variable), LoadInstantToRegister(code.secondOp.Data.value), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSMUL,  GetRegisterNoLoad(code.dest.Data.array_addr),  GetRegister(code.dest.Data.array_addr), LoadInstantToRegister(code.secondOp.Data.value), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.array_addr),  GetRegister(code.firstOp.Data.variable), GetRegister(code.dest.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));

                            }
                            else if(code.secondOp.Type == ARRAY){
                                CalculateInstruction* InsItem=new CalculateInstruction(INSSDIV, GetRegisterNoLoad(code.dest.Data.array_addr), GetRegister(code.firstOp.Data.variable), GetRegister(code.secondOp.Data.array_addr), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSMUL,  GetRegisterNoLoad(code.dest.Data.array_addr),  GetRegister(code.dest.Data.array_addr), GetRegister(code.secondOp.Data.array_addr), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.array_addr),  GetRegister(code.firstOp.Data.variable), GetRegister(code.dest.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in add");
                            }
                        }
                        else if(code.firstOp.Type == INTEGERCONST){
                            if(code.secondOp.Type == VARIABLE){
                                CalculateInstruction* InsItem=new CalculateInstruction(INSSDIV, GetRegisterNoLoad(code.dest.Data.array_addr), LoadInstantToRegister(code.firstOp.Data.value), GetRegister(code.secondOp.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSMUL,  GetRegisterNoLoad(code.dest.Data.array_addr),  GetRegister(code.dest.Data.array_addr), GetRegister(code.secondOp.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.array_addr),  LoadInstantToRegister(code.firstOp.Data.value), GetRegister(code.dest.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                            }
                            else if(code.secondOp.Type == INTEGERCONST){
                                CalculateInstruction* InsItem=new CalculateInstruction(INSSDIV, GetRegisterNoLoad(code.dest.Data.array_addr), LoadInstantToRegister(code.firstOp.Data.value), LoadInstantToRegister(code.secondOp.Data.value), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSMUL,  GetRegisterNoLoad(code.dest.Data.array_addr),  GetRegister(code.dest.Data.array_addr), LoadInstantToRegister(code.secondOp.Data.value), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.array_addr),  LoadInstantToRegister(code.firstOp.Data.value), GetRegister(code.dest.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                            }
                            else if(code.secondOp.Type == ARRAY){
                                CalculateInstruction* InsItem=new CalculateInstruction(INSSDIV, GetRegisterNoLoad(code.dest.Data.array_addr), LoadInstantToRegister(code.firstOp.Data.value), GetRegister(code.secondOp.Data.array_addr), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSMUL,  GetRegisterNoLoad(code.dest.Data.array_addr),  GetRegister(code.dest.Data.array_addr), GetRegister(code.secondOp.Data.array_addr), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                                InsItem=new CalculateInstruction(INSSUB, GetRegisterNoLoad(code.dest.Data.array_addr),  LoadInstantToRegister(code.firstOp.Data.value), GetRegister(code.dest.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem));
                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in mul");
                            }
                        }
                        else if(code.firstOp.Type == ARRAY){
                            if(code.secondOp.Type == VARIABLE){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSMUL, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.firstOp.Data.array_addr), GetRegister(code.secondOp.Data.variable), 0);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == INTEGERCONST){
                                CalculateInstruction* CalItem=new CalculateInstruction(INSMUL, GetRegisterNoLoad(code.dest.Data.array_addr),GetRegister(code.firstOp.Data.array_addr), code.secondOp.Data.value, 1);
                                InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
                            }
                            else if(code.secondOp.Type == ARRAY){
                                //忽略
                                 throw std::runtime_error("not handled in add");
                            }
                            else{
                                //错误处理
                                throw std::runtime_error("not handled in add");
                            }
                        }
                        else{
                            //错误处理
                            throw std::runtime_error("not handled in add");
                        }
                    }


                break;
            }
            case FUNCTIONDF:
            {
                #ifdef DEBUG
                cout<<"tac type FUNCTIONDF"<<endl;
                #endif // DEBUG

                //函数标记指令
                LabelInstruction* InsItem1= new LabelInstruction(code.dest.Data.function->name);
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem1)); //函数名标签
                
                //进入函数通用语句
                MemoryInstruction* InsItem2= new MemoryInstruction(INSPUSH,  R11);
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem2));//push r11

                
                CalculateInstruction* InsItem3= new CalculateInstruction(INSADD, R11, R13, 0, 1);
                InsList.push_back(dynamic_cast<ARMInstruction*>(InsItem3)); //add    r11, sp, #0

                //栈移动实在有参数函数的调用发生时执行的
                StackSubHandler=new CalculateInstruction(INSSUB, R13, R13, 0, 1);
                InsList.push_back(dynamic_cast<ARMInstruction*>(StackSubHandler));//sub    sp, sp, #FUNCSTACKSIZE

               
                //传入参数的处理
                int i=0;
                int offset=0;//函数堆栈大小
                while(entrance->next!=NULL&&entrance->next->code.optype==PARAM){
                    entrance=entrance->next;
                    if(i<4){
                        //函数参数在四个以内就用寄存器r0到r3传参
                        entrance->code.dest.Data.variable->reg=i;
                        regs[i].variable=entrance->code.dest.Data.variable;
                        offset+=4;
                    }
                    else{
                        entrance->code.dest.Data.variable->offset=(i - 3) * 4;// 这里没有溯源到符号表，应该溯源到符号表，那么是否应该把四元式里的variable改回到指针指向符号表内容
                    }
                    ++i;

                }

                
                AllocateStack(code.dest.Data.function, offset );


                //局部变量统计stack大小
                //给符号表中局部变量的offset赋值，计算他们相对于函数fp的地址
                //第一个局部变量
                offset=0;
                ScopeItem* localvariable= code.dest.Data.function->depictor->depictor;
                ScopeItem*  tempvariable=localvariable;
                //遍历local作用域，统计变量大小
                while(localvariable!=NULL){
                    if(localvariable->stype != Local){
                        cout<<"scope type not local in functiondf"<<endl;
                        cout<<"scopeprev:"<<(localvariable->prev!=NULL) <<endl;
                    }
                    switch(localvariable->category){
                        case Variable:{
                            offset+=4;//这里默认variable是int
                            cout<<"Variable offset count+4 :"<<localvariable->name<<endl;
                            break;
                        }
                        case Array:{
                            //统计数组大小

                            break;
                        }
                        default:{
                            break;
                        }
                    }
                    localvariable=localvariable->next;
                }
                while(tempvariable!=NULL){
                    if(tempvariable->stype != Local){
                        cout<<"scope type not local in functiondf"<<endl;
                        cout<<"scopeprev:"<<(tempvariable->prev==NULL) <<endl;
                    }
                    switch(tempvariable->category){
                        case Variable:{
                            offset+=4;//这里默认variable是int
                            cout<<"Variable offset count+4 :"<<tempvariable->name<<endl;
                            break;
                        }
                        case Array:{
                            //统计数组大小

                            break;
                        }
                        default:{
                            break;
                        }
                    }
                    tempvariable=tempvariable->prev;
                }

                
                


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
                cout<<InsItem->toString()<<endl;
                
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
                 cout<<"ControlInstruction String:"<<InsItem2->toString()<<endl;
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
                cout<<"Goto string "<<InsItem->toString()<<endl;
                
                
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
                else
                
                
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
                while(arg!= NULL&& arg->prev->code.optype==ARG){
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

                


                //传入参数在堆栈中的空间分配
                int i=0;
                TACCode* arg=entrance;
                while(arg!=NULL&&arg->prev->code.optype==ARG){
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
    
    int goal;
    //找到保存有该变量的寄存器
    if((goal=FindRegister(variable))!=-1){
        regs[goal].tag++;
        return (Register)goal;
    }
    //没有变量保存
    else{
        //寻找空寄存器
        for(Register item: userReg){
            if(regs[item].filled==false){
                regs[item].filled=true;
                regs[item].tag=1;
                regs[item].variable=variable;
                
                //插入ld指令,加载数据
                #ifdef DEBUG
                cout<<"findregister: insldr rd="<<item<< ",r1="<<R11<<",r2 offset="<<variable->offset<<",op2type=1, insefft=0"   <<endl;
                #endif // DEBUG

                //全局变量
                if(variable->stype==Global){

                    //MemoryInstruction* MemItem=new MemoryInstruction(INSLDR, (Register)item
                }
                else{
                    //如果是局部变量或者形参
                    MemoryInstruction* MemItem=new MemoryInstruction(INSLDR,(Register)item,  R11, variable->offset , 1, 0);
                    InsList.push_back(dynamic_cast<ARMInstruction*>(MemItem));
                }
                

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
        StoreRegister(goal);
        #ifdef DEBUG
        cout<<"Store Register in getregister variable"<<endl;
        #endif // DEBUG
        //分配寄存器给输入变量
        regs[goal].tag=1;
        regs[goal].variable=variable;
        #ifdef DEBUG
                cout<<"findregister: insldr rd="<<goal<< ",r1="<<R11<<",r2 offset="<<variable->offset<<",op2type=1, insefft=0" <<  endl;
        #endif // DEBUG
        MemoryInstruction* MemItem=  new MemoryInstruction(INSLDR,(Register)goal,  R11, variable->offset , 1, 0);
        InsList.push_back(dynamic_cast<ARMInstruction*>(MemItem));
        return (Register)goal;
    }
    
    
}

Register ARM::GetRegister(ARRAY_ADDR* array_addr){
    //分配或者获取已经分配的空余寄存器
    int goal;
    //找到保存有该变量的寄存器
    if((goal=FindRegister(array_addr))!=-1){
        regs[goal].tag++;
        return (Register)goal;
    }
    //没有变量保存
    else{
        //寻找空寄存器
        for(Register item: userReg){
            if(regs[item].filled==false){
                regs[item].filled=true;
                regs[item].tag=1;
                regs[item].array_addr=array_addr;
                
                //插入ld指令,加载数据
                #ifdef DEBUG
                //cout<<"findregister: insldr rd="<<item<< ",r1="<<R11<<",r2 offset="<<array_addr->offset<<",op2type=1, insefft=0"   <<endl;
                #endif // DEBUG

                //全局变量
                if(array_addr->array_si->stype==Global){

                    //MemoryInstruction* MemItem=new MemoryInstruction(INSLDR, (Register)item
                }
                else{
                    //如果是局部变量或者形参
                    MemoryInstruction* MemItem=new MemoryInstruction(INSLDR,(Register)item,  GetRegister(array_addr->array_si), GetRegister(array_addr->deviation) , 0, 0);
                    InsList.push_back(dynamic_cast<ARMInstruction*>(MemItem));
                }
                

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
        #ifdef DEBUG
        cout<<"Store Register in getregister array"<<endl;
        #endif // DEBUG
       StoreRegister(goal);
        //分配寄存器给输入变量
        regs[goal].tag=1;
        regs[goal].array_addr=array_addr;
        #ifdef DEBUG
                //cout<<"findregister: insldr rd="<<goal<< ",r1="<<R11<<",r2 offset="<<array_addr->offset<<",op2type=1, insefft=0" <<  endl;
        #endif // DEBUG
        MemoryInstruction* MemItem=new MemoryInstruction(INSLDR,(Register)goal,  GetRegister(array_addr->array_si), GetRegister(array_addr->deviation) , 0, 0);
        InsList.push_back(dynamic_cast<ARMInstruction*>(MemItem));
        return (Register)goal;
    }

 }
Register ARM::GetRegisterNoLoad(ScopeItem* variable){
    //分配或者获取已经分配的空余寄存器
    int goal;
    //找到保存有该变量的寄存器
    if((goal=FindRegister(variable))!=-1){
        regs[goal].tag++;
        return (Register)goal;
    }
    //没有变量保存
    else{
        //寻找空寄存器
        for(Register item: userReg){
            if(regs[item].filled==false){
                regs[item].filled=true;
                regs[item].tag=1;
                regs[item].variable=variable;
                
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
        #ifdef DEBUG
        cout<<"Store Register in getregisterNoLoad variable"<<endl;
        #endif // DEBUG
        StoreRegister(goal);
        
        //分配寄存器给输入变量
        regs[goal].tag=1;
        regs[goal].variable=variable;
        return (Register)goal;
    }


} 
Register ARM::GetRegisterNoLoad(ARRAY_ADDR* array_addr){

    #ifdef DEBUG
    cout<<"GetRegisterNoLoad array_addr"<<endl;
    #endif // DEBUG
     //分配或者获取已经分配的空余寄存器
    int goal;
    //找到保存有该变量的寄存器
    if((goal=FindRegister(array_addr))!=-1){
        regs[goal].tag++;
        return (Register)goal;
    }
    
    //没有变量保存
    else{
        #ifdef DEBUG
    cout<<"cannot findregister GetRegisterNoLoad ARRAY_ADDR"<<endl;
    #endif // DEBUG
        //寻找空寄存器
        for(Register item: userReg){
            if(regs[item].filled==false){
                regs[item].filled=true;
                regs[item].tag=1;
                regs[item].array_addr=array_addr;
                
                return item;
            }
        }
        //没有空寄存器，用lru腾出一个寄存器
        //这个查找的效率是O(n)
        int minTag=1000;//无穷大
        for(Register item: userReg){
            if(regs[item].tag<minTag  ){
                goal=item;
                regs[item].tag=minTag;
            }
        }
        //保存这个寄存器中的数据至内存
        #ifdef DEBUG
        cout<<"Store Register in getregisterNoLoad array"<<endl;
        #endif // DEBUG
        StoreRegister(goal);
        //分配寄存器给输入变量
        regs[goal].tag=1;
        regs[goal].array_addr=array_addr;
        return (Register)goal;
    }

} 

//Register ARM::GetRegister(ScopeItem* variable);//分配空余寄存器
int  ARM::FindRegister(ScopeItem* variable){
    //查找存有对应变量的寄存器, 没有则返回-1
    if(variable==NULL){
        cout<<"FindRegister receive NULL"<<endl;
        return -1;
    }
    for(Register item: userReg){
        #ifdef DEBUG
        cout<<"userreg"<<item<<"contains"<<regs[item].variable<<endl;
        #endif // DEBUG
        if(regs[item].filled==true&&  regs[item].variable!=NULL&&   *(regs[item].variable)==*variable){
            return item;
        }
    }
    return -1;
}
int ARM::FindRegister(ARRAY_ADDR* array_addr){
    //查找存有对应变量的寄存器
    #ifdef DEBUG
    cout<<"FindRegister ARRAY_ADDR"<<endl;
    #endif // DEBUG
    for(Register item: userReg){
        
        if( regs[item].filled==true&&  regs[item].array_addr!=NULL   &&*(regs[item].array_addr)==*array_addr){
            #ifdef DEBUG
            cout<<"return FindRegister ARRAY_ADDR"<<endl;
            #endif // DEBUG
            return item;
        }
    }
    return -1;

}

void ARM::EmptyRegister(){
    for(Register item: userReg){
        regs[item].filled=false;
        regs[item].tag=0;
        regs[item].variable=NULL;
        regs[item].array_addr=NULL;
        
    }
}
int ARM::LoadInstantToRegister(int instantNum){
    //加载一个一次性的立即数到空寄存器中，不统计内容
    for(Register item: userReg){
        if(regs[item].filled==false){
            CalculateInstruction* CalItem=new CalculateInstruction(INSMOV, (Register)item, instantNum, 1 );
            InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
            return item;
        }
    }

    //如果没有空寄存器，要腾空一个
    int minTag=1000;//无穷大
    int goal=-1;
        for(Register item: userReg){
            if(regs[item].tag<minTag){
                goal=item;
                regs[item].tag=minTag;
            }
        }
    StoreRegister(goal);
    CalculateInstruction* CalItem=new CalculateInstruction(INSMOV, (Register)goal, instantNum, 1 );
    InsList.push_back(dynamic_cast<ARMInstruction*>(CalItem));
}


//将这个寄存器内的变量保存到它内部offset指向的内存单元中
//对于局部变量的存储, 不能用于数组
void ARM::StoreRegister(int RegisterNum){
    
    if(regs[RegisterNum].filled==false || (regs[RegisterNum].variable==NULL && regs[RegisterNum].array_addr==NULL)){
        cout<<"register:"<<RegisterNum<<endl;
        throw std::runtime_error("no variable in this register");
    }
    if(regs[RegisterNum].variable!=NULL){//普通变量存储
        //分类型存储
        if(regs[RegisterNum].variable->stype==Global){
            //全局变量如何存储
            
        }
        else{
            //局部变量和形参
            MemoryInstruction* MemItem=new MemoryInstruction(INSSTR, (Register)RegisterNum, LoadInstantToRegister(regs[RegisterNum].variable->offset), 0);
            InsList.push_back(dynamic_cast<ARMInstruction*>(MemItem));

        }
    }
    else {// 数组变量存储
    
        MemoryInstruction* MemItem= new MemoryInstruction(INSSTR, (Register)RegisterNum, GetRegister(regs[RegisterNum].array_addr->array_si), GetRegister(regs[RegisterNum].array_addr->deviation), 0, 0);
        InsList.push_back(dynamic_cast<ARMInstruction*>(MemItem));

    }
    
}

void ARM::AllocateStack(ScopeItem * variable, int &offset){
    //给变量在栈中分配地址,相对于当前fp
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
    string CodeString= "\n";

    CodeString+="EXTERN getint getchar getarray putint putchar putarray\n";

    CodeString+=".text\n.global main\n";
    int i=0;
    for(auto iter: InsList){
        i++;
        #ifdef DEBUG
        cout<<"instruction number"<<i<<endl;
        #endif // DEBUG
        
        CodeString+=iter->toString();
    }
    //CodeString+="\nEND\n";
    return CodeString;


}


