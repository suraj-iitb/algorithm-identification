#include <stdio.h>

void swap(int *x, int *y)
{
    int t;
    
    t = *x;
    *x = *y;
    *y = t;
}

int main(void)
{
    int N, A[100], i, j = 0, n = 0, *min;
    
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    while (j < N - 1) {
        min = &A[j];
        for (i = j + 1; i < N; i++) {
            if (*min > A[i]) {
                min = &A[i];
            }
        }
        if (*min != A[j]) {
                swap(min, &A[j]);
                n++;
        }
        j++;
    }
    for (i = 0; i < N; i++) {
        printf("%d", A[i]);
        if (i != N - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }
    printf("%d\n", n);
    return 0;
}
