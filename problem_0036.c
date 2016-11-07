// Problem 0036 @ <Project Euler>

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#include "pelib.h"

#define MAX 1000000

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
    printf("\rThe sum is: %lld\n", sum);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", duration);
    
    return 0;
}
