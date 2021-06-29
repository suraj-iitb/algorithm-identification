#include <stdio.h>

void Print(int A[], int N)
{
    for (int i = 0; i < N; i++) {
        if (i > 0)
            printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");   
}

int bubbleSort(int A[], int N)
{
    int num_swaps = 0;
    int flag = 1;
    int i = 0;

    while (flag != 0) {
        flag = 0;
        for (int j = N - 1; j >= i + 1; j--) {
            if (A[j] < A[j - 1]) {
                int tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                flag = 1;
                num_swaps++;
            }
        }
        i++;
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

    int num_swaps = bubbleSort(A, N);
    Print(A, N);
    printf("%d\n", num_swaps);
    return 0;
}
