// Problem 2 @ <Project Euler>
// A stupid algorithm.

#include <stdio.h>
#include <time.h>

#define MAX 4000000

// 递归算法，时间复杂度：O(2^n)
long long fibonacci_recursion(long long n)
{
    if (n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    return fibonacci_recursion(n-1) + fibonacci_recursion(n-2);
}

// 循环算法，时间复杂度：O(n)
long long fibonacci_loop(long long n)
{
    long f0 = 1;
    long f1 = 1;
    long f2 = 0;
    
    for (long long i = 2; i < n; i++) {
        f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
    }
    return f2;
}

int main(void)
{
    clock_t start, finish;
    double  duration;
    long long i=1, result=0, x;
    
    start = clock();
    
    while((x = fibonacci_loop(i)) < MAX) {
        if (x % 2 == 0) {
            result += x;
        }
        i++;
    }
    printf("%lld\n", result);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    
    return 0;
}