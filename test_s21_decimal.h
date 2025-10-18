#ifndef TEST_S21_STRING_H
#define TEST_S21_STRING_H

#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dec_helpers.h"
#include "s21_decimal.h"

#undef TEST_ARITHMETIC_OK
#define TEST_ARITHMETIC_OK 0
#undef TEST_ARITHMETIC_BIG
#define TEST_ARITHMETIC_BIG 1
#undef TEST_ARITHMETIC_SMALL
#define TEST_ARITHMETIC_SMALL 2
#undef TEST_ARITHMETIC_ZERO
#define TEST_ARITHMETIC_ZERO 3
#undef TEST_COMPARISON_FALSE
#define TEST_COMPARISON_FALSE 0
#undef TEST_COMPARISON_TRUE
#define TEST_COMPARISON_TRUE 1

void common_test_div(s21_decimal decimal_1, s21_decimal decimal_2,
                     s21_decimal check);

typedef union float_cast_test {
  float f;
  struct {
    uint32_t mantisa : 23;
    uint32_t exponent : 8;
    uint32_t sign : 1;
  } parts;
  uint32_t bytes;
  int int32_bytes;
} float_cast_test;

#endif