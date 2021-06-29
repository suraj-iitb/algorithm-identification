#include <stdio.h>

static const int MAX = 100;

void Print(int A[], int N)
{
    for (int i = 0; i < N; i++) {
        if (i > 0)
            printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");   
}

int main()
{
    int N;
    int A[MAX];

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < N; i++) {
        int v = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = v;
        Print(A, N);
    }

    return 0;
}
