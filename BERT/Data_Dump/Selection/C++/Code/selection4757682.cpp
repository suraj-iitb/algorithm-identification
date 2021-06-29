#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;

int selectionSort(int A[], int n)
{
    int SwapNum{0};
    for (int i = 0; i < n; i++) //失之毫厘，谬以千里
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
            {
                min = j;
            }
        }
        swap(A[i], A[min]);
        if (min != i)
        {
            SwapNum++;
        }
    }
    return SwapNum;
}

int main()
{
    int A[MAX];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    int ans = selectionSort(A, n);
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", A[i]);
    }
    printf("%d\n%d\n", A[n - 1], ans);
    return 0;
}
