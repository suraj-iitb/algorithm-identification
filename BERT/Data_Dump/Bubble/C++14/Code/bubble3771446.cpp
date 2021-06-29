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

int gcd(int x, int y) {
    int tmp;
    if(x > y)
        return gcd(y, x);
    int r;
    while((r = x % y)) {
        x = y;
        y = r;
    }
    return y;
}

bool isPrime(int n) {
    if(n < 2)
        return false;
    else if(n == 2)
        return true;
    else if(n % 2 == 0)
        return false;
    double sq = sqrt(n);
    for(int i = 3; i <= sq; i += 2) {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int N, co = 0;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    bool flag = 1;
    while(flag) {
        flag = 0;
        for(int j = N - 1; j > 0; j--) {
            if(A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                co++;
                flag = 1;
            }
        }
    }
    vecout(A);
    cout << co << endl;
}

