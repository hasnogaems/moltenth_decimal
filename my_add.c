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

int myaddnormalize(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){
    nullify(result);
    s21_big_decimal big1, big2, resbig;
    nullifyb(&big1);nullifyb(&big2);nullifyb(&resbig);
    int scale=normalize(value_1, value_2, &big1, &big2);
    myaddb(big1, big2, &resbig);
 //   printbb(resbig);
     //Теперь после арифметики пихаем обратно в децимал. К какому скейлу мы приводим если мантисса помещается полностью? Если мантисса не помещается то мы начинаем делить на 10 и уменьшать мантиссу при этом еще округлять и применять банковское если в остатке 0.5? И потом она говорит вам не нужно деление на 10.
     mybig_to_decimal(resbig, result, scale);
    // printb(*result);

 
}

int mybig_to_decimal(s21_big_decimal big, s21_decimal *decimal, int scale){
    
    if(big.bits[3]>0&&scale>0){
        int mod=div_by_tenb(&big);
        scale--;
        my_bank_round(&big, decimal, mod, &scale);
    }
    if(big.bits[3]>0)return 0;
for(int i=0;i<3;i++){
    decimal->bits[i]=big.bits[i];
}
decimal->bits[3]|=scale<<16;

}

int my_bank_round(s21_big_decimal* big, s21_decimal* decimal, int mod, int* scale){
printf("bit0=%d\n",get_bit_valueb(*big, 0));
s21_big_decimal one;
mine_from_int_to_decimalb(1,&one);
if(mod==5 && get_bit_valueb(*big, 0) || mod>5){
myaddb(*big, one, big);
}
if(countLastBitbig(*big)>95){
    
    mod=div_by_tenb(big);
    (*scale)--;
    my_bank_round(big, decimal, mod, scale);
}
set_exp2(decimal, *scale);
}


int div_by_tenb(s21_big_decimal *result) {
  unsigned long long overflow = 0;
  for (int i = 5; i >= 0; i--) {
    unsigned long long save = (overflow << 32) | result->bits[i];
    result->bits[i] = (save / 10);
    overflow = save % 10;
  }
  return overflow;
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

void myshiftright(s21_big_decimal* d, int value){
    int overflow=0;
    int memory=0;
    for(int i=5;i>=0;i--){
memory=d->bits[i];        
d->bits[i]>>=value;
d->bits[i]|=overflow;
overflow=memory<<(32-value);
    }
}