//AOJ::ALDS1_1_A「Insertion Sort」
#include <bits/stdc++.h> //一括include
using namespace std;

void out(int array[], int x) //表示
{
    printf("%d", array[0]);
    for (int num = 1; num < x; num++)
    {
        printf(" %d", array[num]);
    }
    printf("\n");
}

int insertionsort(int A[], int N) //N個の要素を含む0～1000の配列A
{
    int i, v, j;
    for (i = 1; i <= N - 1; i++)
    {
        out(A, N);
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
    }
    return A[100];
}

int main()
{
    int n;
    int a[100] = {};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    insertionsort(a, n);
    out(a, n);
}

