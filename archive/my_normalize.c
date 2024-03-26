#include "utils.h"
#include "s21_decimal.h"
int normalize(s21_decimal num_1, s21_decimal num_2,
                         s21_big_decimal *big1,
                         s21_big_decimal *big2) {
  // Копируем в big decimal
  *big1=decimalToBig(num_1);
  *big2=decimalToBig(num_2);
  

  // Степень дробной части
  int scale_1 = retrieveLevel(num_1);
  int scale_2 = retrieveLevel(num_2);
  int scale = 0;

  // Проверка входного аргумента
  if (scale_1 == scale_2) {
    return scale_1;
  }

  // на что будем умнажать для нормализации
  s21_big_decimal scale_difference = {1, 0, 0, 0, 0, 0};
  s21_big_decimal ten = {10, 0, 0, 0, 0, 0};
  for (int i = 0; i < fabs(scale_1 - scale_2); i++) {
   mulBigDecimal(scale_difference, ten, &scale_difference);
  }

  // Выбираем какое число будем нормализировать и умнажаем для нормализации
  if (scale_1 > scale_2) {
   mulBigDecimal(*big2, scale_difference, big2);
    
    scale = scale_1;
  } else {
   mulBigDecimal(*big1, scale_difference, big1);
    
    scale = scale_2;

  }


  // возвращаем итоговый scale
  return scale;
}