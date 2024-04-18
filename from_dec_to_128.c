#include "s21_decimal.h"
#include "utils.h"
void s21_from_decimal_to_int128(s21_decimal src, uint128_t* dst);
void s21_from_decimal_to_int128(s21_decimal src, uint128_t* dst) {
  uint128_t a = 0;

  for (int i = 0; i < 3; i++) {
    a = a + src.bits[i];
  }
  a = a * a;
  *dst = a;
}
uint128_t s21_decimal_to_uint128(s21_decimal dec, uint128_t* fract);
uint128_t s21_decimal_to_uint128(s21_decimal dec, uint128_t* fract) {
  // Initialize the result as a 128-bit integer
  uint128_t result = 0;

  // Assuming little endian order for simplicity
  // Incorporate the low, middle, and high bits into the result
  result |= (uint128_t)(unsigned int)dec.bits[0];          // Low 32 bits
  result |= ((uint128_t)(unsigned int)dec.bits[1]) << 32;  // Middle 32 bits
  result |= ((uint128_t)(unsigned int)dec.bits[2]) << 64;  // High 32 bits

  // Note: This implementation ignores scaling and sign since we're
  // converting to an unsigned integer (uint128_t)
  int scale = get_exp(dec);

  while (scale > 0) {
    *fract += result % 10;
    result = result / 10;

    scale--;
  }
  return result;
}

int print_uint128(uint128_t u128) {
  int rc;
  if (u128 > UINT64_MAX) {
    uint128_t leading = u128 / P10_UINT64;
    uint64_t trailing = u128 % P10_UINT64;
    rc = print_uint128(leading);
    rc += printf("%." TO_STRING(E10_UINT64) PRIu64, trailing);
  } else {
    uint64_t u64 = u128;
    rc = printf("%" PRIu64, u64);
  }
  return rc;
}

void gptprint_uint128(uint128_t n) {
  if (n >> 64) {
    // If the upper bits are non-zero, print them first.
    printf("%llu", (unsigned long long)(n >> 64));
  }
  // If the upper bits are zero, just print the lower bits.
  printf("%llu\n", (unsigned long long)n);
}