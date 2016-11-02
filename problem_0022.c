// Problem 0022 @ <Project Euler>

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define MAX 6000

struct name_and_score {
    char *name;
    long long score;
};

typedef struct name_and_score nas;

int cmp(const void *a, const void *b);

int main(void) {
    clock_t start, finish;
    double  duration;
    start = clock();
    
    FILE *fp;
    fp = fopen("problem_0022_names.txt", "r");
    char c;
    char *name = NULL;
    nas list[MAX];
    int score = 0;
    int len_name = 0, len_list = 0;
    while ((c = getc(fp)) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            len_name++;
            if (len_name == 1) {
                name = (char *)malloc(sizeof(char) * 2);
                name[0] = c;
                name[1] = '\0';
            } else {
                char *temp = (char *)malloc(sizeof(char) * (len_name + 1));
                strcpy(temp, name);
                temp[len_name - 1] = c;
                temp[len_name] = '\0';
                free(name);
                name = (char *)malloc(sizeof(char) * (len_name + 1));
                strcpy(name, temp);
                free(temp);
            }
            score += c - 'A' + 1;
        }
        if (c == ',') {
            list[len_list].name = name;
            list[len_list].score = score;
            len_list++;
            len_name = 0;
            score = 0;
        }
    }
    list[len_list].name= name;
    list[len_list].score = score;
    len_list++;
    
    /*
    qsort(list, len_list, sizeof(list[0]),
        (int (*)(const void *, const void *))cmp);
    */
    qsort(list, len_list, sizeof(list[0]), cmp);
    long long result = 0;
    for (int i = 0; i < len_list; i++) {
        printf("%4d, %s, %lld\n", i + 1, list[i].name, list[i].score);
        result += list[i].score * (i + 1);
        free(list[i].name);
    }
    printf("The sum = %lld\n", result);
    

    finish = clock();
    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f seconds\n", duration);
    
    return 0;
}

int cmp(const void *a, const void *b) {
    nas *nas_a = (nas *)a;
    nas *nas_b = (nas *)b;
    return strcmp(nas_a->name, nas_b->name);
}
