// Problem 0036 @ <Project Euler>

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "bignumber.h"

#define MAX 1000000

int isPalindrome(const char *src);
char *trim_double(const char *src, size_t from, size_t to);
char *trim_single(const char *src, int remove);

int main(void) {
    clock_t start, finish;
    double  duration;
    start = clock();
    
    long long sum = 0;
    int count = 0, len;
    char *bn = NULL, *temp = NULL;
    int isTruncatablePrime;
    
    for (long n=1; n< MAX; n++) {
        printf("\rTesting: %ld", n);
        bn = bnFromInteger(n);
        if (isPalindrome(bn) != 1) {
            continue;
        }
        bn = bnFromIntegerWithBase(n, 2);
        if (isPalindrome(bn) != 1) {
            continue;
        }
        sum += n;
        printf("\rDouble-base palindrome: %ld\n", n);
    }
    printf("The sum is: %lld\n", sum);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", duration);
    
    return 0;
}

int isPalindrome(const char *src) {
    size_t len = strlen(src);
    if (len == 0) {
        return 0;
    }
    char *temp = (char *)malloc(sizeof(char) * (len + 1));
    for (size_t i = 0, j = len-1; i < len; i++, j--) {
        temp[i] = src[j];
    }
    temp[len] = '\0';
    if (strcmp(src, temp) == 0) {
        return 1;
    } else {
        return 0;
    }
}

char *trim_double(const char *src, size_t trim_left, size_t trim_right) {
    size_t len = strlen(src);
    if (trim_left >= len || trim_left > trim_right) {
        return NULL;
    }
    if (trim_right >= len) {
        trim_right = len - 1;
    }
    size_t l = trim_right - trim_left + 1;
    size_t i, j;
    char *dest = (char *)malloc(sizeof(char) * (l + 1));
    int z = sizeof(dest)/sizeof(char);
    for(i=trim_left, j=0; i<=trim_right; i++, j++) {
        dest[j] = src[i];
    }
    dest[l] = '\0';
    return dest;
}

char *trim_single(const char *src, int remove) {
    size_t len = strlen(src);
    if ((remove > 0 && remove >= len) || (remove < 0 && remove <= -len)) {
        return NULL;
    }
    if (remove == 0) {
        return trim_double(src, 0, len-1);
    }
    if (remove > 0) {
        return trim_double(src, remove, len-1);
    }
    if (remove < 0) {
        return trim_double(src, 0, len-1 + remove);
    }
    return NULL;
}
