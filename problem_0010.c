// Problem 0010 @ <Project Euler>

#include <stdio.h>
#include <time.h>
#include <math.h>

#define NUMBER 2000000


int is_prime(const long n)
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
    
    start = clock();
    
    long sum = 0;;
    
    for (long i=2; i<NUMBER; i++) {
        if (is_prime(i) == 1) {
            sum += i;
        }
    }
    
    printf("%ld\n", sum);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    
    return 0;
}