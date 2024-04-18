#include "s21_decimal.h"

void mine_from_int_to_decimal(int src, s21_decimal *dst) {
  int code = 0;

  if (src < 0) {
    dst->bits[3] = 0b10000000000000000000000000000000;
  } else {
    dst->bits[3] = 0b00000000000000000000000000000000;
  }
  src = abs(src);
  dst->bits[0] = src;
  dst->bits[1] = 0b00000000000000000000000000000000;
  dst->bits[2] = 0b00000000000000000000000000000000;
}

void mine_from_int_to_decimalb(int src, s21_big_decimal *dst) {
  src = abs(src);
  dst->bits[0] = src;
  dst->bits[1] = 0b00000000000000000000000000000000;
  dst->bits[2] = 0b00000000000000000000000000000000;
  dst->bits[3] = 0b00000000000000000000000000000000;
  dst->bits[4] = 0b00000000000000000000000000000000;
  dst->bits[5] = 0b00000000000000000000000000000000;
}