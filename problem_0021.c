// Problem 0021 @ <Project Euler>

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "bignumber.h"

#define NUMBER 10000

long long getSumOfDivisors(long long n);

int main(void) {
    clock_t start, finish;
    double  duration;
    start = clock();
    
    long long result = 0, a = 0, b = 0, sum1 = 0, sum2 = 0;
    for (long long a = 1; a< NUMBER; a++) {
        sum1 = getSumOfDivisors(a);
        // printf("\ta=%lld, sum1=%lld, ", a, sum1);
        if (sum1 == 1) {
            // printf("\tCONTINUE\n");
            continue;
        }
        b = sum1;
        sum2 = getSumOfDivisors(b);
        // printf("\tb=%lld, sum2=%lld\n", b, sum2);
        if (sum2 == a && a != b) {
            result += (a + b);
            printf("%lld and %lld\n", a, b);
        }
    }
    printf("The sum is: %lld\n", result/2);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", duration);
    
    return 0;
}

long long getSumOfDivisors(long long n) {
    long long sum = 0;
    for (long long i=1; i<=(n/2+1); i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}
