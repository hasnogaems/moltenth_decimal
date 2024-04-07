#include <stdio.h>

#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int code = 0;
  if (!dst) code = 1;
  if (src < 0)
    dst->bits[3] = 0b10000000000000000000000000000000;
  else dst->bits[3] = 0b00000000000000000000000000000000;
  dst->bits[2] = 0b00000000000000000000000000000000;
  dst->bits[1] = 0b00000000000000000000000000000000;
  dst->bits[0] = 0b00000000000000000000000000000000;
  src = abs(src);
  for (int i = 31; i > 0, src > 0; i--) {
    if (src / (int)pow(2, i) > 0) {
      dst->bits[0] = (dst->bits[0] | 0b00000000000000000000000000000001 << i);
      src -= (int)pow(2, i);
    }
  }
  return code;
}
// Записать просто интегер

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int code = 0;
  int result = 0;
  if (src.bits[1] > 0 || src.bits[2] > 0 || src.bits[0] > 2147483647) {
    code = 1;
  }
  int sign = get_sign(src);
  for (int i = 0; i < 31; i++) {
    if (src.bits[0] & 0b00000000000000000000000000000001 << i)
      result += (int)pow(2, i);
  }
  if(sign = 1)
    *dst = -1*result;
  else *dst = result;
  return code;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst){
int code=0;
if (!dst) code = 1;
nullify(dst);
if(src < 0)
  dst->bits[3] = 0b10000000000001100000000000000000;
else dst->bits[3] = 0b00000000000001100000000000000000;
float FP, *pFP=&FP, lp;
src=abs(src);
lp=modff(src, &FP);
long double fp=(long double)FP, result= fp*pow(10,6)+lp*(10,6);

for(int i = 95; i >= 64; i--){
  if (result/ pow(2,i) > 1){
  dst->bits[2] = dst->bits[2] |  0b00000000000000000000000000000001 << i;
  result -= pow(2, i);
  }
}

for(int i = 63; i >= 32; i--){
  if (result/ pow(2,i) > 1){
  dst->bits[1] = dst->bits[1] |  0b00000000000000000000000000000001 << i;
  result -= pow(2, i);
  }
}

for(int i = 31; i >= 0; i--){
  if (result/ pow(2,i) > 1){
  dst->bits[0] = dst->bits[0] |  0b00000000000000000000000000000001 << i;
  result -= pow(2, i); 
  }
}
return code;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst){
  int code =0, scale=get_exp(src);
if (scale>6) code=1;
long double result;

for(int i = 95; i >= 64; i--){
  if (get_bit(i, 2))
 result += pow(2, i);
}

for(int i = 63; i >= 32; i--){
  if (get_bit(i, 1))
 result += pow(2, i);
}

for(int i = 31; i >= 0; i--){
  if (get_bit(i, 0))
 result += pow(2, i);
}

float res=(float)result/pow(10,scale);
if (get_sign) res=res*(-1);
return code;
}