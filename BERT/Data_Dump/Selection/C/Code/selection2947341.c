#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    int pre;
    for (pre = 0; pre < n; pre++)
    {
        scanf("%d", &a[pre]);
    }

    int i;
    int num = 0;
    for (i = 0; i <= n - 1; i++)
    {
        int minj = i;
        int j;
        for (j = i; j <= n - 1; j++)
        {
            if (a[j] < a[minj])
            {
                minj = j;
            }
        }
        if (a[i] != a[minj])
        {
            int temp = a[i];
            a[i] = a[minj];
            a[minj] = temp;
            num++;
        }
    }
    for (pre = 0; pre < n; pre++)
    {
        printf("%d", a[pre]);
        if (pre < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n%d\n", num);
    return 0;
}

// 1 selectionSort(A, N) // N個の要素を含む0-オリジンの配列A
// 2   for i が 0 から N-1 まで
// 3     minj = i
// 4     for j が i から N-1 まで
// 5       if A[j] < A[minj]
// 6         minj = j
// 7     A[i] と A[minj] を交換
