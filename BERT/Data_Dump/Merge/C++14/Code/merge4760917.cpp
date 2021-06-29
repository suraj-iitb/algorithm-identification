#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int cnt = 0;

void merge(vector<int> &A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;

    vector<int> L(n1 + 1);
    vector<int> R(n2 + 1);
    for (int i = 0; i < n1; i++) {
        L.at(i) = A.at(left + i);
    }
    for (int i = 0; i < n2; i++) {
        R.at(i) = A.at(mid + i);
    }
    L.at(n1) = INT_MAX;
    R.at(n2) = INT_MAX;

    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        if (L.at(i) <= R.at(j)) {
            A.at(k) = L.at(i);
            i++;
        } else {
            A.at(k) = R.at(j);
            j++;
        }
        cnt++;
    }
}

void mergeSort(vector<int> &A, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    fastIO;
    int n;
    cin >> n;

    vector<int> A(n);
    rep(i, n) cin >> A.at(i);
    mergeSort(A, 0, A.size());
    for (size_t i = 0; i < A.size(); i++) {
        cout << A.at(i) << ((i != A.size() - 1) ? " " : "\n");
    }
    cout << cnt << endl;
}

