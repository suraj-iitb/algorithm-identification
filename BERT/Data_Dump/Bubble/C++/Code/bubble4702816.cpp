#include <iostream>
using namespace std;
int A[100];
int sw = 0;

void bubbleSort(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j > i; j--)
        {
            if (A[j] < A[j - 1])
            {
                swap(A[j], A[j - 1]);
                sw++;
            }
        }
    }
}

int main()
{
    // 入力の受け取り
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    // ソートの実行
    bubbleSort(A, n);

    // 結果出力
    for (int j = 0; j < n; j++)
    {
        if (j > 0)
        {
            cout << " ";
        }
        cout << A[j];
    }

    // 回数出力
    cout << endl;
    cout << sw << endl;

    return 0;
}
