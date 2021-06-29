/*
 * Author: Khan
 * Date: 10th October, 2017
 */
#include <stdio.h>

void print(int A[], int N)
{
    printf("%d", A[0]);
    for (int i = 1; i < N; ++i)
    {
        printf(" %d", A[i]);
    }
    putchar('\n');
}

void insertionSort(int A[], int N)
{
    int v;
    for (int i = 1; i < N; ++i)
    {
        v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = v;
        print(A, N);
    }
}

int main(int argc, char const *argv[])
{
    //freopen("sample.txt", "r", stdin);
    int N, A[100];
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
    {
        scanf("%d", &A[i]);
    }
    print(A, N);
    insertionSort(A, N);
    return 0;
}
