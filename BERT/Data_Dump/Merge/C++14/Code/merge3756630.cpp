#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//#include <boost/math/common_factor_rt.hpp>
#define USE_MATH_DEFINES
#define rep(i, n) for (int i = 0; i < (n); i++)
#define SENTINEL 2000000000
typedef long long ll;

using namespace std;
// namespace mp = boost::multiprecision;
// namespace mt = boost::math
// using Bint = mp::cpp_int;

int cnt = 0;

void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int l[n1 + 1], r[n2 + 1];
    rep(i, n1) l[i] = a[left + i];
    rep(i, n2) r[i] = a[mid + i];
    l[n1] = r[n2] = SENTINEL;
    int p = 0, q = 0;
    for (int i = left; i < right; i++) {
        if (l[p] <= r[q]) {
            a[i] = l[p];
            p++;
        } else {
            a[i] = r[q];
            q++;
        }
        cnt++;
    }
}

void mergeSort(int a[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid, right);
        merge(a, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    rep(i, n) cin >> a[i];
    mergeSort(a, 0, n);
    rep(i, n) {
        if (i != n - 1)
            cout << a[i] << " ";
        else
            cout << a[i] << endl;
    }
    cout << cnt << endl;
}
