#include <stdio.h>
#include <stdlib.h>
#include "s21_decimal.h"
int main() {
    s21_decimal a;
    a.bits[0]=0b011111;
    a.bits[1]=0b000001;
    a.bits[2]=0b100001;
    a.bits[3]=0b000000;
    s21_shift(&a);
    
    
    return 0;
}
