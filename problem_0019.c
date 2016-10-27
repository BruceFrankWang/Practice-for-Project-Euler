// Problem 0014 @ <Project Euler>

#include <stdio.h>
#include <time.h>
#include<stdlib.h>

#define BEGIN 1900
#define END 2000

int main(void)
{
    clock_t start, finish;
    double  duration;
    
    start = clock();
    
    // Insert code below.
    int days_of_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    int result = 0;
    int weekday = 1;
    long days = 1;
    
    for (int year=BEGIN; year<=END; year++) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            days_of_month[1] = 29;
        } else {
            days_of_month[1] = 28;
        }
        for (int month=0; month<12; month++) {
            if (year == BEGIN && month == 0) {
                weekday = (int)days % 7;
            } else {
                if (month == 0) {
                    days += days_of_month[11];
                } else {
                    days += days_of_month[month-1];
                }
            }
            weekday = (int)days % 7;
            if (weekday == 0 && year != BEGIN) {
                result += 1;
            }
            printf("%4d-%02d-01 weekday = %d\n", year, month + 1, weekday);
        }
    }
            
    printf("%d\n", result);
    
    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf( "Run in %f seconds\n", duration );
    
    return 0;
}