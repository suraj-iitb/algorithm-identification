#include <stdio.h>

void bubbleSort(int A[], int N) {
    int c = 0;
    int flag = 1;
    int j, tmp;

    while (flag) {
        flag = 0;
        for (j = N-1; j > 0; j--) {
            if (A[j] < A[j-1]) {
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;

                c++;
                flag = 1;
            }
        }
    }
    for (j = 0; j < N; j++) {
        printf("%d", A[j]);
        if (j != N-1)
            printf(" ");
        else
            printf("\n");
    }
    printf("%d\n", c);
}

int main()
{
    int N, A[101];
    int i;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    bubbleSort(A, N);

    return 0;
}
