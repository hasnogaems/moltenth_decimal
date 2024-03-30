#include "s21_decimal.h"
#include "utils.h"
void s21_from_decimal_to_int128(s21_decimal src, uint128_t *dst) {

  uint128_t a=0;

  for(int i=0;i<3;i++){
    a=a+src.bits[i];
  }
  a = a * (a / pow(10, retrieveLevel(src)));
  *dst = a;
  
}

 int print_uint128(uint128_t u128){
    int rc;
    if (u128 > UINT64_MAX)
    {
        uint128_t leading  = u128 / P10_UINT64;
        uint64_t  trailing = u128 % P10_UINT64;
        rc = print_uint128(leading);
        rc += printf("%." TO_STRING(E10_UINT64) PRIu64, trailing);
    }
    else
    {
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