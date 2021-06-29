#include <stdio.h>

void swap(int* a, int* b);

int main(void)
{
    int i, j, k;
    int len;
    scanf("%d", &len);
    int line[100];

    for (i = 0; i < len; i++) {
        scanf("%d", &line[i]);
    }

    int min;
    int swap_c = 0;
    for (i = 0; i < len; i++) {
        min = i;
        for (j = i; j < len; j++) {
            if (line[j] < line[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(&line[i], &line[min]);
            swap_c++;
        }
    }

    for (i = 0; i < len; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", line[i]);
    }
    printf("\n");
    printf("%d\n", swap_c);
    return 0;
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

