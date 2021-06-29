//#include <climits>
#include <vector>
#include <iostream>
using namespace std;

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    //バブルソート
    int count = 0;
    for (int i = 0; i < N-1; ++i) //i番目までソートが完了する
    {
        for (int j = N-1; j > i; --j)
        {
            if(A[j-1] > A[j]) {
                swap(A[j-1], A[j]);
                count++; //交換回数
            }
        }
    }

    //ソート後の配列を出力
    for (int i = 0; i < N; ++i)
    {
        cout << A[i];
        if(i < N-1) {
            cout << " ";
        }
    }
    cout << endl;

    //交換回数を出力
    cout << count << endl;
   
    return 0;
}
