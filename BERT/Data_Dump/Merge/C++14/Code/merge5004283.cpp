#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; ++i)

void merge(vector<int> &A, int left, int mid, int right, int &cnt) {
    int n1 = mid - left;
    int n2 = right - mid;
    vector<ll> L(n1+1), R(n2+1);
    rep(i, n1) L[i] = A[left + i];
    rep(i, n2) R[i] = A[mid + i];
    L[n1] = 2e9;
    R[n2] = 2e9;
    int i = 0, j = 0;
    for (int k = left; k < right; ++k) {
        ++cnt;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            ++i;
        } else {
            A[k] = R[j];
            ++j;
        }
    }
    return;
}

void mergeSort(vector<int> &A, int left, int right, int &cnt) {
    if (left + 1 < right) {
        int mid = (left + right)/2;
        mergeSort(A, left, mid, cnt);
        mergeSort(A, mid, right, cnt);
        merge(A, left, mid, right, cnt);
    }

    return;
}

int main() {
    int N; cin >> N;
    vector<int> A(N); rep(i, N) cin >> A[i];
    int cnt = 0;
    mergeSort(A, 0, N, cnt);
    cout << A[0];
    for (int i = 1; i < A.size(); ++i) cout << " " << A[i];
    cout << endl << cnt << endl;
}
