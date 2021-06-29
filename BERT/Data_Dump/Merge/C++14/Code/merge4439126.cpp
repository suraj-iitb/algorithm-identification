#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;;

int cnt = 0; //比較回数のカウンター

void MergeSort(vector<int> &A, int l, int m, int r) {
    
    //要素数
    int n1 = m - l + 1; //左側
    int n2 = r - m; //右側
    //格納用vectorの宣言→格納
    vector<int> L(n1);
    vector<int> R(n2);
    rep(i, n1) L[i] = A[l + i];
    rep(i,n2) R[i] = A[m + 1 + i];

    //indexの宣言(i : L, j : R, k : A)
    int i = 0, j = 0, k = l;
    //比較しながらAに再度格納
    //L,R両方に要素が残っている場合
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        } 
        k++;
        cnt++; //while内部の比較回数をカウント
    }
    //この時点でL,R両方に要素が残っていることはない

    //Lに要素が残っている場合
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
        cnt++; //？？？
    }
    //Rに要素が残っている場合
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
        cnt++; //？？？
    }
}

void Marge(vector<int> &A, int l, int r) {
    // l == r のときに再帰ストップ
    if (l < r) {
        int m = (l + r)/ 2;
        Marge(A, l, m);
        Marge(A, m + 1, r);
        MergeSort(A, l, m, r);
    }
}

signed main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<int> vec(n);
    rep(i,n) cin >> vec[i];
    //マージソート
    Marge(vec, 0, n - 1);
    //ソート済のvecの出力
    cout << vec[0];
    rep2(i, 1, n) {
        cout << " " << vec[i];
    }
    //比較回数の出力
    cout << endl << cnt << endl;
    return 0;
}
