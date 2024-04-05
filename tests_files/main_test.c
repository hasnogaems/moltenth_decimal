#include <stdio.h>
#include <stdlib.h>
#include "../s21_decimal.h"
#include "../utils.h"
int main() {

Suite *suite = s21_sub_cases();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  suite = s21_add_cases();
  suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  suite = s21_add_suite();
  suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  suite = s21_sub_suite();
  suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return 0;

}
