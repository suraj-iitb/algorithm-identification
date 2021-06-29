#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int selectionSort(vector<int>& A, int N) {
    int t, sw = 0, minj;
    for (int i = 0; i < N - 1; i++) {
        minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) minj = j;
        }
        swap(A[i], A[minj]);
        if (i != minj) sw++;
    }
    return sw;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int sw = selectionSort(A, N);
    for (int i = 0; i < N; i++) {
        if (i != 0) cout << " ";
        cout << A[i];
    }
    cout << endl << sw << endl;
    return 0;
}
