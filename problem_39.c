// Problem 9 @ <Project Euler>

#include <stdio.h>
#include <time.h>

#define NUMBER 1000

int main(void)
{
    clock_t start, finish;
    double  duration;
    
    int a, b, c, p, s, p0 = 0, s0 = 0;
    
    start = clock();
    
    for (p = 25; p < NUMBER; p++) {
        s = 0;
        for (a = 1; a < p / 2; a++) {
            for (b = 1; b < p / 2; b++) {
                c = p - a - b;
                if (a*a+b*b == c*c) {
                    s += 1;
                }
            }
        }
        if (s0 < s) {
            s0 = s;
            p0 = p;
        }
    }
    
    printf("%d, %d\n", p0, s0);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    
    return 0;
}