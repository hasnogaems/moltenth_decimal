#include "s21_decimal.h"
int s21_floor(s21_decimal value, s21_decimal *result) {
  int error = 0;
  if (result == NULL) {
    error = 1;
  } else {
    s21_decimal buf = {{}};
    s21_truncate(value, &buf);

    if (get_sign(value) && !s21_is_equal(value, buf)) {
      set_bit(&buf.bits[3], 31, 0);
      add_one(&buf);
      set_bit(&buf.bits[3], 31, 1);
    }
    *result = buf;
  }
  return error;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  int error = 0;
  if (result) {
    if (!get_sign(value))
      s21_set_bit(&value, 127, 1);
    else
      s21_set_bit(&value, 127, 0);
  } else
    error = 1;
  *result = value;
  return error;
}
int s21_truncate(s21_decimal value, s21_decimal *result) {
  int err = 0;
  if (result) {
    uint64_t ostatok = 0;
    int scale = get_exp(value);
    while (scale > 0) {
      for (int i = 2; i >= 0; --i) {
        uint64_t num = value.bits[i];
        num += ostatok << 32;
        ostatok = num % 10;
        num /= 10;
        value.bits[i] = num;
      }
      scale--;
      ostatok = 0;
    }
    set_scale(&value, 0);
    *result = value;
  } else
    err = 1;
  return err;
}

int s21_div_by_ten(s21_decimal value, s21_decimal *result) {
  int order = 0, rem = 0;
  unsigned int buf = 0;
  for (int i = 0; i < 3; i++) {
    if (value.bits[i]) order = i;
  }
  buf = value.bits[order];
  while (order >= 0) {
    rem = buf % 10;
    result->bits[order] = buf / 10;
    buf = rem * (MAX_UINT + 1) + value.bits[order - 1];
    order--;
  }
  return 0;
}

void set_scale(s21_decimal *dec, int scale) {
  dec->bits[3] = get_bit_value(*dec, 127) << 31 | scale << 16;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int error = 0, znak = get_sign(value), scale = get_exp(value);
  int res = 0;
  unsigned long long drob = 0;
  if (result == NULL) {
    error = 1;
  } else {
    s21_decimal buf = {{}};
    if (znak) set_bit(&buf.bits[3], 31, 0);
    s21_truncate(value, &buf);

    // if ((scale) && ((get_bit(0, scale)) >= 5)) res = 1;
    if (scale) {
      for (int i = scale; i >= 0; i--) {
        if (value.bits[0] & 0b00000000000000000000000000000001 << i)
          drob += (int)pow(2, i);
      }
    }
    if (drob % ((int)pow(10, scale)) >= 5) res = 1;
    if (res) add_one(&buf);
    if (znak) set_bit(&buf.bits[3], 31, 1);

    *result = buf;
    printb(*result);
  }

  return error;
}

void add_one(s21_decimal *value) {  // нужно будет заменить на обычное сложение
  s21_decimal one = {{1}};

  s21_sum(value, one);
}