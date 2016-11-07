// Problem 0004 @ <Project Euler>
// A stupid algorithm

#include <stdio.h>
#include <time.h>
#include <string.h>

#include "pelib.h"

#define MIN 100
#define MAX 999

int main(void)
{
    clock_t start, finish;
    double  duration;
    start = clock();
    
    long result = 0, x;
    char *temp = NULL;
    
    for (int a = MIN; a <= MAX; a++) {
        for (int b = MIN; b <= MAX; b++) {
            x = a*b;
            temp = bnFromIntegerWithBase(x, 10);
            if (isPalindromeString(temp) != 0 && result < x) {
                result = x;
            }
            free(temp);
        }
    }
    printf("%ld\n", result);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    
    return 0;
}