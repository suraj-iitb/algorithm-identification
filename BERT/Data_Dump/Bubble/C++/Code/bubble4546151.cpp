#include <iostream>
using namespace std;

// バブルソートを行う関数
int bubbleSort(int A[], int N) {
    // 交換回数
    int sw = 0;
    // 交換したかどうかのフラグ
    bool flag = true;

    while (flag) {
        flag = false;

        for (int j = N - 1; j >= 1; --j) {
            if (A[j] < A[j - 1]) {
                int tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                flag = true;

                ++sw;
            }
        }
    }

    return sw;
}

int main() {
    int A[100], N, sw;
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i];

    sw = bubbleSort(A, N);

    for (int i = 0; i < N; ++i) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;

    return 0;
}
