// バブルソート
#include<iostream>
#include<algorithm>
using namespace std;

static const int MAX_N = 100;

void bubbleSort(int A[], int n);

int main(void)
{
    int N;
    int ary_sequence[MAX_N];

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> ary_sequence[i];
    }

    bubbleSort(&ary_sequence[0], N);

    return 0;
}

// バブルソートを実施する関数
void bubbleSort(int A[], int n)
{
    int count = 0, tmp;
    int flag = 1;

    while( flag )
    {
        flag = 0;

        for(int i = n - 1; i > 0; i--)
        {
            if( A[i - 1] > A[i] )
            {
                // 値の入れ替え
                tmp = A[i];
                A[i] = A[i - 1];
                A[i - 1] = tmp;

                flag = 1;

                // 交換回数の保存
                count++;
            }
        }
    }

    // 結果表示用
    for(int i = 0; i < n - 1; i++)
    {
        cout << A[i] << ' ';
    }

    cout << A[n - 1] << endl;
    cout << count << endl;

    return;
}

