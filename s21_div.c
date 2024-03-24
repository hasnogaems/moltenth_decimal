#include "s21_decimal.h"
#include "utils.h"

int s21_div(s21_decimal value1, s21_decimal value2, s21_decimal *result) {
  initializeByZeros(result);
  int code = 0;
  if (zeroDecimal(value2) == 1) {
    code = 3;
  } else if (zeroDecimal(value1) != 1) {
    s21_big_decimal big1 = decimalToBig(value1);
    s21_big_decimal big2 = decimalToBig(value2);
    int sgn = ((value1.bits[3] >> 31) + (value2.bits[3] >> 31)) % 2; //берем оба sign и делим на два получается если мы например 10 делим на -5 то sgn будет 1, значит ответ будет -
    int scl1 = retrieveLevel(value1);
    int scl2 = retrieveLevel(value2);
    int scale_difference = scl1 - scl2;
    s21_big_decimal tmp_r, remain;
normalize(value1, value2, &big1, &big2);
      code = reduceScale(&tmp_r, &scale_difference);
      *result = bigToDecimal(tmp_r);
      setSign(result, sgn);
      setScale(result, scale_difference);
      if (sgn == 1 && code == 1) code++;
    } else if (zeroDecimal(value1) != 1) {
      code = 1;
    }
  
  return code;
}