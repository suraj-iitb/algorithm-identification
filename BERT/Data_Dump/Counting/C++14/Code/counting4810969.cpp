#include <bits/stdc++.h>
#define fastIO (ios::sync_with_stdio(false), cin.tie(0), cout.tie(0))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using ui = uint64_t;
using li = int64_t;
using namespace std;

int main() {
    fastIO;

    int n;
    cin >> n;
    vector<int> A(n + 1), B(n + 1);
    rep(i, n) cin >> A.at(i + 1);

    const int MAX = 10000;
    vector<int> C(MAX + 1, 0);

    for (int i = 0; i < n; i++) {
        C.at(A.at(i + 1))++;
    }

    for (int i = 1; i <= MAX; i++) {
        C.at(i) = C.at(i) + C.at(i - 1);
    }

    for (int i = 1; i <= n; i++) {
        B.at(C.at(A.at(i))) = A.at(i);
        C.at(A.at(i))--;
    }

    for (int i = 1; i <= n; i++) {
        if (i > 1)
            cout << " ";
        cout << B.at(i);
    }
    cout << endl;
}

