// Problem 0004 @ <Project Euler>
// A stupid algorithm

#include <stdio.h>
#include <time.h>
#include <string.h>

char* lltoa(long long val, int base){

    static char buf[64] = {0};

    int i = 62;
    int sign = (val < 0);
    if(sign) val = -val;

    if(val == 0) return "0";

    for(; val && i ; --i, val /= base) {
        buf[i] = "0123456789abcdef"[val % base];
    }

    if(sign) {
        buf[i--] = '-';
    }
    return &buf[i+1];
}

int is_palindromic(const long n)
{
    // 999 * 999 = 998001, 6-digit
    char* s;
    int l, k;
    
    s = lltoa(n, 10);
    l = strlen(s);
    if (l % 2 == 0) {
        k = l / 2;
    } else {
        k = (l - 1) / 2;
    }
    for (int i=0; i<k; i++) {
        // printf("s[%d]=%c, s[%d-%d-1]=%c\n", i, s[i], l, i, s[l-i-1]);
        if (s[i] != s[l-i-1]) {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    clock_t start, finish;
    double  duration;
    long result = 0, x;
    
    start = clock();
    
    for (int a=100; a<=999; a++) {
        for (int b=100; b<=999; b++) {
            x = a*b;
            if (is_palindromic(x) != 0 && result < x) {
                result = x;
            }
        }
    }
    printf("%ld\n", result);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    
    return 0;
}