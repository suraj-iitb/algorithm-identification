#include <bits/stdc++.h>
using namespace std;

int bubbleSort(vector<int> &A) {
    int swapCnt = 0;    // 入れ替えカウント
    bool flag = true;   // ソート継続フラグ
    // 比較対象が存在する間、ループを回す
    // ループ毎にソート済み要素が増えていくのでソート済み
    // indexをインクリメントしていく
    for(int i = 0; flag; i++) {
        flag = false;
        for (int j = A.size() - 1; j > i; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                swapCnt++;
                flag = true;
            }
        }
    }
    return swapCnt;
}

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int swapCnt = bubbleSort(A);

    for (int i = 0; i < A.size(); i++) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << swapCnt << endl;
    return 0;
}
