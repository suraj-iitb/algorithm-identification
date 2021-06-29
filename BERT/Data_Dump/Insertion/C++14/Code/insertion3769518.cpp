#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <tuple>
#include <vector>
using ll = long long;
using namespace std;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a); i < int(b); ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
const long long inf = 1LL << 60;
const long long mod = 1e9 + 7;

template <class T> void vecout(T V) {
    auto t = V.begin();
    while(t != V.end()) {
        cout << *t++;
        if(t != V.end())
            cout << " ";
    }
    cout << endl;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    rep(i, 0, N) {
        int v = A[i];
        int j = i - 1;
        while(j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        vecout(A);
    }
}
