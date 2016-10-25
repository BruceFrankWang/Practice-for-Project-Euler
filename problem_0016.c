// Problem 0016 @ <Project Euler>

#include <stdio.h>
#include <time.h>

#define DIGIT_MAX 512

int print_string_number(const char n[DIGIT_MAX])
{
    int i=0;
    while ('0' == n[i]) {
        i++;
    }
    for (int j=0; j<(DIGIT_MAX-1-i); j++) {
        printf("%c", n[i+j]);
    }
    return i;
}

int main(void)
{
    clock_t start, finish;
    double  duration;
    start = clock();
    
    char bigN[DIGIT_MAX];
    char x;
    int carry = 0, temp, y, result=0;
    
    for (int i=0; i<DIGIT_MAX-1; i++) {
        bigN[i] = '0';
    }
    bigN[DIGIT_MAX-2] = '2';
    
    for (int i=2; i<=1000; i++) {
        printf("2 ^ %d = ", i-1);
        print_string_number(bigN);
        printf("\n");
        for (int j=DIGIT_MAX-2; j>=0; j--) {
            /*
            if (bigN[j] == '0' && carry == 0) {
                break;
            }
            */
            x = bigN[j];
            y = carry;
            temp = (int)(bigN[j]-'0') * 2 + carry;
            if (temp > 9) {
                temp -= 10;
                carry = 1;
            } else {
                carry = 0;
            }
            bigN[j] = (char)(temp + '0');
            // printf("\t[%3d] %c * 2 + %d = %c, carry = %d\n",
            //     j, x, y, bigN[j], carry);
        }
    }
    printf("2 ^ 1000 = ");
    temp = print_string_number(bigN);
    printf("\n");
    printf("Total digits: [%d]\n", DIGIT_MAX - 1 - temp);
    
    for (int i=0; i<DIGIT_MAX-1; i++) {
        result += bigN[i]-'0';
    }
    printf("%s\n", bigN);
    
    printf("%d\n", result);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "%f seconds\n", duration );
    
    return 0;
}