// Problem 0040 @ <Project Euler>

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "bignumber.h"

#define MAX 1100000
#define LIMIT 1000000

char fraction[MAX];

int main(void)
{
    clock_t start, finish;
    double  duration;
    start = clock();
    
    char fraction[MAX];
    long n = 1;
    size_t digit = 0;
    char *bn = NULL;
    
    fraction[0] = '\0';
    while (digit < LIMIT) {
        bn = bnFromInteger(n);
        strcat(fraction, bn);
        free(bn);
        n++;
        digit = strlen(fraction);
        // printf("n=%ld, digit=%zu, fraction=%s\n", n, digit, fraction);
    }
    
    printf("The fraction = 0.%s, digit = %zu, and n = %ld\n",
        fraction, digit, n);
    long long product = 1;
    for(long i=1; i<=LIMIT; i*=10) {
        product *= (int)(fraction[i - 1] - '0');
        printf("\tThe %7ldth digit = %c, product = %lld\n",
            i, fraction[i-1], product);
    }
    printf("The product is: %lld\n", product);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    
    return 0;
}
