#include "QuadrupleOperand.h"

bool operator==(ARRAY_ADDR a1, ARRAY_ADDR a2){
    //重载相等比较运算符
    return *(a1.array_si)==*(a2.array_si) && *(a1.deviation)==*(a2.deviation);
}