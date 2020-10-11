#include <stdio.h>
#include <stdlib.h>

void DisplayArray(int A[], int N)
{
    int i;
    for (i = 0; i < N; i++) {
        if (i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

int BubbleSort(int A[], int N)
{
    int flag = 1;
    int count = 0;
    int j, tmp;

    while (flag) {
        flag = 0;
        for (j = N - 1; j != 0; j--) {
            if (A[j] < A[j - 1]) {
                tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                count++;
                flag = 1;
            }
        }
    }

    return count;
}

int main(void)
{
    int N, i, numOfExchanges;
    scanf("%d%*c", &N);
    int* A = (int*)malloc(sizeof(int) * N);

    for (i = 0; i < N; i++) scanf("%d", &A[i]);
    scanf("%*c");

    numOfExchanges = BubbleSort(A, N);
    DisplayArray(A, N);
    printf("%d\n", numOfExchanges);

    return 0;
}
