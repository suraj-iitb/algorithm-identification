#include <stdio.h>

void trace(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

// 入力されたint配列を昇順にソートする
void InsertationSort(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        int tg = A[i];
        int j = i - 1;
        // 配列の左側はソートされているので、tgをソート済みの右側から調べる
        while (j >= 0 && tg < A[j])
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = tg;
        trace(A, N);
    }
}

int main()
{
    int N;
    int A[100];
    // 入力を第一位引数のフォーマットとして受け取る
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);
    InsertationSort(A, N);
    return 0;
}

