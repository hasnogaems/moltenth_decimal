#include "s21_decimal.h"
int s21_is_greater_ours(s21_decimal mem1, s21_decimal mem2){
int res=0;

for (int i=192; i>0;i--){
    if (get_bit_value(mem1, i)!=get_bit_value(mem2, i))
    { 
     if (get_bit_value(mem1, i))
        res=1;
     break;
    }
}
    return res;
}

int s21_is_equal(s21_decimal mem1, s21_decimal mem2){
int res=1;

for (int i=192; i>0;i--){
    if (get_bit_value(mem1, i)!=get_bit_value(mem2, i))
    res*=0;
}
    return res;
}