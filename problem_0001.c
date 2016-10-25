// Problem 0001 @ <Project Euler>

#include <stdio.h>
#include <time.h>

int main(void)
{
    clock_t start, finish;
    double  duration;
    int result = 0;
    
    start = clock();
    
    for (int i=1; i<1000; i++) {
        if (i % 3 == 0) {
            result += i;
        }
        if (i % 5 == 0) {
            result += i;
        }
        if (i % 15 == 0) {
            result -= i;
        }
    }
    printf("%d\n", result);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    
    return 0;
}