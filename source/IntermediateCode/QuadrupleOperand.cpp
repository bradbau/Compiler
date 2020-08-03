#include "QuadrupleOperand.h"

bool operator==(ARRAY_ADDR a1, ARRAY_ADDR a2){
    //重载相等比较运算符
    std::cout<<"reload == for array"<<std::endl;
    if(a1.array_si==NULL || a2.array_si==NULL || a1.deviation ==NULL || a2.deviation==NULL){
        cout<<"empty array_addr"<<endl;
        return false;
    }
    return *(a1.array_si)==*(a2.array_si) && *(a1.deviation)==*(a2.deviation);
}