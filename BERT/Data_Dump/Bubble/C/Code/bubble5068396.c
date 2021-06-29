#include <stdio.h>

void bubble_sort(int *, int);
void swap(int *, int *);
int cnt = 0;

int main()
{

    int A[100], N, i, j;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
        bubble_sort(A, N);
    for (i = 0; i < N; i++)
    {
        printf("%d", A[i]);
        if (i != N - 1)
            printf(" ");
    }
    printf("\n");
    printf("%d", cnt);
    printf("\n");
    return 0;
}

void bubble_sort(int A[], int N)
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = N - 1; j >=i+1 ; j--)
        {
            if (A[j] < A[j - 1])
            {
                swap(&A[j], &A[j - 1]);
                cnt++;
            }
        }
    }
}

void swap(int *a, int *b)
{
    int e;

    e = *a;
    *a = *b;
    *b = e;
}

