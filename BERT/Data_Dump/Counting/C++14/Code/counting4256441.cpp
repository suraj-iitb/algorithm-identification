#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

void counting_sort(const vi& A, vi& B, const int k) {
    int n = A.size();
    vi C(k + 1, 0);

    rep(i, 0, n) {
        ++C[A[i]];
    }

    rep(i, 1, k + 1) {
        C[i] += C[i - 1];
    }

    rrep(i, 0, n) {
        B[C[A[i]] - 1] = A[i];
        --C[A[i]];
    }
}

int main() {
    int n;
    cin >> n;

    vi A(n), B(n);
    rep(i, 0, n) { cin >> A[i]; }

    counting_sort(A, B, 10000);

    rep(i, 0, n) {
        cout << B[i];
        if (i != n - 1) { cout << " "; }
        else { cout << endl; }
    }

    return 0;
}
