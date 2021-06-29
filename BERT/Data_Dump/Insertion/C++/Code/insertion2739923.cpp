// 挿入ソート
#include<iostream>
#include<algorithm>
using namespace std;

//static const int MAX_N = 100;
static const int MAX_ELE = 1000;

int main(void)
{
    int v, j;
    int N;
    int ary_sequence[MAX_ELE];

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> ary_sequence[i];
    }

    for(int i = 0; i < N - 1; i++)
    {
        cout << ary_sequence[i] << ' ';
    }

    cout << ary_sequence[N - 1] << endl;

    // -----▼▼▼ 挿入ソート ▼▼▼-----

    for(int i = 1; i < N; i++)
    {
        v = ary_sequence[i];
        j = i - 1;

        while( j >= 0 && ary_sequence[j] > v )
        {
            ary_sequence[j + 1] = ary_sequence[j];
            j--;
        }

        ary_sequence[j + 1] = v;

        for(int k = 0; k < N - 1; k++)
        {
        		cout << ary_sequence[k] << ' ';
        }

        cout << ary_sequence[N - 1] << endl;
    }

    // -----▲▲▲ 挿入ソート ▲▲▲-----

    return 0;
}

