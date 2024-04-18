#include "s21_decimal.h"
#include "utils.h"
int tsuboika_is_greater(s21_decimal dec1, s21_decimal dec2) {
  int res = 0;
  s21_big_decimal big1, big2;
  nullifyb(&big1);
  nullifyb(&big2);
  if (!decimal_is_zero(dec1) && !decimal_is_zero(dec2)) {
    if (retrieveBit(dec1, 127) < retrieveBit(dec2, 127)) {
      res = 1;
    } else if (retrieveBit(dec1, 127) > retrieveBit(dec2, 127)) {
      res = 0;
    } else {
      normalize(dec1, dec2, &big1, &big2);
      for (int i = 191; i >= 0; --i) {
        if (getBigBit(big1, i) > getBigBit(big2, i)) {
          res = 1;

          break;
        } else if (getBigBit(big1, i) < getBigBit(big2, i)) {
          res = 0;

          break;
        }
      }
    }
  }
  if (!decimal_is_zero(dec1) && decimal_is_zero(dec2)) {
    res = 1;
  }
  return res;
}

int tsuboika_is_equal(s21_decimal dec1, s21_decimal dec2) {
  int res = 0;
  s21_big_decimal big1, big2;
  nullifyb(&big1);
  nullifyb(&big2);
  normalize(dec1, dec2, &big1, &big2);
  if (big1.bits[0] == big2.bits[0] && big1.bits[1] == big2.bits[1] &&
      big1.bits[2] == big2.bits[2] && big1.bits[3] == big2.bits[3] &&
      big1.bits[4] == big2.bits[4] && big1.bits[5] == big2.bits[5]) {
    res = 1;
  }
  return res;
}