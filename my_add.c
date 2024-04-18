#include "s21_decimal.h"
#include "utils.h"
int myadd(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  // nullify(result);
  int res = 0;
  int carry = 0;
  for (int i = 0; i < 95; i++) {
    res = get_bit_value(value_1, i) + get_bit_value(value_2, i) + carry;
    s21_set_bit(result, i, res % 2);
    carry = res / 2;
  }
  return carry;
}

int myaddnormalize(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal* result) {
  int error = 0;
  int scale1 = GETSCALE(value_1);
  int scale2 = GETSCALE(value_2);
  if (result) {  // if result not null
    int sign1 = extractBitSign(value_1);
    int sign2 = extractBitSign(value_2);
    unsigned int sign = 0;
    nullify(result);
    s21_big_decimal big1, big2, resbig;
    nullifyb(&big1);
    nullifyb(&big2);
    nullifyb(&resbig);
    int scale = normalize(value_1, value_2, &big1, &big2);
    if (sign1 == sign2) {
      sign = (unsigned int)sign1;
      myaddb(big1, big2, &resbig);
      error = mybig_to_decimal(resbig, result, scale, sign);
    }
    if (sign1 != sign2) {
      if (extractBitSign(value_1) == 1) {
        setSign(&value_1, 0);
        error = s21_sub(value_2, value_1, result);
      } else if (extractBitSign(value_2) == 1) {
        setSign(&value_2, 0);
        error = s21_sub(value_1, value_2, result);
      }
      //       if (get_sign(value_1) == 1) {
      //     zero_sign(&value_1, 0);
      //     status = s21_sub(value_2, value_1, result);
      //   } else if (get_sign(value_2) == 1) {
      //     zero_sign(&value_2, 0);
      //     status = s21_sub(value_1, value_2, result);
      //   }
      // }

      //   printbb(resbig);
      //Теперь после арифметики пихаем обратно в децимал. К какому скейлу мы
      //приводим если мантисса помещается полностью? Если мантисса не помещается
      //то мы начинаем делить на 10 и уменьшать мантиссу при этом еще округлять
      //и применять банковское если в остатке 0.5? И потом она говорит вам не
      //нужно деление на 10.

      // printb(*result);
    }
  } else {
    error = 1;
  }
  return error;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int error = 0;
  int sign1 = extractBitSign(value_1);
  int sign2 = extractBitSign(value_2);
  unsigned int sign = 0;
  int ddctbl_bgr = 0;

  nullify(result);
  s21_big_decimal big1, big2, resbig, buffer;
  nullifyb(&big1);
  nullifyb(&big2);
  nullifyb(&resbig);
  nullifyb(&buffer);
  int scale = normalize(value_1, value_2, &big1, &big2);
  if (sign1 == sign2) {
    sign = (unsigned int)sign1;
    if ((tsuboika_is_greater(value_2, value_1))) {
      buffer = big1;
      big1 = big2;
      big2 = buffer;
      sign ^= 1u;  //обращаем знак
      mysubb(big1, big2, &resbig);
      mybig_to_decimal(resbig, result, scale, sign);
    }

    else {
      mysubb(big1, big2, &resbig);
      if (tsuboika_is_equal(value_1, value_2)) sign = 0;
      mybig_to_decimal(resbig, result, scale, sign);
    }
  }
  if (sign1 > sign2) {
    // if((tsuboika_is_greater(value_2, value_1))){
    setSign(&value_2, 1);
    error = myaddnormalize(value_2, value_1, result);
    // setSign(result, 1);

    //  }
    return error;
  }
  if (sign2 > sign1) {
    // sign=0;

    setSign(&value_2, 0);

    error = myaddnormalize(value_1, value_2, result);

    return error;
  }
  //   printbb(resbig);
  //Теперь после арифметики пихаем обратно в децимал. К какому скейлу мы
  //приводим если мантисса помещается полностью? Если мантисса не помещается то
  //мы начинаем делить на 10 и уменьшать мантиссу при этом еще округлять и
  //применять банковское если в остатке 0.5? И потом она говорит вам не нужно
  //деление на 10.

  // printb(*result);

  return error;
}

int mybig_to_decimal(s21_big_decimal big, s21_decimal* decimal, int scale,
                     unsigned int sign) {
  nullify(decimal);
  int error = 0;
  if ((check_345_b(big) > 0 && scale > 0) || scale > 28) {
    int mod = div_by_tenb(&big);
    scale--;
    my_bank_round(&big, decimal, mod, &scale, sign);
  }
  while(scale<0){
    mymulby10(&big);
    scale++;
    
  }
  int wtf = check_345_b(big);
  if (wtf > 0) {
    error = (sign == 1) ? 2 : 1;
    return error;
  }
  for (int i = 0; i < 3; i++) {
    decimal->bits[i] = big.bits[i];
  }
  decimal->bits[3] |= scale << 16;
  setSign(decimal, sign);
  return error;
}
int check_345_b(s21_big_decimal big) {
  int result = 0;
  if (big.bits[3] > 0 || big.bits[4] > 0 || big.bits[5] > 0) {
    result = 1;
  }
  return result;
}

void my_decimal_to_big(s21_decimal val1, s21_big_decimal* tar1) {
  tar1->bits[0] = val1.bits[0];
  tar1->bits[1] = val1.bits[1];
  tar1->bits[2] = val1.bits[2];
}
int my_bank_round(s21_big_decimal* big, s21_decimal* decimal, int mod,
                  int* scale, unsigned int sign) {
  // printf("bit0=%d\n",get_bit_valueb(*big, 0));
  s21_big_decimal one;
  mine_from_int_to_decimalb(1, &one);
  if (mod == 5 && get_bit_valueb(*big, 0) || mod > 5) {
    myaddb(*big, one, big);
  }
  if (countLastBitbig(*big) > 95 && (*scale) > 0) {
    mod = div_by_tenb(big);
    (*scale)--;
    my_bank_round(big, decimal, mod, scale, sign);
  }
  mybig_to_decimal(*big, decimal, *scale, sign);
  // set_exp2(decimal, *scale);
}

int div_by_tenb(s21_big_decimal* result) {
  unsigned long long overflow = 0;
  for (int i = 5; i >= 0; i--) {
    unsigned long long save = (overflow << 32) | result->bits[i];
    result->bits[i] = (save / 10);
    overflow = save % 10;
  }
  return overflow;
}

int myaddb(s21_big_decimal value_1, s21_big_decimal value_2,
           s21_big_decimal* result) {
  int error = 0;
  nullifyb(result);
  int res = 0;
  int carry = 0;
  for (int i = 0; i < 191; i++) {
    res = get_bit_valueb(value_1, i) + get_bit_valueb(value_2, i) + carry;
    s21_set_bitb(result, i, res % 2);
    carry = res / 2;
  }
  if (carry) {
    error = 1;
  }
  return error;
}

int mysubb(s21_big_decimal value_1, s21_big_decimal value_2,
           s21_big_decimal* result) {
  int error = 0;
  nullifyb(result);
  int res = 0;
  int carry = 0;
  int k = 1;
  for (int i = 0; i < 191; i++) {
    res = get_bit_valueb(value_1, i) - get_bit_valueb(value_2, i);
    if (res == -1) {
      res = 1;
      for (k = 1; k + i < 191 && !get_bit_valueb(value_1, i + k); k++) {
      }

      s21_set_bitb(&value_1, k + i, 0);
      k--;
      if (k + i < 191) {
        while (k + i > i) {
          s21_set_bitb(&value_1, k + i, 1);
          k--;
        }
      }
    }
    //и тут вы начинаем занимать из старших битов, сначала ищем где вообще есть
    //бит, потом его нулим и на все нули после него ставим 1 кроме текущего
    s21_set_bitb(result, i, res);
  }
}

int mymulby10(s21_big_decimal* d) {
  int error = 0;
  s21_big_decimal shift3 = *d;
  s21_big_decimal shift1 = *d;

  error = myshiftleft(&shift3, 3);
  myshiftleft(&shift1, 1);

  myaddb(shift3, shift1, d);
  return error;
}

int mymulby10s(s21_decimal* d) {
  s21_decimal shift3 = *d;
  s21_decimal shift1 = *d;
  int error = 0;
  error = myshiftlefts(&shift3, 3);
  myshiftlefts(&shift1, 1);
  if (error) {
    printf("error");
    return 0;
  }
  myadd(shift3, shift1, d);
}
int myshiftleft(s21_big_decimal* d, int value) {
  int error = 0;
  if (value != 0) {
    unsigned int overflow = 0;
    unsigned int memory = 0;
    for (int i = 0; i <= 5; i++) {
      memory = d->bits[i];
      d->bits[i] <<= value;
      d->bits[i] |= overflow;
      overflow = memory >> (32 - value);
    }
    if (overflow > 0) error = 1;
  }
  return error;
}

int myshiftlefts(s21_decimal* d, int value) {
  int error = 0;
  unsigned int overflow = 0;
  unsigned int memory = 0;
  if (value > 0) {
    for (int i = 0; i < 3; i++) {
      memory = (unsigned int)d->bits[i];
      d->bits[i] <<= value;
      d->bits[i] |= overflow;
      overflow = memory >> (32 - value);
    }
  }
  if (overflow > 0) error = 1;
  return error;
}
void myshiftright(s21_big_decimal* d, int value) {
  unsigned int overflow = 0;
  unsigned int memory = 0;
  for (int i = 5; i >= 0; i--) {
    memory = d->bits[i];
    d->bits[i] >>= value;
    d->bits[i] |= overflow;
    overflow = memory << (32 - value);
  }
}

int my_mul(s21_decimal val1, s21_decimal val2, s21_decimal* result) {
  int error = 0;
  int scale = 0;
  s21_big_decimal big1, big2, bigres, add_shift;
  nullifyb(&big1);
  nullifyb(&big2);
  nullifyb(&bigres);
  nullifyb(&add_shift);
  scale = normalize(val1, val2, &big1, &big2);
  int i = 0;

  while (i <= 191) {
    if (getBigBit(big2, i)) {
      for (int k = 0; k <= 191; k++) {
        setBigBit(&add_shift, k, getBigBit(big1, k));
      }
      myshiftleft(&add_shift, i);
      myaddb(bigres, add_shift, &bigres);
    }

    i++;
  }
  scale *= 2;
  mybig_to_decimal(bigres, result, scale, 0);
}

int my_mul_no_normalize(s21_decimal val1, s21_decimal val2,
                        s21_decimal* result) {
  int error = 0;
  int sign = 0;
  if (get_sign(val1) == get_sign(val2)) {
    sign = 0;
  } else {
    sign = 1;
  }
  int scale1 = GETSCALE(val1);
  int scale2 = GETSCALE(val2);
  // if(scale1>28||scale2>28)return
  int scale = scale1 + scale2;
  int i = 0;
  int nonzero = 0;
  s21_decimal add_shift;
  s21_big_decimal big1, big2, resultbig;

  nullify(&add_shift);
  nullify(result);
  nullifyb(&big1);
  nullifyb(&big2);
  nullifyb(&resultbig);
  if (!zeroDecimal(val1) && !zeroDecimal(val2)) {
    big1.bits[0] = val1.bits[0];
    big1.bits[1] = val1.bits[1];
    big1.bits[2] = val1.bits[2];
    big2.bits[0] = val2.bits[0];
    big2.bits[1] = val2.bits[1];
    big2.bits[2] = val2.bits[2];

    for (int i = 0; i < 96; i++) {
      if (getBigBit(big2, i)) {
        myaddb(resultbig, big1, &resultbig);
      }

      myshiftleft(&big1, 1);
      //  printf("addshift iteration%d\n", i);
      // printb(add_shift);
      // printf("SUMM iteration%d\n", i);

      // printb(*result);
      // nullify(&add_shift);
    }

    error = mybig_to_decimal(resultbig, result, scale, sign);
  }
}

void add_carry(unsigned int* bit) { *bit += 1; }