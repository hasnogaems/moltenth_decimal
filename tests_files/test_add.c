#include "../s21_decimal.h"


START_TEST(s21_add_1) {
  // -20450329270260114707023677573
  s21_decimal dec_1 = {{0x72184885, 0x249b602f, 0x42141dab, 0x80000000}};
  // -24944731693436323
  s21_decimal dec_2 = {{0xef9acda3, 0x589f19, 0x0, 0x80000000}};
  // -20450329270285059438717113896
  s21_decimal dec_check = {{0x61b31628, 0x24f3ff49, 0x42141dab, 0x80000000}};
  s21_decimal result;
    myaddnormalize(dec_1, dec_2, &result);
   
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_2) {
  // 77362155012221
  s21_decimal dec_1 = {{0x47c4c07d, 0x465c, 0x0, 0x0}};
  // -142.6052952
  s21_decimal dec_2 = {{0x54ffd758, 0x0, 0x0, 0x80070000}};
  // 77362155012078.3947048
  s21_decimal dec_check = {{0x2061a528, 0xf027dd03, 0x29, 0x70000}};
  s21_decimal result;
    myaddnormalize(dec_1, dec_2, &result);
   
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_3) {
  // -852096926
  s21_decimal dec_1 = {{0x32c9f79e, 0x0, 0x0, 0x80000000}};
  // -86200095542
  s21_decimal dec_2 = {{0x11ed1336, 0x14, 0x0, 0x80000000}};
  // -87052192468
  s21_decimal dec_check = {{0x44b70ad4, 0x14, 0x0, 0x80000000}};
  s21_decimal result;
    myaddnormalize(dec_1, dec_2, &result);
   
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_4) {
  // 7
  s21_decimal dec_1 = {{0x7, 0x0, 0x0, 0x0}};
  // -813274891230635975867.50072703
  s21_decimal dec_2 = {{0xca7b677f, 0x8036ffc0, 0x6c885b3, 0x80080000}};
  // -813274891230635975860.50072703
  s21_decimal dec_check = {{0xa0c2407f, 0x8036ffc0, 0x6c885b3, 0x80080000}};
  s21_decimal result;
    myaddnormalize(dec_1, dec_2, &result);
   
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_5) {
  // -823
  s21_decimal dec_1 = {{0x337, 0x0, 0x0, 0x80000000}};
  // -246.919
  s21_decimal dec_2 = {{0x3c487, 0x0, 0x0, 0x80030000}};
  // -1069.919
  s21_decimal dec_check = {{0x10535f, 0x0, 0x0, 0x80030000}};
  s21_decimal result;
    myaddnormalize(dec_1, dec_2, &result);
   
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_6) {
  // 9381
  s21_decimal dec_1 = {{0x24a5, 0x0, 0x0, 0x0}};
  // -9427
  s21_decimal dec_2 = {{0x24d3, 0x0, 0x0, 0x80000000}};
  // -46
  s21_decimal dec_check = {{0x2e, 0x0, 0x0, 0x80000000}};
  s21_decimal result;
    myaddnormalize(dec_1, dec_2, &result);
   
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_7) {
  // 0
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x0}};
  // 0.9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x10000}};
  // 0.9
  s21_decimal dec_check = {{0x9, 0x0, 0x0, 0x10000}};
  s21_decimal result;
    myaddnormalize(dec_1, dec_2, &result);
   
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_8) {
  // 9.35
  s21_decimal dec_1 = {{0x3a7, 0x0, 0x0, 0x20000}};
  // 776006978
  s21_decimal dec_2 = {{0x2e40ed42, 0x0, 0x0, 0x0}};
  // 776006987.35
  s21_decimal dec_check = {{0x115cb16f, 0x12, 0x0, 0x20000}};
  s21_decimal result;
    myaddnormalize(dec_1, dec_2, &result);
   
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_9) {
  // 30828307417409651777200184218
  s21_decimal dec_1 = {{0x8563db9a, 0xcce236c4, 0x639c9405, 0x0}};
  // 4424460518709
  s21_decimal dec_2 = {{0x2665c535, 0x406, 0x0, 0x0}};
  // 30828307417409656201660702927
  s21_decimal dec_check = {{0xabc9a0cf, 0xcce23aca, 0x639c9405, 0x0}};
  s21_decimal result;
    myaddnormalize(dec_1, dec_2, &result);
   
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST



START_TEST(s21_add_11) {
  // 55952
  s21_decimal dec_1 = {{0xda90, 0x0, 0x0, 0x0}};
  // 76881041156697
  s21_decimal dec_2 = {{0x4325ea59, 0x45ec, 0x0, 0x0}};
  // 76881041212649
  s21_decimal dec_check = {{0x4326c4e9, 0x45ec, 0x0, 0x0}};
  s21_decimal result;
    myaddnormalize(dec_1, dec_2, &result);
   
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_12) {
  // 0.3
  s21_decimal dec_1 = {{0x3, 0x0, 0x0, 0x10000}};
  // -70802443911485517293.35
  s21_decimal dec_2 = {{0xd14cf0b7, 0xd2211901, 0x17f, 0x80020000}};
  // -70802443911485517293.05
  s21_decimal dec_check = {{0xd14cf099, 0xd2211901, 0x17f, 0x80020000}};
  s21_decimal result;
    myaddnormalize(dec_1, dec_2, &result);
   
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_13) {
  // 6214680499901274
  s21_decimal dec_1 = {{0xf96d35a, 0x161438, 0x0, 0x0}};
  // -411406340069847.143749384
  s21_decimal dec_2 = {{0x494b1708, 0x61e3e951, 0x571e, 0x80090000}};
  // 5803274159831426.856250616
  s21_decimal dec_check = {{0x9b9decf8, 0x1f61766c, 0x4cce4, 0x90000}};
  s21_decimal result;
    myaddnormalize(dec_1, dec_2, &result);
   
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_14) {
  // 37350912.6
  s21_decimal dec_1 = {{0x16434c06, 0x0, 0x0, 0x10000}};
  // -74591.5076
  s21_decimal dec_2 = {{0x2c75c2c4, 0x0, 0x0, 0x80040000}};
  // 37276321.0924
  s21_decimal dec_check = {{0xca6b34ac, 0x56, 0x0, 0x40000}};
  s21_decimal result;
    myaddnormalize(dec_1, dec_2, &result);
   
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_15) {
  // 906
  s21_decimal dec_1 = {{0x38a, 0x0, 0x0, 0x0}};
  // 18543195508945815657608
  s21_decimal dec_2 = {{0x661cdc88, 0x3a885553, 0x3ed, 0x0}};
  // 18543195508945815658514
  s21_decimal dec_check = {{0x661ce012, 0x3a885553, 0x3ed, 0x0}};
  s21_decimal result;
    myaddnormalize(dec_1, dec_2, &result);
   
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_add_16) {
  // -7786585.007541
  s21_decimal dec_1 = {{0xf4a225b5, 0x714, 0x0, 0x80060000}};
  // -616
  s21_decimal dec_2 = {{0x268, 0x0, 0x0, 0x80000000}};
  // -7787201.007541
  s21_decimal dec_check = {{0x19598fb5, 0x715, 0x0, 0x80060000}};
  s21_decimal result;
    myaddnormalize(dec_1, dec_2, &result);
   
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST


Suite *s21_add_cases(void) {
  Suite *c = suite_create("s21_add_cases");
  TCase *tc = tcase_create("s21_add_tc");

  
  tcase_add_test(tc, s21_add_1);
  tcase_add_test(tc, s21_add_2);
  tcase_add_test(tc, s21_add_3);
  tcase_add_test(tc, s21_add_4);
  tcase_add_test(tc, s21_add_5);
  tcase_add_test(tc, s21_add_6);
  tcase_add_test(tc, s21_add_7);
  tcase_add_test(tc, s21_add_8);
  tcase_add_test(tc, s21_add_9);
 
  tcase_add_test(tc, s21_add_11);
  tcase_add_test(tc, s21_add_12);
  tcase_add_test(tc, s21_add_13);
  tcase_add_test(tc, s21_add_14);
  tcase_add_test(tc, s21_add_15);
  tcase_add_test(tc, s21_add_16);


  suite_add_tcase(c, tc);
  return c;
}
