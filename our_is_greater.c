#include "s21_decimal.h"
int s21_is_greater_ours(s21_decimal mem1, s21_decimal mem2) {
  int res = 0;

  for (int i = 192; i > 0; i--) {
    if (get_bit_value(mem1, i) != get_bit_value(mem2, i)) {
      if (get_bit_value(mem1, i)) res = 1;
      break;
    }
  }
  return res;
}

// int s21_is_equal(s21_decimal mem1, s21_decimal mem2){
// int res=1;

// for (int i=192; i>0;i--){
//     if (get_bit_value(mem1, i)!=get_bit_value(mem2, i))
//     res*=0;
// }
//     return res;
// }

int s21_is_equal_source(s21_decimal dec1, s21_decimal dec2) {
  int res = 0;
  int scale = 0;
  int sign1 = get_sign(dec1);
  int sign2 = get_sign(dec2);
  if (sign1 == sign2) {
    s21_big_decimal big1, big2;
    nullifyb(&big1);
    nullifyb(&big2);
    scale = normalize(dec1, dec2, &big1, &big2);
    mybig_to_decimal(big1, &dec1, scale, sign1);
    if (dec1.bits[0] == dec2.bits[0] && dec1.bits[1] == dec2.bits[1] &&
        dec1.bits[2] == dec2.bits[2] && dec1.bits[3] == dec2.bits[3]) {
      res = 1;
    }
  }
  return res;
}