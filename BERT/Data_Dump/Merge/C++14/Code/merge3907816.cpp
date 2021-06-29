#include <bits/stdc++.h>
using namespace std;

int64_t cnt = 0;

// A[left:mid], A[mid:right] をマージする
void merge(vector<int> &A, int left, int mid, int right) {
    vector<int> L, R;
    // L, R 作成
    for (int i = left; i < right; i++) {
        if (i < mid) {
            L.push_back(A[i]);
        } else {
            R.push_back(A[i]);
        }
    }
    int l = 0, r = 0;
    for (int i = left; i < right; i++) {
        if (!(l < L.size())) {
            A[i] = R[r];
            r++;
        } else if (!(r < R.size())) {
            A[i] = L[l];
            l++;
        } else if (L[l] <= R[r]) {
            A[i] = L[l];
            l++;
        } else {
            A[i] = R[r];
            r++;
        }
        cnt++;
    }
}

// A[left:right] をマージソートする
void mergeSort(vector<int> &A, int left, int right) {
    // A[left:right] のサイズが 2 以上の場合
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

void mergeSort(vector<int> &A) {
    mergeSort(A, 0, A.size());
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; i++) cin >> S[i];
    mergeSort(S);

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << S[i];
    }
    cout << endl;
    cout << cnt << endl;

    return 0;
}

