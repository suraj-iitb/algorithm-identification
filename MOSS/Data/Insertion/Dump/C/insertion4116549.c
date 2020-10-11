#include <stdio.h>

static const int MAXNUMOFINPUT = 100;

int insertionSort(int A[], int N);
int printArray(int A[], int N);

int main()
{
    int i;
    int N;
    int A[MAXNUMOFINPUT];

    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    
    printArray(A, N);
    insertionSort(A, N);

    return 0;
}

int insertionSort(int A[], int N)
{
    int i, j;
    int v;

    for (i = 1; i < N; i++)
    {
        v = A[i];
        j = i - 1;
        while(j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;

        printArray(A, N);
    }
}

int printArray(int A[], int N)
{
    int i;

    for (i = 0; i < N; i++)
    {
        printf("%d", A[i]);
        if(i < N - 1)
        {
            printf(" ");
        }
    }

    printf("\n");

    return 0;
}

