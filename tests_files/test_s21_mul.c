#include "suits.h"



START_TEST(s21_mul_1) {
  // -52201
  s21_decimal dec_1 = {{0xcbe9, 0x0, 0x0, 0x80000000}};
  // -268348.42927111
  s21_decimal dec_2 = {{0xf947c007, 0x1867, 0x0, 0x80080000}};
  // 14008056356.38121311
  s21_decimal dec_check = {{0xc793535f, 0x1370a94d, 0x0, 0x80000}};
  s21_decimal result;
  my_mul(dec_1, dec_2, &result);
  int equal=s21_is_equal_source(result, dec_check);
  ck_assert_int_eq(1, equal);
  // ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  // ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  // ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  // ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_2) {
  // -2.184
  s21_decimal dec_1 = {{0x888, 0x0, 0x0, 0x80030000}};
  // -824
  s21_decimal dec_2 = {{0x338, 0x0, 0x0, 0x80000000}};
  // 1799.616
  s21_decimal dec_check = {{0x1b75c0, 0x0, 0x0, 0x30000}};
  s21_decimal result;
my_mul(dec_1, dec_2, &result);

  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST



START_TEST(s21_mul_4) {
  // -49141816385517468135
  s21_decimal dec_1 = {{0x5c3d39e7, 0xa9facda3, 0x2, 0x80000000}};
  // 7.5
  s21_decimal dec_2 = {{0x4b, 0x0, 0x0, 0x10000}};
  // -368563622891381011012.5
  s21_decimal dec_check = {{0x5eff6ad, 0xcc7a3edc, 0xc7, 0x80010000}};
  s21_decimal result;
   my_mul(dec_1, dec_2, &result);

  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_5) {
  // -18330294
  s21_decimal dec_1 = {{0x117b2b6, 0x0, 0x0, 0x80000000}};
  // -807107.572377446411475
  s21_decimal dec_2 = {{0x8d926cd3, 0xc0de1cd6, 0x2b, 0x800f0000}};
  // 14794519091304.871691581723650
  s21_decimal dec_check = {{0xfb91402, 0xfbc9f98d, 0x2fcdbd46, 0xf0000}};
  s21_decimal result;
my_mul(dec_1, dec_2, &result);

  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_6) {
  // 51033670457547897989198.175
  s21_decimal dec_1 = {{0x74b7715f, 0xd1a9ed6c, 0x2a36cc, 0x30000}};
  // 68
  s21_decimal dec_2 = {{0x44, 0x0, 0x0, 0x0}};
  // 3470289591113257063265475.900
  s21_decimal dec_check = {{0xba1d3c, 0xb12310cf, 0xb368e67, 0x30000}};
  s21_decimal result;
 my_mul(dec_1, dec_2, &result);
 
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_7) {
  // -4303301081974.9290
  s21_decimal dec_1 = {{0x9b86d5aa, 0x98e24b, 0x0, 0x80040000}};
  // -5667200247542246
  s21_decimal dec_2 = {{0xe1a031e6, 0x142249, 0x0, 0x80000000}};
  // 24387668957017132675104040351
  s21_decimal dec_check = {{0x92f4e59f, 0x40b51ced, 0x4ecd01c7, 0x0}};
  s21_decimal result;
my_mul(dec_1, dec_2, &result);

  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_8) {
  // -276
  s21_decimal dec_1 = {{0x114, 0x0, 0x0, 0x80000000}};
  // -5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 1380
  s21_decimal dec_check = {{0x564, 0x0, 0x0, 0x0}};
  s21_decimal result;
 my_mul(dec_1, dec_2, &result);

  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_9) {
  // -19517
  s21_decimal dec_1 = {{0x4c3d, 0x0, 0x0, 0x80000000}};
  // 363374
  s21_decimal dec_2 = {{0x58b6e, 0x0, 0x0, 0x0}};
  // -7091970358
  s21_decimal dec_check = {{0xa6b6e136, 0x1, 0x0, 0x80000000}};
  s21_decimal result;
 my_mul(dec_1, dec_2, &result);

  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_10) {
  // 72.206964730655333466102945734
  s21_decimal dec_1 = {{0x2c25d7c6, 0x7a60880f, 0xe9503389, 0x1b0000}};
  // -71842
  s21_decimal dec_2 = {{0x118a2, 0x0, 0x0, 0x80000000}};
  // -5187492.7601797404668717678274
  s21_decimal dec_check = {{0x464bbec2, 0x2b7b4e01, 0xa79def34, 0x80160000}};
  s21_decimal result;
my_mul(dec_1, dec_2, &result);

  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_11) {
  // 63
  s21_decimal dec_1 = {{0x3f, 0x0, 0x0, 0x0}};
  // -184557.28072343
  s21_decimal dec_2 = {{0xf1da697, 0x10c9, 0x0, 0x80080000}};
  // -11627108.68557609
  s21_decimal dec_check = {{0xb84bff29, 0x4217a, 0x0, 0x80080000}};
  s21_decimal result;
 my_mul(dec_1, dec_2, &result);

  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_12) {
  // 426.7190475437150428276932799
  s21_decimal dec_1 = {{0xf32740bf, 0x31a4c6fc, 0xdc9bcbb, 0x190000}};
  // -154411538143836.58
  s21_decimal dec_2 = {{0xc8074c2a, 0x36dba5, 0x0, 0x80020000}};
  // -65890344486497970.416305360597
  s21_decimal dec_check = {{0x1d60ced5, 0xe76a8200, 0xd4e7372b, 0x800c0000}};
  s21_decimal result;
 my_mul(dec_1, dec_2, &result);

  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_13) {
  // 13353396418157.124280077632679
  s21_decimal dec_1 = {{0xbd65c4a7, 0x54d06de1, 0x2b25abae, 0xf0000}};
  // -7762
  s21_decimal dec_2 = {{0x1e52, 0x0, 0x0, 0x80000000}};
  // -103649062997735598.66196258485
  s21_decimal dec_check = {{0xed2c6eb5, 0x642302f5, 0x217da648, 0x800b0000}};
  s21_decimal result;
 my_mul(dec_1, dec_2, &result);

  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_14) {
  // -0.3592099
  s21_decimal dec_1 = {{0x36cfa3, 0x0, 0x0, 0x80070000}};
  // 445667.05
  s21_decimal dec_2 = {{0x2a808b1, 0x0, 0x0, 0x20000}};
  // -160088.016463795
  s21_decimal dec_check = {{0x655aa7b3, 0x9199, 0x0, 0x80090000}};
  s21_decimal result;
 my_mul(dec_1, dec_2, &result);
 
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_15) {
  // 5188326659052018900.78
  s21_decimal dec_1 = {{0x5c7b431e, 0x203fe8bf, 0x1c, 0x20000}};
  // 970576774.92887564
  s21_decimal dec_2 = {{0x85b0200c, 0x158d171, 0x0, 0x80000}};
  // 5035669356020216648862084333.5
  s21_decimal dec_check = {{0xb19bc147, 0xdb9f5554, 0xa2b614a3, 0x10000}};
  s21_decimal result;
 my_mul(dec_1, dec_2, &result);

  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_16) {
  // -799842
  s21_decimal dec_1 = {{0xc3462, 0x0, 0x0, 0x80000000}};
  // -8056927482.6452
  s21_decimal dec_2 = {{0xff017ed4, 0x4946, 0x0, 0x80040000}};
  // 6444268991573902.0584
  s21_decimal dec_check = {{0xde459d28, 0x7e526d0b, 0x3, 0x40000}};
  s21_decimal result;
 my_mul(dec_1, dec_2, &result);

  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_mul_17) {
  // -8
  s21_decimal dec_1 = {{0x8, 0x0, 0x0, 0x80000000}};
  // -43.3681876
  s21_decimal dec_2 = {{0x19d975d4, 0x0, 0x0, 0x80070000}};
  // 346.9455008
  s21_decimal dec_check = {{0xcecbaea0, 0x0, 0x0, 0x70000}};
  s21_decimal result;
  int return_value = my_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(fail_s21_mul_1) {
  // -85691084311200035751
  s21_decimal dec_1 = {{0x932073a7, 0xa533e32b, 0x4, 0x80000000}};
  // 551022107836899
  s21_decimal dec_2 = {{0xd50041e3, 0x1f526, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = my_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_2) {
  // -48680439904191709117934612
  s21_decimal dec_1 = {{0x344fec14, 0xef61a5cb, 0x28447b, 0x80000000}};
  // 2233
  s21_decimal dec_2 = {{0x8b9, 0x0, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = my_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_3) {
  // -60690994415661495146716.36
  s21_decimal dec_1 = {{0x5174b614, 0x8a3c0d73, 0x5052e, 0x80020000}};
  // 402335213372637
  s21_decimal dec_2 = {{0xf77944dd, 0x16deb, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = my_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_4) {
  // 66371478770832141347927139774
  s21_decimal dec_1 = {{0xf2a4a5be, 0xb878680c, 0xd6753351, 0x0}};
  // -2652148912966838777671
  s21_decimal dec_2 = {{0xfacff747, 0xc5f5b8a7, 0x8f, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = my_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_mul_5) {
  // 4626841076.0
  s21_decimal dec_1 = {{0xc5cfeb88, 0xa, 0x0, 0x10000}};
  // 1955.82396977071095981864
  s21_decimal dec_2 = {{0x1bdea728, 0x8b0112b2, 0x296a, 0x140000}};
  s21_decimal result;
  // overflow
  int check = 3; // Результат слишком мал или отрицательная бесконечность.
  int return_value = my_mul(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

Suite *s21_mul_cases(void) {
  Suite *c = suite_create("s21_mul_cases");
  TCase *tc = tcase_create("s21_mul_tc");


;
  tcase_add_test(tc, s21_mul_1);
  tcase_add_test(tc, s21_mul_2);

  tcase_add_test(tc, s21_mul_4);
  tcase_add_test(tc, s21_mul_5);
  tcase_add_test(tc, s21_mul_6);
  tcase_add_test(tc, s21_mul_7);
  tcase_add_test(tc, s21_mul_8);
  tcase_add_test(tc, s21_mul_9);
  tcase_add_test(tc, s21_mul_10);
  tcase_add_test(tc, s21_mul_11);
  tcase_add_test(tc, s21_mul_12);
  tcase_add_test(tc, s21_mul_13);
  tcase_add_test(tc, s21_mul_14);
  tcase_add_test(tc, s21_mul_15);
  tcase_add_test(tc, s21_mul_16);
  tcase_add_test(tc, s21_mul_17);
  tcase_add_test(tc, fail_s21_mul_1);
  tcase_add_test(tc, fail_s21_mul_2);
  tcase_add_test(tc, fail_s21_mul_3);
  tcase_add_test(tc, fail_s21_mul_4);
  tcase_add_test(tc, fail_s21_mul_5);

  suite_add_tcase(c, tc);
  return c;
}
