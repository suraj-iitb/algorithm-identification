//ALDS1_2_A 「Bubble Sort」
#include <bits/stdc++.h>
//一括include
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

int bubbleSort(int A[], int N)
{
    int flag = 1;
    int count = 0;
    while (flag)
    {
        flag = 0;
        for (int j = N - 1; 0 < j; j--)
        {
            if (A[j] < A[j - 1])
            {
                swap(A[j], A[j - 1]);
                flag = 1;
                count++;
            }
        }
    }
    out(A, N);
    return count;
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
    printf("%d\n", bubbleSort(a, n));
}

