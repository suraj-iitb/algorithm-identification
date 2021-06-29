#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)

int bubbleSort(int A[], int N) {
    int cnt = 0;
    bool flag = true;
    for (int i = 0; flag; i++) {
        flag = false;
        for (int j = N - 1; j >= i + 1; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                flag = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int A[n];
    REP(i, n) cin >> A[i];

    int ans = bubbleSort(A, n);
    REP(i, n) {
        cout << (i == 0 ? "" : " ") << A[i];
    }
    cout << endl;
    cout << ans << endl;
    return 0;
}
