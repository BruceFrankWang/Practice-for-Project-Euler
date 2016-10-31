/*
 * Arithmetic calculations and utilities for big numbers (larger than %lld)
 * with char array.
 * Support positive integer only.
 *
 * 极大数（比 long long 大）算术计算及工具，使用字符数组。
 *
 *
 * file:   bignumber.c
 * Author: Bruce Frank Wang
 * Date:   Oct 29, 2016
 */
 
#include "bignumber.h"

size_t getDigit(long long n) {
    return snprintf(NULL, 0, "%lld", n);
}

char *bnFromInteger(long long n) {
    // Integer to String.
    size_t length = getDigit(n);
    char *bn = (char *)malloc(length + 1);
    snprintf(bn, length + 1, "%lld", n);
    return bn;
}

char *bnRemovePrefixZero(const char *bn) {
    // Remove one or many prefix zero of a big
    // number(in a char array).
    // printf("\n");
    long long iPrefix = 0;
    while (bn[iPrefix] == '0') {
        iPrefix++;
    }
    size_t len_old = strlen(bn);
    size_t len_new = len_old - iPrefix + 1;
    // printf("len_old = %zu, len_new = %zu\n", len_old, len_new);
    char *result = (char *)malloc(sizeof(char) * len_new);
    for (size_t i = iPrefix, j = 0; i < len_old; i++, j++) {
        result[j] = bn[i];
        // printf("i = %zu, j = %zu, %c\n", i, j, result[j]);
    }
    result[len_new-1] = '\0';
    return result;
}

void bnPrint(const char *bn, const int printPrefixZero) {
    // Print a big number(in a char array).
    int prefix = 0;
    if (printPrefixZero == 0) {
        while (bn[prefix] == '0') {
            prefix++;
        }
    }
    for (int i = prefix; i < strlen(bn); i++) {
        printf("%c", bn[i]);
    }
}

char *bnAdd(const char *a, const char *b) {
    // Addition for big numbers.
    int carry = 0;
    long long i, j, k;
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);
    size_t len_sum = (len_a > len_b ? len_a : len_b) + 1;
    char *sum = (char *)malloc(sizeof(char) * (len_sum + 1));
    
    // fill sum with '0'.
    for (i=0; i<len_sum; i++) {
        sum[i] = '0';
    }
    sum[len_sum] = '\0';
    
    // calculate.
    for (i=len_a-1, j=len_b-1, k=len_sum-1; i>=0 || j>=0; i--, j--, k--) {
        if (i >= 0 && j >= 0) {
            sum[k] = a[i] + b[j] - '0' + carry;
            // printf("%c + %c + %d = ", a[i], b[j], carry);
        }
        if (i >= 0 && j < 0) {
            sum[k] = a[i] + carry;
            // printf("%c + %d = ", a[i], carry);
        }
        if (i < 0 && j >= 0) {
            sum[k] = b[j] + carry;
            // printf("%c + %d = ", b[j], carry);
        }
        if (sum[k] > '9') {
            sum[k] = sum[k] - 10;
            carry = 1;
        } else {
            carry = 0;
        }
        // printf("%c, carry = %d\n", sum[k], carry);
        // printf("%s\n", sum);
    }
    if (carry != 0) {
        sum[k] = (char)(carry + '0');
    }
    char *result = NULL;
    result = bnRemovePrefixZero(sum);
    free(sum);
    return result;
}

char *bnMultiply(const char *a, const char *b) {
    // Multiplication for big numbers.
    size_t len_a = strlen(a);
    size_t len_b  = strlen(b);
    size_t len_p = len_a + len_b;
    long i, j, k, z;
    int temp = 0, carry = 0;
    char *product = NULL;
    
    // printf("[PROBLEM] %s * %s = ?\n", a, b);
    
    /*
    if (result != NULL) {
        free(result);
    }
    */
    
    product = malloc(sizeof(char)*(len_p + 1));
    for (size_t i = 0; i < len_p; i++) {
        product[i] = '0';
    }
    product[len_p] = '\0';
    
    // printf("length of A = %lu, B = %lu, of C= %lu\n", len_a, len_b, len_r+1);
    // printf("C is %s\n", result);
    // printf("[STEP Ai.Bj]\tA * B + O + C = T\n");
    
    // i: index of a;
    // j: index of b;
    // k: index of product;
    // z: digit;
    for (i = len_a-1, z = 0; i >= 0; i--, z++) {
        for (j = len_b-1, k = len_p-1-z; j >= 0; j--, k--) {
            // printf("[STEP %2ld.%2ld]\t", i, j);
            if (i >= 0 && j >= 0) {
                temp = product[k]-'0' + (a[i]-'0') * (b[j]-'0') + carry;
                // printf("%c * %c + %c + %d = %d\t",
                //       a[i], b[j], product[k], carry, temp);
                if (temp > 9) {
                    product[k] = (char)(temp % 10 + '0');
                    carry = temp / 10;
                } else {
                    product[k] = (char)(temp + '0');
                    carry = 0;
                }
            }
            // printf("XXX = %s, carry = %d\n", product, carry);
        }
        if (carry != 0) {
            product[k] = (char)(carry + '0');
            carry = 0;
        }
    }
    if (carry != 0) {
        product[k] = (char)(carry + '0');
    }
    // printf("Result = %s, address of result = %p\n", product, &product);
    char *result = NULL;
    result = bnRemovePrefixZero(product);
    free(product);
    return result;
}

char *bnFactorial(long long n) {
    if (n < 0) {
        return "ValueError";
    }
    if (n == 0 || n == 1) {
        return bnFromInteger(1);
    }
    char *a = NULL, *b = NULL, *result = NULL;
    for (long long i = 2; i <= n; i++) {
        if (i == 2) {
            a = bnFromInteger(1);
        } else {
            a = (char *)malloc(sizeof(char) * (strlen(result) + 1));
            strcpy(a, result);
            free(result);
        }
        b = bnFromInteger(i);
        result = bnMultiply(a, b);
        // printf("%s * %s = %s\n", a, b, result);
        free(a);
        free(b);
        // free(temp);
    }
    return result;
}
