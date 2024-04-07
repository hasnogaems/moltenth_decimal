#include "s21_decimal.h"
#include "utils.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  initializeByZeros(result);
  int code = 0;
  if (zeroDecimal(value_2) == 1) {
    code = 3;
  } else if (zeroDecimal(value_1) != 1) {
    s21_big_decimal big1 = decimalToBig(value_1);
    s21_big_decimal big2 = decimalToBig(value_2);
    int sgn = ((value_1.bits[3] >> 31) + (value_2.bits[3] >> 31)) % 2; //берем оба sign и делим на два получается если мы например 10 делим на -5 то sgn будет 1, значит ответ будет -
    int scl1 = retrieveLevel(value_1);
    int scl2 = retrieveLevel(value_2);
    int scale_difference = scl1 - scl2;
    s21_big_decimal big_r, remain;
    while (isLessBigDecimal(big1, big2) && scale_difference < 28) {
      mulBigDecimal(big1, getBigDecimal10(), &big1);
      scale_difference++;
    }
    if (isLessBigDecimal(big1, big2) != 1) {
      remain = divBigDecimal(big1, big2, &big_r);
      while (zeroBigDecimal(remain) != 1 && scale_difference < 28) {
        mulBigDecimal(big1, getBigDecimal10(), &big1);
        remain = divBigDecimal(big1, big2, &big_r);
       
      }
      while (scale_difference < 0) {
        mulBigDecimal(big_r, getBigDecimal10(), &big_r);
        scale_difference++;
      }
      code = reduceScale(&big_r, &scale_difference);
      *result = bigToDecimal(big_r);
      setSign(result, sgn);
      setScale(result, scale_difference);
      if (sgn == 1 && code == 1) code++;
    } else if (zeroDecimal(value_1) != 1) {
      code = 1;
    }
  }
  return code;
}