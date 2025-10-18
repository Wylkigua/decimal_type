#include "dec_helpers.h"

int s21_compare_body(s21_decimal first, s21_decimal second) {
  int is_compared = 0, result = 0;
  for (int i = 2; i >= 0 && !is_compared; i--) {
    for (int j = COUNT_BIT - 1; j >= 0; j--) {
      int f_bit = IS_BIT(first.bits[i], j);
      int s_bit = IS_BIT(second.bits[i], j);
      if (f_bit && !s_bit) {
        result = 1;
        is_compared = 1;
        break;

      } else if (!f_bit && s_bit) {
        result = -1;
        is_compared = 1;
        break;
      }
    }
  }
  return result;
}

int is_zero_decimal(s21_decimal value) {
  int res = 1;
  for (int i = 0; i < 3; i++) {
    if (value.bits[i] != 0) {
      res = 0;
    }
  }
  return res;
}

int handler_minus_zero(s21_decimal f, s21_decimal s) {
  int res = s21_compare_body(f, s);
  if (!res && is_zero_decimal(f) && is_zero_decimal(s) &&
      ((!IS_BIT(f.bits[3], 31) || IS_BIT(s.bits[3], 31)) ||
       ((IS_BIT(f.bits[3], 31) || (!IS_BIT(s.bits[3], 31)))))) {
    res = 200;
  }
  return res;
}

int s21_common_compare(s21_decimal first, s21_decimal second) {
  int result = 0;
  int is_overflow = smart_normalize(&first, &second);
  if (is_overflow == 1) {
    result = 1;
  } else if (is_overflow == 2) {
    result = -1;
  } else {
    if (IS_BIT(first.bits[3], 31) && !IS_BIT(second.bits[3], 31)) {
      result = -1;
      if (handler_minus_zero(first, second) == 200) {
        result = 0;
        return result;
      }
    } else if (!IS_BIT(first.bits[3], 31) && IS_BIT(second.bits[3], 31)) {
      result = 1;
    }
    if (!result) {
      result = s21_compare_body(first, second);
      if (IS_BIT(first.bits[3], 31) && IS_BIT(second.bits[3], 31)) {
        result *= -1;
      }
    }
  }
  return result;
}

int divide10(s21_decimal *decimal_value) {
  unsigned long last_block = 0;
  for (int i = 2; i >= 0; i--) {
    unsigned long value = ((unsigned long)last_block << 32) |
                          (unsigned int)decimal_value->bits[i];
    decimal_value->bits[i] = (unsigned int)(value / 10);
    last_block = value % 10;
  }
  return (int)last_block;
}

void bank_round(s21_decimal *value) {
  int last_digit = divide10(value);

  s21_decimal one = {0};
  one.bits[0] = 1;

  if (last_digit > 5) {
    common_add(*value, one, value);

  } else if (last_digit == 5) {
    if ((value->bits[0] % 2 != 0)) {
      common_add(*value, one, value);
    }
  }
}

int multy10(s21_decimal *value) {
  unsigned long long temp = 0;
  for (int i = 0; i < 3; i++) {
    temp = (unsigned long long)(unsigned int)value->bits[i] * 10 + temp;
    value->bits[i] = (unsigned int)temp;
    temp >>= 32;
  }
  return (temp) ? 1 : 0;
}

int smart_normalize(s21_decimal *value_1, s21_decimal *value_2) {
  int error = normalize(value_1, value_2);
  int scale_1 = get_scale(value_1);
  int scale_2 = get_scale(value_2);
  int diff = abs(scale_1 - scale_2);
  int smart_error = 0;
  if (error) {
    if (scale_1 > scale_2) {
      for (int i = 0; i < diff - 1 && !smart_error; i++) {
        if (scale_1 == 0) {
          smart_error = (IS_BIT(value_1->bits[3], 31)) ? 2 : 1;
          break;
        }
        divide10(value_1);
        scale_1--;
        if (scale_1 < 0 || scale_1 > 28) {
          smart_error = (IS_BIT(value_1->bits[3], 31)) ? 2 : 1;
        } else {
          set_scale(scale_1, value_1);
        }
      }
      if (!smart_error) {
        bank_round(value_1);
        scale_1--;
        set_scale(scale_1, value_1);
      }

    } else if (scale_2 > scale_1) {
      for (int i = 0; i < diff - 1 && !smart_error; i++) {
        if (scale_2 == 0) {
          smart_error = (IS_BIT(value_2->bits[3], 31)) ? 2 : 1;
          break;
        }
        divide10(value_2);
        scale_2--;
        if (scale_2 < 0 || scale_2 > 28) {
          smart_error = (IS_BIT(value_2->bits[3], 31)) ? 2 : 1;
        } else {
          set_scale(scale_2, value_2);
        }
      }
      if (!smart_error) {
        bank_round(value_2);
        scale_2--;
        set_scale(scale_2, value_2);
      }
    }
  }
  return (!error) ? 0 : ((smart_error) ? smart_error : 0);
}

int normalize(s21_decimal *value_1, s21_decimal *value_2) {
  int scale_1 = get_scale(value_1);
  int scale_2 = get_scale(value_2);

  int is_overflow_first = 0, is_overflow_second = 0;
  if (scale_1 == scale_2) {
    return 0;
  }
  if (scale_1 < scale_2) {
    while (scale_1 < scale_2 && !is_overflow_first) {
      s21_decimal prev = *value_1;
      is_overflow_first = multy10(value_1);
      if (is_overflow_first) {
        *value_1 = prev;
        break;
      }
      scale_1++;
    }
    set_scale(scale_1, value_1);
  }
  if (scale_2 < scale_1) {
    while (scale_2 < scale_1 && !is_overflow_second) {
      s21_decimal prev = *value_2;
      is_overflow_second = multy10(value_2);
      if (is_overflow_second) {
        *value_2 = prev;
        break;
      }
      scale_2++;
    }
    if (is_overflow_second) {
      is_overflow_second = 2;
    }
    set_scale(scale_2, value_2);
  }
  return (is_overflow_first) ? is_overflow_first : is_overflow_second;
}

int get_float_exp(float *value) {
  return ((*((int *)value) & ~(1u << 31)) >> 23) - 127;
}

void set_bit_in_position(s21_decimal *val, int pos, int bit) {
  if (pos / 32 < 4 && bit) {
    val->bits[pos / 32] |= (1u << (pos % 32));
  } else if (pos / 32 < 4 && !bit) {
    val->bits[pos / 32] &= ~(1u << (pos % 32));
  }
  return;
}

void set_scale(int scale, s21_decimal *dst) {
  dst->bits[3] &= ~(0xFF << 16);
  dst->bits[3] |= (scale << 16);
}

int get_scale(s21_decimal *dst) {
  int bit16to23 = (dst->bits[3] & 0xFF0000) >> 16;
  return bit16to23;
}

int try_leveling_result_of_sum(s21_decimal *value_1, s21_decimal *value_2,
                               s21_decimal *result, int scale) {
  int count_error = 0;
  s21_decimal fract_1 = {0};
  s21_decimal fract_2 = {0};
  s21_decimal res_frac = {0};
  s21_decimal integer1 = {0};
  s21_decimal integer2 = {0};
  s21_decimal res_integ = {0};
  s21_truncate(*value_1, &integer1);
  s21_sub(*value_1, integer1, &fract_1);

  s21_truncate(*value_2, &integer2);
  s21_sub(*value_2, integer2, &fract_2);

  count_error += common_add(integer1, integer2, &res_integ);
  count_error += common_add(fract_1, fract_2, &res_frac);

  bank_round(&res_frac);
  scale--;

  set_scale(scale, &res_frac);
  count_error += s21_add(res_frac, res_integ, result);
  set_scale(scale, result);
  return count_error;
}

// простые арифметические функции, которые работают только с битовым
// представление числа, без нормализации и когда первый операнд больше второго
// (для вычитания и деления)
#if 1
int common_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;
  ull temp = 0;
  uint carry = 0;
  for (int i = 0; i < 3; i++) {
    temp = (ull)(uint)value_1.bits[i] + (ull)(uint)value_2.bits[i] + carry;
    result->bits[i] = (uint)temp;
    carry = temp >> 32;
  }
  if (carry > 0) {
    error = 1;
  }
  return error;
}
#endif

int common_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;
  uint carry = 0;

  for (int i = 0; i < 3; i++) {
    ull first = (ull)(uint)value_1.bits[i];
    ull second = (ull)(uint)value_2.bits[i] + carry;
    if (first < second) {
      result->bits[i] = (uint)(0x100000000 + first - second);
      carry = 1;
    } else {
      result->bits[i] = (uint)(first - second);
      carry = 0;
    }
  }

  if (carry > 0) {
    error = 2;
  }
  return error;
}

s21_decimal common_divide(s21_decimal value_1, s21_decimal value_2,
                          s21_decimal *remainder) {
  int shift = first_msb(&value_1) - first_msb(&value_2);
  s21_decimal result = {{0, 0, 0, 0}};
  *remainder = value_1;
  left_shift(&value_2, shift);
  for (; shift >= 0; --shift) {
    if (s21_compare_body_128(value_1, value_2) >= 0) {
      *remainder = (s21_decimal){{0, 0, 0, 0}};
      SET_BIT(result.bits[shift / COUNT_BIT], shift % COUNT_BIT);
      common_sub_128(value_1, value_2, remainder);
      value_1 = *remainder;
    }
    rigth_shift(&value_2);
  }
  return result;
}

s21_decimal common_fraction_div(s21_decimal value_1, s21_decimal value_2,
                                s21_decimal ceil, int *scale_ceil,
                                s21_decimal *remainder, int scale_limit) {
  s21_decimal fraction = {{0, 0, 0, 0}};
  while (1) {
    if (*scale_ceil == scale_limit ||
        !s21_compare_body_128(value_1, (s21_decimal){{0, 0, 0, 0}}) ||
        _multy10(ceil, &ceil, USING_2BIT) ||
        _multy10(value_1, &value_1, USING_3BIT)) {
      break;
    }
    fraction = common_divide(value_1, value_2, &value_1);
    common_add(ceil, fraction, &ceil);
    ++*scale_ceil;
  }
  *remainder = value_1;
  return ceil;
}

int is_valid(s21_decimal value) {
  int error = 1;
  int scale = get_scale(&value);
  if (scale > 28 || (value.bits[3] & 0x7FE0FFFF)) {
    error = 0;
  }
  return error;
}

void left_shift(s21_decimal *value, int shift) {
  for (int j = 0; j < shift; ++j) {
    int Msb = 0;
    int carry = 0;
    for (int i = 0; i <= 3; ++i) {
      Msb = IS_BIT(value->bits[i], COUNT_BIT - 1);
      value->bits[i] <<= 1;
      if (carry) {
        SET_BIT(value->bits[i], 0);
      }
      carry = Msb ? 1 : 0;
    }
  }
}

void rigth_shift(s21_decimal *value) {
  int Lsb = 0;
  int carry = 0;
  for (int i = 3; i >= 0; --i) {
    Lsb = IS_BIT(value->bits[i], 0);
    value->bits[i] >>= 1;
    if (carry) {
      SET_BIT(value->bits[i], COUNT_BIT - 1);
    } else {
      RESET_BIT(value->bits[i], COUNT_BIT - 1);
    }
    carry = Lsb ? 1 : 0;
  }
}

int first_msb(const s21_decimal *value) {
  int msb = 0;
  for (int i = 3; !msb && i >= 0; --i) {
    for (int j = COUNT_BIT - 1; value->bits[i] && j >= 0; --j) {
      if (IS_BIT(value->bits[i], j)) {
        msb = i * COUNT_BIT + j;
        break;
      }
    }
  }
  return msb;
}

int _multy10(s21_decimal value, s21_decimal *result, int last_bit) {
  ull temp = 0;
  for (int i = 0; i <= last_bit; i++) {
    temp = (ull)(uint)value.bits[i] * 10 + temp;
    value.bits[i] = (uint)temp;
    temp >>= 32;
  }
  if (!temp && result != NULL) {
    *result = value;
  }
  return temp;
}

int common_sub_128(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result) {
  int error = 0;
  uint carry = 0;
  for (int i = 0; i <= 3; i++) {
    ull first = (ull)(uint)value_1.bits[i];
    ull second = (ull)(uint)value_2.bits[i] + carry;
    if (first < second) {
      result->bits[i] = (uint)(0x100000000 + first - second);
      carry = 1;
    } else {
      result->bits[i] = (uint)(first - second);
      carry = 0;
    }
  }
  if (carry > 0) {
    error = 2;
  }
  return error;
}

int s21_compare_body_128(s21_decimal first, s21_decimal second) {
  int is_compared = 0, result = 0;
  for (int i = 3; i >= 0 && !is_compared; i--) {
    for (int j = COUNT_BIT - 1; j >= 0; j--) {
      int f_bit = IS_BIT(first.bits[i], j);
      int s_bit = IS_BIT(second.bits[i], j);
      if (f_bit && !s_bit) {
        result = 1;
        is_compared = 1;
        break;

      } else if (!f_bit && s_bit) {
        result = -1;
        is_compared = 1;
        break;
      }
    }
  }
  return result;
}

int is_sign(int sign_1, int sign_2) {
  return (sign_1 || sign_2) && !(sign_1 && sign_2);
}