#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e9
#define ALL(v) v.begin(), v.end()

using namespace std;

int cnt;

void printArr(int A[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << A[i];
        if (i < n-1)
            cout << ' ';
    }
    cout << endl;
}

void selectionSort(int A[], int N) {
    int minj;
    REP(i, N) {
        minj = i;
        FOR(j, i, N) {
            if (A[j] < A[minj])
                minj = j;
        }
        if (minj != i) {
            swap(A[i], A[minj]);
            ++cnt;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];

    selectionSort(arr, n);
    printArr(arr, n);
    cout << cnt << endl;
}
