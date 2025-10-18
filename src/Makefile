TEST = all_tests
CC = gcc
CFlags = -std=c11 -Wall -Wextra -Werror 
TESTS_FLAGS = -lcheck -Wno-format-security
TESTS_EXEC = s21_decimal_test
TESTS_SRC = test_s21_decimal.c s21_decimal.c
OS := $(shell uname -s)

ifeq ($(OS), Darwin)
	TESTS_FLAGS +=
else
	TESTS_FLAGS += -lm -lsubunit
endif

all: gcov_report

gcov_report:
	$(MAKE) clean
	COVERAGE=1 $(MAKE) test
	lcov -t "$(TEST)" -o $(TEST).info -c -d .
	genhtml -o report $(TEST).info

test: s21_decimal.a test_s21_decimal.o
	$(CC) -o $(TESTS_EXEC) test_s21_decimal.o s21_decimal.a $(TESTS_FLAGS) $(if $(COVERAGE),--coverage,)
	./$(TESTS_EXEC)

test_s21_decimal.o: test_s21_decimal.c test_s21_decimal.h
	$(CC) -c $(TESTS_FLAGS) $(if $(COVERAGE),--coverage,) test_s21_decimal.c

s21_decimal.a: dec_helpers.o s21_decimal.o
	ar crs s21_decimal.a s21_decimal.o dec_helpers.o
	ranlib s21_decimal.a

s21_decimal.o: s21_decimal.c s21_decimal.h
	$(CC) -c $(CFlags) $(if $(COVERAGE),--coverage,) s21_decimal.c -o s21_decimal.o

dec_helpers.o: dec_helpers.c dec_helpers.h
	$(CC) -c $(CFlags) dec_helpers.c -o dec_helpers.o

clean:
	rm -f *.o *.a *.gcda *.gcno *.info
	rm -f $(TESTS_EXEC)
	rm -rf report

clang:
	clang-format-18 -i *.c *.h

.PHONY: all test clean gcov_report clang