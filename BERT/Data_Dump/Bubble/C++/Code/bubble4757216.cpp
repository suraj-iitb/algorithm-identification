#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX = 100;

int bubbleSort(int A[], int n)
{
    int num{0};
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (A[j] < A[j - 1])
            {
                swap(A[j], A[j - 1]);
                num++;
            }
        }
    }
    return num;
}

void trace(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", A[i]);
    }
    printf("%d", A[n - 1]);
}

int main()
{
    int n;
    int A[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    int ans = bubbleSort(A, n);
    trace(A, n);
    printf("\n%d\n", ans);
    return 0;
}
