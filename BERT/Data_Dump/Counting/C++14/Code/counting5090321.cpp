// ALDS1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//C:\Users\bbtos\source
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

using namespace std;

static int k = 10010;

vector<int> CountingSort(vector<int> A, vector<int> B, int n) {
    vector<int> C(k);

    /* C[i] に i の出現数を記録する */
    for (int j = 0; j < n; j++) {
        C.at(A.at(j))++;
    }
    //for (auto i : C) cout << i << " ";
    //cout << endl;

    /* C[i] に i 以下の数の出現数を記録する*/
    for (int i = 1; i < k; i++) {
        C.at(i) += C.at(i-1);
    }
    //for (auto i : C) cout << i << " ";
    //cout<<endl;
    for (int j = n-1; j >= 0; j--) {
        B.at(C.at(A.at(j))) = A.at(j);
        C.at(A.at(j))--;
    }
    return B;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n+1);
    vector<int> B(n+1);

    for (int i = 0; i < n; i++) {
        cin >> A.at(i);
    }

    B = CountingSort(A, B, n);
    for (int i = 1; i < n+1; i++) {
        if (i != n ) cout << B.at(i) << " ";
        else cout << B.at(i) << endl;
    }
    return 0;
}
