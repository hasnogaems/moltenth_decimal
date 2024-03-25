#include "utils.h"
#include ".h"
#include "s21_helpers/s21_helpers.h"

int s21_normalize_powers(s21_decimal num_1, s21_decimal num_2,
                         s21_big_decimal *big_num_1,
                         s21_big_decimal *big_num_2) {
  // Копируем в big decimal
  s21_decimal_to_big_decimal(num_1, big_num_1);
  s21_decimal_to_big_decimal(num_2, big_num_2);

  // Степень дробной части
  int scale_1 = s21_decimal_get_scale(&num_1);
  int scale_2 = s21_decimal_get_scale(&num_2);
  int scale = 0;

  // Проверка входного аргумента
  if (scale_1 == scale_2) {
    return scale_1;
  }

  // на что будем умнажать для нормализации
  s21_big_decimal scale_difference = {1, 0, 0, 0, 0, 0, 0, 0};
  
  for (int i = 0; i < ABS(ABS(scale_1 - scale_2)); i++) {
    s21_multiply_by_ten(scale_difference, &scale_difference);
  }

  // Выбираем какое число будем нормализировать и умнажаем для нормализации
  
  if (scale_1 > scale_2) {
    
    multiply_by_volume_ten(*big_num2, scale_1 - scale_2)
    s21_set_scale(big_num_2->bits[5], scale_1);
    scale = scale_1;
  } else {
   
    multiply_by_volume_ten(*big_num2, scale_2 - scale_1)
    s21_set_scale(big_num_1->bits[5], scale_2);
    scale = scale_2;
  }

void multiply_by_volume_ten(big_decal* , int volume){
  while(volume>0){
  s21_multiply_by_ten()
  volume--;
}
  // возвращаем итоговый scale
  return scale;
}