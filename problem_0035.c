// Problem 0036 @ <Project Euler>

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "pelib.h"

#define MAX 1000000

char *ratateString(const char *src, unsigned int times);

int main(void) {
    clock_t start, finish;
    double  duration;
    start = clock();
    
    long long m = 0;
    int count = 0, digit, d;
    char *oldString = NULL, *newString = NULL;
    int isCircularPrime = 0;
    
    for (long n=2; n< MAX; n++) {
        printf("\rTesting: %ld", n);
        isCircularPrime = 1;
        digit = getDigit(n);
        d = 0;
        while (d < digit) {
            oldString = bnFromInteger(n);
            newString = ratateString(oldString, d);
            m = atoll(newString);
            free(oldString);
            free(newString);
            if (isPrime(m) != 1) {
                isCircularPrime = 0;
                break;
            }
            // printf("\t%lld is prime, ", m);
            d++;
        }
        if (isCircularPrime == 1) {
            printf("\rCircular prime: %ld\n", n);
            count++;
        }
    }
    printf("\rThe count is: %d\n", count);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", duration);
    
    return 0;
}

char *ratateString(const char *src, unsigned int times) {
    // 旋转字符串。"123"->"231"
    int i, j;
    size_t len = strlen(src);
    if (times >= len) {
        times = times % len;
    }
    char *new = (char *)malloc(sizeof(char) * (len + 1));
    if (times == 0) {
        return strcpy(new, src);
    }
    for (i=0; i<len-times; i++) {
        new[i] = src[i+times];
    }
    for (j=0; j<times; j++) {
        new[i+j] = src[j];
    }
    new[len] = '\0';
    return new;
}
