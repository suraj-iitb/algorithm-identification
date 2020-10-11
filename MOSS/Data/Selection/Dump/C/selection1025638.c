#include <stdio.h>

void swap(int* a, int* b);

int main(void)
{
    int i, j;

    int length;
    scanf("%d", &length);

    int line[100];

    for (i = 0; i < length; i++) {
        scanf("%d", &line[i]);
    }

    int min;
    int swap_cnt = 0;
    for (i = 0; i < length; i++) {
        min = i;
        for (j = i; j < length; j++) {
            if (line[j] < line[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(&line[i], &line[min]);
            swap_cnt++;
        }
    }

    for (i = 0; i < length; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", line[i]);
    }
    printf("\n");

    printf("%d\n", swap_cnt);

    return 0;
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
