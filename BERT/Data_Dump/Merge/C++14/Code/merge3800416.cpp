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

int counts = 0;

template <class T> void vecout(T V) {
    auto t = V.begin();
    while(t != V.end()) {
        cout << *t++;
        if(t != V.end())
            cout << " ";
    }
    cout << endl;
};

void merge(vector<int> &A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L(n1 + 1);
    vector<int> R(n2 + 1);
    rep(i, n1) L[i] = A[left + i];
    L[n1] = intinf;
    rep(i, n2) R[i] = A[mid + i];
    R[n2] = intinf;
    int i = 0, j = 0;
    rep(k, left, right) {
        counts++;
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(vector<int> &A, int left, int right) {
    if(left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];

    mergeSort(A, 0, n);

    vecout(A);
    cout << counts << endl;
}

