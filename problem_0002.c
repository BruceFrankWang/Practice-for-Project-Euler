// Problem 2 @ <Project Euler>
// A stupid algorithm.

#include <stdio.h>
#include <time.h>

#define MAX 4000000

long fibonacci(long n)
{
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(void)
{
    clock_t start, finish;
    double  duration;
    long i=1, result=0, x;
    
    start = clock();
    
    while((x = fibonacci(i)) < MAX) {
        if (i % 2 == 0) {
            result += i;
        }
    }
    printf("%ld\n", result);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    
    return 0;
}