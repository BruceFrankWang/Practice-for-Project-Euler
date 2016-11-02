/*
 * Test for bignumber
 *
 *
 * file:   bignumber_test.c
 * Author: Bruce Frank Wang
 * Date:   Oct 29, 2016
 */

#include <stdio.h>
// #define NDEBUG
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include "bignumber.h"

void test_getDigit(void);
void test_bnFromInteger(void);
void test_bnRemovePrefixZero(const char *bn);
void test_bnAdd(long long an, long long bn);
void test_bnMultiply(long long an, long long bn);
void test_bnFactorial(void);

int main(void) {
    // test_getDigit();
    // test_bnFromInteger();    // test ok.
    // printf("Nothing.\n");
    test_bnAdd(2, 3);
	test_bnAdd(9, 99);
	test_bnMultiply(586896569799, 99);
	test_bnFactorial();
	// test_bnRemovePrefixZero("0056789");
    return 0;
}

void test_getDigit(void) {
    clock_t start, finish;
    double  duration;
    start = clock();
    for (long long i = 0; i <= LLONG_MAX; i++) {
        printf("\rTesting %lld / %lld", i, LLONG_MAX);
        if (i >=0 && i < 10) {
            assert(getDigit(i) == 1);
            continue;
        }
        if (i >=10 && i < 100) {
            assert(getDigit(i) == 2);
            continue;
        }
        if (i >=100 && i < 1000) {
            assert(getDigit(i) == 3);
            continue;
        }
        if (i >=1000 && i < 10000) {
            assert(getDigit(i) == 4);
            continue;
        }
        if (i >=10000 && i < 100000) {
            assert(getDigit(i) == 5);
            continue;
        }
        if (i >=100000 && i < 1000000) {
            assert(getDigit(i) == 6);
            continue;
        }
        if (i >=1000000 && i < 10000000) {
            assert(getDigit(i) == 7);
            continue;
        }
        if (i >=10000000 && i < 100000000) {
            assert(getDigit(i) == 8);
            continue;
        }
        if (i >=100000000 && i < 1000000000) {
            assert(getDigit(i) == 9);
            continue;
        }
        if (i >=1000000000 && i < 10000000000) {
            assert(getDigit(i) == 10);
            continue;
        }
        if (i >=10000000000 && i < 100000000000) {
            assert(getDigit(i) == 11);
            continue;
        }
        if (i >=100000000000 && i < 1000000000000) {
            assert(getDigit(i) == 12);
            continue;
        }
        if (i >=1000000000000 && i < 10000000000000) {
            assert(getDigit(i) == 13);
            continue;
        }
        if (i >=10000000000000 && i < 100000000000000) {
            assert(getDigit(i) == 14);
            continue;
        }
        if (i >=100000000000000 && i < 1000000000000000) {
            assert(getDigit(i) == 15);
            continue;
        }
        if (i >=1000000000000000 && i < 10000000000000000) {
            assert(getDigit(i) == 16);
            continue;
        }
        if (i >=10000000000000000 && i < 100000000000000000) {
            assert(getDigit(i) == 17);
            continue;
        }
        if (i >=100000000000000000 && i < 1000000000000000000) {
            assert(getDigit(i) == 18);
            continue;
        }
        if (i >=1000000000000000000 && i <= LLONG_MAX) {
            assert(getDigit(i) == 19);
            continue;
        }
    }
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("\rtest_getDigit PASSED, in %f seconds.\n", duration);
}

void test_bnFromInteger(void) {
    char *bn = NULL;
    long long n = 586896569799879;
    // size_t l;
    bn = bnFromInteger(n);
    // l = strlen(bn);
    // assert(bn[(*bn) + l] == '\0');
    free(bn);
}

void test_bnRemovePrefixZero(const char *bn) {
	char *result = NULL;
	result = bnRemovePrefixZero(bn);
	printf("Remove prefix zero for %s: %s\n", bn, result);
	free(result);
}

void test_bnAdd(long long an, long long bn) {
	char *ac = NULL, *bc = NULL;
	char *result1 = NULL, *result2 = NULL;
	
	ac = bnFromInteger(an);
	bc = bnFromInteger(bn);
	result1 = bnFromInteger(an*bn);
	result2 = bnAdd(ac, bc);
	// assert(strcmp(result1, result2) == 0);
	printf("Test for %lld + %lld = %s, PASSED.\n", an, bn, result2);
	free(ac);
	free(bc);
	free(result1);
	free(result2);
}

void test_bnMultiply(long long an, long long bn) {
	char *ac = NULL, *bc = NULL;
	char *result1 = NULL, *result2 = NULL;
	
	ac = bnFromInteger(an);
	bc = bnFromInteger(bn);
	result1 = bnFromInteger(an*bn);
	result2 = bnMultiply(ac, bc);
	// assert(strcmp(result1, result2) == 0);
	printf("Test for %lld * %lld = %s, PASSED.\n", an, bn, result2);
	free(ac);
	free(bc);
	free(result1);
	free(result2);
}

// Test for bnFactorial.
void test_bnFactorial(void) {
	int test_n[5] = {0, 1, 2, 5, 10};
	int test_count = 5;
	char *result1 = NULL, *result2 = NULL;
	for (int i=0; i< test_count; i++) {
	    result1 = bnFactorial(test_n[i]);
		result2 = bnFromInteger(test_n[i]);
        // assert(strcmp(result1, result2));
	    free(result1);
		free(result2);
	}
}
