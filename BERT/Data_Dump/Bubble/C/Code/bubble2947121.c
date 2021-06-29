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

    int num = 0;
    int flag = 1;
    while (flag)
    {
        flag = 0;
        int j;
        for (j = n - 1; j >= 1; j--)
        {
            if (a[j] < a[j - 1])
            {
                int temp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = temp;
                flag = 1;
                num++;
            }
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

// 1 bubbleSort(A, N) // N 個の要素を含む 0-オリジンの配列 A
// 2   flag = 1 // 逆の隣接要素が存在する
// 3   while flag
// 4     flag = 0
// 5     for j が N-1 から 1 まで
// 6       if A[j] < A[j-1]
// 7         A[j] と A[j-1] を交換
// 8         flag = 1
