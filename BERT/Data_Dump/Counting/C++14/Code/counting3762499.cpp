#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <boost/math/common_factor_rt.hpp>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define SENTINEL 2000000000
typedef long long ll;

using namespace std;
// namespace mp = boost::multiprecision;
// namespace mt = boost::math
// using Bint = mp::cpp_int;

int n, k = -1;

void CountingSort(int a[], int b[], int k) {
    int c[k + 1] = {};
    for (int j = 0; j < n; j++) c[a[j]]++;
    for (int i = 0; i < k + 1; i++) {
        c[i + 1] += c[i];
        // cout << c[i] << endl;
    }
    for (int j = n - 1; j >= 0; j--) {
        b[c[a[j]] - 1] = a[j];
        c[a[j]]--;
    }
    for (int i = 0; i < n; i++) {
        cout << b[i];
        if (i != n - 1)
            cout << " ";
        else
            cout << endl;
    }
}

int main() {
    cin >> n;
    int a[n], b[n];
    rep(i, n) {
        cin >> a[i];
        k = max(k, a[i]);
    }
    CountingSort(a, b, k);
}
