// Problem 0021 @ <Project Euler>

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "bignumber.h"

#define NUMBER 10000

struct divisor_table_node {
    int divisor;
    struct divisor_table_node *next;
};

typedef struct divisor_table_node dtn;
typedef dtn *dt;

int isAmicableNumbers(int a, int b);
long long getSumOfDivisors(long long n);
dt getDivisor(long long n, int prime);

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

int isAmicableNumbers(int a, int b) {
    if (getSumOfDivisors(a) == b && getSumOfDivisors(b) == a) {
        return 1;
    } else {
        return 0;
    }
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

dt getDivisor(long long n, int prime) {
    dt result = (dt)malloc(sizeof(dtn));
    dt pt;
    result->divisor = 0;
    result->next = NULL;
    pt = result->next;
    for (long long i=1; i<=(n/2); i++) {
        if (n % i == 0) {
            dt node = (dt)malloc(sizeof(dtn));
            node->divisor = i;
            node->next = NULL;
            pt->next = node;
        }
    }
    return result;
}
