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

    //選択ソート
    int count = 0;
    for (int i = 0; i < N; ++i)
    {
        int minj = i;
        for (int j = i; j < N; ++j)
        {
            if(A[j] < A[minj]) {
                minj = j;
            }
        }

        if(i != minj) {
            swap(A[i], A[minj]);
            count++; //交換回数
        }
    }

    //出力
    for (int i = 0; i < N; ++i)
    {
        cout << A[i];
        if(i < N-1) {
            cout << " ";
        }
    }
    cout << endl;

    cout << count << endl;
   
    return 0;
}
