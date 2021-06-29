#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

//margesortは安定だが，quicksortはそうとは限らない
//quicksort
int Partition(vector<pair<string,int>> &A, int l, int r) {
    int i = l - 1; //境界のindex
    rep2(j,l,r) {
        if (A[j].second <= A[r].second) {
            i++;
            swap(A[i], A[j]);
        }
    }
    i++;
    swap(A[i], A[r]);
    return i;
}

void quickSort(vector<pair<string,int>> &A, int l, int r) {
    //l == r のとき再帰ストップ
    if (l < r) { 
        int x = Partition(A, l, r);
        quickSort(A, l, x - 1); //左側 (※右端 = x にすると無限ループ)
        quickSort(A, x+1, r); //右側 (※左端はx,x+1のどっちでも良い)   ←要チェック
    }
    return;
}

//mergesort
void Merge(vector<pair<string,int>> &A, int l, int m, int r) {
    //要素数
    int n1 = m - l + 1; //左側
    int n2 = r - m; //右側
    //格納用vectorの宣言→格納
    vector<pair<string,int>> L(n1);
    vector<pair<string,int>> R(n2);
    rep(i,n1) L[i] = A[l + i];
    rep(i,n2) R[i] = A[m + 1 + i];
    //indexの宣言
    int i = 0, j = 0, k = l;
    //比較しながらAに再格納する
    while (i < n1 && j < n2) {
        if (L[i].second <= R[j].second) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
    return;
}

void mergeSort(vector<pair<string,int>> &A, int l, int r) {
    //l == rのとき再帰ストップ
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m+1, r);
        Merge(A, l, m, r);
    }
    return;
}


signed main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //入力
    int n; cin >> n;
    string s; int p;
    vector<pair<string,int>> A_quick(n);
    vector<pair<string,int>> A_merge(n);
    rep(i,n) {
        cin >> s >> p;
        A_quick[i] = make_pair(s,p);
        A_merge[i] = make_pair(s,p);
    }
    //sorting
    quickSort(A_quick, 0, n - 1);
    mergeSort(A_merge, 0, n - 1);
    //check if stable
    bool stable = true;
    rep(i,n) {
        if (A_quick[i] != A_merge[i]) {
            stable = false;
            break;
        }
    }
    //stableか出力
    if (stable) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
    //quicksortの結果を出力
    rep(i,n) {
        cout << A_quick[i].first << " " << A_quick[i].second << endl;
    }
    
    return 0;
}
