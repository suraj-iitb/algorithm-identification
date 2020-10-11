#include <stdio.h>

#define MAX 100

void swap(int* line, int j);

int main(void)
{
    int i, j;

    int n;
    scanf("%d", &n);

    int line[MAX];
    for (i = 0; i < n; i++) {
        scanf("%d", &line[i]);
    }

    int swap_cnt = 0;
    for (i = 0; i < n; i++) {
        for (j = n - 1; j > i; j--) {
            if (line[j] < line[j - 1]) {
                swap(line, j);
                swap_cnt++;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (i != 0) {
            printf(" ");
        }
        printf("%d", line[i]);
    }
    printf("\n");

    printf("%d\n", swap_cnt);

    return 0;
}

void swap(int* line, int j)
{
    int tmp = line[j];
    line[j] = line[j - 1];
    line[j - 1] = tmp;
}
