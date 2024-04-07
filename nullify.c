#include "s21_decimal.h"
void nullify(s21_decimal *d) {
  d->bits[0] = 0u;
  d->bits[1] = 0u;
  d->bits[2] = 0u;
  d->bits[3] = 0u;
}

void nullifyb(s21_big_decimal *d) {
  d->bits[0] = 0u;
  d->bits[1] = 0u;
  d->bits[2] = 0u;
  d->bits[3] = 0u;
  d->bits[4] = 0u;
  d->bits[5] = 0u;
}