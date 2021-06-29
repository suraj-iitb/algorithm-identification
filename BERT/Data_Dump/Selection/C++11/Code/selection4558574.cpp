#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void selectionSort(int A[], int N) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) minj = j; //未ソート部分の最小値を探している
        }
        swap(A[i], A[minj]);
        if (i != minj) cnt++; //swap しないなら、インクリメントしない
    }
    rep(i,N) {
        cout << A[i];
        if (i != N-1) cout << " ";
    }
    printf("\n");
    cout << cnt << endl;
}

int main() {
    int n;
    cin >> n;
    int A[n];
    rep(i,n) cin >> A[i];

    selectionSort(A, n);

    return 0;
}
