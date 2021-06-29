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

int selectionSort (int A[], int N) {
    int min_j, cnt = 0;
    for (int i = 0; i < N; i++) {
        min_j = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[min_j]) min_j = j;
        }
        swap(A[i], A[min_j]);
        if (i != min_j) cnt++;
    }
    return cnt;
}

int main() {
    int N, A[110], cnt;
    cin >> N;
    rep(i, N) cin >> A[i];
    cnt = selectionSort(A, N);
    printArr(A, N);
    cout << cnt << endl;
}

