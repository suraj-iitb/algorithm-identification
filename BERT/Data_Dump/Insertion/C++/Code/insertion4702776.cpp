#include <stdio.h>

static const int MAX = 2000;

void trace(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d", A[i]);
        if (i < N - 1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void insertionSort(int A[], int N)
{
    int i, j, v;

    for (int i = 1; i < N; i++)
    {
        v = A[i];
        int j = i - 1;

        // その要素の左隣と比べて、
        // 左隣のほうが大きかったら、左隣の要素を1個右にずらす
        while (j >= 0 && A[j] > v)
        {
            // ずらす
            A[j + 1] = A[j];
            // さらに左隣と比較する
            j--;
        }

        // 空いたポジションにA[i]の値を入れる
        A[j + 1] = v;

        // 途中結果の出力
        trace(A, N);
    }
}

int main()
{
    int R[MAX], n;

    // 入力を受け取る
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &R[i]);
    }

    // 初期状態を出力
    trace(R, n);
    // ソートの実行
    insertionSort(R, n);

    return 0;
}
