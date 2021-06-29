// ALDS1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//C:\Users\bbtos\source
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

int c = 0;

vector<int> BubbleSort(vector<int> A, int N) {
    int flag = 1;
    while (flag == 1) {
        flag = 0;
        for (int j = N - 1; j > 0; j--) {
            if (A.at(j) < A.at(j - 1)) {
                int t = A.at(j);
                A.at(j) = A.at(j - 1);
                A.at(j - 1) = t;
                flag = 1;
                c++;
            }
        }
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
    A = BubbleSort(A, n);

    for (int i = 0; i < n; i++) {
        cout << A.at(i);
        if (i < n - 1) cout << " ";
        else cout << endl;
    }
    cout << c << endl;
}

