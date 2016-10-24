// Problem 9 @ <Project Euler>

#include <stdio.h>
#include <time.h>

#define NUMBER 1000

int main(void)
{
    clock_t start, finish;
    double  duration;
    
    int a, b, c;
    long result=0;
    
    start = clock();
    
    for (a = 1; a < NUMBER / 2; a++) {
        for (b = 1; b < NUMBER / 2; b++) {
            c = NUMBER - a - b;
            if ((a*a+b*b == c*c) && (result < a * b * c)) {
                result = a * b * c;
            }
        }
    }
    
    printf("%ld\n", result);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    
    return 0;
}