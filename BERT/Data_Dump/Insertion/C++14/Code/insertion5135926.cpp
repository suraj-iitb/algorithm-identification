#include <bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
const double PI = 3.141592653589793;
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

void printArr(int A[], int N) {
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

void insertionSort(int A[], int N) {
    int v, j;
    for (int i = 1; i < N; i++) {
        printArr(A, N);
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
    }
    printArr(A, N);
}

int main() {
    int N, A[1100], cnt;
    cin >> N;
    rep(i, N) cin >> A[i];
    insertionSort(A, N);
}
