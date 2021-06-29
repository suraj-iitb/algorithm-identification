// 選択ソート
#include<iostream>
#include<algorithm>
using namespace std;

static const int MAX_N = 100;

void selectionSort(int A[], int n);

int main(void)
{
    int N;
    int ary_sequence[MAX_N];

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> ary_sequence[i];
    }

    selectionSort(&ary_sequence[0], N);

    return 0;
}

// 選択ソートを実施する関数
void selectionSort(int A[], int n)
{

    int count = 0;
    // 最小値の存在する配列の要素No.
    int min_pos;

    for(int i = 0; i < n; i++)
    {
        min_pos = i;

        for(int j = i; j < n; j++)
        {
            if( A[j] < A[min_pos] )
            {
                // 最小値の存在する位置を保存する
                min_pos = j;
            }
        }

        if( i != min_pos )
        {
            // 最小値を移動させる
            swap(A[i], A[min_pos]);

            count++;
        }
    }

    // 結果表示用
   for(int i = 0; i < n; i++)
   {
       if( i )
       {
           cout << ' ';
       }

       cout << A[i];
   }

   cout << endl;
   cout << count << endl;

    return;
}

