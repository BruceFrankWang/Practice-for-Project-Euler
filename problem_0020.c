// Problem 0020 @ <Project Euler>

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "bignumber.h"

#define NUMBER 100

int main(void)
{
    clock_t start, finish;
    double  duration;
    start = clock();
    
    char *factorial = NULL;
    char *sum = NULL;
    char *a = NULL, *b = NULL;
    factorial = bnFactorial(100);
    printf("100! = %s\n", factorial);
    for (long long i=1; i<strlen(factorial); i++) {
        if (i == 1) {
            a = (char *)malloc(sizeof(char) * 2);
            // strcpy(a, &factorial[0]);
            a[0] = factorial[0];
            a[1] = '\0';
        } else {
            a = (char *)malloc(sizeof(char) * (strlen(sum) + 1));
            strcpy(a, sum);
            free(sum);
        }
        b = (char *)malloc(sizeof(char) * 2);
        b[0] = factorial[i];
        b[1] = '\0';
        // strcpy(b, &factorial[i]);
        // printf("%lu\n", strlen(b));
        sum = bnAdd(a, b);
        printf("a + b = %s + %s = %s\n", a, b, sum);
        free(a);
        free(b);
    }
    free(factorial);
    printf("The sum is: %s\n", sum);
    free(sum);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", duration);
    
    return 0;
}
