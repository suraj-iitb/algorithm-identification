#include <stdio.h>

static const int MAXNUMOFINPUT = 100;

int selectionSort(int A[], int N);
int printArray(int A[], int N);

int main()
{
    int i;
    int N;
    int A[MAXNUMOFINPUT];
    int cnt = 0;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    cnt = selectionSort(A, N);
    printArray(A, N);
    printf("%d\n", cnt);

    return 0;
}

int selectionSort(int A[], int N)
{
    int i, j;
    int minj;
    int tmp;
    int cnt = 0;

    for (i = 0; i < N - 1; i++)
    {
        minj = i;

        for (j = i; j < N; j++)
        {
            if(A[j] < A[minj])
            {
                minj = j;
            }
        }

        tmp = A[i];
        A[i] = A[minj];
        A[minj] = tmp;

        if (i != minj)
        {
            cnt++;
        }
    }

    return cnt;
}

int printArray(int A[], int N)
{
    int i;

    for (i = 0; i < N; i++)
    {
        printf("%d", A[i]);
        if (i < N - 1)
        {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}
