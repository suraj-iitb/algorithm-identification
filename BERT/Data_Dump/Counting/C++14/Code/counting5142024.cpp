#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
const double PI = 3.141592653589793;
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int n = 2200000, A[2200000], B[2200000], C[10001] = {0};

void countingSort(int A[], int n, int B[], int k) {
    for (int i = 0; i < n; i++) C[A[i]]++;
    for (int i = 0; i < k; i++) C[i] += C[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
}

void printArr(int A[], int n) {
    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << A[i + 1];
    }
    cout << endl;
}

int main() {
    cin >> n;
    rep(i, n) cin >> A[i];
    countingSort(A, n, B, 10000);
    printArr(B, n);
}
