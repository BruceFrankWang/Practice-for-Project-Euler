// Problem 0006 @ <Project Euler>

#include <stdio.h>
#include <time.h>

#define NUMBER 100

int main(void)
{
    clock_t start, finish;
    double  duration;
    
    int i=1;
    long sum1, sum2;
    
    start = clock();
    
    sum1 = sum2 = 0;
    for (int i=1; i <= NUMBER; i++) {
        sum1 += i*i;
        sum2 += i;
        //printf("[%3d]: sum1=%ld, sum2=%ld\n", i, sum1, sum2);
    }
    sum2 *= sum2;
    
    //printf("%ld-%ld=%ld\n", sum2, sum1, sum2 - sum1);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    
    return 0;
}