#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#define MAX_UINT 4294967295  // нужно для смещения на 32 бита влево
#define TRUE 1
#define FALSE 0
#define PLUS 0b00000000000000000000000000000000
#define MAX_DECIMAL 79228162514264337593543950335.L
//#include <check.h>
#include <math.h>  // необхлжима для ftoi
#include <stdio.h>
#include <stdlib.h>  // для тестов
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>

#define STRINGIZER(x)   # x
#define TO_STRING(x)    STRINGIZER(x)
#define P10_UINT64 10000000000000000000ULL   /* 19 zeroes */
#define E10_UINT64 19


typedef __int128 int128_t;
typedef unsigned __int128 uint128_t;

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[6];
} s21_big_decimal;

#define SC 0x00ff0000
#define MINUS 0x80000000
#define GETSCALE(v) ((v.bits[3] & SC) >> 16)
#define CHECKMINUS(v) ((v.bits[3] & MINUS) >> 31)

// доп функции

// приведение к  степени scale (умножение на 10 scale раз)
// возвращает 1 если переполнение
int s21_align_10(s21_decimal *value, int scale);
// сдвиг влево всех интов один раз и возвращение переполнения если оно есть
int s21_shift(s21_decimal *value);
// сложение только мантисс, возвращает переполнение буфера, если есть
int s21_sum(s21_decimal *dst, s21_decimal src);
// из value_1 вычитает value_2
int s21_diff(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

//
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);  //
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);  //
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);  //
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);  //

int s21_is_less(s21_decimal, s21_decimal);              //+
int s21_is_less_or_equal(s21_decimal, s21_decimal);     //+
int s21_is_greater(s21_decimal, s21_decimal);           //+
int s21_is_greater_or_equal(s21_decimal, s21_decimal);  //+
int s21_is_equal(s21_decimal, s21_decimal);             //+
int s21_is_not_equal(s21_decimal, s21_decimal);         //+

int s21_from_int_to_decimal(int src, s21_decimal *dst);      //
int s21_from_float_to_decimal(float src, s21_decimal *dst);  //
int s21_from_decimal_to_int(s21_decimal src, int *dst);      //
int s21_from_decimal_to_float(s21_decimal src, float *dst);  //

int s21_floor(s21_decimal value, s21_decimal *result);     //
int s21_round(s21_decimal value, s21_decimal *result);     //
int s21_truncate(s21_decimal value, s21_decimal *result);  //
int s21_negate(s21_decimal value, s21_decimal *result);    //

// tools
int get_bit(unsigned int value, int bit_number);  // проверить бит по номеру
void set_bit(unsigned int *value, int bit_number,
             int set_value);  // установить значение бита
                              // set_value 0 или 1
int get_sign(
    s21_decimal value);  // 1 -- число отрицательное, 2 -- положительное
int get_exp(s21_decimal value);  // узнать степень десятки
int set_exp(s21_decimal *value, int exp);
void clear_decimal(s21_decimal *value);  // очистить децимал
int decimal_is_zero(
    s21_decimal value);  // проверить, является ли децимал нулевым
void s21_shift_left(s21_decimal *number);
void s21_shift_right(s21_decimal *number);
int s21_div_by_ten(s21_decimal value, s21_decimal *result);
int rem_div_by_ten(s21_decimal value);
void add_one(s21_decimal *value);
void printb(s21_decimal bits_array);
int normalize(s21_decimal num_1, s21_decimal num_2,
                         s21_big_decimal *big1,
                         s21_big_decimal *big2);

// для тестов
typedef union {
  int ui;
  float fl;
} floatbits;
// int s21_from_float_to_decimal(float src, s21_decimal *dst);
// int s21_from_decimal_to_float(s21_decimal src, float *dst);
bool get_bit_value(s21_decimal target, int bit_number);
void s21_set_bit(s21_decimal* num, int index, int value);
int myadd(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void nullify(s21_decimal *d);
s21_big_decimal mantissadecimalToBig(s21_decimal value);
void myshiftleft(s21_big_decimal* d, int value);
void nullifyb(s21_big_decimal *d);
bool get_bit_valueb(s21_big_decimal target, int bit_number);
void s21_set_bitb(s21_big_decimal* num, int index, int value);
void mymulby10(s21_big_decimal* d);
int myaddnormalize(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int myaddb(s21_big_decimal value_1, s21_big_decimal value_2, s21_big_decimal *result);
int div_by_tenb(s21_big_decimal *result);
int mybig_to_decimal(s21_big_decimal big, s21_decimal *decimal, int scale, unsigned int sign);
int my_bank_round(s21_big_decimal* big, s21_decimal* decimal, int mod, int* scale, unsigned int sign);
void myshiftright(s21_big_decimal* d, int value);
void mine_from_int_to_decimal(int src, s21_decimal *dst);
void mine_from_int_to_decimalb(int src, s21_big_decimal *dst);
int countLastBitbig(s21_big_decimal);
void set_exp2(s21_decimal *dec, int power);
int print_uint128(uint128_t n);
void s21_from_decimal_to_int128(s21_decimal src, uint128_t *dst);
void gptprint_uint128(uint128_t n);
int check_345_b(s21_big_decimal big);
//Suite *s21_add_cases(void);
int mysubb(s21_big_decimal value_1, s21_big_decimal value_2, s21_big_decimal *result);
int mysubnormalize(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
//Suite *s21_sub_cases(void);
int s21_is_greater_ours(s21_decimal mem1, s21_decimal mem2);
int tsuboika_is_greater(s21_decimal dec1, s21_decimal dec2);

#endif