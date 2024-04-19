#include "s21_decimal.h"
#include "utils.h"
// int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){
//     int error=0;
//     nullify(result);
//     s21_decimal one={{0b01,0,0,0}};
//     int sign1=extractBitSign(value_1);
//     int sign2=extractBitSign(value_2);
//     unsigned int sign=0;  
// s21_big_decimal big1, big2, resbig, buffer;
//     nullifyb(&big1);nullifyb(&big2);nullifyb(&resbig);nullifyb(&buffer);
//      int scale=normalize(value_1, value_2, &big1, &big2);
//      s21_decimal compareit; nullify(&compareit);
//      while(s21_is_less(value_2, value_1)){
//        myshiftlefts(&value_2, 1);
//        myadd(*result, one, result);


//      }
// }

int div_int(unsigned int value1, unsigned int value2, unsigned int* result){
    int top_bit1=0;
    int top_bit2=0;
    for(int i=31;i>0;i--){
if(get_bit(value1, i)){top_bit1=i;
break;}
    }
        for(int i=31;i>0;i--){
if(get_bit(value2, i)){top_bit2=i;
break;}
    }
    int shift=top_bit1-top_bit2;
    value2<<=shift;
    
    *result=1111111;


}



int s21_div2(s21_decimal divident_src, s21_decimal divisor, s21_decimal *result) {
     int error=0;
    s21_decimal divident, ostatok;
    nullify(&divident);nullify(&ostatok);nullify(result);
    printb(divident);
    int zero=1;
   // int divident=0;
    //int divisor=0;
    int i=95;
    for(;i>=0&&zero;i--)
       if(retrieveBit(divident_src, i)){ //срезаем нули
        zero=0;
        {
            setBit(&divident, 0, retrieveBit(divident_src, i));}}
i++;
            for(;(i)>=0;){

                int position=0;
                while(s21_is_less_or_equal(divident, divisor)&&i>=0){
 myshiftlefts(result, 1); 
 setBit(result, 0, 0); //ставим ноль пока не отнимается
                    i--;
                    position++;
                    grow_divident(&divident, divident_src, i, position);

                }//now divident can be actually substracted from
                if(i>=0){
s21_sub(divident, divisor, &ostatok);

 myshiftlefts(result, 1); 
 setBit(result, 0, 1);
divident=ostatok;
grow_divident(&divident, divident_src, i, position);
i--;}
// и теперь мы заведем цикл на собственно деление, но если divisor биты будут занимать больше одного инта, то просто делением я не смогу это сделать, надо ведь через вычитание?

            }
            // if(zeroDecimal(ostatok)){
            //     mymulby10(ostatok);

            // }

            
        
        
        
        printf("divident:\n");
        printb(divident);
        printf("ostatok:\n");
        printb(ostatok);
    return error;
}

int s21_div(s21_decimal divident_src, s21_decimal divisor, s21_decimal *result) {
     int to_long=OK;
     int error=0;
     int scale1=GETSCALE(divident_src);
    int scale2=GETSCALE(divisor);   
      if(result){         //if result not null
        if(!(divisor.bits[0]==0&&divisor.bits[1]==0&&divisor.bits[2]==0)){

       int sign1=extractBitSign(divident_src);
    int sign2=extractBitSign(divisor);  
     unsigned int sign=0; 
    s21_big_decimal divident={{0}}, divident_srcb={{0}}, divisorb={{0}}, ostatok={{0}}, resultb={{0}}, fraction={{0}};
    
   nullify(result);
   int scale=scale1-scale2;
// int scale=normalize(divident_src, divisor, &divident_srcb, &divisorb);
   my_decimal_to_big(divident_src, &divident_srcb);
   my_decimal_to_big(divisor, &divisorb);
    int zero=1;
   // int divident=0;
    //int divisor=0;
    int i=191;
    while(s21_is_lessb(divident_srcb, divisorb)&&scale<28){
         mymulby10(&divident_srcb);
scale++;

    }
    for(;i>=0&&zero;i--)
       if(getBigBit(divident_srcb, i)){ //срезаем нули
        zero=0;
        {
            setBigBit(&divident, 0, getBigBit(divident_srcb, i));}}// ставим 1 в делимое
i++;
            for(;(i)>=0;){
                

                int position=0;
                while(s21_is_lessb(divident, divisorb)&&i>=0){
 myshiftleft(&resultb, 1); 
 s21_set_bitb(&resultb, 0, 0); //ставим ноль пока не отнимается
                    i--;
                    ostatok=divident;
                    position++;
                    if(i>=0)grow_dividentb(&divident, divident_srcb, i);

                }//now divident can be actually substracted from
                if(i>=0){
                     while(s21_is_greater_or_equalb(divident, divisorb)){
mysubb(divident, divisorb, &ostatok);

 myshiftleft(&resultb, 1); 
 s21_set_bitb(&resultb, 0, 1);

divident=ostatok;
}
i--;
grow_dividentb(&divident, divident_srcb, i);
}


            }
             while(!zeroBigDecimal(ostatok)&&scale<=28){
               
                   //ставим ноль пока не отнимается
                 mymulby10(&ostatok);
                 mymulby10(&resultb);
                 scale++;
                 fraction=big_division(&ostatok, divisorb);
                // myaddb(ostatok, fraction, &fraction);
              
             myaddb(resultb, fraction, &resultb);
             }
            //  int shift=countLastBitbig(fraction);
            //  myshiftleft(&resultb, shift+1);
            
        
        
        
        // printf("divident:\n");
        // printbb(divident);
        // printf("ostatok:\n");
        // printbb(ostatok);
        error=mybig_to_decimal(resultb, result, scale, 0);}
      else{error=3;}
        }else{
            error=1;
        }
        
    return error;
}
    void grow_divident(s21_decimal* divident, s21_decimal divident_src,int i, int position){
 myshiftlefts(divident, 1); 
 setBit(divident, 0, retrieveBit(divident_src, i));
    }

 void grow_dividentb(s21_big_decimal* divident, s21_big_decimal divident_src,int i){
 myshiftleft(divident, 1); 
 s21_set_bitb(divident, 0, getBigBit(divident_src, i));
    }







s21_big_decimal divb(s21_big_decimal divident_srcb, s21_big_decimal divisorb, s21_big_decimal* resultb, int* scale){
    nullifyb(resultb);
      s21_big_decimal divident={{0}}, ostatok={{0}};
   int zero=1;
   // int divident=0;
    //int divisor=0;
    int i=191;
    while(s21_is_lessb(divident_srcb, divisorb)&&(*scale)<28){
         mymulby10(&divident_srcb);
(*scale)++;

    }
    for(;i>=0&&zero;i--)
       if(getBigBit(divident_srcb, i)){ //срезаем нули
        zero=0;
        {
            setBigBit(&divident, 0, getBigBit(divident_srcb, i));}}// ставим 1 в делимое
i++;
            for(;(i)>=0;){
                

                int position=0;
                while(s21_is_lessb(divident, divisorb)&&i>=0){
 myshiftleft(resultb, 1); 
 s21_set_bitb(resultb, 0, 0); //ставим ноль пока не отнимается
                    i--;
                    position++;
                 //  if(isZer) ostatok=divident;
                   if(i>=0){ grow_dividentb(&divident, divident_srcb, i);}

                }//now divident can be actually substracted from
                if(i>=0){
                     while(s21_is_greater_or_equalb(divident, divisorb)){
mysubb(divident, divisorb, &ostatok);

 myshiftleft(resultb, 1); 
 s21_set_bitb(resultb, 0, 1);

divident=ostatok;
}
i--;
grow_dividentb(&divident, divident_srcb, i);
}
            }

return ostatok;            }


void putfractiontomantissa(s21_big_decimal* mantissa, s21_big_decimal fraction){
   int shift=countLastBitbig(fraction);
    myshiftleft(mantissa, shift);
    int i=shift;
    while(i>0){
        s21_set_bitb(mantissa, i , getBigBit(fraction, i));
        i--;
    }
}

s21_big_decimal big_division(s21_big_decimal *value_1,
                             s21_big_decimal value_2) {
  s21_big_decimal res = {{0, 0, 0, 0, 0, 0}};
  s21_big_decimal shifted_bit = {{1, 0, 0, 0, 0, 0}};
  while (big_comparison(*value_1, value_2) == 1) {
    s21_big_decimal del = value_2;
    int i = 0;
    if (big_comparison(del, *value_1) == 2 ||
        big_comparison(del, *value_1) == 0) {
      while (big_comparison(del, *value_1) == 2 ||
             big_comparison(del, *value_1) == 0) {
       del = big_shift_bits(del, -1);
        ++i;
      }
      del = big_shift_bits(del, 1);
      i--;
    }
    myaddb(res, big_shift_bits(shifted_bit, -i), &res);
    if (big_comparison(*value_1, del) == 1 ||
        big_comparison(*value_1, del) == 0) {
      mysubb(*value_1, del, value_1);
    }
    myshiftright(&del, 1);
    
  }
  return res;
}

int big_comparison(s21_big_decimal value_1, s21_big_decimal value_2) {
  int bit_value_1 = 0;
  int bit_value_2 = 0;
  char res = 0;
  for (int i = 255; i > -1; i--) {
    bit_value_1 = get_bit_valueb(value_1, i);
    bit_value_2 = get_bit_valueb(value_2, i);

    if (bit_value_1 < bit_value_2) {
      res = 2;
      break;
    } else if (bit_value_1 > bit_value_2) {
      res = 1;
      break;
    } else if (i == 0 && bit_value_1 == bit_value_2) {
      res = 0;
    }
  }
  return res;
}

// void myshiftright(s21_big_decimal* d, int value) {
//   unsigned int overflow = 0;
//   unsigned int memory = 0;
//   for (int i = 5; i >= 0; i--) {
//     memory = d->bits[i];
//     d->bits[i] >>= value;
//     d->bits[i] |= overflow;
//     overflow = memory << (32 - value);
//   }
// }

s21_big_decimal big_shift_bits(s21_big_decimal dec, int shif) {
  s21_big_decimal answer = {{0, 0, 0, 0, 0, 0}};

  if (shif > 0) {
    for (int i = 0; i < 192 - shif; i++) {
      if (get_bit_valueb(dec, i + shif)) {
        s21_set_bitb(&answer, i, 1);
      }
    }
  } else {
    for (int i = 191; i > -1 + (shif * -1); i--) {
      if (get_bit_valueb(dec, i + shif)) {
       s21_set_bitb(&answer, i, 1);
      }
    }
  }

  return answer;
}
