#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

//flg を用いたバブルソート
int bubbleSort(int A[], int N) {
    int sw = 0;
    bool flg = 1;
    for (int i = 0; flg; i++) {  // ２番目の式がi< のような形になっていないので、flgによってのみ判断される。
        flg = 0;
        for (int j = N-1; j >= i+1; j--) {
            if (A[j] < A[j-1]) {
                //隣接要素を交換する
                swap(A[j], A[j-1]);
                flg = 1;
                sw++;
            }
        }
    }
    return sw;  
}

int main() {
    int A[100], N, sw;
    cin >> N;
    rep(i,N) cin >> A[i];

    sw = bubbleSort(A, N);

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;

    return 0;
}
