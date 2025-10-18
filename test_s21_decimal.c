#include "test_s21_decimal.h"

// --------------------------- //
//                             //
// Test compare functions      //
//                             //
// --------------------------- //

/**
 * // Test s21_is_equal is beginning...
 */

START_TEST(test_s21_eq_1) {
  s21_decimal dec1 = {0, 0, 0, 0};
  s21_decimal dec2 = {0, 0, 0, 0};
  ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}

START_TEST(test_s21_eq_2) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {-1, -1, -1, 0};
  ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}

START_TEST(test_s21_eq_3) {
  s21_decimal dec1 = {0, 0, 1, 0};
  s21_decimal dec2 = {1, 0, 0, 0};
  ck_assert_int_eq(s21_is_equal(dec1, dec2), 0);
}

START_TEST(test_s21_eq_4) {
  s21_decimal dec1 = {1000, 1000, 1000, 0};
  s21_decimal dec2 = {1000, 1000, 1000, 0};
  set_scale(1, &dec2);
  ck_assert_int_eq(s21_is_equal(dec1, dec2), 0);
}

START_TEST(test_s21_eq_5) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {-1, -1, -1, 0};
  set_scale(2, &dec1);
  ck_assert_int_eq(s21_is_equal(dec1, dec2), 0);
}

START_TEST(test_s21_eq_6) {
  s21_decimal dec1 = {10000, 10000, 10000, 0};
  s21_decimal dec2 = {10000, 10000, 10000, 0};
  set_scale(1, &dec1);
  set_scale(1, &dec2);
  ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}

START_TEST(test_s21_eq_7) {
  s21_decimal dec1 = {-1, -1, 0, 0};
  s21_decimal dec2 = {-1, -1, 0, 0};
  SET_BIT(dec1.bits[3], 31);
  ck_assert_int_eq(s21_is_equal(dec1, dec2), 0);
}

START_TEST(test_s21_eq_8) {
  s21_decimal dec1 = {0, -1, -1, 0};
  s21_decimal dec2 = {-1, 0, 0, 0};
  SET_BIT(dec1.bits[3], 31);
  SET_BIT(dec2.bits[3], 31);
  ck_assert_int_eq(s21_is_equal(dec1, dec2), 0);
}

START_TEST(test_s21_eq_9) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {-1, -1, -1, 0};
  SET_BIT(dec1.bits[3], 31);
  SET_BIT(dec2.bits[3], 31);
  ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}

START_TEST(test_s21_eq_10) {
  s21_decimal dec1 = {0, -1, -1, 0};
  s21_decimal dec2 = {0, -1, -1, 0};
  set_scale(2, &dec1);
  set_scale(2, &dec2);
  SET_BIT(dec1.bits[3], 31);
  SET_BIT(dec2.bits[3], 31);
  ck_assert_int_eq(s21_is_equal(dec1, dec2), 1);
}

/**
 * // Test s21_is_equal has finished
 */

/**
 * // Test s21_is_not_equal is beginning...
 */

START_TEST(test_s21_is_not_equal_1) {
  s21_decimal dec1 = {1, 1, 1, 0};
  s21_decimal dec2 = {2, 2, 2, 0};

  int code = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_is_not_equal_2) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {-1, -1, -1, 0};
  int code = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(code, 0);
}

START_TEST(test_s21_is_not_equal_3) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {-1, -1, -1, 0};
  set_scale(2, &dec2);
  int code = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_is_not_equal_4) {
  s21_decimal dec1 = {1, 1, 1, 0};
  s21_decimal dec2 = {1, 1, 1, 0};
  SET_BIT(dec1.bits[3], 31);
  int code = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_is_not_equal_5) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {-1, -1, -1, 0};
  SET_BIT(dec1.bits[3], 31);
  SET_BIT(dec2.bits[3], 31);
  int code = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(code, 0);
}

START_TEST(test_s21_is_not_equal_6) {
  s21_decimal dec1 = {123, 123, 122, 0};
  s21_decimal dec2 = {123, 123, 123, 0};
  int code = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_is_not_equal_7) {
  s21_decimal dec1 = {1, 0, 0, 0};
  s21_decimal dec2 = {1, 0, 0, 0};
  set_scale(4, &dec1);
  SET_BIT(dec2.bits[3], 31);
  int code = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_is_not_equal_8) {
  s21_decimal dec1 = {1, 2, 3, 0};
  s21_decimal dec2 = {1, 2, 3, 0};
  set_scale(12, &dec1);
  set_scale(12, &dec2);
  SET_BIT(dec1.bits[3], 31);
  SET_BIT(dec2.bits[3], 31);
  int code = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(code, 0);
}

START_TEST(test_s21_is_not_equal_9) {
  s21_decimal dec1 = {0, 0, 0, 0};
  s21_decimal dec2 = {0, 0, 0, 0};
  SET_BIT(dec1.bits[3], 31);
  SET_BIT(dec2.bits[3], 31);
  int code = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(code, 0);
}

START_TEST(test_s21_is_not_equal_10) {
  s21_decimal dec1 = {999999, 999999, 999999, 0};
  s21_decimal dec2 = {999998, 999999, 999999, 0};
  SET_BIT(dec1.bits[3], 31);
  SET_BIT(dec2.bits[3], 31);
  int code = s21_is_not_equal(dec1, dec2);
  ck_assert_int_eq(code, 1);
}

/**
 * // Test s21_is_not_equal has finished
 */

/**
 * // Test s21_is_greater is beginning...
 */

START_TEST(test_s21_is_greather_1) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_2) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_3) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_4) {
  s21_decimal dec1 = {0x99999999, 0x99999999, 0x19999999, 0x0};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_5) {
  s21_decimal dec1 = {0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_6) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0x1E078, 0x0, 0x0, 0x80050000};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_7) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_8) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0xE0000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_9) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x801C0000};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_10) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x801C0000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_11) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_12) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  s21_decimal dec2 = {0x55555555, 0x0, 0x0, 0x80000000};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_13) {
  s21_decimal dec1 = {0x55555555, 0x0, 0x0, 0x80000000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_14) {
  s21_decimal dec1 = {0x11111112, 0x11111111, 0x11111111, 0x801B0000};
  s21_decimal dec2 = {0x1, 0x0, 0x0, 0x80000000};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_15) {
  s21_decimal dec1 = {0x1, 0x0, 0x0, 0x80000000};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x0};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_16) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x0};
  s21_decimal dec2 = {0x1, 0x0, 0x0, 0x80000000};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_17) {
  s21_decimal dec1 = {0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x70000};
  s21_decimal dec2 = {0x5554D320, 0x8235, 0x0, 0x50000};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_18) {
  s21_decimal dec1 = {0x5554D320, 0x8235, 0x0, 0x50000};
  s21_decimal dec2 = {0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_19) {
  s21_decimal dec1 = {0x96DCDDCA, 0x5C57756E, 0x1BC00CA7, 0x80070000};
  s21_decimal dec2 = {0x5554D320, 0x8235, 0x0, 0x50000};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_20) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x1C0000};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x0};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_21) {
  s21_decimal dec1 = {0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000};
  s21_decimal dec2 = {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_22) {
  s21_decimal dec1 = {0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000};
  s21_decimal dec2 = {0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_23) {
  s21_decimal dec1 = {0x11111112, 0x11111111, 0x11111111, 0x1B0000};
  s21_decimal dec2 = {0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_24) {
  s21_decimal dec1 = {0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000};
  s21_decimal dec2 = {0x99999999, 0x99999999, 0x19999999, 0x0};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_25) {
  s21_decimal dec1 = {0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000};
  s21_decimal dec2 = {0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000};
  int code = s21_is_greater(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

/**
 * // Test s21_is_greater has finished
 */

/**
 * // Test s21_is_less is beginning...
 */

START_TEST(test_s21_is_less_1) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_2) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_3) {
  s21_decimal dec1 = {0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_4) {
  s21_decimal dec1 = {0x9999999A, 0x99999999, 0x19999999, 0x80000000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_5) {
  s21_decimal dec1 = {0x7A, 0x0, 0x0, 0x20000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_6) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_7) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x80000000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_8) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x800E0000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_9) {
  s21_decimal dec1 = {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_10) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  s21_decimal dec2 = {0x11111111, 0x11111111, 0x11111111, 0x80000000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_11) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  s21_decimal dec2 = {0x99999999, 0x99999999, 0x19999999, 0x80000000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_12) {
  s21_decimal dec1 = {0x11111111, 0x11111111, 0x11111111, 0x80000000};
  s21_decimal dec2 = {0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_13) {
  s21_decimal dec1 = {0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000};
  s21_decimal dec2 = {0x11111111, 0x11111111, 0x11111111, 0x80000000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_14) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x0};
  s21_decimal dec2 = {0x11111111, 0x11111111, 0x11111111, 0x80000000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_15) {
  s21_decimal dec1 = {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000};
  s21_decimal dec2 = {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_16) {
  s21_decimal dec1 = {0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000};
  s21_decimal dec2 = {0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_17) {
  s21_decimal dec1 = {0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000};
  s21_decimal dec2 = {0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_18) {
  s21_decimal dec1 = {0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000};
  s21_decimal dec2 = {0x1, 0x0, 0x0, 0x0};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_19) {
  s21_decimal dec1 = {0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000};
  s21_decimal dec2 = {0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_20) {
  s21_decimal dec1 = {0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000};
  s21_decimal dec2 = {0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x80090000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_21) {
  s21_decimal dec1 = {0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000};
  s21_decimal dec2 = {0x55555555, 0x0, 0x0, 0x0};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_22) {
  s21_decimal dec1 = {0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000};
  s21_decimal dec2 = {0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_23) {
  s21_decimal dec1 = {0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000};
  s21_decimal dec2 = {0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_24) {
  s21_decimal dec1 = {0x4A3C829B, 0xD2D8CC92, 0x988B0249, 0x90000};
  s21_decimal dec2 = {0x1, 0x0, 0x0, 0x801C0000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_25) {
  s21_decimal dec1 = {0x11111112, 0x11111111, 0x11111111, 0x801B0000};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x1C0000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_26) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x1C0000};
  s21_decimal dec2 = {0x1E078, 0x0, 0x0, 0x50000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_27) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x1C0000};
  s21_decimal dec2 = {0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_28) {
  s21_decimal dec1 = {0x1, 0x0, 0x0, 0x801C0000};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x1C0000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_29) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x1C0000};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x0};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_30) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x1C0000};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x80000000};
  int code = s21_is_less(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

/**
 * // Test s21_is_less has finished
 */

/**
 * // Test s21_is_greater_or_equal is beginning...
 */

START_TEST(test_s21_is_greather_or_equal_1) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_or_equal_2) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_or_equal_3) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_or_equal_4) {
  s21_decimal dec1 = {0x11111111, 0x11111111, 0x11111111, 0x80000000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_or_equal_5) {
  s21_decimal dec1 = {0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_or_equal_6) {
  s21_decimal dec1 = {0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_or_equal_7) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_or_equal_8) {
  s21_decimal dec1 = {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x80000000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_or_equal_9) {
  s21_decimal dec1 = {0x8A5D3486, 0x8A87F668, 0xED66924A, 0x80070000};
  s21_decimal dec2 = {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_or_equal_10) {
  s21_decimal dec1 = {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000};
  s21_decimal dec2 = {0x8A5D3486, 0x8A87F668, 0xED66924A, 0x70000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_or_equal_11) {
  s21_decimal dec1 = {0x11111112, 0x11111111, 0x11111111, 0x801B0000};
  s21_decimal dec2 = {0x99999999, 0x99999999, 0x19999999, 0x0};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_or_equal_12) {
  s21_decimal dec1 = {0x99999999, 0x99999999, 0x19999999, 0x0};
  s21_decimal dec2 = {0x9999999A, 0x99999999, 0x19999999, 0x0};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_or_equal_13) {
  s21_decimal dec1 = {0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000};
  s21_decimal dec2 = {0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_or_equal_14) {
  s21_decimal dec1 = {0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000};
  s21_decimal dec2 = {0x8A5D3486, 0x8A87F668, 0xED66924A, 0x80070000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_or_equal_15) {
  s21_decimal dec1 = {0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0};
  s21_decimal dec2 = {0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_or_equal_16) {
  s21_decimal dec1 = {0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000};
  s21_decimal dec2 = {0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_or_equal_17) {
  s21_decimal dec1 = {0x55555555, 0x0, 0x0, 0x80000000};
  s21_decimal dec2 = {0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x130000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_or_equal_18) {
  s21_decimal dec1 = {0x55555555, 0x0, 0x0, 0x80000000};
  s21_decimal dec2 = {0x5554D320, 0x8235, 0x0, 0x80050000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_or_equal_19) {
  s21_decimal dec1 = {0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000};
  s21_decimal dec2 = {0x55555555, 0x0, 0x0, 0x80000000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_or_equal_20) {
  s21_decimal dec1 = {0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000};
  s21_decimal dec2 = {0x1E078, 0x0, 0x0, 0x80050000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_or_equal_21) {
  s21_decimal dec1 = {0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000};
  s21_decimal dec2 = {0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_or_equal_22) {
  s21_decimal dec1 = {0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x120000};
  s21_decimal dec2 = {0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x110000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_or_equal_23) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x0};
  s21_decimal dec2 = {0x11111111, 0x11111111, 0x11111111, 0x80000000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_or_equal_24) {
  s21_decimal dec1 = {0x1, 0x0, 0x0, 0x1C0000};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x800E0000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_or_equal_25) {
  s21_decimal dec1 = {0x1, 0x0, 0x0, 0x801C0000};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x800E0000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_or_equal_26) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x800E0000};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x0};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_or_equal_27) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x0};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x80000000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_or_equal_28) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x80000000};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x0};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_or_equal_29) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x800E0000};
  s21_decimal dec2 = {0x734381E9, 0x8ACE66A, 0xB16E034E, 0x80130000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_or_equal_30) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x1C0000};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x800E0000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_greather_or_equal_31) {
  s21_decimal dec1 = {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x1c0000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_greather_or_equal_32) {
  s21_decimal dec1 = {0xDB6476FA, 0x9C33420F, 0xA78F3B0F, 0x80110000};
  s21_decimal dec2 = {0xC8340001, 0x8881186E, 0x4A03CE6, 0x80120000};
  int code = s21_is_greater_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

/**
 * // Test s21_is_greater_or_equal has finished
 */

/**
 * // Test s21_is_less_or_equal is beginning...
 */

START_TEST(test_s21_is_less_or_equal_1) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_or_equal_2) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_or_equal_3) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0x11111112, 0x11111111, 0x11111111, 0x1B0000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_or_equal_4) {
  s21_decimal dec1 = {0x11111112, 0x11111111, 0x11111111, 0x1B0000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_or_equal_5) {
  s21_decimal dec1 = {0x1E078, 0x0, 0x0, 0x50000};
  s21_decimal dec2 = {0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_or_equal_6) {
  s21_decimal dec1 = {0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0};
  s21_decimal dec2 = {0x1E078, 0x0, 0x0, 0x80050000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_or_equal_7) {
  s21_decimal dec1 = {0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x0};
  s21_decimal dec2 = {0x11111111, 0x11111111, 0x11111111, 0x0};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_or_equal_8) {
  s21_decimal dec1 = {0x11111111, 0x11111111, 0x11111111, 0x0};
  s21_decimal dec2 = {0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_or_equal_9) {
  s21_decimal dec1 = {0xAAAAAAAB, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000};
  s21_decimal dec2 = {0x11111111, 0x11111111, 0x11111111, 0x0};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_or_equal_10) {
  s21_decimal dec1 = {0x9999999A, 0x99999999, 0x19999999, 0x80000000};
  s21_decimal dec2 = {0x9999999A, 0x99999999, 0x19999999, 0x80000000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_or_equal_11) {
  s21_decimal dec1 = {0x9999999A, 0x99999999, 0x19999999, 0x80000000};
  s21_decimal dec2 = {0xAAAAAAA9, 0xAAAAAAAA, 0x0, 0x80130000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_or_equal_12) {
  s21_decimal dec1 = {0x9999999A, 0x99999999, 0x19999999, 0x80000000};
  s21_decimal dec2 = {0x1, 0x0, 0x0, 0x0};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_or_equal_13) {
  s21_decimal dec1 = {0x9999999A, 0x99999999, 0x19999999, 0x80000000};
  s21_decimal dec2 = {0x1, 0x0, 0x0, 0x80000000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_or_equal_14) {
  s21_decimal dec1 = {0x1, 0x0, 0x0, 0x0};
  s21_decimal dec2 = {0x9999999A, 0x99999999, 0x19999999, 0x80000000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_or_equal_15) {
  s21_decimal dec1 = {0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000};
  s21_decimal dec2 = {0x11111111, 0x11111111, 0x11111111, 0x0};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_or_equal_16) {
  s21_decimal dec1 = {0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000};
  s21_decimal dec2 = {0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_or_equal_17) {
  s21_decimal dec1 = {0xAAAAAAAB, 0xAAAAAAAA, 0x0, 0x80130000};
  s21_decimal dec2 = {0x1E078, 0x0, 0x0, 0x80050000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_or_equal_18) {
  s21_decimal dec1 = {0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000};
  s21_decimal dec2 = {0x55555555, 0x0, 0x0, 0x80000000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_or_equal_19) {
  s21_decimal dec1 = {0x55555555, 0x0, 0x0, 0x80000000};
  s21_decimal dec2 = {0x1, 0x0, 0x0, 0x1C0000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_or_equal_20) {
  s21_decimal dec1 = {0x1, 0x0, 0x0, 0x1C0000};
  s21_decimal dec2 = {0x55555555, 0x0, 0x0, 0x80000000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_or_equal_21) {
  s21_decimal dec1 = {0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000};
  s21_decimal dec2 = {0x5554D320, 0x8235, 0x0, 0x80050000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_or_equal_22) {
  s21_decimal dec1 = {0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000};
  s21_decimal dec2 = {0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_or_equal_23) {
  s21_decimal dec1 = {0xC8340001, 0x8881186E, 0x4A03CE6, 0x120000};
  s21_decimal dec2 = {0xC833FFFF, 0x8881186E, 0x4A03CE6, 0x80120000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_or_equal_24) {
  s21_decimal dec1 = {0x1, 0x0, 0x0, 0x801C0000};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x801C0000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_or_equal_25) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x801C0000};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x0};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_or_equal_26) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x80000000};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x801C0000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_or_equal_27) {
  s21_decimal dec1 = {0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x801C0000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_or_equal_28) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x0};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x0};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_is_less_or_equal_29) {
  s21_decimal dec1 = {0x11111111, 0x11111111, 0x11111111, 0x0};
  s21_decimal dec2 = {0xCEDBC273, 0x56AF422B, 0x981B561D, 0x1C0000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_FALSE);
}

START_TEST(test_s21_is_less_or_equal_30) {
  s21_decimal dec1 = {0xE333C1D3, 0xC173E715, 0x631797E3, 0x800F0000};
  s21_decimal dec2 = {0xCEDBC273, 0x56AF422B, 0x981B561D, 0x801C0000};
  int code = s21_is_less_or_equal(dec1, dec2);
  ck_assert_int_eq(code, TEST_COMPARISON_TRUE);
}

/**
 * // Test s21_is_less_or_equal has finished
 */

// ------------------------------------ //
//                                      //
// Test main operations of functions    //
//                                      //
// ------------------------------------ //

/**
 * // Test s21_add is beginning...
 */

START_TEST(test_transform_and_add_two_positive) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {4, 0, 0, 0};
  s21_decimal res = {0};
  set_scale(1, &dec2);
  s21_decimal expected = {-1, -1, -1, 0};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
  ck_assert_int_eq(code, 0);
}
END_TEST

START_TEST(test_s21_add_1) {
  s21_decimal dec1 = {1, 2, 3, 0};
  s21_decimal dec2 = {2, 3, 4, 0};
  s21_decimal res = {0};
  s21_decimal expected = {3, 5, 7, 0};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_2) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {1, 0, 0, 0};
  s21_decimal res = {0};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_BIG);
}

START_TEST(test_s21_add_3) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {1, 0, 0, 0};
  s21_decimal res = {0};
  SET_BIT(dec1.bits[3], 31);
  SET_BIT(dec2.bits[3], 31);
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_SMALL);
}

START_TEST(test_s21_add_4) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {-1, -1, -1, 0};
  s21_decimal res = {0};
  set_scale(29, &dec1);
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}

START_TEST(test_s21_add_5) {
  s21_decimal dec1 = {1200, 0, 0, 0};
  s21_decimal dec2 = {1200, 0, 0, 0};
  s21_decimal res = {0};
  s21_decimal expected = {2400, 0, 0, 0};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_6) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {6, 0, 0, 0};
  s21_decimal res = {0};
  set_scale(1, &dec2);
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_BIG);
}

START_TEST(test_s21_add_7) {
  s21_decimal dec1 = {1, 0, 0, 0};
  s21_decimal dec2 = {-1, 0, 0, 0};
  s21_decimal res = {0};
  SET_BIT(dec2.bits[3], 31);
  s21_decimal expected = {-2, 0, 0, 0};
  SET_BIT(expected.bits[3], 31);
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_8) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {-1, -1, -1, 0};
  s21_decimal res = {0};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_BIG);
}

START_TEST(test_s21_add_9) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {-1, -1, -1, 0};
  s21_decimal res = {0};
  SET_BIT(dec1.bits[3], 31);
  SET_BIT(dec2.bits[3], 31);
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_SMALL);
}

START_TEST(test_s21_add_10) {
  s21_decimal dec1 = {0, 1000, 0, 0};
  s21_decimal dec2 = {1, 0, 0, 0};
  s21_decimal res = {0};
  set_scale(2, &dec1);
  s21_decimal expected = {100, 1000, 0, 0};
  set_scale(2, &expected);
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_11) {
  s21_decimal dec1 = {-1, 0, 0, 0};
  s21_decimal dec2 = {0, 1, 0, 0};
  s21_decimal res = {0};
  SET_BIT(dec1.bits[3], 31);
  s21_decimal expected = {1, 0, 0, 0};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_12) {
  s21_decimal dec1 = {0, 0, 0, 0};
  s21_decimal dec2 = {0, 0, 0, 0};
  s21_decimal res = {0};
  SET_BIT(dec1.bits[3], 31);
  s21_decimal expected = {0, 0, 0, 0};
  SET_BIT(res.bits[3], 31);
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_13) {
  s21_decimal dec1 = {0, 1, 1, 0};
  s21_decimal dec2 = {0, -1, 0, 0};
  s21_decimal res = {0};
  SET_BIT(dec1.bits[3], 31);
  SET_BIT(dec2.bits[3], 31);
  s21_decimal expected = {0, 0, 2, 0};
  SET_BIT(expected.bits[3], 31);
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_14) {
  s21_decimal dec1 = {0, 1, 1, 0};
  s21_decimal dec2 = {0, -1, 0, 0};
  s21_decimal res = {0};
  SET_BIT(dec1.bits[3], 31);
  SET_BIT(dec2.bits[3], 31);
  s21_decimal expected = {0, 0, 2, 0};
  SET_BIT(expected.bits[3], 31);
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_15) {
  s21_decimal dec1 = {1000, 1, 0, 0};
  s21_decimal dec2 = {100000, 1, 0, 0};
  s21_decimal res = {0};
  set_scale(2, &dec1);
  set_scale(5, &dec2);
  s21_decimal expected = {1100000, 1001, 0, 0};
  set_scale(5, &expected);
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_16) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000};
  s21_decimal res = {0};
  s21_decimal expected = {0xD94D529D, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_17) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000};
  s21_decimal res = {0};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_BIG);
}

START_TEST(test_s21_add_18) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  s21_decimal dec2 = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal res = {0};
  s21_decimal expected = {0x1, 0x0, 0x0, 0x80000000};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_19) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  s21_decimal res = {0};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_SMALL);
}

START_TEST(test_s21_add_20) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  s21_decimal dec2 = {0x99999999, 0x99999999, 0x19999999, 0x0};
  s21_decimal res = {0};
  s21_decimal expected = {0x66666666, 0x66666666, 0xE6666666, 0x80000000};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_21) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  s21_decimal dec2 = {0x55555555, 0x0, 0x55555555, 0x0};
  s21_decimal res = {0};
  s21_decimal expected = {0xAAAAAAAA, 0xFFFFFFFF, 0xAAAAAAAA, 0x80000000};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_22) {
  s21_decimal dec1 = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0x55555555, 0x55555555, 0x55555555, 0x80000000};
  s21_decimal res = {0};
  s21_decimal expected = {0xAAAAAAA9, 0xAAAAAAAA, 0xAAAAAAAA, 0x0};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_23) {
  s21_decimal dec1 = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0x1B755555, 0x2CE411B0, 0x55555560, 0x80150000};
  s21_decimal res = {0};
  s21_decimal expected = {0xFE6D0652, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_24) {
  s21_decimal dec1 = {0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x801C0000};
  s21_decimal res = {0};
  s21_decimal expected = {0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_25) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000};
  s21_decimal dec2 = {0x1B755555, 0x2CE411B0, 0x55555560, 0x150000};
  s21_decimal res = {0};
  s21_decimal expected = {0xFFACDCF, 0xAC0DBD7B, 0x5555570D, 0x150000};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_26) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000};
  s21_decimal dec2 = {0x0, 0x55555555, 0x0, 0x0};
  s21_decimal res = {0};
  s21_decimal expected = {0x8DA22E2E, 0x8EA6B3ED, 0xC6AEA154, 0xA0000};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_27) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000};
  s21_decimal dec2 = {0x1B755555, 0x2CE411B0, 0x55555560, 0x150000};
  s21_decimal res = {0};
  s21_decimal expected = {0x26EFDCDB, 0xADBA65E5, 0x555553B2, 0x150000};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_28) {
  s21_decimal dec1 = {0xF555887, 0x553F1641, 0xB5597F0B, 0x60000};
  s21_decimal dec2 = {0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000};
  s21_decimal res = {0};
  s21_decimal expected = {0xF5752326, 0x554164BC, 0xB5597F0B, 0x60000};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_29) {
  s21_decimal dec1 = {0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x80120000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal res = {0};
  s21_decimal expected = {0x6D692071, 0xFFFFFFF4, 0xFFFFFFFF, 0x0};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_30) {
  s21_decimal dec1 = {0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x80120000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  s21_decimal res = {0};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_SMALL);
}

START_TEST(test_s21_add_31) {
  s21_decimal dec1 = {0x7F7B8E5F, 0x2B4271A6, 0xA09A2FB4, 0x80120000};
  s21_decimal dec2 = {0x9999999A, 0x99999999, 0x19999999, 0x80000000};
  s21_decimal res = {0};
  s21_decimal expected = {0x2C307928, 0x999999A5, 0x19999999, 0x80000000};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_32) {
  s21_decimal dec1 = {0x122233EE, 0x5675EBE6, 0xD1C83484, 0x140000};
  s21_decimal dec2 = {0xF555887, 0x553F1641, 0xB5597F0B, 0x60000};
  s21_decimal res = {0};
  s21_decimal expected = {0xF5752326, 0x554164BC, 0xB5597F0B, 0x60000};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_33) {
  s21_decimal dec1 = {0x55555555, 0x0, 0x55555555, 0x0};
  s21_decimal dec2 = {0x0, 0x55555555, 0x0, 0x80000000};
  s21_decimal res = {0};
  s21_decimal expected = {0x55555555, 0xAAAAAAAB, 0x55555554, 0x0};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_34) {
  s21_decimal dec1 = {0x55555555, 0x0, 0x55555555, 0x0};
  s21_decimal dec2 = {0x811800, 0x811800, 0x0, 0x80100000};
  s21_decimal res = {0};
  s21_decimal expected = {0x55555551, 0x0, 0x55555555, 0x0};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_35) {
  s21_decimal dec1 = {0x55555555, 0x0, 0x55555555, 0x0};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x80000000};
  s21_decimal res = {0};
  s21_decimal expected = {0x55555555, 0x0, 0x55555555, 0x0};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_36) {
  s21_decimal dec1 = {0x55555555, 0x0, 0x55555555, 0x80000000};
  s21_decimal dec2 = {0x9999999A, 0x99999999, 0x19999999, 0x80000000};
  s21_decimal res = {0};
  s21_decimal expected = {0xEEEEEEEF, 0x99999999, 0x6EEEEEEE, 0x80000000};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_37) {
  s21_decimal dec1 = {0x55555555, 0x0, 0x55555555, 0x80000000};
  s21_decimal dec2 = {0x55555555, 0x55555555, 0x55555555, 0x80000000};
  s21_decimal res = {0};
  s21_decimal expected = {0xAAAAAAAA, 0x55555555, 0xAAAAAAAA, 0x80000000};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_38) {
  s21_decimal dec1 = {0x55555555, 0x55555555, 0x0, 0x0};
  s21_decimal dec2 = {0x9999999A, 0x99999999, 0x19999999, 0x80000000};
  s21_decimal res = {0};
  s21_decimal expected = {0x44444445, 0x44444444, 0x19999999, 0x80000000};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_39) {
  s21_decimal dec1 = {0x55555555, 0x0, 0x55555555, 0x150000};
  s21_decimal dec2 = {0x122233EE, 0x5675EBE6, 0xD1C83484, 0x80140000};
  s21_decimal res = {0};
  s21_decimal expected = {0x999AB66, 0xD675EBE6, 0xC93FABFB, 0x80140000};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_40) {
  s21_decimal dec1 = {{0x55555555, 0x0, 0x55555555, 0x80150000}};
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  s21_decimal res = {0};
  s21_decimal expected = {0x9B2C9345, 0x99999999, 0x19999999, 0x80000000};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_add_41) {
  s21_decimal dec1 = {0x55555555, 0x55555555, 0x55555555, 0x0};
  s21_decimal dec2 = {0x9999999A, 0x99999999, 0x19999999, 0x80000000};
  s21_decimal res = {0};
  s21_decimal expected = {0xBBBBBBBB, 0xBBBBBBBB, 0x3BBBBBBB, 0x0};
  int code = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

/**
 * // Test s21_add has finished
 */

/**
 * // Test s21_sub is beginning...
 */

START_TEST(test_s21_sub_1) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {-1, -1, -1, 0};
  s21_decimal res = {0};
  s21_decimal expected = {0, 0, 0, 0};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
}

START_TEST(test_s21_sub_2) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {6, 0, 0, 0};
  s21_decimal res = {0};
  set_scale(1, &dec2);
  s21_decimal expected = {-2, -1, -1, 0};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
}

START_TEST(test_s21_sub_3) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {15, 0, 0, 0};
  s21_decimal res = {0};
  SET_BIT(dec2.bits[3], 31);
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_BIG);
}

START_TEST(test_s21_sub_4) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {-1, 0, 0, 0};
  s21_decimal res = {0};
  SET_BIT(dec2.bits[3], 31);
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_BIG);
}

START_TEST(test_s21_sub_5) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {-1, 0, 0, 0};
  s21_decimal res = {0};
  SET_BIT(dec1.bits[3], 31);
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_SMALL);
}

START_TEST(test_s21_sub_6) {
  s21_decimal dec1 = {10000, 0, 0, 0};
  s21_decimal dec2 = {100, 0, 0, 0};
  s21_decimal res = {0};
  s21_decimal expected = {9900, 0, 0, 0};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_7) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {16, 0, 0, 0};
  s21_decimal res = {0};
  set_scale(1, &dec2);
  SET_BIT(dec2.bits[3], 31);
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_sub_8) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {4, 0, 0, 0};
  s21_decimal res = {0};
  set_scale(1, &dec2);
  s21_decimal expected = {-1, -1, -1, 0};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_9) {
  s21_decimal dec1 = {1000, 0, 0, 0};
  s21_decimal dec2 = {1000, 0, 0, 0};
  s21_decimal res = {0};
  s21_decimal expected = {0, 0, 0, 0};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_10) {
  s21_decimal dec1 = {400, 0, 0, 0};
  s21_decimal dec2 = {800, 0, 0, 0};
  s21_decimal res = {0};
  s21_decimal expected = {400, 0, 0, 0};
  SET_BIT(expected.bits[3], 31);
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_11) {
  s21_decimal dec1 = {55, 0, 0, 0};
  s21_decimal dec2 = {12, 0, 0, 0};
  s21_decimal res = {0};
  set_scale(1, &dec1);
  set_scale(1, &dec2);
  s21_decimal expected = {43, 0, 0, 0};
  set_scale(1, &expected);
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_12) {
  s21_decimal dec1 = {100, 0, 0, 0};
  s21_decimal dec2 = {5, 0, 0, 0};
  s21_decimal res = {0};
  set_scale(2, &dec1);
  set_scale(1, &dec2);
  s21_decimal expected = {5, 0, 0, 0};
  set_scale(1, &expected);
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_13) {
  s21_decimal dec1 = {0, 0, 1, 0};
  s21_decimal dec2 = {1, 0, 0, 0};
  s21_decimal res = {0};
  s21_decimal expected = {-1, -1, 0, 0};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_14) {
  s21_decimal dec1 = {100, 0, 0, 0};
  s21_decimal dec2 = {50, 0, 0, 0};
  s21_decimal res = {0};
  set_scale(29, &dec1);
  set_scale(29, &dec2);
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_ne(code, TEST_ARITHMETIC_OK);
}

START_TEST(test_s21_sub_15) {
  s21_decimal dec1 = {1000, 0, 0, 0};
  s21_decimal dec2 = {1, 0, 0, 0};
  s21_decimal res = {0};
  set_scale(2, &dec2);
  s21_decimal expected = {99999, 0, 0, 0};
  set_scale(2, &expected);
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_16) {
  s21_decimal dec1 = {0, 1, 0, 0};
  s21_decimal dec2 = {1, 0, 0, 0};
  s21_decimal res = {0};
  s21_decimal expected = {-1, 0, 0, 0};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_17) {
  s21_decimal dec1 = {-1, -1, 1, 0};
  s21_decimal dec2 = {1, 0, 0, 0};
  s21_decimal res = {0};
  s21_decimal expected = {-2, -1, 1, 0};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_18) {
  s21_decimal dec1 = {-2, 2, 1, 0};
  s21_decimal dec2 = {1, 1, 0, 0};
  s21_decimal res = {0};
  set_scale(3, &dec1);
  set_scale(3, &dec2);
  s21_decimal expected = {-3, 1, 1, 0};
  set_scale(3, &expected);
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_19) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0};
  s21_decimal dec2 = {0x4C23E884, 0x648C702C, 0xC2A02CFF, 0};
  s21_decimal res = {0};
  SET_BIT(dec1.bits[3], 31);
  SET_BIT(dec2.bits[3], 31);

  s21_decimal expected = {0xB3DC177B, 0x9B738FD3, 0x3D5FD300, 0};
  SET_BIT(expected.bits[3], 31);
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_20) {
  s21_decimal dec1 = {1, 2, 3, 0};
  s21_decimal dec2 = {1, 2, 3, 0};
  s21_decimal res = {0};
  set_scale(3, &dec1);
  set_scale(3, &dec2);
  SET_BIT(dec2.bits[3], 31);
  s21_decimal expected = {2, 4, 6, 0};
  set_scale(3, &expected);
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_21) {
  s21_decimal dec1 = {0x9999999B, 0x99999999, 0x19999999, 0x80000000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000};
  s21_decimal res = {0};
  s21_decimal expected = {0x999999A3, 0x99999999, 0x19999999, 0x80000000};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_22) {
  s21_decimal dec1 = {123456, 0, 0, 0};
  s21_decimal dec2 = {7890, 0, 0, 0};
  s21_decimal res = {0};
  set_scale(5, &dec1);
  set_scale(4, &dec2);
  s21_decimal expected = {44556, 0, 0, 0};
  set_scale(5, &expected);
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_23) {
  s21_decimal dec1 = {0x000F4240, 0x00000001, 0, 0};
  s21_decimal dec2 = {0x000186A0, 0, 0, 0};
  s21_decimal res = {0};
  set_scale(3, &dec1);
  set_scale(2, &dec2);
  SET_BIT(dec2.bits[3], 31);
  s21_decimal expected = {2000000, 1, 0, 0};
  set_scale(3, &expected);
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_24) {
  s21_decimal dec1 = {0x000F4240, 0x00000001, 0, 0};
  s21_decimal dec2 = {0x000186A0, 0, 0, 0};
  s21_decimal res = {0};
  set_scale(3, &dec1);
  set_scale(2, &dec2);
  SET_BIT(dec1.bits[3], 31);
  SET_BIT(dec2.bits[3], 31);

  s21_decimal expected = {0, 1, 0, 0};
  set_scale(3, &expected);
  SET_BIT(expected.bits[3], 31);
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_25) {
  s21_decimal dec1 = {0x000186A0, 0, 0, 0};
  s21_decimal dec2 = {0x000F4240, 0x00000001, 0, 0};
  s21_decimal res = {0};
  set_scale(2, &dec1);
  set_scale(3, &dec2);
  s21_decimal expected = {0, 1, 0, 0};
  set_scale(3, &expected);
  SET_BIT(expected.bits[3], 31);
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_26) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {-1, -1, -1, 0};
  s21_decimal res = {0};
  set_scale(12, &dec2);
  SET_BIT(dec1.bits[3], 31);
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_SMALL);
}

START_TEST(test_s21_sub_27) {
  s21_decimal dec1 = {-1, -1, -1, 0};
  s21_decimal dec2 = {-1, -1, -1, 0};
  s21_decimal res = {0};
  set_scale(12, &dec2);
  SET_BIT(dec2.bits[3], 31);
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_BIG);
}

START_TEST(test_s21_sub_28) {
  s21_decimal dec1 = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0x55555555, 0x0, 0x55555555, 0x150000};
  s21_decimal res = {0};
  s21_decimal expected = {0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_29) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0x55555555, 0x0, 0x55555555, 0x150000};
  s21_decimal res = {0};
  s21_decimal expected = {0xFE6D0654, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_30) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x0};
  s21_decimal res = {0};
  s21_decimal expected = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_31) {
  s21_decimal dec1 = {0x55555555, 0x55555555, 0x55555555, 0x150000};
  s21_decimal dec2 = {0x811800, 0x811800, 0x0, 0x100000};
  s21_decimal res = {0};
  s21_decimal expected = {0x5A165555, 0x5A165490, 0x55555490, 0x150000};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_32) {
  s21_decimal dec1 = {0x55555555, 0x55555555, 0x55555555, 0x150000};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x801C0000};
  s21_decimal res = {0};
  s21_decimal expected = {0x55555555, 0x55555555, 0x55555555, 0x150000};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_33) {
  s21_decimal dec1 = {0x55555555, 0x55555555, 0x55555555, 0x150000};
  s21_decimal dec2 = {0xB2C6F4A5, 0xA11CA39F, 0xD0D7B8CF, 0x801A0000};
  s21_decimal res = {0};
  s21_decimal expected = {0xD90F56FD, 0x5170F176, 0x5555DE33, 0x150000};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_34) {
  s21_decimal dec1 = {0x55555555, 0x55555555, 0x55555555, 0x150000};
  s21_decimal dec2 = {0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0x800B0000};
  s21_decimal res = {0};
  s21_decimal expected = {0x479E300A, 0xC901970B, 0x4E5898A9, 0xC0000};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_35) {
  s21_decimal dec1 = {0x55555555, 0x55555555, 0x55555555, 0x80150000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  s21_decimal res = {0};
  s21_decimal expected = {0xFE6D0653, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_36) {
  s21_decimal dec1 = {0x55555555, 0x55555555, 0x55555555, 0x80150000};
  s21_decimal dec2 = {0x55555555, 0x0, 0x55555555, 0x150000};
  s21_decimal res = {0};
  s21_decimal expected = {0xAAAAAAAA, 0x55555555, 0xAAAAAAAA, 0x80150000};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_37) {
  s21_decimal dec1 = {0x55555555, 0x55555555, 0x55555555, 0x80150000};
  s21_decimal dec2 = {0x0, 0x0, 0x0, 0x0};
  s21_decimal res = {0};
  s21_decimal expected = {0x55555555, 0x55555555, 0x55555555, 0x80150000};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_38) {
  s21_decimal dec1 = {0x55555555, 0x0, 0x55555555, 0x150000};
  s21_decimal dec2 = {0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000};
  s21_decimal res = {0};
  s21_decimal expected = {0x12955555, 0x6B935B8C, 0x555555C1, 0x150000};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_39) {
  s21_decimal dec1 = {0x55555555, 0x0, 0x55555555, 0x150000};
  s21_decimal dec2 = {0x55555555, 0x0, 0x55555555, 0x150000};
  s21_decimal res = {0};
  s21_decimal expected = {0x0, 0x0, 0x0, 0x150000};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_40) {
  s21_decimal dec1 = {0x55555555, 0x0, 0x55555555, 0x150000};
  s21_decimal dec2 = {0x4C23E884, 0x648C702C, 0xC2A02CFF, 0x0};
  s21_decimal res = {0};
  s21_decimal expected = {0x4A90EED9, 0x648C702C, 0xC2A02CFF, 0x80000000};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_41) {
  s21_decimal dec1 = {0x55555555, 0x0, 0x55555555, 0x80150000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal res = {0};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_SMALL);
}

START_TEST(test_s21_sub_42) {
  s21_decimal dec1 = {0x192F9AB, 0x0, 0x0, 0x80000000};
  s21_decimal dec2 = {0x55555555, 0x0, 0x55555555, 0x0};
  s21_decimal res = {0};
  s21_decimal expected = {0x56E84F00, 0x0, 0x55555555, 0x80000000};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_43) {
  s21_decimal dec1 = {0xA, 0x0, 0x0, 0x801C0000};
  s21_decimal dec2 = {0x55555555, 0x55555555, 0x55555555, 0x80150000};
  s21_decimal res = {0};
  s21_decimal expected = {0x55555555, 0x55555555, 0x55555555, 0x150000};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_sub_44) {
  s21_decimal dec1 = {0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0xB0000};
  s21_decimal dec2 = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  s21_decimal res = {0};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_BIG);
}

START_TEST(test_s21_sub_45) {
  s21_decimal dec1 = {0x11B612E, 0xA2A675B4, 0x7D5A8DD, 0xB0000};
  s21_decimal dec2 = {0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000};
  s21_decimal res = {0};
  s21_decimal expected = {0xA0BF43CC, 0x5A809893, 0x4E5898A8, 0xC0000};
  int code = s21_sub(dec1, dec2, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

/**
 * // Test s21_sub has finished
 */

/**
 * // Test s21_div is beginning...
 */
START_TEST(test_div_arithmetic_error_1) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000};
  s21_decimal res = {};
  int code = s21_div(dec1, dec2, &res);
  ck_assert_int_ne(code, ARITHMETIC_OK);
}

START_TEST(test_div_arithmetic_error_2) {
  // Показатель степени должен быть от 0 до 28!
  s21_decimal dec1 = {0, 0, 0, 1000000000};
  s21_decimal dec2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000};
  s21_decimal result = {};
  int code = s21_div(dec1, dec2, &result);
  ck_assert_int_ne(code, ARITHMETIC_OK);
}

START_TEST(test_div_arithmetic_error_3) {
  // 1.9999999999999999999999999000
  s21_decimal decimal1 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 79228162495817593524129366015
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  s21_decimal result = {};
  int code = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(code, ARITHMETIC_SMALL);
}

START_TEST(test_div_arithmetic_error_4) {
  // -79228162495817593524129366015
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // -0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x80040000}};
  // overflow
  s21_decimal result = {};
  int code = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(code, ARITHMETIC_BIG);
}

START_TEST(test_div_arithmetic_error_5) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0
  s21_decimal decimal2 = {{0x0, 0x0, 0x0, 0x80000000}};
  // division by zero

  s21_decimal result = {};
  int code = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(code, ARITHMETIC_DIV_ZERO);
}

START_TEST(test_div_arithmetic_error_6) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // overflow
  s21_decimal result = {};
  int code = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(code, ARITHMETIC_BIG);
}

START_TEST(test_div_arithmetic_error_7) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // overflow
  s21_decimal result = {};
  int code = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(code, ARITHMETIC_SMALL);
}

START_TEST(test_div_arithmetic_error_8) {
  // 0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x1C0000}};
  // -79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // -0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};
  s21_decimal result = {};
  int code = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(code, ARITHMETIC_SMALL);
  ck_assert_int_eq(s21_common_compare(result, decimal_check), 0);
}

START_TEST(test_div_arithmetic_error_9) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -0.0000000000000000000000000001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // overflow
  s21_decimal result;
  int code = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(code, ARITHMETIC_SMALL);
}

START_TEST(test_div_arithmetic_error_10) {
  // 1
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x0}};
  // 39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x0}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result = {};
  int code = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(code, ARITHMETIC_SMALL);
  ck_assert_int_eq(s21_common_compare(result, decimal_check), 0);
}

START_TEST(test_div_arithmetic_error_11) {
  // 79228162514264337593543950320
  s21_decimal decimal1 = {{0xFFFFFFF0, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.9999999999999999999999999998
  s21_decimal decimal2 = {{0xFFFFFFE, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // overflow
  s21_decimal result = {};
  int code = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(code, ARITHMETIC_BIG);
}

START_TEST(test_div_arithmetic_error_12) {
  // -79228162514264337593543950320
  s21_decimal decimal1 = {{0xFFFFFFF0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 0.9999999999999999999999999998
  s21_decimal decimal2 = {{0xFFFFFFE, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // overflow
  s21_decimal result = {};
  int code = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(code, ARITHMETIC_SMALL);
}

START_TEST(test_div_arithmetic_error_13) {
  // -0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // -3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x80130000}};
  // 0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};
  s21_decimal result = {};
  int code = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(code, ARITHMETIC_SMALL);
  ck_assert_int_eq(s21_common_compare(result, decimal_check), 0);
}

START_TEST(test_div_arithmetic_error_14) {
  // -0.0000000000000000000000000001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x801C0000}};
  // 626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x140000}};
  // -0
  s21_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};
  s21_decimal result = {};
  int code = s21_div(decimal1, decimal2, &result);
  ck_assert_int_eq(code, ARITHMETIC_SMALL);
  ck_assert_int_eq(s21_common_compare(result, decimal_check), 0);
}

// End test s21_div arithmetic error
START_TEST(test_div) {
  // -23.4783424
  s21_decimal decimal1 = {{234783424, 0, 0, 0x80070000}};
  // 76.34
  s21_decimal decimal2 = {{7634, 0, 0, 0x20000}};
  // -0.3075496777574011003405816086
  s21_decimal decimal_check = {{0xAAAF5116, 0x62CA0CF2, 0x9EFFDC6, 0x801C0000}};
  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div3) {
  // -42.94967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x80080000}};
  // 42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // -1.0000000002328306437080797375
  s21_decimal decimal_check = {
      {0x6E74D0BF, 0x5E74D0BF, 0x204FCE5E, 0x801C0000}};
  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div4) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // -1844674407800451891300000000
  s21_decimal decimal_check = {{0x5F5E100, 0x5F5E100, 0x5F5E100, 0x80000000}};
  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div5) {
  // 0.9999999999999999999999999999
  s21_decimal decimal1 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // -0.0000000004656612873077392578
  s21_decimal decimal_check = {{0x7C4A04C2, 0x409F9CBC, 0x0, 0x801C0000}};
  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div6) {
  // 39614081266355.540835774234624
  s21_decimal decimal1 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // 0.001
  s21_decimal decimal2 = {{0x1, 0x0, 0x0, 0x30000}};
  // 39614081266355540.835774234624
  s21_decimal decimal_check = {{0x80000000, 0x80000000, 0x80000000, 0xC0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div7) {
  // 39614081266355.540835774234624
  s21_decimal decimal1 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // 922337203900.22594565
  s21_decimal decimal_check = {{0x5, 0x5, 0x5, 0x80000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div8) {
  // -214748.3648
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -27105.054312137610850186320022
  s21_decimal decimal_check = {
      {0x4B385896, 0x8721CAEB, 0x5794C682, 0x80180000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div9) {
  // -214748.3648
  s21_decimal decimal1 = {{0x80000000, 0x0, 0x0, 0x80040000}};
  // -1429062841781896312709593009.2
  s21_decimal decimal2 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x80010000}};
  // 0.0000000000000000000001502722
  s21_decimal decimal_check = {{0x16EE02, 0x0, 0x0, 0x1C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div10) {
  // 42.94967295
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // -8589934591
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x1, 0x0, 0x80000000}};
  // -0.0000000049999999994179233908
  s21_decimal decimal_check = {{0x56962874, 0xB5E3AF15, 0x2, 0x801C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div11) {
  // 42.94967295
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // -21.474836475000000000000000001
  s21_decimal decimal_check = {
      {0xBB0C0001, 0xFF906E7D, 0x45639181, 0x801B0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div12) {
  // 42.94967295
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -42949672950000000000000000000
  s21_decimal decimal_check = {
      {0x76180000, 0xFF20DCFB, 0x8AC72303, 0x80000000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div13) {
  // 42.94967295
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 42.949672950000000000000000004
  s21_decimal decimal_check = {{0x76180004, 0xFF20DCFB, 0x8AC72303, 0x1B0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div14) {
  // 42.94967295
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // 0.7158278824999999999999999999
  s21_decimal decimal_check = {{0xE903FFFF, 0xAA857A29, 0x17213080, 0x1C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div15) {
  // -42.94967295
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // -0.000000009999999995343387128
  s21_decimal decimal_check = {{0x7459B9F8, 0x8AC72303, 0x0, 0x801B0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div16) {
  // -1.001
  s21_decimal decimal1 = {{0x3E9, 0x0, 0x0, 0x80030000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -0.126343962580197250754742447
  s21_decimal decimal_check = {{0xE30D08AF, 0xEF7C8680, 0x68825F, 0x801B0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div17) {
  // 1429062841781896312709593009.2
  s21_decimal decimal1 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x10000}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // -285812568356379262541918601.84
  s21_decimal decimal_check = {
      {0xBE2C59D8, 0xADA12E5D, 0x5C59DC8D, 0x80020000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div18) {
  // 3656273013.5441854660747245473
  s21_decimal decimal1 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // -7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  // -0.0000000000000000004614865343
  s21_decimal decimal_check = {{0x131141BF, 0x1, 0x0, 0x801C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div19) {
  // 3656273013.5441854660747245473
  s21_decimal decimal1 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // 79228162514264337593543950334
  s21_decimal decimal2 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000461486534
  s21_decimal decimal_check = {{0x1B81B9C6, 0x0, 0x0, 0x1C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div20) {
  // 14290628417818963127095930092
  s21_decimal decimal1 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // -3327296212739069742.8714321209
  s21_decimal decimal_check = {
      {0x6508F539, 0x2D5FF241, 0x6B82BFCB, 0x800A0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}
/*

*/

START_TEST(test_div21) {
  // 1429062841781896312709593009.2
  s21_decimal decimal1 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x10000}};
  // 214748.3648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x40000}};
  // 6654592425478139485742.8642418
  s21_decimal decimal_check = {{0xCA11EA72, 0x5ABFE482, 0xD7057F96, 0x70000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div22) {
  // 1429062841781896312709593009.2
  s21_decimal decimal1 = {{0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x10000}};
  // -10
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x80000000}};
  // -142906284178189631270959300.92
  s21_decimal decimal_check = {
      {0xDF162CEC, 0xD6D0972E, 0x2E2CEE46, 0x80020000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div23) {
  // -626656361.06935169033698303587
  s21_decimal decimal1 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // 7922816251426433759354395033.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  // -0.0000000000000000000790951527
  s21_decimal decimal_check = {{0x2F24F667, 0x0, 0x0, 0x801C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div24) {
  // -626656361.06935169033698303587
  s21_decimal decimal1 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // -4294967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000000}};
  // 0.1459048038975688839184546461
  s21_decimal decimal_check = {{0x98C07A9D, 0xAE4FF9E5, 0x4B6E570, 0x1C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div25) {
  // -626656361.06935169033698303587
  s21_decimal decimal1 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // -0.2918096077951377678369092922
  s21_decimal decimal_check = {{0x3180F53A, 0x5C9FF3CB, 0x96DCAE1, 0x801C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div26) {
  // -626656361.06935169033698303587
  s21_decimal decimal1 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // 5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x0}};
  // -125331272.21387033806739660717
  s21_decimal decimal_check = {
      {0x5E7CDFAD, 0x12C0A10E, 0x287F28EC, 0x80140000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div27) {
  // -626656361.06935169033698303587
  s21_decimal decimal1 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // -5
  s21_decimal decimal2 = {{0x5, 0x0, 0x0, 0x80000000}};
  // 125331272.21387033806739660717
  s21_decimal decimal_check = {{0x5E7CDFAD, 0x12C0A10E, 0x287F28EC, 0x140000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div28) {
  // -626656361.06935169033698303587
  s21_decimal decimal1 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // 2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x0}};
  // -313328180.53467584516849151794
  s21_decimal decimal_check = {
      {0xEC382F32, 0x2EE192A3, 0x653DE64E, 0x80140000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div29) {
  // -626656361.06935169033698303587
  s21_decimal decimal1 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // -2
  s21_decimal decimal2 = {{0x2, 0x0, 0x0, 0x80000000}};
  // 313328180.53467584516849151794
  s21_decimal decimal_check = {{0xEC382F32, 0x2EE192A3, 0x653DE64E, 0x140000}};
  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div30) {
  // -626656361.06935169033698303587
  s21_decimal decimal1 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -313328180.5346758451684915336
  s21_decimal decimal_check = {{0x979F3888, 0x4B02843, 0xA1FCA3B, 0x80130000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div31) {
  // -626656361.06935169033698303587
  s21_decimal decimal1 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // -1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 313328180.5346758451684915336
  s21_decimal decimal_check = {{0x979F3888, 0x4B02843, 0xA1FCA3B, 0x130000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div32) {
  // -626656361.06935169033698303587
  s21_decimal decimal1 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // 1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -313328180.53467584516849151795
  s21_decimal decimal_check = {
      {0xEC382F33, 0x2EE192A3, 0x653DE64E, 0x80140000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div33) {
  // -626656361.06935169033698303587
  s21_decimal decimal1 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // -1.9999999999999999999999999999
  s21_decimal decimal2 = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};
  // 313328180.53467584516849151795
  s21_decimal decimal_check = {{0xEC382F33, 0x2EE192A3, 0x653DE64E, 0x140000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div34) {
  // -626656361.06935169033698303587
  s21_decimal decimal1 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // -10444272.684489194838949717264
  s21_decimal decimal_check = {
      {0x4EBD6510, 0xBA4B30E1, 0x21BF4CC4, 0x80150000}};
  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div35) {
  // -626656361.06935169033698303587
  s21_decimal decimal1 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // 3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // -0.1713921139772618486656577484
  s21_decimal decimal_check = {{0xADFCAFCC, 0x291786E7, 0x589B8EB, 0x801C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div36) {
  // -626656361.06935169033698303587
  s21_decimal decimal1 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // -3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x80130000}};
  // 0.1713921139772618486656577484
  s21_decimal decimal_check = {{0xADFCAFCC, 0x291786E7, 0x589B8EB, 0x1C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div37) {
  // -626656361.06935169033698303587
  s21_decimal decimal1 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // 626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x140000}};
  // -1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div38) {
  // -626656361.06935169033698303587
  s21_decimal decimal1 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // -626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // 1
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div39) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 2147483648.0000000000000001074
  s21_decimal decimal_check = {{0x432, 0x44F40000, 0x45639182, 0x130000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div40) {
  // 1.9999999999999999999999999000
  s21_decimal decimal1 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -39614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x80000000}};
  // -0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div41) {
  // 1.9999999999999999999999999000
  s21_decimal decimal1 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 3.9614081257132168796771975168
  s21_decimal decimal2 = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  // 0.5048709793414475554635062565
  s21_decimal decimal_check = {{0xF7FF1D25, 0x503DA893, 0x105031E2, 0x1C0000}};
  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div42) {
  // 1.9999999999999999999999999000
  s21_decimal decimal1 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 4294967297
  s21_decimal decimal2 = {{0x1, 0x1, 0x0, 0x0}};
  // 0.0000000004656612871993190406
  s21_decimal decimal_check = {{0x3BAA6806, 0x409F9CBC, 0x0, 0x1C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div44) {
  // 1.9999999999999999999999999000
  s21_decimal decimal1 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x0}};
  // 0.0000000009313225746154785156
  s21_decimal decimal_check = {{0xF8940984, 0x813F3978, 0x0, 0x1C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div45) {
  // 1.9999999999999999999999999000
  s21_decimal decimal1 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -2147483648
  s21_decimal decimal2 = {{0x80000000, 0x0, 0x0, 0x80000000}};
  // -0.0000000009313225746154785156
  s21_decimal decimal_check = {{0xF8940984, 0x813F3978, 0x0, 0x801C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div46) {
  // 1.9999999999999999999999999000
  s21_decimal decimal1 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -0.019
  s21_decimal decimal2 = {{0x13, 0x0, 0x0, 0x80030000}};
  // -105.26315789473684210526315263
  s21_decimal decimal_check = {
      {0x5435E2FF, 0x5C5CDA15, 0x22032A12, 0x801A0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div47) {
  // 1.9999999999999999999999999000
  s21_decimal decimal1 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // 0.0000000000000504870979223898
  s21_decimal decimal_check = {{0x6F5FC15A, 0x1CB2D, 0x0, 0x1C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div48) {
  // 1.9999999999999999999999999000
  s21_decimal decimal1 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -42.94967295
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  // -0.0465661287416159475086293969
  s21_decimal decimal_check = {{0x5FAA7BD1, 0xF9133DC8, 0x1812F9C, 0x801C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div49) {
  // 1.9999999999999999999999999000
  s21_decimal decimal1 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 0.9999
  s21_decimal decimal2 = {{0x270F, 0x0, 0x0, 0x40000}};
  // 2.0002000200020002000200019002
  s21_decimal decimal_check = {{0xBCD82C3A, 0x8BBD6AAE, 0x40A1444B, 0x1C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div50) {
  // 1.9999999999999999999999999000
  s21_decimal decimal1 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // -1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x80090000}};
  // -1.3969838622484784252588819073
  s21_decimal decimal_check = {
      {0x35FA8281, 0x30413D7B, 0x2D239465, 0x801C0000}};
  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div51) {
  // 1.9999999999999999999999999000
  s21_decimal decimal1 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x30000}};
  // 0.0002363985717743887678528201
  s21_decimal decimal_check = {{0x576D5AC9, 0xEC2BEAF0, 0x1F497, 0x1C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div52) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal decimal2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 2147483648.0000000000000001074
  s21_decimal decimal_check = {{0x432, 0x44F40000, 0x45639182, 0x130000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div53) {
  // -79228162495817593524129366015
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // 39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};
  // -1999999999068677.4256013619188
  s21_decimal decimal_check = {
      {0xA8AB2FF4, 0xFB0ACB49, 0x409F9CBB, 0x800D0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div54) {
  // -79228162495817593524129366015
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // -39614081266355.540835774234624
  s21_decimal decimal2 = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};
  // 1999999999068677.4256013619188
  s21_decimal decimal_check = {{0xA8AB2FF4, 0xFB0ACB49, 0x409F9CBB, 0xD0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div55) {
  // -79228162495817593524129366015
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // 42.94967296
  s21_decimal decimal2 = {{0x0, 0x1, 0x0, 0x80000}};
  // -1844674406941458432100000000
  s21_decimal decimal_check = {{0x5F5E100, 0xFA0A1F00, 0x5F5E0FF, 0x80000000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div57) {
  // -79228162495817593524129366015
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // 1.431655765
  s21_decimal decimal2 = {{0x55555555, 0x0, 0x0, 0x90000}};
  // -55340232221128654851000000000
  s21_decimal decimal_check = {{0xB2D05E00, 0x0, 0xB2D05E00, 0x80000000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div58) {
  // -79228162495817593524129366015
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // 3656273013.5441854660747245473
  s21_decimal decimal2 = {{0x3C2CB7A1, 0x3E0B91AF, 0x7623FB44, 0x130000}};
  // -21669104632593688025.07401738
  s21_decimal decimal_check = {{0x8BE1AA0A, 0x97A57D66, 0x7006D23, 0x80080000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div59) {
  // -79228162495817593524129366015
  s21_decimal decimal1 = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  // -626656361.06935169033698303587
  s21_decimal decimal2 = {{0xD8705E63, 0x5DC32547, 0xCA7BCC9C, 0x80140000}};
  // 126429998030530578866.03122539
  s21_decimal decimal_check = {{0x568F176B, 0xA902A354, 0x28DA0B58, 0x80000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div60) {
  // 4294967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x0}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000542101086
  s21_decimal decimal_check = {{0x204FCE5E, 0x0, 0x0, 0x1C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div61) {
  // -23.4783424
  s21_decimal decimal1 = {{234783424, 0, 0, 0x80070000}};
  // 76.34
  s21_decimal decimal2 = {{7634, 0, 0, 0x20000}};
  // -0.3075496777574011003405816086
  s21_decimal decimal_check = {{0xAAAF5116, 0x62CA0CF2, 0x9EFFDC6, 0x801C0000}};
  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div64) {
  s21_decimal decimal1 = {0x1888888D, 0xBE250261, 0x28D856E6, 0x1C0000};
  s21_decimal decimal2 = {0x2, 0x0, 0x0, 0x0};
  s21_decimal decimal_check = {{0x8C444446, 0x5F128130, 0x146C2B73, 0x1C0000}};
  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div65) {
  // 2 - dec1
  s21_decimal decimal1 = {0x2, 0x0, 0x0, 0x0};
  // 1.2640938749860586450804312205 - dec2
  s21_decimal decimal2 = {0x1888888D, 0xBE250261, 0x28D856E6, 0x1C0000};
  // 1.5821609767882606564463392905 - expected
  s21_decimal decimal_check = {0x8B80B889, 0x20B8279E, 0x331F5430, 0x1C0000};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div66) {
  // 1431655765 - dec1
  s21_decimal decimal1 = {0x55555555, 0x0, 0x0, 0x0};
  // 12.640938749860586450805 - dec2
  s21_decimal decimal2 = {0x2EB3EF75, 0x4444026F, 0x2AD, 0x150000};
  // 113255494.17884722765619814067 - expected
  s21_decimal decimal_check = {0x6D7C5EB3, 0x2C521AF0, 0x24984660, 0x140000};
  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div67) {
  // 1
  s21_decimal decimal1 = {0x1, 0x0, 0x0, 0x0};
  // 500
  s21_decimal decimal2 = {0x1F4, 0x0, 0x0, 0x0};
  s21_decimal res = {};
  // 0.002
  s21_decimal decimal_check = {0x2, 0x0, 0x0, 0x30000};
  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div68) {
  // 79228162514264337593543950335 - dec1
  s21_decimal decimal1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  // 7.9228162514264337593543950335 -dec2
  s21_decimal decimal2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000};
  // 10000000000000000000000000000 - expected
  s21_decimal decimal_check = {0x10000000, 0x3E250261, 0x204FCE5E, 0x0};
  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div69) {
  s21_decimal decimal1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000};
  s21_decimal decimal2 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal decimal_check = {0x1, 0x0, 0x0, 0x1C0000};
  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div70) {
  s21_decimal decimal1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0};
  s21_decimal decimal2 = {0x55555555, 0x55555555, 0x55555555, 0x80000000};
  s21_decimal decimal_check = {0x3, 0x0, 0x0, 0x80000000};
  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div71) {
  // -26409387504754779197847983445 - dec1
  s21_decimal decimal1 = {0x55555555, 0x55555555, 0x55555555, 0x80000000};
  // 156064767525876035022225408 - dec2
  s21_decimal decimal2 = {0x0, 0x0, 0x811800, 0x0};
  // -169.22068909868474138626644073 - expected
  s21_decimal decimal_check = {0x8C085869, 0xC05E68BD, 0x36AD9B79, 0x801A0000};
  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div72) {
  // -79228162514264337593543950335 - dec1
  s21_decimal decimal1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  // 1.0000000000000000000000000001 - dec2
  s21_decimal decimal2 = {0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000};
  // -79228162514264337593543950327 - expected
  s21_decimal decimal_check = {0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div73) {
  // -0.001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80030000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // 0.001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x30000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div74) {
  // -0.001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80030000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // -0.0001262177448353618888658766
  s21_decimal decimal_check = {{0xE0828F4E, 0xC6CDD6E3, 0x10B46, 0x801C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div75) {
  // -0.001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80030000}};
  // -7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  // 0.0001262177448353618888658766
  s21_decimal decimal_check = {{0xE0828F4E, 0xC6CDD6E3, 0x10B46, 0x1C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div76) {
  // -0.001
  s21_decimal decimal1 = {{0x1, 0x0, 0x0, 0x80030000}};
  // 60.000000000000000000000000005
  s21_decimal decimal2 = {{0x60000005, 0x74DE0E46, 0xC1DED635, 0x1B0000}};
  // -0.0000166666666666666666666667
  s21_decimal decimal_check = {{0xF02AAAAB, 0x4A2777C, 0x234B, 0x801C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div77) {
  // 42.94967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x80000}};
  // -0.0000000000000000000000000010
  s21_decimal decimal2 = {{0xA, 0x0, 0x0, 0x801C0000}};
  // -42949672960000000000000000000
  s21_decimal decimal_check = {{0x0, 0x89E80000, 0x8AC72304, 0x80000000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div78) {
  // 42.94967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x80000}};
  // 0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // 42.949672960000000000000000004
  s21_decimal decimal_check = {{0x4, 0x89E80000, 0x8AC72304, 0x1B0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div79) {
  // 42.94967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x80000}};
  // -0.9999999999999999999999999999
  s21_decimal decimal2 = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  // -42.949672960000000000000000004
  s21_decimal decimal_check = {{0x4, 0x89E80000, 0x8AC72304, 0x801B0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div80) {
  // 42.94967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x80000}};
  // 7.9228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 5.4210108624275221700372640044
  s21_decimal decimal_check = {{0x9670B12C, 0xE4395D6, 0xAF298D05, 0x1C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div81) {
  // 42.94967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x80000}};
  // -8460.288
  s21_decimal decimal2 = {{0x811800, 0x0, 0x0, 0x80030000}};
  // -0.0050766206729605422415879932
  s21_decimal decimal_check = {{0x64841EFC, 0x94CD154E, 0x29FE29, 0x801C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div82) {
  // 42.94967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x80000}};
  // 8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x30000}};
  // 5.36870912
  s21_decimal decimal_check = {{0x20000000, 0x0, 0x0, 0x80000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div83) {
  // 42.94967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x80000}};
  // -8.000
  s21_decimal decimal2 = {{0x1F40, 0x0, 0x0, 0x80030000}};
  // -5.36870912
  s21_decimal decimal_check = {{0x20000000, 0x0, 0x0, 0x80080000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div84) {
  // 42.94967296
  s21_decimal decimal1 = {{0x0, 0x1, 0x0, 0x80000}};
  // 1.001
  s21_decimal decimal2 = {{0x3E9, 0x0, 0x0, 0x30000}};
  // 42.906766193806193806193806194
  s21_decimal decimal_check = {{0xFD714B72, 0x15262B79, 0x8AA3A528, 0x1B0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div85) {
  // 7.9228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  // 79228162514264337593543950335
  s21_decimal decimal2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // 0.0000000000000000000000000001
  s21_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div86) {
  // 79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  // -26409387504754779197847983445
  s21_decimal decimal2 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -3
  s21_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div87) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // 156064767525876035022225408
  s21_decimal decimal2 = {{0x0, 0x0, 0x811800, 0x0}};
  // -169.22068909868474138626644073
  s21_decimal decimal_check = {
      {0x8C085869, 0xC05E68BD, 0x36AD9B79, 0x801A0000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div88) {
  // -26409387504754779197847983445
  s21_decimal decimal1 = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  // -429496729.5
  s21_decimal decimal2 = {{0xFFFFFFFF, 0x0, 0x0, 0x80010000}};
  // 61489146926681729710
  s21_decimal decimal_check = {{0xAAAAAAAE, 0x55555558, 0x3, 0x0}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div89) {
  // -79228162514264337593543950335
  s21_decimal decimal1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  // 1.0000000000000000000000000001
  s21_decimal decimal2 = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  // -79228162514264337593543950327
  s21_decimal decimal_check = {
      {0xFFFFFFF7, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  common_test_div(decimal1, decimal2, decimal_check);
}

START_TEST(test_div90) {
  // 1.2640938749860586450804312207
  s21_decimal decimal1 = {{0x1888888F, 0xBE250261, 0x28D856E6, 0x1C0000}};
  // 2.0000000000000000000000000000
  s21_decimal decimal2 = {{0x20000000, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  // 0.6320469374930293225402156104
  s21_decimal decimal_check = {{0x8C444448, 0x5F128130, 0x146C2B73, 0x1C0000}};
  common_test_div(decimal1, decimal2, decimal_check);
}

/**
 * Test s21_div has finished
 */

// --------------------------- //
//                             //
//     Test other functions    //
//                             //
// --------------------------- //

/**
 * // Test s21_truncate is beginning
 */

START_TEST(test_s21_truncate_1) {
  // 1.49999999
  s21_decimal decimal = {{149999999, 0, 0, 0x80000}};
  // 1
  s21_decimal decimal_check = {{1, 0, 0, 0}};
  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  ck_assert_int_eq(s21_common_compare(result, decimal_check), 0);
  ck_assert_int_eq(code, ARITHMETIC_OK);
}

START_TEST(test_s21_truncate_2) {
  // -1e-29
  s21_decimal decimal = {{1, 0, 0, 0x801D0000}};
  s21_decimal result;
  int code = s21_truncate(decimal, &result);
  ck_assert_int_eq(code, ARITHMETIC_BIG);
}

START_TEST(test_s21_truncate_3) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  s21_decimal res = {0x0};
  s21_decimal expected = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  int code = s21_truncate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_truncate_4) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000};
  s21_decimal res = {0x0};
  s21_decimal expected = {0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000};
  int code = s21_truncate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_truncate_5) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000};
  s21_decimal res = {0x0};
  s21_decimal expected = {0x84230FCF, 0xAC471B47, 0xA7C5, 0x0};
  int code = s21_truncate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_truncate_6) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000};
  s21_decimal res = {0x0};
  s21_decimal expected = {0x70D42573, 0x2D093, 0x0, 0x0};
  int code = s21_truncate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_truncate_7) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000};
  s21_decimal res = {0x0};
  s21_decimal expected = {0x70D42573, 0x2D093, 0x0, 0x80000000};
  int code = s21_truncate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_truncate_8) {
  s21_decimal dec1 = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000};
  s21_decimal res = {0x0};
  s21_decimal expected = {0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0};
  int code = s21_truncate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_truncate_9) {
  s21_decimal dec1 = {0x0, 0x55555555, 0x55555555, 0x80010000};
  s21_decimal res = {0x0};
  s21_decimal expected = {0x80000000, 0x88888888, 0x8888888, 0x80000000};
  int code = s21_truncate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_truncate_10) {
  s21_decimal dec1 = {0x0, 0x55555555, 0x55555555, 0x1C0000};
  s21_decimal res = {0x0};
  s21_decimal expected = {0x2, 0x0, 0x0, 0x0};
  int code = s21_truncate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_truncate_11) {
  s21_decimal dec1 = {0x1, 0x1, 0x0, 0x80090000};
  s21_decimal res = {0x0};
  s21_decimal expected = {0x4, 0x0, 0x0, 0x80000000};
  int code = s21_truncate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_truncate_12) {
  s21_decimal dec1 = {0x1, 0x1, 0x0, 0x80000};
  s21_decimal res = {0x0};
  s21_decimal expected = {0x2A, 0x0, 0x0, 0x0};
  int code = s21_truncate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_truncate_13) {
  s21_decimal dec1 = {0x1, 0x0, 0x0, 0x0};
  s21_decimal res = {0x0};
  s21_decimal expected = {0x1, 0x0, 0x0, 0x0};
  int code = s21_truncate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_truncate_14) {
  s21_decimal dec1 = {0x1, 0x0, 0x0, 0x80000000};
  s21_decimal res = {0x0};
  s21_decimal expected = {0x1, 0x0, 0x0, 0x80000000};
  int code = s21_truncate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_truncate_15) {
  s21_decimal dec1 = {0x1, 0x0, 0x0, 0x800D0000};
  s21_decimal res = {0x0};
  s21_decimal expected = {0x0, 0x0, 0x0, 0x80000000};
  int code = s21_truncate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_truncate_16) {
  s21_decimal dec1 = {0x5F5E0FF, 0x0, 0x0, 0x40000};
  s21_decimal res = {0x0};
  s21_decimal expected = {0x270F, 0x0, 0x0, 0x0};
  int code = s21_truncate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_truncate_17) {
  s21_decimal dec1 = {0x16632459, 0x49565B09, 0x7AFF1E43, 0x801A0000};
  s21_decimal res = {0x0};
  s21_decimal expected = {0x17C, 0x0, 0x0, 0x80000000};
  int code = s21_truncate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_truncate_18) {
  s21_decimal dec1 = {0x41151F02, 0xF5D2C738, 0x5416B21C, 0x801C0000};
  s21_decimal res = {0x0};
  s21_decimal expected = {0x2, 0x0, 0x0, 0x80000000};
  int code = s21_truncate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

/**
 * // Test s21_truncate has finished
 */

/**
 * // Test s21_floor is beginning...
 */

START_TEST(test_floor) {
  // -0.3075496777574011003405816086
  s21_decimal decimal = {{0xAAAF5116, 0x62CA0CF2, 0x9EFFDC6, 0x801C0000}};
  // -1
  s21_decimal decimal_check = {{1, 0, 0, 0x80000000}};
  s21_decimal res;
  int code = s21_floor(decimal, &res);
  ck_assert_int_eq(s21_is_equal(res, decimal_check), TEST_COMPARISON_TRUE);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
}

START_TEST(test_floor_2) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000};
  int code = s21_floor(dec1, NULL);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_floor_3) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000};
  s21_decimal res = {};
  s21_decimal expected = {0x9999999A, 0x99999999, 0x19999999, 0x80000000};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_floor_4) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000};
  s21_decimal res = {};
  s21_decimal expected = {0x28F5C290, 0xF5C28F5C, 0x28F5C28, 0x80000000};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
}

START_TEST(test_floor_5) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000};
  s21_decimal res = {};
  s21_decimal expected = {0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_floor_6) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000};
  s21_decimal res = {};
  s21_decimal expected = {0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x80000000};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_floor_7) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000};
  s21_decimal res = {};
  s21_decimal expected = {0xBE7B9D58, 0x480E, 0x0, 0x0};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_floor_8) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000};
  s21_decimal res = {};
  s21_decimal expected = {0xBE7B9D59, 0x480E, 0x0, 0x80000000};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_floor_9) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000};
  s21_decimal res = {};
  s21_decimal expected = {0x4B8ED02, 0x0, 0x0, 0x0};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_floor_10) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000};
  s21_decimal res = {};
  s21_decimal expected = {0x4B8ED03, 0x0, 0x0, 0x80000000};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_floor_11) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000};
  s21_decimal res = {};
  s21_decimal expected = {0x78E480, 0x0, 0x0, 0x0};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_floor_12) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000};
  s21_decimal res = {};
  s21_decimal expected = {0x78E481, 0x0, 0x0, 0x80000000};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_floor_13) {
  s21_decimal dec1 = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000};
  s21_decimal res = {};
  s21_decimal expected = {0x99999999, 0x99999999, 0x19999999, 0x0};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_floor_14) {
  s21_decimal dec1 = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000};
  s21_decimal res = {};
  s21_decimal expected = {0x9999999A, 0x99999999, 0x19999999, 0x80000000};

  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_floor_15) {
  s21_decimal dec1 = {0x811800, 0x0, 0x0, 0x80000000};
  s21_decimal res = {};
  s21_decimal expected = {0x811800, 0x0, 0x0, 0x80000000};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_floor_16) {
  s21_decimal dec1 = {0x811800, 0x0, 0x0, 0x80010000};
  s21_decimal res = {};
  s21_decimal expected = {0xCE8CD, 0x0, 0x0, 0x80000000};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_floor_17) {
  s21_decimal dec1 = {0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000};
  s21_decimal res = {};
  s21_decimal expected = {0x80000000, 0x99999999, 0x19999999, 0x80000000};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_floor_18) {
  s21_decimal dec1 = {0x95, 0x0, 0x0, 0x20000};
  s21_decimal res = {};
  s21_decimal expected = {0x1, 0x0, 0x0, 0x0};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_floor_19) {
  s21_decimal dec1 = {0x95, 0x0, 0x0, 0x80020000};
  s21_decimal res = {};
  s21_decimal expected = {0x2, 0x0, 0x0, 0x80000000};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_floor_20) {
  s21_decimal dec1 = {0x97, 0x0, 0x0, 0x20000};
  s21_decimal res = {};
  s21_decimal expected = {0x1, 0x0, 0x0, 0x0};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_floor_21) {
  s21_decimal dec1 = {0x97, 0x0, 0x0, 0x80020000};
  s21_decimal res = {};
  s21_decimal expected = {0x2, 0x0, 0x0, 0x80000000};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_floor_22) {
  s21_decimal dec1 = {0xDBD2185D, 0x27DCADA9, 0x10A64009, 0x0};
  s21_decimal res = {};
  s21_decimal expected = {0xDBD2185D, 0x27DCADA9, 0x10A64009, 0x0};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_floor_23) {
  s21_decimal dec1 = {0xE3C4D7EE, 0x1A344107, 0x23F13FF5, 0x80150000};
  s21_decimal res = {};
  s21_decimal expected = {0xA9BBAD, 0x0, 0x0, 0x80000000};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_floor_24) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  s21_decimal res = {};
  s21_decimal expected = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_floor_25) {
  s21_decimal dec1 = {0xEFE99B1F, 0x9755E57A, 0xF04F1D48, 0x150000};
  s21_decimal res = {};
  s21_decimal expected = {0x46ED3CD, 0x0, 0x0, 0x0};
  int code = s21_floor(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

/**
 * // Test s21_floor has finished
 */

/**
 * // Test s21_round is beginning...
 */

START_TEST(test_round) {
  // 234.543
  s21_decimal decimal = {{234543, 0, 0, 0x30000}};
  // 235
  s21_decimal decimal_check = {{235, 0, 0, 0}};
  s21_decimal result;
  int code = s21_round(decimal, &result);
  ck_assert_int_eq(s21_common_compare(result, decimal_check), 0);
  ck_assert_int_eq(code, ARITHMETIC_OK);
}

START_TEST(test_round_2) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000};
  int code = s21_round(dec1, NULL);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_round_3) {
  s21_decimal dec1 = {0, 0, 0, 1000000000};
  s21_decimal res = {};
  int code = s21_round(dec1, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_round_4) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000};
  s21_decimal res = {};
  s21_decimal expected = {0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0};
  int code = s21_round(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_round_5) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000};
  s21_decimal res = {};
  s21_decimal expected = {0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000};
  int code = s21_round(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_round_6) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000};
  s21_decimal res = {};
  s21_decimal expected = {0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000};
  int code = s21_round(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_round_7) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000};
  s21_decimal res = {};
  s21_decimal expected = {0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x0};
  int code = s21_round(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_round_8) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000};
  s21_decimal res = {};
  s21_decimal expected = {0xBE7B9D58, 0x480E, 0x0, 0x0};
  int code = s21_round(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_round_9) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000};
  s21_decimal res = {};
  s21_decimal expected = {0xBE7B9D58, 0x480E, 0x0, 0x80000000};
  int code = s21_round(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_round_10) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000};
  s21_decimal res = {};
  s21_decimal expected = {0x318, 0x0, 0x0, 0x80000000};
  int code = s21_round(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_round_11) {
  s21_decimal dec1 = {0x1, 0x1, 0x0, 0x80090000};
  s21_decimal res = {};
  s21_decimal expected = {0x4, 0x0, 0x0, 0x80000000};
  int code = s21_round(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_round_12) {
  s21_decimal dec1 = {0x1, 0x1, 0x0, 0x80000};
  s21_decimal res = {};
  s21_decimal expected = {0x2B, 0x0, 0x0, 0x0};
  int code = s21_round(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_round_13) {
  s21_decimal dec1 = {0x1, 0x1, 0x0, 0x80080000};
  s21_decimal res = {};
  s21_decimal expected = {0x2B, 0x0, 0x0, 0x80000000};
  int code = s21_round(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_round_14) {
  s21_decimal dec1 = {0x1, 0x0, 0x0, 0x80000000};
  s21_decimal res = {};
  s21_decimal expected = {0x1, 0x0, 0x0, 0x80000000};
  int code = s21_round(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_round_15) {
  s21_decimal dec1 = {0x1, 0x0, 0x0, 0x10000};
  s21_decimal res = {};
  s21_decimal expected = {0x0, 0x0, 0x0, 0x0};
  int code = s21_round(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_round_16) {
  s21_decimal dec1 = {0x8F0D17F, 0x0, 0x0, 0x80000};
  s21_decimal res = {};
  s21_decimal expected = {0x1, 0x0, 0x0, 0x0};
  int code = s21_round(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_round_17) {
  s21_decimal dec1 = {0x63, 0x0, 0x0, 0x20000};
  s21_decimal res = {};
  s21_decimal expected = {0x1, 0x0, 0x0, 0x0};
  int code = s21_round(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_round_18) {
  s21_decimal dec1 = {0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000};
  s21_decimal res = {};
  s21_decimal expected = {0x1, 0x0, 0x0, 0x80000000};
  int code = s21_round(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_round_19) {
  s21_decimal dec1 = {0x2446E975, 0x3DD6B6CE, 0x8C68C7AE, 0xD0000};
  s21_decimal res = {};
  s21_decimal expected = {0x9C852076, 0xF702B, 0x0, 0x0};
  int code = s21_round(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_round_20) {
  s21_decimal dec1 = {0x324853F4, 0xA561AB58, 0xE61DAA42, 0x80160000};
  s21_decimal res = {};
  s21_decimal expected = {0x6CAB4E, 0x0, 0x0, 0x80000000};
  int code = s21_round(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_round_21) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x0};
  s21_decimal res;
  s21_decimal expected = {0x0, 0x0, 0x0, 0x0};
  int code = s21_round(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

/**
 * // Test s21_round has finished
 */

/**
 * // Test s21_negate is beginning...
 */

START_TEST(test_negate) {
  // -0.3075496777574011003405816086
  s21_decimal decimal = {{0xAAAF5116, 0x62CA0CF2, 0x9EFFDC6, 0x801C0000}};
  // 0.3075496777574011003405816086
  s21_decimal decimal_check = {{0xAAAF5116, 0x62CA0CF2, 0x9EFFDC6, 0x1C0000}};
  s21_decimal result;
  int code = s21_negate(decimal, &result);
  ck_assert_int_eq(s21_common_compare(result, decimal_check), 0);
  ck_assert_int_eq(code, ARITHMETIC_OK);
}

START_TEST(test_negate_2) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000};
  int code = s21_negate(dec1, NULL);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_negate_3) {
  s21_decimal dec1 = {-1, 0, 0, 0x1D0000};
  s21_decimal res = {};
  int code = s21_negate(dec1, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_negate_4) {
  s21_decimal dec1 = {0, 0, 0, 0x1D0000};
  s21_decimal res = {};
  int code = s21_negate(dec1, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_negate_5) {
  s21_decimal dec1 = {-1, 0, 0, 0x11C0000};
  s21_decimal res = {};
  int code = s21_negate(dec1, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_negate_6) {
  s21_decimal dec1 = {-1, 0, 0, 0x1C0001};
  s21_decimal res = {};
  int code = s21_negate(dec1, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_negate_7) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000};
  s21_decimal res = {};
  s21_decimal expected = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000};
  int code = s21_negate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_negate_8) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000};
  s21_decimal res = {};
  s21_decimal expected = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000};
  int code = s21_negate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_negate_9) {
  s21_decimal dec1 = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000};
  s21_decimal res = {};
  s21_decimal expected = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000};
  int code = s21_negate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_negate_10) {
  s21_decimal dec1 = {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000};
  s21_decimal res = {};
  s21_decimal expected = {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000};
  int code = s21_negate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_negate_11) {
  s21_decimal dec1 = {0x0, 0x0, 0xAAAAAAAA, 0x80010000};
  s21_decimal res = {};
  s21_decimal expected = {0x0, 0x0, 0xAAAAAAAA, 0x10000};
  int code = s21_negate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_negate_12) {
  s21_decimal dec1 = {0x63, 0x0, 0x0, 0x80000000};
  s21_decimal res = {};
  s21_decimal expected = {0x63, 0x0, 0x0, 0x0};
  int code = s21_negate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_negate_13) {
  s21_decimal dec1 = {0x70110A39, 0x6E8B37A6, 0x66FC0D82, 0x80180000};
  s21_decimal res = {};
  s21_decimal expected = {0x70110A39, 0x6E8B37A6, 0x66FC0D82, 0x180000};
  int code = s21_negate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_negate_14) {
  s21_decimal dec1 = {0x7EE5ACD1, 0x274997F0, 0x313D6309, 0x60000};
  s21_decimal res = {};
  s21_decimal expected = {0x7EE5ACD1, 0x274997F0, 0x313D6309, 0x80060000};
  int code = s21_negate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_negate_15) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x801C0000};
  s21_decimal res = {};
  s21_decimal expected = {0x0, 0x0, 0x0, 0x1C0000};
  int code = s21_negate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_negate_16) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x1C0000};
  s21_decimal res = {};
  s21_decimal expected = {0x0, 0x0, 0x0, 0x801C0000};
  int code = s21_negate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_negate_17) {
  s21_decimal dec1 = {0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000};
  s21_decimal res = {};
  s21_decimal expected = {0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000};
  int code = s21_negate(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

/**
 * // Test s21_negate has finished
 */

// ----------------------------- //
//                               //
//     TANSFORM FUNCTIONS        //
//                               //
// ----------------------------- //

/**
 * // Test s21_from_decimal_to_float is beginning...
 */

START_TEST(test_s21_from_dec_to_float_1) {
  s21_decimal dec1 = {0xA, 0x0, 0x0, 0x0};
  float res = 0;
  int code = s21_from_decimal_to_float(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, 10.0f);
}

START_TEST(test_s21_from_dec_to_float_2) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x0};
  float res = 1.f;
  int code = s21_from_decimal_to_float(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, 0);
}

START_TEST(test_s21_from_dec_to_float_3) {
  s21_decimal dec1 = {0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80060000};
  float res = 0;
  int expected = -460438189;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(cast_res.int32_bytes, expected);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
}

START_TEST(test_s21_from_dec_to_float_4) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000};
  float res = 0;
  int expected = -500446089;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(cast_res.int32_bytes, expected);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
}

START_TEST(test_s21_from_dec_to_float_5) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000};
  float res = 0;
  int expected = 1619619935;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(cast_res.int32_bytes, expected);
}

START_TEST(test_s21_from_dec_to_float_6) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000};
  float res = 0;
  int expceted = -639554029;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(cast_res.int32_bytes, expceted);
}

START_TEST(test_s21_from_dec_to_float_7) {
  s21_decimal dec1 = {0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80140000};
  float res = 0;
  int expected = -850904460;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(cast_res.int32_bytes, expected);
}

START_TEST(test_s21_from_dec_to_float_8) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000};
  float res = 0;
  int expected = 1145442822;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(cast_res.int32_bytes, expected);
}

START_TEST(test_s21_from_dec_to_float_9) {
  s21_decimal dec1 = {0x0, 0x0, 0x80000000, 0x80010000};
  float res = 0;
  int expceted = -313733939;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(cast_res.int32_bytes, expceted);
}

START_TEST(test_s21_from_dec_to_float_10) {
  s21_decimal dec1 = {0x811800, 0x0, 0x811800, 0x80150000};
  float res = 0;
  int expceted = -937924559;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(cast_res.int32_bytes, expceted);
}

START_TEST(test_s21_from_dec_to_float_11) {
  s21_decimal dec1 = {0x0, 0xFFF7B800, 0x847, 0x80020000};
  float res = 0;
  int expected = -508978791;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(cast_res.int32_bytes, expected);
}

START_TEST(test_s21_from_dec_to_float_12) {
  s21_decimal dec1 = {0x0, 0xAAA7E800, 0x6E6, 0x20000};
  float res = 0;
  int expected = 1636652373;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(cast_res.int32_bytes, expected);
}

START_TEST(test_s21_from_dec_to_float_13) {
  s21_decimal dec1 = {0x0, 0x0, 0x2, 0x0};
  float res = 0;
  int expected = 1610612736;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(cast_res.int32_bytes, expected);
}

START_TEST(test_s21_from_dec_to_float_14) {
  s21_decimal dec1 = {0x0, 0x94D80000, 0x77359311, 0x80090000};
  float res = 0;
  int expected = -536870914;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(cast_res.int32_bytes, expected);
}

START_TEST(test_s21_from_dec_to_float_15) {
  s21_decimal dec1 = {0x0, 0x22F28000, 0x1A534C60, 0x80080000};
  float res = 0;
  int expected = -527608491;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(cast_res.int32_bytes, expected);
}

START_TEST(test_s21_from_dec_to_float_16) {
  s21_decimal dec1 = {0x0, 0x55555400, 0x1, 0x80000000};
  float res = 0;
  int expected = -542463318;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(cast_res.int32_bytes, expected);
}

START_TEST(test_s21_from_dec_to_float_17) {
  s21_decimal dec1 = {0x0, 0xF, 0x0, 0x80010000};
  float res = 0;
  int expected = -809500672;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(cast_res.int32_bytes, expected);
}

START_TEST(test_s21_from_dec_to_float_18) {
  s21_decimal dec1 = {0x3C, 0x0, 0x0, 0x10000};
  float res = 0;
  int expected = 1086324736;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(cast_res.int32_bytes, expected);
}

START_TEST(test_s21_from_dec_to_float_19) {
  s21_decimal dec1 = {0x8290A94, 0x5340, 0x0, 0x1C0000};
  float res = 0;
  int expected = 673506516;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(cast_res.int32_bytes, expected);
}

START_TEST(test_s21_from_dec_to_float_20) {
  s21_decimal dec1 = {0, 0, 0, 1000000000};
  float res = 0;
  int code = s21_from_decimal_to_float(dec1, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_from_dec_to_float_21) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x0};
  float res;
  int expected = 0;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(cast_res.int32_bytes, expected);
}

START_TEST(test_s21_from_dec_to_float_22) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000};
  float *res = NULL;
  int code = s21_from_decimal_to_float(dec1, res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_from_dec_to_float_23) {
  s21_decimal dec1 = {0x7D, 0x0, 0x0, 0x80030000};
  float res = 0;
  int expected = -1107296256;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(cast_res.int32_bytes, expected);
}

START_TEST(test_s21_from_dec_to_float_24) {
  s21_decimal dec1 = {0x286F9, 0x0, 0x0, 0x80060000};
  float res = 0;
  int expected = -1104569958;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(cast_res.int32_bytes, expected);
}

START_TEST(test_s21_from_dec_to_float_25) {
  s21_decimal dec1 = {0x35DA, 0x0, 0x0, 0x801C0000};
  float res = 0;
  int expected = -1747627015;
  int code = s21_from_decimal_to_float(dec1, &res);
  float_cast_test cast_res;
  cast_res.f = res;
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(cast_res.int32_bytes, expected);
}

/**
 * // Test s21_from_decimal_to_float has finished
 */

/**
 * // Test s21_from_float_to_decimal is beginning...
 */

START_TEST(test_s21_from_fl_to_dec_1) {
  float f = 1.0f;
  int code = s21_from_float_to_decimal(f, NULL);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_from_fl_to_dec_2) {
  float f = 9.98999985E-06;
  s21_decimal res = {};
  s21_decimal expected = {0x3E7, 0x0, 0x0, 0x80000};
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_fl_to_dec_3) {
  float f = -205114.672;
  s21_decimal res = {};
  s21_decimal expected = {0x1F4C4B, 0x0, 0x0, 0x80010000};
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_fl_to_dec_4) {
  float f = -2.82437522E+23;
  s21_decimal res = {};
  s21_decimal expected = {0xCDA60000, 0xF7B1A7FD, 0x3BCE, 0x80000000};
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_fl_to_dec_5) {
  float f = 99.9999f;
  s21_decimal res = {};
  float expected = 0;
  s21_from_float_to_decimal(f, &res);
  s21_from_decimal_to_float(res, &expected);
  ck_assert_float_eq(f, expected);
}

START_TEST(test_s21_from_fl_to_dec_6) {
  float f = 99123.1299123f;
  s21_decimal res = {};
  float expected = 0;
  s21_from_float_to_decimal(f, &res);
  s21_from_decimal_to_float(res, &expected);
  ck_assert_float_eq(f, expected);
}

START_TEST(test_s21_from_fl_to_dec_7) {
  float f = 0.00001;
  s21_decimal res = {};
  float expected = 0;
  s21_from_float_to_decimal(f, &res);
  s21_from_decimal_to_float(res, &expected);
  ck_assert_float_eq(f, expected);
}

START_TEST(test_s21_from_fl_to_dec_8) {
  float f = 0.00f;
  s21_decimal res = {};
  float expected = 0;
  s21_from_float_to_decimal(f, &res);
  s21_from_decimal_to_float(res, &expected);
  ck_assert_float_eq(f, expected);
}

START_TEST(test_s21_from_fl_to_dec_9) {
  float f = 0.999999999999999999999999999999999999999f;
  s21_decimal res = {};
  float expected = 0;
  int code = s21_from_float_to_decimal(f, &res);
  s21_from_decimal_to_float(res, &expected);
  ck_assert_int_eq(code, 0);
  ck_assert_float_eq(f, expected);
}

START_TEST(test_s21_from_fl_to_dec_10) {
  float f = 340282346638528859811704183484516925440.0f;
  s21_decimal res = {};
  float expected = 0;
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_from_fl_to_dec_11) {
  float f = 79228162514264337593543950335.f;
  s21_decimal res = {};
  float expected = 0;
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_from_fl_to_dec_12) {
  float f =
      0.00000000000000000000000000009999999429857660888699309391359540480357727713304344f;
  s21_decimal res = {};
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_from_fl_to_dec_13) {
  float f =
      4.999999414002276633844052655683216711283970335073789659219301029224880039691925048828125E-29;
  s21_decimal res = {};
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_from_fl_to_dec_14) {
  float f =
      1.4012984643248170709237295832899161312802619418765157717570682838897910826858606014866381E-45f;
  s21_decimal res = {};
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_from_fl_to_dec_15) {
  float f = -2.28401628E-19;
  s21_decimal res = {};
  int code = s21_from_float_to_decimal(f, &res);
  s21_decimal expected = {0x22D9F0, 0x0, 0x0, 0x80190000};
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_from_fl_to_dec_16) {
  float f = 3574.10864;
  s21_decimal res = {};
  int code = s21_from_float_to_decimal(f, &res);
  s21_decimal expected = {0x36895D, 0x0, 0x0, 0x30000};
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_from_fl_to_dec_17) {
  float f = -2.20958198E-20;
  s21_decimal res = {};
  s21_decimal expected = {0x21B72E, 0x0, 0x0, 0x801A0000};
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_from_fl_to_dec_18) {
  float f = -0.000973391929;
  s21_decimal res = {};
  s21_decimal expected = {0x94871F, 0x0, 0x0, 0x800A0000};
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_from_fl_to_dec_19) {
  float f = -32;
  s21_decimal res = {};
  s21_decimal expected = {0x20, 0x0, 0x0, 0x80000000};
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_from_fl_to_dec_20) {
  float f = 6.10351526E-05;
  s21_decimal res = {};
  s21_decimal expected = {0x5D21DB, 0x0, 0x0, 0xB0000};
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_from_fl_to_dec_21) {
  float f = 9.31322519E-10;
  s21_decimal res = {};
  s21_decimal expected = {0x8E1BC9, 0x0, 0x0, 0x100000};
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_fl_to_dec_22) {
  float f = 7.05860773E-22;
  s21_decimal res = {};
  s21_decimal expected = {0x6BB4B0, 0x0, 0x0, 0x1C0000};
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_fl_to_dec_23) {
  float f = 0.1875;
  s21_decimal res = {};
  s21_decimal expected = {0x753, 0x0, 0x0, 0x40000};
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), 1);
}

START_TEST(test_s21_from_fl_to_dec_24) {
  // float f = -0.015625;
  int f = -1132462080;
  s21_decimal res = {};
  s21_decimal expected = {0x3D09, 0x0, 0x0, 0x80060000};
  float_cast_test cast_float;
  cast_float.int32_bytes = f;
  int code = s21_from_float_to_decimal(cast_float.f, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_fl_to_dec_25) {
  float f = 0.100000001;
  s21_decimal res = {};
  s21_decimal expected = {0x1, 0x0, 0x0, 0x10000};
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_fl_to_dec_26) {
  float f = 2.82437522E+23;
  s21_decimal res = {};
  s21_decimal expected = {0xCDA60000, 0xF7B1A7FD, 0x3BCE, 0x0};
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_fl_to_dec_27) {
  float f = -4.54454516E+14;
  s21_decimal res = {};
  s21_decimal expected = {0xEF0A0100, 0x19D52, 0x0, 0x80000000};
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_fl_to_dec_28) {
  float f = -6.46234815E-27;
  s21_decimal res = {};
  s21_decimal expected = {0x41, 0x0, 0x0, 0x801C0000};
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_fl_to_dec_29) {
  float f = 1.65436113E-24;
  s21_decimal res = {};
  s21_decimal expected = {0x40A0, 0x0, 0x0, 0x1C0000};
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_fl_to_dec_30) {
  float f = INFINITY;
  s21_decimal res = {};
  int code = s21_from_float_to_decimal(f, &res);
  ck_assert_int_eq(code, 1);
}

/**
 * // Test s21_from_float_to_decimal has finished
 */

/**
 * // Test s21_from_int_to_decimal is beginning...
 */

START_TEST(test_s21_from_int_to_dec_1) {
  int num = -2147483648;
  int code = s21_from_int_to_decimal(num, NULL);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_from_int_to_dec_2) {
  int num = -2147483648;
  s21_decimal res = {};
  s21_decimal expected = {0x80000000, 0x0, 0x0, 0x80000000};
  int code = s21_from_int_to_decimal(num, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_int_to_dec_3) {
  int num = -2147483647;
  s21_decimal res = {};
  s21_decimal expected = {0x7FFFFFFF, 0x0, 0x0, 0x80000000};
  int code = s21_from_int_to_decimal(num, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_int_to_dec_4) {
  int num = -214748364;
  s21_decimal res = {};
  s21_decimal expected = {0xCCCCCCC, 0x0, 0x0, 0x80000000};
  int code = s21_from_int_to_decimal(num, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_int_to_dec_5) {
  int num = -214748;
  s21_decimal res = {};
  s21_decimal expected = {0x346DC, 0x0, 0x0, 0x80000000};
  int code = s21_from_int_to_decimal(num, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_int_to_dec_6) {
  int num = -1000;
  s21_decimal res = {};
  s21_decimal expected = {0x3E8, 0x0, 0x0, 0x80000000};
  int code = s21_from_int_to_decimal(num, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_int_to_dec_7) {
  int num = -1;
  s21_decimal res = {};
  s21_decimal expected = {0x1, 0x0, 0x0, 0x80000000};
  int code = s21_from_int_to_decimal(num, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_int_to_dec_8) {
  int num = 0;
  s21_decimal res = {};
  s21_decimal expected = {0x0, 0x0, 0x0, 0x0};
  int code = s21_from_int_to_decimal(num, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_int_to_dec_9) {
  int num = 214748364;
  s21_decimal res = {};
  s21_decimal expected = {0xCCCCCCC, 0x0, 0x0, 0x0};
  int code = s21_from_int_to_decimal(num, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_int_to_dec_10) {
  int num = 1000;
  s21_decimal res = {};
  s21_decimal expected = {0x3E8, 0x0, 0x0, 0x0};
  int code = s21_from_int_to_decimal(num, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_int_to_dec_11) {
  int num = 2147483647;
  s21_decimal res = {};
  s21_decimal expected = {0x7FFFFFFF, 0x0, 0x0, 0x0};
  int code = s21_from_int_to_decimal(num, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

START_TEST(test_s21_from_int_to_dec_12) {
  int num = 2147483646;
  s21_decimal res = {};
  s21_decimal expected = {0x7FFFFFFE, 0x0, 0x0, 0x0};
  int code = s21_from_int_to_decimal(num, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(s21_is_equal(res, expected), TEST_COMPARISON_TRUE);
}

/**
 * // Test s21_from_int_to_decimal has finished
 */

/**
 * // Test s21_from_decimal_to_int is beginning...
 */

START_TEST(test_s21_from_dec_to_int_1) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000};
  int code = s21_from_decimal_to_int(dec1, NULL);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_from_dec_to_int_2) {
  s21_decimal dec1 = {0, 0, 0, 1000000000};
  int res = 0;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_from_dec_to_int_3) {
  s21_decimal dec1 = {-1, 0, 0, 0x1D0000};
  int res = 0;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_from_dec_to_int_4) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
  int res;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_from_dec_to_int_5) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000};
  int res = 0;
  int expected = -792281625;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_6) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000};
  int res = 0;
  int expected = 79228162;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_7) {
  s21_decimal dec1 = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000};
  int res = 0;
  int expected = -7;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_8) {
  s21_decimal dec1 = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000};
  int res = 0;
  int expected = -792281625;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_9) {
  s21_decimal dec1 = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000};
  int res = 0;
  int expected = 79;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_10) {
  s21_decimal dec1 = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000};
  int res = 0;
  int expected = -79;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_11) {
  s21_decimal dec1 = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000};
  int res = 0;
  int expected = 7;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_12) {
  s21_decimal dec1 = {0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80140000};
  int res = 0;
  int expected = -528187750;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_13) {
  s21_decimal dec1 = {0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000};
  int res = 0;
  int expected = 5;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_14) {
  s21_decimal dec1 = {0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x140000};
  int res = 0;
  int expected = 528187749;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_15) {
  s21_decimal dec1 = {0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80140000};
  int res = 0;
  int expected = -528187749;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_16) {
  s21_decimal dec1 = {0x55555555, 0x0, 0x0, 0x0};
  int res = 0;
  int expected = 1431655765;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_17) {
  s21_decimal dec1 = {0x0, 0x55555555, 0x0, 0x80120000};
  int res = 0;
  int expected = -6;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_18) {
  s21_decimal dec1 = {0x0, 0x0, 0x1, 0x80130000};
  int res = 0;
  int expected = -1;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_19) {
  s21_decimal dec1 = {0x1, 0x0, 0x0, 0x0};
  int res = 0;
  int expected = 1;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_20) {
  s21_decimal dec1 = {0x1, 0x0, 0x0, 0x80010000};
  int res;
  int expected = 0;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_21) {
  s21_decimal dec1 = {0x1, 0x0, 0x0, 0xE0000};
  int res;
  int expected = 0;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_22) {
  s21_decimal dec1 = {0x1, 0x0, 0x0, 0x801B0000};
  int res;
  int expected = 0;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_23) {
  s21_decimal dec1 = {0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x1B0000};
  int res = 0;
  int expected = 1;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_24) {
  s21_decimal dec1 = {0x63, 0x0, 0x0, 0x80010000};
  int res = 0;
  int expected = -9;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_25) {
  s21_decimal dec1 = {0xF423F, 0x0, 0x0, 0x30000};
  int res = 0;
  int expected = 999;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_26) {
  s21_decimal dec1 = {0x9, 0x0, 0x0, 0x10000};
  int res;
  int expected = 0;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_27) {
  s21_decimal dec1 = {0x0, 0x0, 0x0, 0x0};
  int res;
  int expected = 0;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_28) {
  s21_decimal dec1 = {0x589BFFFF, 0xC5D1494C, 0x6F05B59, 0x120000};
  int res = 0;
  int expected = 2147483646;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, TEST_ARITHMETIC_OK);
  ck_assert_int_eq(res, expected);
}

START_TEST(test_s21_from_dec_to_int_29) {
  s21_decimal dec1 = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000};
  int res = 0;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_from_dec_to_int_30) {
  s21_decimal dec1 = {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000};
  int res = 0;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_from_dec_to_int_31) {
  s21_decimal dec1 = {0x0, 0x55555555, 0x0, 0x80000000};
  int res = 0;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_from_dec_to_int_32) {
  s21_decimal dec1 = {0x0, 0x1, 0x1, 0x0};
  int res = 0;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_from_dec_to_int_33) {
  s21_decimal dec1 = {0x0, 0x1, 0x1, 0x10000};
  int res = 0;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_from_dec_to_int_34) {
  s21_decimal dec1 = {0x80000000, 0x0, 0x80000000, 0x80010000};
  int res = 0;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_from_dec_to_int_35) {
  s21_decimal dec1 = {0xFFFFFFFF, 0x0, 0x0, 0x0};
  int res = 0;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, 1);
}

START_TEST(test_s21_from_dec_to_int_36) {
  s21_decimal dec1 = {0xFFFFFFFF, 0x0, 0x0, 0x80000000};
  int res = 0;
  int code = s21_from_decimal_to_int(dec1, &res);
  ck_assert_int_eq(code, 1);
}

/**
 * // Test s21_from_decimal_to_int has finished
 */

Suite *s21_decimal_suite(void) {
  Suite *s;
  TCase *tc_s21_is_equal, *tc_s21_is_not_equal, *tc_s21_is_greater,
      *tc_s21_is_less, *tc_s21_is_greather_or_equal, *tc_s21_is_less_or_equal,
      *tc_s21_from_dec_to_float, *tc_s21_from_fl_to_dec,
      *tc_s21_from_int_to_dec, *tc_s21_from_dec_to_int, *tc_s21_sub, *tc_add,
      *tc_div, *tc_truncate, *tc_round, *tc_floor, *tc_negate;

  s = suite_create("s21_decimal");

  // Compare functions
  tc_s21_is_equal = tcase_create("s21_is_equal");
  tcase_add_test(tc_s21_is_equal, test_s21_eq_1);
  tcase_add_test(tc_s21_is_equal, test_s21_eq_2);
  tcase_add_test(tc_s21_is_equal, test_s21_eq_3);
  tcase_add_test(tc_s21_is_equal, test_s21_eq_4);
  tcase_add_test(tc_s21_is_equal, test_s21_eq_5);
  tcase_add_test(tc_s21_is_equal, test_s21_eq_6);
  tcase_add_test(tc_s21_is_equal, test_s21_eq_7);
  tcase_add_test(tc_s21_is_equal, test_s21_eq_8);
  tcase_add_test(tc_s21_is_equal, test_s21_eq_9);
  tcase_add_test(tc_s21_is_equal, test_s21_eq_10);
  suite_add_tcase(s, tc_s21_is_equal);

  tc_s21_is_not_equal = tcase_create("s21_is_not_equal");
  tcase_add_test(tc_s21_is_not_equal, test_s21_is_not_equal_1);
  tcase_add_test(tc_s21_is_not_equal, test_s21_is_not_equal_2);
  tcase_add_test(tc_s21_is_not_equal, test_s21_is_not_equal_3);
  tcase_add_test(tc_s21_is_not_equal, test_s21_is_not_equal_4);
  tcase_add_test(tc_s21_is_not_equal, test_s21_is_not_equal_5);
  tcase_add_test(tc_s21_is_not_equal, test_s21_is_not_equal_6);
  tcase_add_test(tc_s21_is_not_equal, test_s21_is_not_equal_7);
  tcase_add_test(tc_s21_is_not_equal, test_s21_is_not_equal_8);
  tcase_add_test(tc_s21_is_not_equal, test_s21_is_not_equal_9);
  tcase_add_test(tc_s21_is_not_equal, test_s21_is_not_equal_10);
  suite_add_tcase(s, tc_s21_is_not_equal);

  tc_s21_is_greater = tcase_create("s21_is_greather");
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_1);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_2);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_3);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_4);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_5);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_6);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_7);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_8);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_9);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_10);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_11);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_12);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_13);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_14);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_15);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_16);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_17);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_18);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_19);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_20);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_21);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_22);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_23);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_24);
  tcase_add_test(tc_s21_is_greater, test_s21_is_greather_25);
  suite_add_tcase(s, tc_s21_is_greater);

  tc_s21_is_less = tcase_create("s21_is_less");
  tcase_add_test(tc_s21_is_less, test_s21_is_less_1);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_2);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_3);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_4);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_5);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_6);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_7);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_8);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_9);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_10);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_11);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_12);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_13);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_14);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_15);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_16);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_17);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_18);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_19);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_20);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_21);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_22);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_23);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_24);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_25);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_26);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_27);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_28);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_29);
  tcase_add_test(tc_s21_is_less, test_s21_is_less_30);
  suite_add_tcase(s, tc_s21_is_less);

  tc_s21_is_greather_or_equal = tcase_create("s21_is_greather_or_equal");
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_1);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_2);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_3);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_4);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_5);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_6);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_7);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_8);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_9);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_10);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_11);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_12);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_13);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_14);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_15);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_16);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_17);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_18);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_19);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_20);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_21);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_22);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_23);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_24);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_25);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_26);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_27);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_28);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_29);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_30);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_31);
  tcase_add_test(tc_s21_is_greather_or_equal, test_s21_is_greather_or_equal_32);
  suite_add_tcase(s, tc_s21_is_greather_or_equal);

  tc_s21_is_less_or_equal = tcase_create("s21_is_less_or_equal");
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_1);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_2);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_3);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_4);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_5);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_6);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_7);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_8);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_9);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_10);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_11);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_12);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_13);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_14);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_15);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_16);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_17);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_18);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_19);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_20);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_21);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_22);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_23);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_24);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_25);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_26);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_27);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_28);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_29);
  tcase_add_test(tc_s21_is_less_or_equal, test_s21_is_less_or_equal_30);
  suite_add_tcase(s, tc_s21_is_less_or_equal);

  // Main operation functions
  tc_add = tcase_create("s21_add");
  tcase_add_test(tc_add, test_transform_and_add_two_positive);
  tcase_add_test(tc_add, test_s21_add_1);
  tcase_add_test(tc_add, test_s21_add_2);
  tcase_add_test(tc_add, test_s21_add_3);
  tcase_add_test(tc_add, test_s21_add_4);
  tcase_add_test(tc_add, test_s21_add_5);
  tcase_add_test(tc_add, test_s21_add_6);
  tcase_add_test(tc_add, test_s21_add_7);
  tcase_add_test(tc_add, test_s21_add_8);
  tcase_add_test(tc_add, test_s21_add_9);
  tcase_add_test(tc_add, test_s21_add_10);
  tcase_add_test(tc_add, test_s21_add_11);
  tcase_add_test(tc_add, test_s21_add_12);
  tcase_add_test(tc_add, test_s21_add_13);
  tcase_add_test(tc_add, test_s21_add_14);
  tcase_add_test(tc_add, test_s21_add_15);
  tcase_add_test(tc_add, test_s21_add_16);
  tcase_add_test(tc_add, test_s21_add_17);
  tcase_add_test(tc_add, test_s21_add_18);
  tcase_add_test(tc_add, test_s21_add_19);
  tcase_add_test(tc_add, test_s21_add_20);
  tcase_add_test(tc_add, test_s21_add_21);
  tcase_add_test(tc_add, test_s21_add_22);
  tcase_add_test(tc_add, test_s21_add_23);
  tcase_add_test(tc_add, test_s21_add_24);
  tcase_add_test(tc_add, test_s21_add_25);
  tcase_add_test(tc_add, test_s21_add_26);
  tcase_add_test(tc_add, test_s21_add_27);
  tcase_add_test(tc_add, test_s21_add_28);
  tcase_add_test(tc_add, test_s21_add_29);
  tcase_add_test(tc_add, test_s21_add_30);
  tcase_add_test(tc_add, test_s21_add_31);
  tcase_add_test(tc_add, test_s21_add_32);
  tcase_add_test(tc_add, test_s21_add_33);
  tcase_add_test(tc_add, test_s21_add_34);
  tcase_add_test(tc_add, test_s21_add_35);
  tcase_add_test(tc_add, test_s21_add_36);
  tcase_add_test(tc_add, test_s21_add_37);
  tcase_add_test(tc_add, test_s21_add_38);
  tcase_add_test(tc_add, test_s21_add_39);
  tcase_add_test(tc_add, test_s21_add_40);
  tcase_add_test(tc_add, test_s21_add_41);

  suite_add_tcase(s, tc_add);

  tc_s21_sub = tcase_create("s21_sub");
  tcase_add_test(tc_s21_sub, test_s21_sub_1);
  tcase_add_test(tc_s21_sub, test_s21_sub_2);
  tcase_add_test(tc_s21_sub, test_s21_sub_3);
  tcase_add_test(tc_s21_sub, test_s21_sub_4);
  tcase_add_test(tc_s21_sub, test_s21_sub_5);
  tcase_add_test(tc_s21_sub, test_s21_sub_6);
  tcase_add_test(tc_s21_sub, test_s21_sub_7);
  tcase_add_test(tc_s21_sub, test_s21_sub_8);
  tcase_add_test(tc_s21_sub, test_s21_sub_9);
  tcase_add_test(tc_s21_sub, test_s21_sub_10);
  tcase_add_test(tc_s21_sub, test_s21_sub_11);
  tcase_add_test(tc_s21_sub, test_s21_sub_12);
  tcase_add_test(tc_s21_sub, test_s21_sub_13);
  tcase_add_test(tc_s21_sub, test_s21_sub_14);
  tcase_add_test(tc_s21_sub, test_s21_sub_15);
  tcase_add_test(tc_s21_sub, test_s21_sub_16);
  tcase_add_test(tc_s21_sub, test_s21_sub_17);
  tcase_add_test(tc_s21_sub, test_s21_sub_18);
  tcase_add_test(tc_s21_sub, test_s21_sub_19);
  tcase_add_test(tc_s21_sub, test_s21_sub_20);
  tcase_add_test(tc_s21_sub, test_s21_sub_21);
  tcase_add_test(tc_s21_sub, test_s21_sub_22);
  tcase_add_test(tc_s21_sub, test_s21_sub_23);
  tcase_add_test(tc_s21_sub, test_s21_sub_24);
  tcase_add_test(tc_s21_sub, test_s21_sub_25);
  tcase_add_test(tc_s21_sub, test_s21_sub_26);
  tcase_add_test(tc_s21_sub, test_s21_sub_27);
  tcase_add_test(tc_s21_sub, test_s21_sub_28);
  tcase_add_test(tc_s21_sub, test_s21_sub_29);
  tcase_add_test(tc_s21_sub, test_s21_sub_30);
  tcase_add_test(tc_s21_sub, test_s21_sub_31);
  tcase_add_test(tc_s21_sub, test_s21_sub_32);
  tcase_add_test(tc_s21_sub, test_s21_sub_33);
  tcase_add_test(tc_s21_sub, test_s21_sub_34);
  tcase_add_test(tc_s21_sub, test_s21_sub_35);
  tcase_add_test(tc_s21_sub, test_s21_sub_36);
  tcase_add_test(tc_s21_sub, test_s21_sub_37);
  tcase_add_test(tc_s21_sub, test_s21_sub_38);
  tcase_add_test(tc_s21_sub, test_s21_sub_39);
  tcase_add_test(tc_s21_sub, test_s21_sub_40);
  tcase_add_test(tc_s21_sub, test_s21_sub_41);
  tcase_add_test(tc_s21_sub, test_s21_sub_42);
  tcase_add_test(tc_s21_sub, test_s21_sub_43);
  tcase_add_test(tc_s21_sub, test_s21_sub_44);
  tcase_add_test(tc_s21_sub, test_s21_sub_45);

  suite_add_tcase(s, tc_s21_sub);

  tc_s21_from_dec_to_float = tcase_create("s21_from_dec_to_float");
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_1);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_2);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_3);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_4);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_5);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_6);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_7);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_8);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_9);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_10);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_11);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_12);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_13);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_14);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_15);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_16);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_17);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_18);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_19);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_20);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_21);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_22);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_23);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_24);
  tcase_add_test(tc_s21_from_dec_to_float, test_s21_from_dec_to_float_25);

  suite_add_tcase(s, tc_s21_from_dec_to_float);

  tc_s21_from_fl_to_dec = tcase_create("s21_from_float_to_decimal");
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_1);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_2);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_3);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_4);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_5);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_6);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_7);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_8);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_9);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_10);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_11);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_12);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_13);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_14);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_15);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_16);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_17);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_18);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_19);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_20);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_21);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_22);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_23);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_24);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_25);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_26);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_27);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_28);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_29);
  tcase_add_test(tc_s21_from_fl_to_dec, test_s21_from_fl_to_dec_30);

  suite_add_tcase(s, tc_s21_from_fl_to_dec);

  tc_s21_from_int_to_dec = tcase_create("s21_from_int_to_decimal");
  tcase_add_test(tc_s21_from_int_to_dec, test_s21_from_int_to_dec_1);
  tcase_add_test(tc_s21_from_int_to_dec, test_s21_from_int_to_dec_2);
  tcase_add_test(tc_s21_from_int_to_dec, test_s21_from_int_to_dec_3);
  tcase_add_test(tc_s21_from_int_to_dec, test_s21_from_int_to_dec_4);
  tcase_add_test(tc_s21_from_int_to_dec, test_s21_from_int_to_dec_5);
  tcase_add_test(tc_s21_from_int_to_dec, test_s21_from_int_to_dec_6);
  tcase_add_test(tc_s21_from_int_to_dec, test_s21_from_int_to_dec_7);
  tcase_add_test(tc_s21_from_int_to_dec, test_s21_from_int_to_dec_8);
  tcase_add_test(tc_s21_from_int_to_dec, test_s21_from_int_to_dec_9);
  tcase_add_test(tc_s21_from_int_to_dec, test_s21_from_int_to_dec_10);
  tcase_add_test(tc_s21_from_int_to_dec, test_s21_from_int_to_dec_11);
  tcase_add_test(tc_s21_from_int_to_dec, test_s21_from_int_to_dec_12);

  suite_add_tcase(s, tc_s21_from_int_to_dec);

  tc_s21_from_dec_to_int = tcase_create("s21_from_decimal_to_int");
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_1);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_2);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_3);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_4);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_5);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_6);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_7);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_8);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_9);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_10);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_11);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_12);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_13);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_14);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_15);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_16);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_17);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_18);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_19);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_20);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_21);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_22);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_23);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_24);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_25);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_26);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_27);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_28);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_29);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_30);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_31);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_32);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_33);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_34);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_35);
  tcase_add_test(tc_s21_from_dec_to_int, test_s21_from_dec_to_int_36);
  suite_add_tcase(s, tc_s21_from_dec_to_int);

  tc_div = tcase_create("div_function");
  tcase_add_test(tc_div, test_div_arithmetic_error_1);
  tcase_add_test(tc_div, test_div_arithmetic_error_2);
  tcase_add_test(tc_div, test_div_arithmetic_error_3);
  tcase_add_test(tc_div, test_div_arithmetic_error_4);
  tcase_add_test(tc_div, test_div_arithmetic_error_5);
  tcase_add_test(tc_div, test_div_arithmetic_error_6);
  tcase_add_test(tc_div, test_div_arithmetic_error_7);
  tcase_add_test(tc_div, test_div_arithmetic_error_8);
  tcase_add_test(tc_div, test_div_arithmetic_error_9);
  tcase_add_test(tc_div, test_div_arithmetic_error_10);
  tcase_add_test(tc_div, test_div_arithmetic_error_11);
  tcase_add_test(tc_div, test_div_arithmetic_error_12);
  tcase_add_test(tc_div, test_div_arithmetic_error_13);
  tcase_add_test(tc_div, test_div_arithmetic_error_14);
  tcase_add_test(tc_div, test_div);
  tcase_add_test(tc_div, test_div3);
  tcase_add_test(tc_div, test_div5);
  tcase_add_test(tc_div, test_div6);
  tcase_add_test(tc_div, test_div7);
  tcase_add_test(tc_div, test_div9);
  tcase_add_test(tc_div, test_div10);
  tcase_add_test(tc_div, test_div11);
  tcase_add_test(tc_div, test_div58);
  tcase_add_test(tc_div, test_div55);
  tcase_add_test(tc_div, test_div30);
  tcase_add_test(tc_div, test_div31);
  tcase_add_test(tc_div, test_div13);
  tcase_add_test(tc_div, test_div14);
  tcase_add_test(tc_div, test_div17);
  tcase_add_test(tc_div, test_div18);
  tcase_add_test(tc_div, test_div19);
  tcase_add_test(tc_div, test_div20);
  tcase_add_test(tc_div, test_div21);
  tcase_add_test(tc_div, test_div8);
  tcase_add_test(tc_div, test_div15);
  tcase_add_test(tc_div, test_div16);
  tcase_add_test(tc_div, test_div12);
  tcase_add_test(tc_div, test_div4);
  tcase_add_test(tc_div, test_div32);
  tcase_add_test(tc_div, test_div33);
  tcase_add_test(tc_div, test_div26);
  tcase_add_test(tc_div, test_div27);
  tcase_add_test(tc_div, test_div46);
  tcase_add_test(tc_div, test_div53);
  tcase_add_test(tc_div, test_div54);
  tcase_add_test(tc_div, test_div37);
  tcase_add_test(tc_div, test_div38);
  tcase_add_test(tc_div, test_div39);
  tcase_add_test(tc_div, test_div41);
  tcase_add_test(tc_div, test_div42);
  tcase_add_test(tc_div, test_div44);
  tcase_add_test(tc_div, test_div45);
  tcase_add_test(tc_div, test_div47);
  tcase_add_test(tc_div, test_div48);
  tcase_add_test(tc_div, test_div49);
  tcase_add_test(tc_div, test_div50);
  tcase_add_test(tc_div, test_div51);
  tcase_add_test(tc_div, test_div52);
  tcase_add_test(tc_div, test_div57);
  tcase_add_test(tc_div, test_div60);
  tcase_add_test(tc_div, test_div67);
  tcase_add_test(tc_div, test_div68);
  tcase_add_test(tc_div, test_div69);
  tcase_add_test(tc_div, test_div70);
  tcase_add_test(tc_div, test_div64);
  tcase_add_test(tc_div, test_div65);
  tcase_add_test(tc_div, test_div61);
  tcase_add_test(tc_div, test_div36);
  tcase_add_test(tc_div, test_div35);
  tcase_add_test(tc_div, test_div72);
  tcase_add_test(tc_div, test_div59);
  tcase_add_test(tc_div, test_div66);
  tcase_add_test(tc_div, test_div71);
  tcase_add_test(tc_div, test_div22);
  tcase_add_test(tc_div, test_div24);
  tcase_add_test(tc_div, test_div25);
  tcase_add_test(tc_div, test_div28);
  tcase_add_test(tc_div, test_div29);
  tcase_add_test(tc_div, test_div34);
  tcase_add_test(tc_div, test_div23);
  tcase_add_test(tc_div, test_div73);
  tcase_add_test(tc_div, test_div74);
  tcase_add_test(tc_div, test_div75);
  tcase_add_test(tc_div, test_div76);
  tcase_add_test(tc_div, test_div77);
  tcase_add_test(tc_div, test_div78);
  tcase_add_test(tc_div, test_div79);
  tcase_add_test(tc_div, test_div80);
  tcase_add_test(tc_div, test_div81);
  tcase_add_test(tc_div, test_div82);
  tcase_add_test(tc_div, test_div83);
  tcase_add_test(tc_div, test_div84);
  tcase_add_test(tc_div, test_div85);
  tcase_add_test(tc_div, test_div86);
  tcase_add_test(tc_div, test_div87);
  tcase_add_test(tc_div, test_div88);
  tcase_add_test(tc_div, test_div89);
  tcase_add_test(tc_div, test_div90);

  suite_add_tcase(s, tc_div);

  tc_truncate = tcase_create("truncate_function");
  tcase_add_test(tc_truncate, test_s21_truncate_1);
  tcase_add_test(tc_truncate, test_s21_truncate_2);
  tcase_add_test(tc_truncate, test_s21_truncate_3);
  tcase_add_test(tc_truncate, test_s21_truncate_4);
  tcase_add_test(tc_truncate, test_s21_truncate_5);
  tcase_add_test(tc_truncate, test_s21_truncate_6);
  tcase_add_test(tc_truncate, test_s21_truncate_7);
  tcase_add_test(tc_truncate, test_s21_truncate_8);
  tcase_add_test(tc_truncate, test_s21_truncate_9);
  tcase_add_test(tc_truncate, test_s21_truncate_10);
  tcase_add_test(tc_truncate, test_s21_truncate_11);
  tcase_add_test(tc_truncate, test_s21_truncate_12);
  tcase_add_test(tc_truncate, test_s21_truncate_13);
  tcase_add_test(tc_truncate, test_s21_truncate_14);
  tcase_add_test(tc_truncate, test_s21_truncate_15);
  tcase_add_test(tc_truncate, test_s21_truncate_16);
  tcase_add_test(tc_truncate, test_s21_truncate_17);
  tcase_add_test(tc_truncate, test_s21_truncate_18);
  suite_add_tcase(s, tc_truncate);

  tc_floor = tcase_create("floor_function");
  tcase_add_test(tc_floor, test_floor);
  tcase_add_test(tc_floor, test_floor_2);
  tcase_add_test(tc_floor, test_floor_3);
  tcase_add_test(tc_floor, test_floor_4);
  tcase_add_test(tc_floor, test_floor_5);
  tcase_add_test(tc_floor, test_floor_6);
  tcase_add_test(tc_floor, test_floor_7);
  tcase_add_test(tc_floor, test_floor_8);
  tcase_add_test(tc_floor, test_floor_9);
  tcase_add_test(tc_floor, test_floor_10);
  tcase_add_test(tc_floor, test_floor_11);
  tcase_add_test(tc_floor, test_floor_12);
  tcase_add_test(tc_floor, test_floor_13);
  tcase_add_test(tc_floor, test_floor_14);
  tcase_add_test(tc_floor, test_floor_15);
  tcase_add_test(tc_floor, test_floor_16);
  tcase_add_test(tc_floor, test_floor_17);
  tcase_add_test(tc_floor, test_floor_18);
  tcase_add_test(tc_floor, test_floor_19);
  tcase_add_test(tc_floor, test_floor_20);
  tcase_add_test(tc_floor, test_floor_21);
  tcase_add_test(tc_floor, test_floor_22);
  tcase_add_test(tc_floor, test_floor_23);
  tcase_add_test(tc_floor, test_floor_24);
  tcase_add_test(tc_floor, test_floor_25);

  suite_add_tcase(s, tc_floor);

  tc_round = tcase_create("round_function");
  tcase_add_test(tc_round, test_round);
  tcase_add_test(tc_round, test_round_2);
  tcase_add_test(tc_round, test_round_3);
  tcase_add_test(tc_round, test_round_4);
  tcase_add_test(tc_round, test_round_5);
  tcase_add_test(tc_round, test_round_6);
  tcase_add_test(tc_round, test_round_7);
  tcase_add_test(tc_round, test_round_8);
  tcase_add_test(tc_round, test_round_9);
  tcase_add_test(tc_round, test_round_10);
  tcase_add_test(tc_round, test_round_11);
  tcase_add_test(tc_round, test_round_12);
  tcase_add_test(tc_round, test_round_13);
  tcase_add_test(tc_round, test_round_14);
  tcase_add_test(tc_round, test_round_15);
  tcase_add_test(tc_round, test_round_16);
  tcase_add_test(tc_round, test_round_17);
  tcase_add_test(tc_round, test_round_18);
  tcase_add_test(tc_round, test_round_19);
  tcase_add_test(tc_round, test_round_20);
  tcase_add_test(tc_round, test_round_21);
  suite_add_tcase(s, tc_round);

  tc_negate = tcase_create("negate_function");
  tcase_add_test(tc_negate, test_negate);
  tcase_add_test(tc_negate, test_negate_2);
  tcase_add_test(tc_negate, test_negate_3);
  tcase_add_test(tc_negate, test_negate_4);
  tcase_add_test(tc_negate, test_negate_5);
  tcase_add_test(tc_negate, test_negate_6);
  tcase_add_test(tc_negate, test_negate_7);
  tcase_add_test(tc_negate, test_negate_8);
  tcase_add_test(tc_negate, test_negate_9);
  tcase_add_test(tc_negate, test_negate_10);
  tcase_add_test(tc_negate, test_negate_11);
  tcase_add_test(tc_negate, test_negate_12);
  tcase_add_test(tc_negate, test_negate_13);
  tcase_add_test(tc_negate, test_negate_14);
  tcase_add_test(tc_negate, test_negate_15);
  tcase_add_test(tc_negate, test_negate_16);
  tcase_add_test(tc_negate, test_negate_17);
  suite_add_tcase(s, tc_negate);

  return s;
}

int main() {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = s21_decimal_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
void common_test_div(s21_decimal decimal_1, s21_decimal decimal_2,
                     s21_decimal check) {
  s21_decimal result = {};
  int code = s21_div(decimal_1, decimal_2, &result);
  ck_assert_int_eq(s21_common_compare(result, check), 0);
  ck_assert_int_eq(code, ARITHMETIC_OK);
}
