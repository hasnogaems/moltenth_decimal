#include "s21_decimal.h"
#include "utils.h"
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){
    int error=0;
    nullify(result);
    s21_decimal one={{0b01,0,0,0}};
    int sign1=extractBitSign(value_1);
    int sign2=extractBitSign(value_2);
    unsigned int sign=0;  
s21_big_decimal big1, big2, resbig, buffer;
    nullifyb(&big1);nullifyb(&big2);nullifyb(&resbig);nullifyb(&buffer);
     int scale=normalize(value_1, value_2, &big1, &big2);
     s21_decimal compareit; nullify(&compareit);
     while(s21_is_less(value_2, value_1)){
       myshiftlefts(&value_2, 1);
       myadd(*result, one, result);


     }
}

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

int s21_div_ammoshri(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
int res = OK, sign = (get_sign(value_1) + get_sign(value_2)) % 2,
to_long = OK;
s21_decimal temp = {{0}};
ls21_decimal a, b, c, d, temp2 = {{0}}, dva = {{0, 0, 0, 0, 0, 2, 0}},
nuli = {{0}};
ls21_decimal des = {{0, 0, 0, 0, 0, 10, 0}};
to_long_dec(value_1, &a);
to_long_dec(value_2, &b);
int nol1 = mem_dec(a, nuli), nol2 = mem_dec(b, nuli);
if (nol2 == 0) return DIV_BY_ZERO;
if (nol1 == 0) {
memcpy(result, &temp, 4 * sizeof(int));
return res;
}
to_long_dec(temp, &c);
int scale = get_scale(value_1) - get_scale(value_2);
memcpy(&temp2, &a, 6 * sizeof(int));
while (to_long == OK) {
memcpy(&a, &temp2, 6 * sizeof(int));
to_long = s21_umn_bit(temp2, des, &temp2);
scale++;
}
scale--;
s21_del_bit(a, b, &c, &d);
s21_umn_bit(d, dva, &d);
lset_sign(&c, sign);
to_norm(&c, &scale);
if (scale < 0) res = TOO_BIG + sign;
if (res == OK) {
min_scale(&c, &scale);
from_long_dec(c, result);
set_sign(result, sign);
set_scale(result, scale);
}
return res;
}
