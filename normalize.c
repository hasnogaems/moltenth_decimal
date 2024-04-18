#include "s21_decimal.h"
#include "utils.h"

int normalize(s21_decimal num_1, s21_decimal num_2, s21_big_decimal *big1,
              s21_big_decimal *big2) {
  // Копируем в big decimal
  *big1 = mantissadecimalToBig(num_1);
  *big2 = mantissadecimalToBig(num_2);

  // Степень дробной части
  int scale_1 = retrieveLevel(num_1);
  int scale_2 = retrieveLevel(num_2);
  int scale = 0;

  // Проверка входного аргумента
  if (scale_1 == scale_2) {
    return scale_1;
  }

  // на что будем умнажать для нормализации
  s21_big_decimal scale_difference = {1, 0, 0, 0, 0};

  // Выбираем какое число будем нормализировать и умножаем для нормализации
  if (scale_1 > scale_2) {
    for (int i = 0; i < abs(scale_1 - scale_2); i++) {
      mymulby10(big2);
    }

    scale = scale_1;
  } else {
    for (int i = 0; i < abs(scale_1 - scale_2); i++) {
      mymulby10(big1);
    }

    scale = scale_2;
  }

  // возвращаем итоговый scale
  return scale;
}