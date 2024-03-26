#include <stdio.h>
#include <stdlib.h>
#include "s21_decimal.h"
#include "utils.h"
int main() {
  int a = 0b00000010001;
  int bitN = 33;
  // int result=get_bit_from_int(a, bitN);
  // printf("bit %d of %d is %d\n", bitN, a, get_bit_from_int(a, bitN));
  s21_decimal bits = {0b000001010, 0b0000000, 0b000101, 0b000000000000000000000000000000};
  // printf("decimal bit %d is %d", bitN, get_bit_value(bits, bitN));
 // set_bit_value(&bits, 32, 1); // howw toprintf in binary?????
  s21_decimal bits2 = {0b000000010, 0b0000000, 0b00000, 0b000000000000000000000000000};
  s21_decimal bits3 = {0b000000011, 0b0000110, 0b000101, 0b00000000000000000000011100000000};
   printb(bits3);
 // printb(bits);
 s21_div(bits, bits2, &bits3);
 // nullify(&bits);
 printb(bits3);
   s21_decimal twenty = {0b000010100, 0b0000000, 0b0000, 0b000000000000000000000000000000};
    s21_decimal two = {0b0000011, 0b0000000, 0b0000, 0b000000000000000000000000000000};
    s21_big_decimal bd;
    s21_big_decimal btwenty = {0b000010100, 0b111, 0b0000, 0b00000000000000000, 0b000, 0b0000};
    s21_big_decimal btwo = {0b0000011, 0b0000000, 0b0000, 0b000000000000000000000000000000, 0b0000, 0b00000};
    initializeByBigZeros(&bd);


     s21_div(twenty, two, &bits3);
     subBigDecimal(btwenty, btwo, &bd);
     printb(bits3);
     myadd(twenty, two, &bits3);
     myshiftleft(&btwenty, 31);
     printbb(btwenty);
     printb(bits3);
     s21_big_decimal ten = {0b00001010, 0b0000, 0b0000, 0b00000000000000000, 0b000, 0b0000};
     mymulby10(&ten);
     printbb(ten);


     //printbb(bd);
//s21_decimal delimoe     
  return 0;
}
 