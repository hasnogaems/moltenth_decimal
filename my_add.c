#include "s21_decimal.h"
#include "utils.h"
int myadd(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){
    nullify(result);
    int res=0;
    int carry=0;
    for(int i=0;i<95;i++){
       res=get_bit_value(value_1, i)+get_bit_value(value_2, i)+carry;
       s21_set_bit(result, i, res%2);
carry=res/2;

    }
}

void myaddb(s21_big_decimal value_1, s21_big_decimal value_2, s21_big_decimal *result){
    nullifyb(result);
    int res=0;
    int carry=0;
    for(int i=0;i<159;i++){
       res=get_bit_valueb(value_1, i)+get_bit_valueb(value_2, i)+carry;
       s21_set_bitb(result, i, res%2);
carry=res/2;

    }
}

void mymulby10(s21_big_decimal* d){
    s21_big_decimal shift3=*d;
 s21_big_decimal shift1=*d;

 myshiftleft(&shift3, 3);
 myshiftleft(&shift1, 1);

 myaddb(shift3, shift1, d);

}

void myshiftleft(s21_big_decimal* d, int value){
    int overflow=0;
    int memory=0;
    for(int i=0;i<5;i++){
memory=d->bits[i];        
d->bits[i]<<=value;
d->bits[i]|=overflow;
overflow=memory>>(32-value);
    }
}