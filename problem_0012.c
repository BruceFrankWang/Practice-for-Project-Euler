// Problem 0012 @ <Project Euler>

#include <stdio.h>
#include <time.h>

int main(void)
{
    clock_t start, finish;
    double  duration;
    
    int d_max = 0, d = 0, first;
    long n = 0, tn = 0;
    
    start = clock();
    
    while (d <= 500) {
        tn += ++n;
        d = 0;
        // first = 1;
        // printf("n= %ld, tn= %ld\n", n, tn);
        for (long i=1; i<tn/2; i++) {
            if (tn%i==0) {
                d++;
                // if (first) {
                //     printf("\t{%ld", i);
                //     first = 0;
                // } else {
                //     printf(", %ld", i);
                // }
            }
        }
        // printf("}\n");
        // printf("\tTotal factors: %d\n", d);
        if (d_max < d) {
            d_max = d;
        }
    }
    
    printf("%ld\n", tn);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    
    return 0;
}