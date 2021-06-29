#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
const long long inf = 1LL << 60;
const int intinf = 1 << 30;
const long long mod = 1e9 + 7;

int n;

template <class T> void vecout(T V) {
    auto t = V.begin();
    while(t != V.end()) {
        cout << *t++;
        if(t != V.end())
            cout << " ";
    }
    cout << endl;
};

void CountingSort(vector<int> A, vector<int> &B, int M) {
    vector<int> C(M + 1, 0);

    for(int i = 0; i < n; i++) {
        C[A[i]]++;
    }

    rep(i, 1, M + 1) C[i] += C[i - 1];

    for(int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
}

int main() {
    int M = -1;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    rep(i, n) {
        cin >> A[i];
        M = max(A[i], M);
    }

    CountingSort(A, B, M);

    vecout(B);
}

