// std = c++14
#include <iostream>
using namespace std;

// 計数ソート
void keisu_sort(int n, int* A, int max, int* B) {
    int C[max + 1]; // カウンタ数列
    for (int i = 0; i <= max; i++)
        C[i] = 0;

    // `C[i]`に`i`の出現数を記録
    for (int j = 0; j <= n - 1; j++)
        C[A[j]]++;

    // `C[i]`に`i`以下の数の出現数を記録
    for (int i = 1; i <= max; i++)
        C[i] += C[i - 1];

    // test
    /*
    cout << "C: ";
    for (int i = 0; i <= max; i++) {
        cout << C[i] << ' ';
    } cout << endl;
    */

    // ここまでOK -----

    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
}

int main() {
    // 入力
    int n; cin >> n;
    int A[n];
    for (int i=0; i<n; i++)
        cin >> A[i];

    // 最大値を求めておく
    int max = 0;
    for (int i=0; i<n; i++)
        if (max < A[i])
            max = A[i];
    //cout << "max: " << max << endl;

    // 計数ソート
    int B[n]; for (int i = 0; i < n; i++) B[i] = 0;
    keisu_sort(n, A, max, B);

    // 出力
    for (int i=0; i<n; i++) {
        cout << B[i];
        if (i == n - 1)
            cout << endl;
        else
            cout << ' ';
    }
}
