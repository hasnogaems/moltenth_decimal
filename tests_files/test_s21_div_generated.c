#include "не забудьте здесь добавить свой header.h"

START_TEST(invalid_dec_s21_div_1) {
  // ссылка на результат - NULL
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x0}};
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x0}};
  int result_value = s21_div(dec_1, dec_2, NULL);

  ck_assert_int_eq(result_value, 1);
}

START_TEST(invalid_dec_s21_div_2) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x0, 0x0, 0x0, 0x380000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_3) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_4) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_5) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_6) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_7) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_1 = {{0xA, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_8) {
  // Все биты имеют максимальное значение
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_9) {
  // степень 56 (допустимое значение от 0 до 28)
  // биты 0-15 не пустые
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x380000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_10) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_11) {
  // степень 29 (допустимое значение от 0 до 28)
  s21_decimal dec_2 = {{0xA, 0x0, 0x0, 0x1D0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_12) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C0001}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_13) {
  // степень 28
  // биты 0-15 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x1C8000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_14) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x11C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_15) {
  // степень 28
  // биты 24-30 не пустые
  s21_decimal dec_2 = {{0x1, 0x0, 0x0, 0x401C0000}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(invalid_dec_s21_div_16) {
  // Все биты имеют максимальное значение
  s21_decimal dec_2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  s21_decimal dec_1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  s21_decimal result;
  int result_value = s21_div(dec_1, dec_2, &result);

  ck_assert_int_eq(result_value, 1);
}
END_TEST

START_TEST(s21_div_1) {
  // 324841
  s21_decimal dec_1 = {{0x4f4e9, 0x0, 0x0, 0x0}};
  // 76491.028412484247
  s21_decimal dec_2 = {{0x6107ca97, 0x10fc02f, 0x0, 0xc0000}};
  // 4.2467856262602174568974386935
  s21_decimal dec_check = {{0xf6d606f7, 0x928438c, 0x8938965d, 0x1c0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_2) {
  // -501000735667609109203369
  s21_decimal dec_1 = {{0xa0d709a9, 0x4de6b207, 0x6a17, 0x80000000}};
  // 77712169815.681501782605898
  s21_decimal dec_2 = {{0x2ea0004a, 0x2ac97067, 0x404831, 0xf0000}};
  // -6446876169535.4491190459511677
  s21_decimal dec_check = {{0x9974337d, 0x60afac6e, 0xd04f4f4e, 0x80100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_3) {
  // -64353413376481
  s21_decimal dec_1 = {{0x725829e1, 0x3a87, 0x0, 0x80000000}};
  // 5855804332
  s21_decimal dec_2 = {{0x5d087bac, 0x1, 0x0, 0x0}};
  // -10989.679594451483458481105547
  s21_decimal dec_check = {{0x2a232a8b, 0x8faa86e4, 0x2382732c, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_4) {
  // -844452484606138755
  s21_decimal dec_1 = {{0x86a51983, 0xbb8190f, 0x0, 0x80000000}};
  // 569361.2880575677044917476
  s21_decimal dec_2 = {{0xa34c84e4, 0x5f6a9dad, 0x4b5ab, 0x130000}};
  // -1483157535151.4885225243665587
  s21_decimal dec_check = {{0x413ae4b3, 0xdfef47d6, 0x2fec643e, 0x80100000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_5) {
  // 74944973358207
  s21_decimal dec_1 = {{0x7c83c47f, 0x4429, 0x0, 0x0}};
  // -2579837578890
  s21_decimal dec_2 = {{0xaa4d6e8a, 0x258, 0x0, 0x80000000}};
  // -29.050268114341057706012087030
  s21_decimal dec_check = {{0x8aca92f6, 0xaf182a2, 0x5dddd18e, 0x801b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_6) {
  // 2020692
  s21_decimal dec_1 = {{0x1ed554, 0x0, 0x0, 0x0}};
  // -3.52
  s21_decimal dec_2 = {{0x160, 0x0, 0x0, 0x80020000}};
  // -574060.22727272727272727272727
  s21_decimal dec_check = {{0xf0345d17, 0xbbaa41a0, 0xb97d2627, 0x80170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_7) {
  // 1878741.294636
  s21_decimal dec_1 = {{0x6db51e2c, 0x1b5, 0x0, 0x60000}};
  // 34.15657303887322457247446
  s21_decimal dec_2 = {{0x42d30ed6, 0x27499d86, 0x2d34b, 0x170000}};
  // 55003.799488251498478897274657
  s21_decimal dec_check = {{0x5f391f21, 0x1871770, 0xb1ba1399, 0x180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_8) {
  // -430389728407
  s21_decimal dec_1 = {{0x353a1497, 0x64, 0x0, 0x80000000}};
  // 46
  s21_decimal dec_2 = {{0x2e, 0x0, 0x0, 0x0}};
  // -9356298443.6304347826086956522
  s21_decimal dec_check = {{0xc5634dea, 0x80e0d510, 0x2e517c9d, 0x80130000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_9) {
  // -7846211472000700706148
  s21_decimal dec_1 = {{0x4c8ced64, 0x580ed2c6, 0x1a9, 0x80000000}};
  // -7557148520194211
  s21_decimal dec_2 = {{0xc10fa0a3, 0x1ad92f, 0x0, 0x80000000}};
  // 1038250.2674168776404387379668
  s21_decimal dec_check = {{0x6f0239d4, 0xc22e3137, 0x218c3475, 0x160000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_10) {
  // 1605359235645094699581
  s21_decimal dec_1 = {{0xee7b223d, 0x6d5b742, 0x57, 0x0}};
  // -7960842154099479557.367800
  s21_decimal dec_2 = {{0xd0fee7f8, 0x1e2fa40f, 0x695c6, 0x80060000}};
  // -201.65696098099446808381913242
  s21_decimal dec_check = {{0xa3ee789a, 0xf64bcafe, 0x4128ac3f, 0x801a0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_11) {
  // 40531358335554445559332166
  s21_decimal dec_1 = {{0x8e15fd46, 0x568b16c7, 0x2186d9, 0x0}};
  // 5.50701
  s21_decimal dec_2 = {{0x8672d, 0x0, 0x0, 0x50000}};
  // 7359957279095996840269432.2327
  s21_decimal dec_check = {{0xf149b897, 0xb2bca412, 0xedd023c3, 0x40000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_12) {
  // 8852211295934376107788952
  s21_decimal dec_1 = {{0x30a74a98, 0x55feb2c8, 0x75287, 0x0}};
  // -8.087341699968130555576653
  s21_decimal dec_2 = {{0x870014d, 0xac0a9c48, 0x6b08f, 0x80180000}};
  // -1094576144342863569297215.2190
  s21_decimal dec_check = {{0x1e54957e, 0xd2dc078a, 0x235e1f24, 0x80040000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_13) {
  // 452361241726876915460375955
  s21_decimal dec_1 = {{0xde368593, 0xd2a416b, 0x1762f38, 0x0}};
  // -62845062171864638024395.53123
  s21_decimal dec_2 = {{0x1be4d063, 0xaf012446, 0x144e6bf4, 0x80050000}};
  // -7198.0395291803269649492688275
  s21_decimal dec_check = {{0xf8693d93, 0x9640a693, 0xe894c997, 0x80190000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_14) {
  // -13151203045750.99090175450644
  s21_decimal dec_1 = {{0x794ede14, 0x90a43c4c, 0x43fd78e, 0x800e0000}};
  // 888919721
  s21_decimal dec_2 = {{0x34fbd6a9, 0x0, 0x0, 0x0}};
  // -14794.590259462801255316627676
  s21_decimal dec_check = {{0xa1aca0dc, 0x462256d, 0x2fcdcc59, 0x80180000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_15) {
  // 3819663417304562228790949
  s21_decimal dec_1 = {{0x73a806a5, 0x5e671260, 0x328d8, 0x0}};
  // -0.5
  s21_decimal dec_2 = {{0x5, 0x0, 0x0, 0x80010000}};
  // -7639326834609124457581898
  s21_decimal dec_check = {{0xe7500d4a, 0xbcce24c0, 0x651b0, 0x80000000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_16) {
  // 81805720406751432
  s21_decimal dec_1 = {{0x897078c8, 0x122a1de, 0x0, 0x0}};
  // 7691864483810818
  s21_decimal dec_2 = {{0xc237ce02, 0x1b53b5, 0x0, 0x0}};
  // 10.635356431321580470058406094
  s21_decimal dec_check = {{0xa764d0ce, 0x665b0f2b, 0x225d5c53, 0x1b0000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_div_17) {
  // -74818952268.45990591
  s21_decimal dec_1 = {{0x6ad88ebf, 0x67d50811, 0x0, 0x80080000}};
  // -95716.3
  s21_decimal dec_2 = {{0xe9aeb, 0x0, 0x0, 0x80010000}};
  // 781674.09593203985016136227581
  s21_decimal dec_check = {{0xbd915afd, 0xed014c24, 0xfc9290d4, 0x170000}};
  s21_decimal result;
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, 0);
  ck_assert_uint_eq(dec_check.bits[0], result.bits[0]);
  ck_assert_uint_eq(dec_check.bits[1], result.bits[1]);
  ck_assert_uint_eq(dec_check.bits[2], result.bits[2]);
  ck_assert_uint_eq(dec_check.bits[3], result.bits[3]);
}
END_TEST

START_TEST(fail_s21_div_1) {
  // 58639875584
  s21_decimal dec_1 = {{0xa7357e00, 0xd, 0x0, 0x0}};
  // 6103061987133
  s21_decimal dec_2 = {{0xfad77f3d, 0x58c, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_2) {
  // 735118.4661264
  s21_decimal dec_1 = {{0x94c01b10, 0x6af, 0x0, 0x70000}};
  // 584657877898097134797373392
  s21_decimal dec_2 = {{0x798bfd0, 0x11a30af2, 0x1e39e1f, 0x0}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_3) {
  // 99727234961752563
  s21_decimal dec_1 = {{0x4e53c1f3, 0x1624d64, 0x0, 0x0}};
  // 1199928410441085
  s21_decimal dec_2 = {{0x1aa9057d, 0x44354, 0x0, 0x0}};
  s21_decimal result;
  // overflow
  int check = 3; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_4) {
  // -1317771.175950
  s21_decimal dec_1 = {{0xd148680e, 0x132, 0x0, 0x80060000}};
  // -7100219816198145854797180
  s21_decimal dec_2 = {{0x360df57c, 0xafff7f5e, 0x5df87, 0x80000000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

START_TEST(fail_s21_div_5) {
  // 87.48132214675713703781
  s21_decimal dec_1 = {{0x19323f65, 0x3cb8fba8, 0x1da, 0x140000}};
  // -84160.54
  s21_decimal dec_2 = {{0x806b36, 0x0, 0x0, 0x80020000}};
  s21_decimal result;
  // overflow
  int check = 2; // Результат слишком мал или отрицательная бесконечность.
  int return_value = s21_div(dec_1, dec_2, &result);
  ck_assert_int_eq(return_value, check);
}
END_TEST

Suite *s21_div_cases(void) {
  Suite *c = suite_create("s21_div_cases");
  TCase *tc = tcase_create("s21_div_tc");

  tcase_add_test(tc, invalid_dec_s21_div_1);
  tcase_add_test(tc, invalid_dec_s21_div_2);
  tcase_add_test(tc, invalid_dec_s21_div_3);
  tcase_add_test(tc, invalid_dec_s21_div_4);
  tcase_add_test(tc, invalid_dec_s21_div_5);
  tcase_add_test(tc, invalid_dec_s21_div_6);
  tcase_add_test(tc, invalid_dec_s21_div_7);
  tcase_add_test(tc, invalid_dec_s21_div_8);
  tcase_add_test(tc, invalid_dec_s21_div_9);
  tcase_add_test(tc, invalid_dec_s21_div_10);
  tcase_add_test(tc, invalid_dec_s21_div_11);
  tcase_add_test(tc, invalid_dec_s21_div_12);
  tcase_add_test(tc, invalid_dec_s21_div_13);
  tcase_add_test(tc, invalid_dec_s21_div_14);
  tcase_add_test(tc, invalid_dec_s21_div_15);
  tcase_add_test(tc, invalid_dec_s21_div_16);
  tcase_add_test(tc, s21_div_1);
  tcase_add_test(tc, s21_div_2);
  tcase_add_test(tc, s21_div_3);
  tcase_add_test(tc, s21_div_4);
  tcase_add_test(tc, s21_div_5);
  tcase_add_test(tc, s21_div_6);
  tcase_add_test(tc, s21_div_7);
  tcase_add_test(tc, s21_div_8);
  tcase_add_test(tc, s21_div_9);
  tcase_add_test(tc, s21_div_10);
  tcase_add_test(tc, s21_div_11);
  tcase_add_test(tc, s21_div_12);
  tcase_add_test(tc, s21_div_13);
  tcase_add_test(tc, s21_div_14);
  tcase_add_test(tc, s21_div_15);
  tcase_add_test(tc, s21_div_16);
  tcase_add_test(tc, s21_div_17);
  tcase_add_test(tc, fail_s21_div_1);
  tcase_add_test(tc, fail_s21_div_2);
  tcase_add_test(tc, fail_s21_div_3);
  tcase_add_test(tc, fail_s21_div_4);
  tcase_add_test(tc, fail_s21_div_5);

  suite_add_tcase(c, tc);
  return c;
}
