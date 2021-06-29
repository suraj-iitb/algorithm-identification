#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int N; cin >> N;
    vector<int> A(N+1); rep(i, N) cin >> A[i+1];
    vector<int> C(10001), B(N+1);

    for (int i = 1; i < N+1; ++i) ++C[A[i]];
    for (int i = 0; i < 10000; ++i) {
        C[i+1] = C[i] + C[i+1];
    }
    for (int i = N; i > 0; --i) {
        B[ C[A[i]] ] = A[i];
        --C[A[i]];
    }
    for (int i = 1; i < N; ++i) cout << B[i] << " ";
    cout << B[N] << endl;
}
