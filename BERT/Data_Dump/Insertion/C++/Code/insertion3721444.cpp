#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> A) {
    for (int i = 0; i < A.size(); ++i) {
        if (i == 0) cout << A[i];
        else cout << " " << A[i];
    }
    cout << endl;
}

// 挿入ソート
vector<int> insertionSort(vector<int> A) {
    int N = A.size();
    // 整列済みでない要素を順に見ていく
    for (int i = 1; i < N; ++i) {
        // 対象の要素を変数vに退避
        int v = A[i];
        int j = i - 1;
        // vより大きい要素を後ろにずらしていく
        while(A[j] > v && j >= 0) {
            A[j+1] = A[j];
            --j;
        }
        // ずらして空いたスペースにvを挿入
        A[j+1] = v;
        printVector(A);
    }
    return A;
}

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    printVector(A);
    insertionSort(A);
}
