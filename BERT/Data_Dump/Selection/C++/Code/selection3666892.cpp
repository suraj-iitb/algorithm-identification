#include <cstdio>
#include <iostream>
using namespace std;

void trace(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        if (i > 0)
        {
            printf(" ");
        }
        printf("%d", A[i]);
    }
    printf("\n");
}

int selectionSort(int A[], int N)
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        int minj = i;
        for (int j = i; j < N; j++)
        {
            if (A[j] < A[minj])
            {
                minj = j;
            }
        }
        if (i != minj)
        {
            swap(A[i], A[minj]);
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int N;
    scanf("%d", &N);

    int A[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    
    int cnt = selectionSort(A, N);
    trace(A, N);
    printf("%d%s", cnt, "\n");

    return 0;
}
