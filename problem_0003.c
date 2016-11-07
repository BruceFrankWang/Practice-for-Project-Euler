// Problem 0003 @ <Project Euler>

#include <stdio.h>
#include <time.h>
#include <math.h>

#include "pelib.h"

#define NUMBER 600851475143

int main(void)
{
    clock_t start, finish;
    double  duration;
    start = clock();
    
    long i=1, result=0, x;
    
    for (long i=2; i < ((long)sqrt(NUMBER)+1); i++) {
        if (isPrime(i) == 1 && NUMBER % i == 0) {
            x = NUMBER;
            while (x != i) {
                if (x % i == 0) {
                    x = x / i;
                    if (result < i) {
                        result = i;
                    }
                } else {
                    break;
                }
            }
        }
        
    }
    printf("%ld\n", result);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    
    return 0;
}
