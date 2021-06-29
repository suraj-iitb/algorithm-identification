#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
const double PI = 3.141592653589793;
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int n, S[550000], cnt = 0;

void printArr(int A[], int N) {
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void merge(int A[], int left, int mid, int right){
    int n1 = mid - left, n2 = right - mid, L[n1], R[n2];
    rep(i, n1) L[i] = A[left + i];
    rep(i, n2) R[i] = A[mid + i];
    L[n1] = INF;
    R[n2] = INF;
    int i = 0, j = 0;
    for (int k = left; k < right; k++) {
        cnt++;
        if (L[i] <= R[j]) A[k] = L[i++];
        else A[k] = R[j++];
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
    cin >> n;
    rep(i, n) cin >> S[i];
    mergeSort(S, 0, n);
    printArr(S, n);
    cout << cnt << endl;
}
