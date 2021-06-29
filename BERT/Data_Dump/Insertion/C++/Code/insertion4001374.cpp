#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> &vec, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (i != N - 1)
        {
            printf("%d ", vec[i]);
        }
        else
        {
            printf("%d\n", vec[i]);
        }
    }
}

void insertion_sort(vector<int> &vec, int N)
{
    for (int i = 1; i < N; i++)
    {
        //中間配列を出力
        print_vector(vec, N);

        //sort
        int j = i - 1; //ソート済み部分裂の最後尾アドレス
        int m;         //swap用変数
        while (j >= 0 && vec[j]> vec[j + 1])
            {
                m = vec[j + 1];
                vec[j + 1] = vec[j];
                vec[j] = m;
                j--;
            }
    }
    //最終配列を出力
    print_vector(vec, N);
}

int main()
{
    //vectorのサイズnと要素の入力
    int n;
    scanf("%d", &n);
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    insertion_sort(A, n);
}
