CC=gcc 
CHECK=$(shell pkg-config --cflags --libs check) 
CFLAG=-Wall -Werror -Wextra -std=c11
CHECK=$(shell pkg-config --cflags --libs check) 
TARGET=s21_decimal.a 
TEST_TARGET=s21_decimal_test 
CCOV=-fprofile-arcs  
CCOVTEST=-fprofile-arcs -ftest-coverage 
TEST_A=test_s21_decimal.a
TEST_SRC=./tests_files/test_*.c

all: 
	gcc *.c main1/*.c -lm $(CHECK)
	./a.out

s21_decimal.a: 
	$(CC) $(CFLAG) -c *.c 
	ar rc s21_decimal.a *.o 
	ranlib s21_decimal.a 
	rm -f *.o 

build_coverage:
	$(CC) $(CFLAG) $(CCOVTEST) -c *.c 
	ar rc s21_decimal.a *.o
	ranlib s21_decimal.a

build_test_lib:
	$(CC) $(CFLAG) -c $(TEST_SRC)
	ar rc test_s21_decimal.a *.o
	ranlib test_s21_decimal.a
	rm -f *.o 

mytest: build_coverage
	$(CC) $(CCOV) $(TARGET) -o $(TEST_TARGET) 
	rm -f *.o
	./s21_decimal_test 
	
test: build_coverage build_test_lib
	$(CC) $(TEST_A) $(CHECK) $(CCOV) $(TARGET) -o $(TEST_TARGET) 
	rm -f *.o
	./s21_decimal_test 

gcov_report:
	mkdir ./report 
	gcov s21_*.gcda  
	gcovr -b 
	gcovr --html-details -o ./report/report.html 
	open ./report/report.html
 
format:
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -n *.c *.h
	clang-format -n tests_files/*.c tests_files/*.h
	
fix:
	clang-format -i *.c *.h
	clang-format -i tests_files/*.c tests_files/*.h


clean: 
	rm -rf ./report *.o *.a *.gcda *.gcno *.gcov s21_decimal_test

mytest:
	gcc  *.c tests_files/test_add.c tests_files/main_test.c tests_files/s21_add_test.c  tests_files/s21_mul_test.c tests_files/test_s21_mul.c tests_files/s21_div_test.c tests_files/test_s21_div.c -lm $(CHECK)
	./a.out

exportmine:
	gcc -c from_dec_to_128.c s21_decimal_tools.c
	ar rc export_mine.a *.o
	ranlib export_mine.a	
