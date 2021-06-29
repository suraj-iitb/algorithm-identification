/*
    マージソート
    https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/5/ALDS1_5_B
*/
#include <bits/stdc++.h>
using namespace std;

// global
int cnt;

void trace(vector<int> A) {
    for (size_t i = 0; i < A.size(); i++) {
        cout << A[i];
        cout << ((i != A.size() - 1) ? " " : "\n");
    }
}

void merge(vector<int> &A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    vector<int> L;
    vector<int> R;
    for (int i = 0; i < n1; i++) {
        L.push_back(A.at(left + i));
    }

    for (int i = 0; i < n2; i++) {
        R.push_back(A.at(mid + i));
    }

    L[n1] = 1000000009;
    R[n2] = 1000000009;
    int i = 0, j = 0;

    for (int k = left; k < right; k++) {
        cnt++;
        if (L[i] <= R[j]) {
            A[k] = L.at(i++);
        } else {
            A[k] = R.at(j++);
        }
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
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    mergeSort(A, 0, n);

    trace(A);
    cout << cnt << endl;
}
