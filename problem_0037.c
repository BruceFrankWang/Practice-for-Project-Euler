// Problem 0037 @ <Project Euler>

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "bignumber.h"

#define NUMBER 10000

int is_prime(const long long n);
char *trim_double(const char *src, size_t from, size_t to);
char *trim_single(const char *src, int remove);

int main(void) {
    clock_t start, finish;
    double  duration;
    start = clock();
    
    long long sum = 0, n = 10;
    int count = 0, len;
    char *bn = NULL, *temp = NULL;
    int isTruncatablePrime;
    
    while (count < 11) {
        printf("\rTesting: %lld", n);
        if (is_prime(n) == 1) {
            bn = bnFromInteger(n);
            len = strlen(bn);
            isTruncatablePrime = 1;
            for (int i = 0; i < len; i++) {
                temp = trim_single(bn, i);
                if (is_prime(atoll(temp)) != 1) {
                    isTruncatablePrime = 0;
                    break;
                }
                temp = trim_single(bn, -i);
                if (is_prime(atoll(temp)) != 1) {
                    isTruncatablePrime = 0;
                    break;
                }
            }
            if (isTruncatablePrime) {
                printf("\rTruncatable prime: %lld\n", n);
                sum += n;
                count++;
            }
        }
        n++;
    }
    printf("The sum is: %lld\n", sum);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", duration);
    
    return 0;
}

int is_prime(const long long n) {
    if (n < 2) {
        return 0;
    }
    for (long long i=2; i<((long long)sqrt(n)+1); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
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
