#ifndef DEC_HELPERS_H
#define DEC_HELPERS_H

#include "s21_decimal.h"

#define COUNT_BIT 32
#define USING_2BIT 2
#define USING_3BIT 3

typedef struct {
  int bits[8];
} s21_big_decimal;

typedef unsigned int uint;
typedef unsigned long long ull;

void set_bit_in_position(s21_decimal *val, int pos, int bit);
int get_float_exp(float *value);
void set_scale(int scale, s21_decimal *dst);
int get_scale(s21_decimal *dst);
int is_valid(s21_decimal value);
void left_shift(s21_decimal *value, int shift);
void rigth_shift(s21_decimal *value);
int first_msb(const s21_decimal *value);
int _multy10(s21_decimal value, s21_decimal *result, int last_bit);
int is_sign(int sign_1, int sign_2);

// for function s21_add
int normalize(s21_decimal *value_1, s21_decimal *value_2);
int divide10(s21_decimal *decimal_value);
int multy10(s21_decimal *value);
void bank_round(s21_decimal *value);
int smart_normalize(s21_decimal *value_1, s21_decimal *value_2);
// for function s21_compare_*
// if first == second : return 0;
// if first < second : return -1;
// if first > second : return 1;
int s21_common_compare(s21_decimal first, s21_decimal second);

// for arithmetical func and for common_compare
// if first == second : return 0;
// if first < second  : return -1;
// if first > second  : return 1;
int s21_compare_body(s21_decimal first, s21_decimal second);
int s21_compare_body_128(s21_decimal first, s21_decimal second);
int try_leveling_result_of_sum(s21_decimal *value_1, s21_decimal *value_2,
                               s21_decimal *result, int scale);
int common_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int common_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int common_sub_128(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result);
s21_decimal common_divide(s21_decimal value_1, s21_decimal value_2,
                          s21_decimal *remainder);
s21_decimal common_fraction_div(s21_decimal value_1, s21_decimal value_2,
                                s21_decimal ceil, int *scale_ceil,
                                s21_decimal *remainder, int scale_limit);
int common_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

#endif