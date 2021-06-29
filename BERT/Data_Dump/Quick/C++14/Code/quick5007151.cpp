#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(v) v.begin(), v.end()

int partition(vector<pair<char, int>> &A, int p, int r) {
    int x = A[r].second;
    int i = p - 1;
    for (int j = p; j < r; ++j) {
        if (A[j].second <= x) {
            ++i;
            swap(A[i], A[j]);
        }
    }
    swap(A[i+1], A[r]);
    return i+1;
}

void quickSort(vector<pair<char, int>> &A, int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }
}

void merge(vector<pair<char, int>> &A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    vector<pair<char, int>> L(n1+1), R(n2+1);
    rep(i, n1) L[i] = A[left + i];
    rep(i, n2) R[i] = A[mid + i];
    L[n1].second = 2e9;
    R[n2].second = 2e9;
    int i = 0, j = 0;
    for (int k = left; k < right; ++k) {
        if (L[i].second <= R[j].second) {
            A[k] = L[i];
            ++i;
        } else {
            A[k] = R[j];
            ++j;
        }
    }
    return;
}

void mergeSort(vector<pair<char, int>> &A, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }

    return;
}

int main() {
    int N; cin >> N;
    vector<pair<char, int>> A(N);
    rep(i, N) cin >> A[i].first >> A[i].second;
    auto B = A;
    quickSort(A, 0, N-1);
    mergeSort(B, 0, N);
    bool flg = true;
    rep(i, N) {
        if (A[i].first != B[i].first) {
            flg = false;
            break;
        }
    }
    if (flg) cout << "Stable" << endl;
    else cout << "Not stable" << endl;
    rep(i, N) {
        cout << A[i].first << " " << A[i].second << endl;
    }
}
