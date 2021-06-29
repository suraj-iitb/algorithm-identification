#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    rep(k, N) {
        cout << A[k];
        if (k != N - 1)
            cout << " ";
    }
    cout << endl;

    for (int i = 1; i < N; ++i) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = v;

        rep(k, N) {
            cout << A[k];
            if (k != N - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}
