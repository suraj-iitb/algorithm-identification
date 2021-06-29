#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int i, j, n, min;
    int count = 0;
    int data[100];

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i; j < n; j++) {
            if (data[j] < data[min]) {
                min = j;
            }
        }
        swap(&data[i], &data[min]);
        if (i != min) count++;
    }

    for (i = 0; i < n; i++) {
        printf("%d", data[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
    printf("%d\n", count);

    return 0;
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

