// Problem 0007 @ <Project Euler>

#include <stdio.h>
#include <time.h>
#include <math.h>

#define NUMBER 10001

int is_prime(long n)
{
    for (long i=2; i<((long)sqrt(n)+1); i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    clock_t start, finish;
    double  duration;
    
    int index=0;
    long p=1;
    
    start = clock();
    
    while(index<NUMBER) {
        p++;
        if (is_prime(p) == 1) {
            index++;
        }
    }
    
    printf("%ld\n", p);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    
    return 0;
}