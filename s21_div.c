#include "s21_decimal.h"
#include "utils.h"
// int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){
//     int error=0;
//     nullify(result);
//     s21_decimal one={{0b01,0,0,0}};
//     int sign1=extractBitSign(value_1);
//     int sign2=extractBitSign(value_2);
//     unsigned int sign=0;  
// s21_big_decimal big1, big2, resbig, buffer;
//     nullifyb(&big1);nullifyb(&big2);nullifyb(&resbig);nullifyb(&buffer);
//      int scale=normalize(value_1, value_2, &big1, &big2);
//      s21_decimal compareit; nullify(&compareit);
//      while(s21_is_less(value_2, value_1)){
//        myshiftlefts(&value_2, 1);
//        myadd(*result, one, result);


//      }
// }





int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = OK, sign = (get_sign(value_1) + get_sign(value_2)) % 2,
      to_long = OK;
  s21_decimal temp = {{0}};
  s21_big_decimal a, b, c, d, temp2 = {{0}}, dva = {{0, 0, 0, 0, 0, 2, 0}},
                           nuli = {{0}};
  s21_big_decimal des = {{0, 0, 0, 0, 0, 10, 0}};
  my_decimal_to_big(value_1, &a);
  my_decimal_to_big(value_2, &b);
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

int s21_del_bit(s21_big_decimal a, s21_big_decimal b, s21_big_decimal *result,
                s21_big_decimal *ostatok) {
  int res = OK, len_a = lget_len(a), len_b = lget_len(b), bit = 0;
  s21_big_decimal new_a = {{0, 0, 0, 0, 0, 0, 0}};
  s21_big_decimal temp_res = {{0, 0, 0, 0, 0, 0, 0}};
  lget_new_dec(a, &new_a, len_b);
  for (unsigned long i = 6 * 8 * sizeof(int) - len_a + len_b;
       i <= 6 * 8 * sizeof(int); i++) {
    if (mem_dec(new_a, b) >= 0) {
      bit = 1;
      s21_minus_bit(new_a, b, &new_a);
    } else {
      bit = 0;
    }
    lsdvig_vlevo_it(&temp_res);
    lset_bit(&temp_res, 6 * 8 * sizeof(int) - 1, bit);
    if ((unsigned long)i < 6 * 8 * sizeof(int)) {
      lsdvig_vlevo_it(&new_a);
      lset_bit(&new_a, 6 * 8 * sizeof(int) - 1, lget_bit(a, i));
    }
  }
  memcpy(result, &temp_res, 6 * sizeof(int));
  memcpy(ostatok, &new_a, 6 * sizeof(int));
  return res;
}

int s21_del_bit(ls21_decimal a, ls21_decimal b, ls21_decimal *result,
                ls21_decimal *ostatok) {
  int res = OK, len_a = lget_len(a), len_b = lget_len(b), bit = 0;
  ls21_decimal new_a = {{0, 0, 0, 0, 0, 0, 0}};
  ls21_decimal temp_res = {{0, 0, 0, 0, 0, 0, 0}};
  lget_new_dec(a, &new_a, len_b);
  for (unsigned long i = 6 * 8 * sizeof(int) - len_a + len_b;
       i <= 6 * 8 * sizeof(int); i++) {
    if (mem_dec(new_a, b) >= 0) {
      bit = 1;
      s21_minus_bit(new_a, b, &new_a);
    } else {
      bit = 0;
    }
    lsdvig_vlevo_it(&temp_res);
    lset_bit(&temp_res, 6 * 8 * sizeof(int) - 1, bit);
    if ((unsigned long)i < 6 * 8 * sizeof(int)) {
      lsdvig_vlevo_it(&new_a);
      lset_bit(&new_a, 6 * 8 * sizeof(int) - 1, lget_bit(a, i));
    }
  }
  memcpy(result, &temp_res, 6 * sizeof(int));
  memcpy(ostatok, &new_a, 6 * sizeof(int));
  return res;
}