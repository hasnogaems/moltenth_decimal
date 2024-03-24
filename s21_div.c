#include "s21_decimal.h"
#include "utils.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  initializeByZeros(result);
  int code = 0;
  if (zeroDecimal(value_2) == 1) {
    code = 3;
  } else if (zeroDecimal(value_1) != 1) {
    s21_big_decimal tmp1 = decimalToBig(value_1);
    s21_big_decimal tmp2 = decimalToBig(value_2);
    int sgn = ((value_1.bits[3] >> 31) + (value_2.bits[3] >> 31)) % 2; //берем оба sign и делим на два получается если мы например 10 делим на -5 то sgn будет 1, значит ответ будет -
    int scl1 = retrieveLevel(value_1);
    int scl2 = retrieveLevel(value_2);
    int scale_difference = scl1 - scl2;
    s21_big_decimal tmp_r, remain;
    while (isLessBigDecimal(tmp1, tmp2) && scale_difference < 28) {
      mulBigDecimal(tmp1, getBigDecimal10(), &tmp1);
      scale_difference++;
    }
    if (isLessBigDecimal(tmp1, tmp2) != 1) {
      remain = divBigDecimal(tmp1, tmp2, &tmp_r);
      while (zeroBigDecimal(remain) != 1 && scale_difference < 28) {
        mulBigDecimal(tmp1, getBigDecimal10(), &tmp1);
        remain = divBigDecimal(tmp1, tmp2, &tmp_r);
        scale_difference++;
      }
      while (scale_difference < 0) {
        mulBigDecimal(tmp_r, getBigDecimal10(), &tmp_r);
        scale_difference++;
      }
      code = reduceScale(&tmp_r, &scale_difference);
      *result = bigToDecimal(tmp_r);
      setSign(result, sgn);
      setScale(result, scale_difference);
      if (sgn == 1 && code == 1) code++;
    } else if (zeroDecimal(value_1) != 1) {
      code = 1;
    }
  }
  return code;
}