#include "s21_decimal.h"
#include "utils.h"
// int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){
//     int error=0;
//     int sign1=extractBitSign(value_1);
//     int sign2=extractBitSign(value_2);
//     unsigned int sign=0;  
// s21_big_decimal big1, big2, resbig, buffer;
//     nullifyb(&big1);nullifyb(&big2);nullifyb(&resbig);nullifyb(&buffer);
//      int scale=normalize(value_1, value_2, &big1, &big2);
//      s21_decimal compareit; nullify(&compareit);
//      while(s21_is_less(compareit, value_1)){
//         my_mul_no_normalize(big2)

//      }
// }

int div_int(unsigned int value1, unsigned int value2, unsigned int* result){
    int top_bit1=0;
    int top_bit2=0;
    for(int i=31;i>0;i--){
if(get_bit(value1, i)){top_bit1=i;
break;}
    }
        for(int i=31;i>0;i--){
if(get_bit(value2, i)){top_bit2=i;
break;}
    }
    int shift=top_bit1-top_bit2;
    value2<<=shift;
    
    *result=1111111;


}

