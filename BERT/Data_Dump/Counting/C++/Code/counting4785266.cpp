#include <bits/stdc++.h>
using namespace std;

#define MAX 2000000

void CountingSort(int A[], int B[], int k, int n) {
    int C[k + 1];
    for(int i = 0; i <= k; i++) C[i] = 0;
    for(int j = 0; j < n; j++) C[A[j]]++;
    for(int i = 1; i <= k; i++) C[i] = C[i] + C[i - 1];
    for(int j = n - 1; j >= 0; j--) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}

int main() {
    int n;
    cin >> n;
    int A[n], B[n];
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    CountingSort(A, B, 10000, n);

    for(int i = 1; i <= n; i++) {
        if(i > 1) cout << " ";
        cout << B[i];
    }

    cout << endl;

    return 0;
}
