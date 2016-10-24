#include <stdio.h>
#include <stdlib.h>

#define MAX_PRIME_COUNT 8

// Prime(less than 20)
const int p20[MAX_PRIME_COUNT] = {2, 3, 5, 7, 11, 13, 17, 19};

// Struct for Prime(less than 40) and its count.
struct prime_count {
    int prime;
    int power;
};

typedef struct prime_count pct;

// prime factor
int get_prime_factor2(const int n, pct p[])
{
    if (n < 2) {
        return 1;
    }
    int m = n;
    for (int i = 2; i <= m; i++) {
        while (m != i) {
            if ( m % i == 0) {
                m = m / i;
                for (int j=0; j<MAX_PRIME_COUNT; j++) {
                    if (p[j].prime == i) {
                        p[j].power++;
                    }
                }
            } else {
                break;
            }
        }
    }
    for (int j=0; j<MAX_PRIME_COUNT; j++) {
        if (p[j].prime == m) {
            p[j].power++;
        }
    }
    return 0;
}

int main(void)
{
    pct pct20[MAX_PRIME_COUNT], result[MAX_PRIME_COUNT];
    int n = 20;
    
    for (int i=0; i<12; i++) {
        result[i].prime = p20[i];
        result[i].power = 0;
    }
    
    for (int i=2; i<=n; i++) {
        for (int i=0; i<MAX_PRIME_COUNT; i++) {
            pct20[i].prime = p20[i];
            pct20[i].power = 0;
        }
        
        get_prime_factor2(i, pct20);
        
        for (int i=0; i<MAX_PRIME_COUNT; i++) {
            if (pct20[i].power > result[i].power) {
                result[i].power = pct20[i].power;
            }
        }
    }
    
    long m =1;
    for (int i=0; i<MAX_PRIME_COUNT; i++) {
        if (result[i].power != 0) {
            for (int j=1; j<=result[i].power; j++) {
                m *= result[i].prime;
            }
        }
    }
    printf("\n%ld\n", m);
    
    return 0;
}