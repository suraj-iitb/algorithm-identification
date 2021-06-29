#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

/*********** Constants ***********/
const auto INF = static_cast<ll>(1e15);
const auto MOD = static_cast<ll>(1e9 + 7);

/*********** Variables ***********/
ll N, ANS;
vector<ll> A;

/*********** Functions ***********/
bool init() {
    cin >> N;
    A.resize(N, 0);
    for (auto& a : A) cin >> a;
    return true;
}

void solve() {
    ll flag = true;
    while (flag) {
        flag = false;
        for (ll i = 0; i < N - 1; i++) {
            if (A[i] > A[i + 1]) {
                flag = true;
                swap(A[i], A[i + 1]);
                ANS++;
            }
        }
    }
}

void output() {
    for (ll i = 0; i < N; i++) {
        cout << (i ? " " : "") << A[i];
    }
    cout << endl;
    cout << ANS << endl;
}

int main() {
    init();
    solve();
    output();
    return 0;
}
