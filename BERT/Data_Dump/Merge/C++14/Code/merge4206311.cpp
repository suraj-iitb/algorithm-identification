#define _GLIBCXX_DEBUG
#pragma GCC diagnostic ignored "-Wsign-compare"
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define INF 1e9 + 7;
int cnt = 0;

void merge(vector<int>& A, int left, int mid, int right) {
    int n1 = mid - left, n2 = right - mid;
    vector<int> L(n1 + 1), R(n2 + 1);
    rep(i, n1) L[i] = A[left + i];
    rep(i, n2) R[i] = A[mid + i];
    L[n1] = INF;
    R[n2] = INF;
    int i = 0;
    int j = 0;
    for (int k = left; k < right; k++) {
        cnt++;
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}
void merge_sort(vector<int>& A, int left, int right) {
    if (left + 1 < right) {
        int mid = left + (right - left) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid, right);
        merge(A, left, mid, right);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& e : A) {
        cin >> e;
    }
    merge_sort(A, 0, n);
    rep(i, n) {
        if (i) cout << " ";
        cout << A.at(i);
    }
    cout << "\n" << cnt << "\n";
}
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
}
