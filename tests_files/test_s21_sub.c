#include "../s21_decimal.h"
#include "suits.h"




START_TEST(s21_sub_2) {
  // 4636249360
  s21_decimal dec_1 = {{0x14578d10, 0x1, 0x0, 0x0}};
  // 1707922025
  s21_decimal dec_2 = {{0x65ccd269, 0x0, 0x0, 0x0}};
  // 2928327335
  s21_decimal dec_check = {{0xae8abaa7, 0x0, 0x0, 0x0}};
  s21_decimal result;
  mysubnormalize(dec_1, dec_2, &result);
   
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_3) {
  // -86727035062894149274443
  s21_decimal dec_1 = {{0x5d4c8b4b, 0x7b63ca2d, 0x125d, 0x80000000}};
  // -3.78
  s21_decimal dec_2 = {{0x17a, 0x0, 0x0, 0x80020000}};
  // -86727035062894149274439.22
  s21_decimal dec_check = {{0x71e667d2, 0x32faf9b8, 0x72c84, 0x80020000}};
  s21_decimal result;
  mysubnormalize(dec_1, dec_2, &result);
  
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_4) {
  // 8669471812474.2
  s21_decimal dec_1 = {{0x2fe0b2c6, 0x4ed9, 0x0, 0x10000}};
  // -62998273073.1
  s21_decimal dec_2 = {{0xade599eb, 0x92, 0x0, 0x80010000}};
  // 8732470085547.3
  s21_decimal dec_check = {{0xddc64cb1, 0x4f6b, 0x0, 0x10000}};
  s21_decimal result;
  mysubnormalize(dec_1, dec_2, &result);
  
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_5) {
  // -8862
  s21_decimal dec_1 = {{0x229e, 0x0, 0x0, 0x80000000}};
  // 5435.69416625140342859070770
  s21_decimal dec_2 = {{0xba017d32, 0x1ebdbe98, 0x1c1a14d, 0x170000}};
  // -14297.69416625140342859070770
  s21_decimal dec_check = {{0xdd017d32, 0x6206bf99, 0x49ead73, 0x80170000}};
  s21_decimal result;
  mysubnormalize(dec_1, dec_2, &result);
  
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_6) {
  // 917.123163660089
  s21_decimal dec_1 = {{0x60629f39, 0x3421e, 0x0, 0xc0000}};
  // -3
  s21_decimal dec_2 = {{0x3, 0x0, 0x0, 0x80000000}};
  // 920.123163660089
  s21_decimal dec_check = {{0xde51cf39, 0x344d8, 0x0, 0xc0000}};
  s21_decimal result;
 mysubnormalize(dec_1, dec_2, &result);
  
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST



START_TEST(s21_sub_8) {
  // -6422229398
  s21_decimal dec_1 = {{0x7ecb7196, 0x1, 0x0, 0x80000000}};
  // -9
  s21_decimal dec_2 = {{0x9, 0x0, 0x0, 0x80000000}};
  // -6422229389
  s21_decimal dec_check = {{0x7ecb718d, 0x1, 0x0, 0x80000000}};
  s21_decimal result;
  mysubnormalize(dec_1, dec_2, &result);
  
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_9) {
  // 18098600888995.679
  s21_decimal dec_1 = {{0xe4eb8f5f, 0x404c94, 0x0, 0x30000}};
  // -888993799.16
  s21_decimal dec_2 = {{0xb2d0e2cc, 0x14, 0x0, 0x80020000}};
  // 18099489882794.839
  s21_decimal dec_check = {{0xe1146b57, 0x404d63, 0x0, 0x30000}};
  s21_decimal result;
 mysubnormalize(dec_1, dec_2, &result);
  
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_10) {
  // -30321046467
  s21_decimal dec_1 = {{0xf4673c3, 0x7, 0x0, 0x80000000}};
  // 25788.198654806455244189
  s21_decimal dec_2 = {{0x7120559d, 0xfb261cd0, 0x575, 0x120000}};
  // -30321072255.198654806455244189
  s21_decimal dec_check = {{0xde4c559d, 0x8f0e9d32, 0x61f900cc, 0x80120000}};
  s21_decimal result;
  mysubnormalize(dec_1, dec_2, &result);
  
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_11) {
  // 50.2
  s21_decimal dec_1 = {{0x1f6, 0x0, 0x0, 0x10000}};
  // -2340981.74943164050448009
  s21_decimal dec_2 = {{0xfa41e89, 0x7ccc4d85, 0x3192, 0x80110000}};
  // 2341031.94943164050448009
  s21_decimal dec_check = {{0x341a1e89, 0xc276ecec, 0x3192, 0x110000}};
  s21_decimal result;
mysubnormalize(dec_1, dec_2, &result);
 
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_12) {
  // 79088187
  s21_decimal dec_1 = {{0x4b6ca3b, 0x0, 0x0, 0x0}};
  // -6150146510181741040
  s21_decimal dec_2 = {{0x87fdb1f0, 0x5559b5aa, 0x0, 0x80000000}};
  // 6150146510260829227
  s21_decimal dec_check = {{0x8cb47c2b, 0x5559b5aa, 0x0, 0x0}};
  s21_decimal result;
 mysubnormalize(dec_1, dec_2, &result);

  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_13) {
  // 209521945007519679047.6816
  s21_decimal dec_1 = {{0xd4d51010, 0x12f05efa, 0x1bbae, 0x40000}};
  // -7320875951
  s21_decimal dec_2 = {{0xb45bb3af, 0x1, 0x0, 0x80000000}};
  // 209521945014840554998.6816
  s21_decimal dec_check = {{0x12eff400, 0x12f0a190, 0x1bbae, 0x40000}};
  s21_decimal result;
 mysubnormalize(dec_1, dec_2, &result);
 
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_14) {
  // 5.24797
  s21_decimal dec_1 = {{0x801fd, 0x0, 0x0, 0x50000}};
  // 3704757061284524102195
  s21_decimal dec_2 = {{0x18229233, 0xd5d51698, 0xc8, 0x0}};
  // -3704757061284524102189.75203
  s21_decimal dec_check = {{0xc04d0fe3, 0x4599d3d3, 0x1327348, 0x80050000}};
  s21_decimal result;
 mysubnormalize(dec_1, dec_2, &result);
 
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_15) {
  // -1631601
  s21_decimal dec_1 = {{0x18e571, 0x0, 0x0, 0x80000000}};
  // -42611472373368358044.7796
  s21_decimal dec_2 = {{0x62942c34, 0xb9b7bf38, 0x5a3b, 0x80040000}};
  // 42611472373366726443.7796
  s21_decimal dec_check = {{0x96119e24, 0xb9b7bf34, 0x5a3b, 0x40000}};
  s21_decimal result;
mysubnormalize(dec_1, dec_2, &result);
 
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_sub_16) {
  // 7108119410265
  s21_decimal dec_1 = {{0xfceeb659, 0x676, 0x0, 0x0}};
  // -7257
  s21_decimal dec_2 = {{0x1c59, 0x0, 0x0, 0x80000000}};
  // 7108119417522
  s21_decimal dec_check = {{0xfceed2b2, 0x676, 0x0, 0x0}};
  s21_decimal result;
 mysubnormalize(dec_1, dec_2, &result);
  
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST



Suite *s21_sub_cases(void) {
  Suite *c = suite_create("s21_sub_cases");
  TCase *tc = tcase_create("s21_sub_tc");

 
 
  tcase_add_test(tc, s21_sub_2);
  tcase_add_test(tc, s21_sub_3);
  tcase_add_test(tc, s21_sub_4);
  tcase_add_test(tc, s21_sub_5);
  tcase_add_test(tc, s21_sub_6);
 
  tcase_add_test(tc, s21_sub_8);
  tcase_add_test(tc, s21_sub_9);
  tcase_add_test(tc, s21_sub_10);
  tcase_add_test(tc, s21_sub_11);
  tcase_add_test(tc, s21_sub_12);
  tcase_add_test(tc, s21_sub_13);
  tcase_add_test(tc, s21_sub_14);
  tcase_add_test(tc, s21_sub_15);
  tcase_add_test(tc, s21_sub_16);
 

  suite_add_tcase(c, tc);
  return c;
}
