#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

/*********** Constants ***********/
const auto INF = static_cast<ll>(1e15);
const auto MOD = static_cast<ll>(1e9 + 7);

/*********** Variables ***********/
ll N;
vector<ll> A;
vector<vector<ll>> ANS;

/*********** Functions ***********/
bool init() {
    cin >> N;
    A.resize(N, 0);
    for (auto& a : A) cin >> a;
    return true;
}

void solve() {
    ANS.push_back(A);
    for (ll i = 1; i < N; i++) {
        ll v = A[i];
        ll j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        ANS.push_back(A);
    }
}

void output() {
    for (const auto& item : ANS) {
        for(ll i = 0; i < N; i++) {
            cout << (i ? " " : "") << item[i];
        }
        cout << endl;
    }
}

int main() {
    init();
    solve();
    output();
    return 0;
}
