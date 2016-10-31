// Problem 0013 @ <Project Euler>

#include <stdio.h>
#include <time.h>
#include<stdlib.h>

#define MAX 28124

long long getSumOfDivisors(int n);

int main(void)
{
    clock_t start, finish;
    double  duration;
    start = clock();
    
    int abundant[MAX];  // is an abundant
    int number[MAX];
    long long sum = 0;
    int i, j;
    
    for (i=0; i<MAX; i++) {
        abundant[i] = 0;
        number[i] = 0;
    }
    for (i=12; i<MAX; i++) {
        if (getSumOfDivisors(i) > i) {
            abundant[i] = 1;
        }
    }
    for (i=12; i<MAX; i++) {
        for (j=12; j<MAX; j++) {
            if (abundant[i] == 1 && abundant[j] == 1 && (i + j < MAX)) {
                number[i+j] = 1;
            }
        }
    }
    for (i=1; i<MAX; i++) {
        if (number[i] == 0) {
            printf("%d cannot be written as the sum of two abundant numbers.\n",
                i);
        }
        if (number[i] == 0) {
            sum += i;
        }
    }
    
    printf("%lld\n", sum);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    
    return 0;
}

long long getSumOfDivisors(int n) {
    long long sum = 0;
    for (long long i=1; i<=(n/2+1); i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}
