// ALDS1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//C:\Users\bbtos\source
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

int c = 0;

vector<int> SelectionSort(vector<int> A, int N) {
    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (A.at(j) < A.at(minj)) {
                minj = j;
            }
        }
        if (i != minj) c++;
        int t = A.at(i);
        A.at(i) = A.at(minj);
        A.at(minj) = t;
    }
    return A;
}

int main(void) {
    int n;
    int t;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> t;
        A.at(i) = t;
    }
    A = SelectionSort(A, n);

    for (int i = 0; i < n; i++) {
        cout << A.at(i);
        if (i < n - 1) cout << " ";
        else cout << endl;
    }
    cout << c << endl;
}
