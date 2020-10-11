#include <stdio.h>

static int selectionSort(int A[], int N)
{
    int num_swaps = 0;

    for (int i = 0; i < N; i++) {
        int minj = i;

        for (int j = i + 1; j < N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }

        if (minj != i) {
            int tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
            num_swaps++;
        }
    }

    return num_swaps;
}

int main()
{
    int N;
    int A[100];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int num_swaps = selectionSort(A, N);

    for (int i = 0; i < N; i++) {
        if (i > 0)
            printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", num_swaps);
    return 0;
}
