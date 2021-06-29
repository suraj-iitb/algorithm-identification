#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < int(n); ++i)

void Main() {
    int n, v;
    cin >> n;
    vector<int> A(n);
    for (auto &e : A) {
        cin >> e;
    }
    rep(i, n) { cout << A.at(i) << (i != n - 1 ? " " : "\n"); }
    for (int i = 1; i < n; i++) {
        v = A.at(i);
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        rep(k, n) { cout << A.at(k) << (k != n - 1 ? " " : "\n"); }
    }
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
