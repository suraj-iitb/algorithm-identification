#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)

int selectionSort(int A[], int n) {
    int cnt = 0;
    REP(i, n) {
        int minj = i;
        FOR(j, i, n) if (A[minj] > A[j]) minj = j;
        if (A[i] > A[minj]) {
            swap(A[i], A[minj]);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int A[n];
    REP(i, n) cin >> A[i];

    int cnt = selectionSort(A, n);
    REP(i, n) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
