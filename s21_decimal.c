#include "s21_decimal.h"

#include "dec_helpers.h"

// transform functions
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int error = 0;
  if (dst != NULL) {
    if (src < 0) {
      SET_BIT(dst->bits[3], 31);
      src *= -1;
    }
    dst->bits[0] = src;
  } else {
    error = 1;
  }
  return error;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int error = 0;
  if (dst == NULL) {
    error = 1;
  } else if (isinf(src)) {
    error = 1;
  } else if (fabs(src) > 0 && fabs(src) < 1e-28) {
    *dst = (s21_decimal){0};
    error = 1;
  } else {
    char buffer[64];
    snprintf(buffer, sizeof(buffer), "%.6e", src);
    char *e_ptr = strchr(buffer, 'e');
    int scale = atoi(e_ptr + 1);
    *e_ptr = '\0';
    int exp = get_float_exp(&src);
    if (scale > 28 || exp <= -94 || exp >= 96) {
      error = 1;
      if (fabs(src) == 0) {
        error = 0;
      }
    } else {
      char digits[50];
      int pos = 0;
      int digits_after_dot = 0;
      int is_dot = 0;
      int sign = 0;
      for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '-') {
          sign = 1;
        } else if (buffer[i] == '.') {
          is_dot = 1;
        } else {
          digits[pos++] = buffer[i];
          if (is_dot) {
            digits_after_dot++;
          }
        }
      }
      digits[pos] = '\0';
      unsigned long int_value = strtoul(digits, NULL, 10);
      int final_scale = digits_after_dot - scale;
      *dst = (s21_decimal){0};
      dst->bits[0] = (unsigned int)(int_value & 0xFFFFFFFF);
      dst->bits[1] = (unsigned int)((int_value >> 32) & 0xFFFFFFFF);
      dst->bits[2] = 0;
      if (final_scale < 0) {
        while (final_scale != 0) {
          multy10(dst);
          final_scale++;
        }
      } else if (final_scale > 28) {
        while (final_scale > 29) {
          divide10(dst);
          final_scale--;
        }
        bank_round(dst);
        final_scale--;
      }
      set_scale(final_scale, dst);
      if (sign) {
        SET_BIT(dst->bits[3], 31);
      }
    }
  }
  return error;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = 0;
  int scale = get_scale(&src);
  if (dst != NULL && scale <= 28) {
    s21_decimal truncated_dec = {0};
    s21_decimal min_int_dec = {{0x80000000, 0x0, 0x0, 0x80000000}};
    s21_decimal max_int_dec = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};
    s21_truncate(src, &truncated_dec);

    if (s21_is_greater(truncated_dec, max_int_dec) == 1) {
      error = 1;

    } else if (s21_is_less(truncated_dec, min_int_dec) == 1) {
      error = 1;

    } else {
      *dst = 0;
      for (int i = 0; i < 96; i++) {
        if (IS_BIT(truncated_dec.bits[i / 32], i % 32)) {
          *dst += pow(2, i);
        }
      }
      if (IS_BIT(src.bits[3], 31)) {
        *dst = -*dst;
      }
    }
  } else {
    error = 1;
  }

  return error;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int error = ARITHMETIC_OK;
  int scale = get_scale(&src);

  if (dst == NULL) {
    error = 1;
  } else if (scale < 0 || scale > 28) {
    error = 1;
    *dst = 0;
  } else {
    double result = 0.0;
    int sign = IS_BIT(src.bits[3], 31);

    for (int i = 0; i < 96; i++) {
      if ((src.bits[i / 32] & (1 << i % 32)) != 0) {
        result += pow(2, i);
      }
    }
    if (scale > 0) {
      for (int i = scale; i > 0; i--, result /= 10.0) {
      }
    }

    if (sign) {
      result *= -1;
    }
    if (isnan(result) || isinf(result)) {
      *dst = 0;
      error = 1;
    } else {
      *dst = (float)result;
    }
  }

  return error;
}

// arithmetic functions
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = ARITHMETIC_OK;
  if (get_scale(&value_1) < 0 || get_scale(&value_1) > 28 ||
      get_scale(&value_2) < 0 || get_scale(&value_2) > 28)
    error = 1;
  else
    error = smart_normalize(&value_1, &value_2);
  int res_of_compare_body = s21_compare_body(value_1, value_2);
  if (!error) {
    result->bits[3] = value_1.bits[3];

    if (!IS_BIT(value_1.bits[3], 31) && IS_BIT(value_2.bits[3], 31) &&
        res_of_compare_body == 1) {
      error = common_sub(value_1, value_2, result);

    } else if (IS_BIT(value_1.bits[3], 31) && !IS_BIT(value_2.bits[3], 31) &&
               res_of_compare_body == 1) {
      error = common_sub(value_1, value_2, result);

    } else if (IS_BIT(value_1.bits[3], 31) && !IS_BIT(value_2.bits[3], 31) &&
               res_of_compare_body == -1) {
      error = common_sub(value_2, value_1, result);
      RESET_BIT(result->bits[3], 31);

    } else if (!IS_BIT(value_1.bits[3], 31) && IS_BIT(value_2.bits[3], 31) &&
               res_of_compare_body == -1) {
      error = common_sub(value_2, value_1, result);
      SET_BIT(result->bits[3], 31);

    } else if (IS_BIT(value_1.bits[3], 31) && !IS_BIT(value_2.bits[3], 31) &&
               !res_of_compare_body) {
      for (int i = 0; i < 4; i++) {
        result->bits[i] = 0;
      }

    } else if (!IS_BIT(value_1.bits[3], 31) && IS_BIT(value_2.bits[3], 31) &&
               !res_of_compare_body) {
      for (int i = 0; i < 4; i++) {
        result->bits[i] = 0;
      }

    } else if (IS_BIT(value_1.bits[3], 31) && IS_BIT(value_2.bits[3], 31)) {
      error = common_add(value_1, value_2, result);
      int scale = get_scale(&value_1);

      if (error) {
        error = try_leveling_result_of_sum(&value_1, &value_2, result, scale);
      }
      SET_BIT(result->bits[3], 31);
      if (error) {
        error = 2;
      }

    } else if (!IS_BIT(value_1.bits[3], 31) && !IS_BIT(value_2.bits[3], 31)) {
      error = common_add(value_1, value_2, result);
      int scale = get_scale(&value_1);
      if (error) {
        error = try_leveling_result_of_sum(&value_1, &value_2, result, scale);
      }
      if (error) {
        error = 1;
      }
    }
  }

  return error;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = ARITHMETIC_OK;
  int sign_val_1 = IS_BIT(value_1.bits[3], 31);
  int sign_val_2 = IS_BIT(value_2.bits[3], 31);
  if (get_scale(&value_1) < 0 || get_scale(&value_1) > 28 ||
      get_scale(&value_2) < 0 || get_scale(&value_2) > 28)
    error = 1;
  else
    error = smart_normalize(&value_1, &value_2);
  int res_of_compare_body = s21_compare_body(value_1, value_2);
  if (!error) {
    result->bits[3] = value_1.bits[3];

    if (!IS_BIT(value_1.bits[3], 31) && !IS_BIT(value_2.bits[3], 31) &&
        res_of_compare_body == 1) {
      error = common_sub(value_1, value_2, result);

    } else if (!IS_BIT(value_1.bits[3], 31) && !IS_BIT(value_2.bits[3], 31) &&
               res_of_compare_body == -1) {
      error = common_sub(value_2, value_1, result);
      SET_BIT(result->bits[3], 31);

    } else if (IS_BIT(value_1.bits[3], 31) && IS_BIT(value_2.bits[3], 31) &&
               res_of_compare_body == 1) {
      error = common_sub(value_1, value_2, result);

    } else if (IS_BIT(value_1.bits[3], 31) && IS_BIT(value_2.bits[3], 31) &&
               res_of_compare_body == -1) {
      error = common_sub(value_2, value_1, result);
      RESET_BIT(result->bits[3], 31);

    } else if (!IS_BIT(value_1.bits[3], 31) && !IS_BIT(value_2.bits[3], 31) &&
               !res_of_compare_body) {
      for (int i = 0; i < 4; i++) {
        result->bits[i] = 0;
      }

    } else if (IS_BIT(value_1.bits[3], 31) && IS_BIT(value_2.bits[3], 31) &&
               !res_of_compare_body) {
      for (int i = 0; i < 4; i++) {
        result->bits[i] = 0;
      }

    } else if (!IS_BIT(value_1.bits[3], 31) && IS_BIT(value_2.bits[3], 31)) {
      error = common_add(value_1, value_2, result);
      int scale = get_scale(&value_1);
      if (error) {
        error = try_leveling_result_of_sum(&value_1, &value_2, result, scale);
      }
      if (error) {
        error = 2;
      }
    } else if (IS_BIT(value_1.bits[3], 31) && !IS_BIT(value_2.bits[3], 31)) {
      error = common_add(value_1, value_2, result);
      int scale = get_scale(&value_1);
      if (error) {
        error = try_leveling_result_of_sum(&value_1, &value_2, result, scale);
      }
      SET_BIT(result->bits[3], 31);
      if (error) {
        error = 1;
      }
    }
  }
  if (error) {
    if (sign_val_1 > sign_val_2) {
      error = 1;
    } else if (sign_val_2 > sign_val_1) {
      error = 2;
    }
  }
  return error;
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;
  s21_add(value_1, value_2, result);
  return error;
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = ARITHMETIC_OK;
  int sign_v1 = (IS_BIT(value_1.bits[3], 31)) ? 1 : 0;
  int sign_v2 = (IS_BIT(value_2.bits[3], 31)) ? 1 : 0;
  RESET_BIT(value_1.bits[3], 31);
  RESET_BIT(value_2.bits[3], 31);
  if (s21_common_compare(value_2, (s21_decimal){{0, 0, 0, 0}}) == 0) {
    return ARITHMETIC_DIV_ZERO;
  }
  if (!is_valid(value_1) || !is_valid(value_2)) {
    return ARITHMETIC_BIG;
  }
  int scale_v1 = get_scale(&value_1);
  int scale_v2 = get_scale(&value_2);
  int scale_result = scale_v1 - scale_v2;
  set_scale(0, &value_1);
  set_scale(0, &value_2);
  s21_decimal remainder = {{0, 0, 0, 0}};
  s21_decimal overflow = {{0, 0, 0, 0}};
  s21_decimal answer = common_divide(value_1, value_2, &remainder);
  if (s21_compare_body_128(remainder, (s21_decimal){{0, 0, 0, 0}}) != 0) {
    answer = common_fraction_div(remainder, value_2, answer, &scale_result,
                                 &overflow, 28);
  }
  if (_multy10(answer, NULL, USING_2BIT) && scale_result < 0) {
    error = is_sign(sign_v1, sign_v2) ? ARITHMETIC_SMALL : ARITHMETIC_BIG;
  } else if (scale_result == 28 &&
             !s21_compare_body_128(answer, (s21_decimal){{0, 0, 0, 0}}) &&
             ((s21_compare_body_128(remainder, (s21_decimal){{0, 0, 0, 0}}) >
               0) ||
              (s21_compare_body_128(overflow, (s21_decimal){{0, 0, 0, 0}}) >
               0))) {
    error = ARITHMETIC_SMALL;
  }
  if (s21_compare_body_128(overflow, (s21_decimal){{0, 0, 0, 0}}) != 0) {
    s21_decimal temp = {{0, 0, 0, 0}};
    int overflow_scale = -1;
    s21_decimal overflow_result = common_fraction_div(
        overflow, value_2, temp, &overflow_scale, &remainder, 10);
    set_scale(overflow_scale, &overflow_result);
    int compare =
        s21_common_compare(overflow_result, (s21_decimal){{5, 0, 0, 0}});
    if (compare > 0 || (compare == 0 && IS_BIT(answer.bits[0], 0))) {
      if (common_add(answer, (s21_decimal){{1, 0, 0, 0}}, &answer)) {
        answer = (s21_decimal){{0, 0, 0, 0}};
        error = is_sign(sign_v1, sign_v2) ? ARITHMETIC_SMALL : ARITHMETIC_BIG;
      }
    }
  } else if (scale_result < 0) {
    while (scale_result < 0) {
      if (_multy10(answer, &answer, USING_2BIT)) {
        error = is_sign(sign_v1, sign_v2) ? ARITHMETIC_SMALL : ARITHMETIC_BIG;
      }
      ++scale_result;
    }
  }
  set_scale(scale_result, &answer);
  if (is_sign(sign_v1, sign_v2)) {
    SET_BIT(answer.bits[3], 31);
  }
  *result = answer;
  return error;
}

// compare functions
int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  result = s21_common_compare(value_1, value_2);
  return (result == -1) ? 1 : 0;
}

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  result = s21_common_compare(value_1, value_2);
  return (result == -1 || !result) ? 1 : 0;
}

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  result = s21_common_compare(value_1, value_2);
  return (result == 1) ? 1 : 0;
}

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  result = s21_common_compare(value_1, value_2);
  return (result == 1 || !result) ? 1 : 0;
}

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  result = s21_common_compare(value_1, value_2);
  return (!result) ? 1 : 0;
}

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  int result = 0;
  result = s21_common_compare(value_1, value_2);
  return (result) ? 1 : 0;
}

// other
int s21_floor(s21_decimal value, s21_decimal *result) {
  if (!result) {
    return 1;
  }
  s21_decimal prev = value;
  if (s21_truncate(value, &value)) {
    return 1;
  }
  if (!s21_is_equal(prev, value)) {
    if (IS_BIT(value.bits[3], 31)) {
      common_add(value, (s21_decimal){{1, 0, 0, 0}}, &value);
    }
  }
  *result = value;
  return 0;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  if (!is_valid(value) || !result) {
    return 1;
  }
  int scale = get_scale(&value);
  int sign = IS_BIT(value.bits[3], 31);
  RESET_BIT(value.bits[3], 31);
  set_scale(0, &value);
  s21_decimal remainder = {{0, 0, 0, 0}};

  while (scale > 0) {
    value = common_divide(value, (s21_decimal){{10, 0, 0, 0}}, &remainder);
    --scale;
  }
  if (s21_common_compare(remainder, (s21_decimal){{5, 0, 0, 0}}) >= 0) {
    common_add(value, (s21_decimal){{1, 0, 0, 0}}, &value);
  }
  if (sign) {
    SET_BIT(value.bits[3], 31);
  }
  set_scale(scale, &value);
  *result = value;
  return 0;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  if (!is_valid(value)) {
    return 1;
  }
  int scale = get_scale(&value);
  int sign = IS_BIT(value.bits[3], 31);
  RESET_BIT(value.bits[3], 31);
  set_scale(0, &value);
  s21_decimal remainder = {{0, 0, 0, 0}};
  while (scale > 0) {
    value = common_divide(value, (s21_decimal){{10, 0, 0, 0}}, &remainder);
    --scale;
  }
  if (sign) {
    SET_BIT(value.bits[3], 31);
  }
  set_scale(scale, &value);
  *result = value;
  return 0;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  if (!is_valid(value) || !result) {
    return 1;
  }
  value.bits[3] ^= (1u << 31);
  *result = value;
  return 0;
}
