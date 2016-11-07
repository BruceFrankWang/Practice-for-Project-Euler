// Problem 2 @ <Project Euler>

#include <stdio.h>
#include <time.h>

#include "pelib.h"

#define MAX 4000000


int main(void)
{
    clock_t start, finish;
    double  duration;
    long long i=1, result=0, x;
    
    start = clock();
    
    while((x = getFibonacciByLoop(i)) < MAX) {
        if (x % 2 == 0) {
            result += x;
        }
        i++;
    }
    printf("%lld\n", result);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    
    return 0;
}