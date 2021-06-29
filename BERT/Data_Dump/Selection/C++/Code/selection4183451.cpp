#include <iostream>
#include <stdio.h>
using namespace std;

// 最小値を左に詰めていくようにソートする
int SelectionSort(int A[], int N)
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        int minj = i;
        for (int j = i; j < N; j++)
        {
            if (A[minj] > A[j])
                minj = j;
        }
        if (minj != i)
            cnt++;
        swap(A[minj], A[i]);
    }
    return cnt;
}

int main()
{
    int N;
    int A[100];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    int rel = SelectionSort(A, N);
    for (int i = 0; i < N; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
    printf("%d", rel);
    printf("\n");
}
