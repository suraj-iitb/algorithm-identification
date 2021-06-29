#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); (i)++)
using namespace std;
typedef long long ll;
// Welcome to my source code!

#define SENTINEL 2000000000

int cnt = 0;

void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1], R[n2];
    rep(i,n1) L[i] = A[left + i];
    rep(i,n2) R[i] = A[mid + i];
    L[n1] = R[n2] = SENTINEL;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        cnt++;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int A[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int n;
    cin >> n;
    int A[n];
    rep(i,n) cin >> A[i];

    mergeSort(A, 0, n);

    rep(i,n) {
        if (i) cout << ' ';
        cout << A[i];
    }

    cout << '\n' << cnt << endl;
}
