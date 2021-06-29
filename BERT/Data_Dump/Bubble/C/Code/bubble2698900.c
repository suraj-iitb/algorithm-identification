#include<stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int bubblesort(int A[], int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j > i; j--)
        {
            if (A[j] < A[j - 1])
            {
                swap(&A[j], &A[j-1]);
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int A[100], N;
    int count = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }

    count = bubblesort(A, N);
    
    for (int i = 0; i < N; i++)
    {
        if (i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d\n", count);
    return 0;
}

