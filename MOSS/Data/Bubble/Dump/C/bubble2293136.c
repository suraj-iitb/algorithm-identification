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
    int N, A[100], i, j = 0, n = 0;
    
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
       scanf("%d", &A[i]); 
    }
    while (j < N) {
        for (i = N - 1; i > j; i--) {
            if (A[i] < A[i - 1]) {
                swap(&A[i], &A[i - 1]);
                n++;
            }
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
