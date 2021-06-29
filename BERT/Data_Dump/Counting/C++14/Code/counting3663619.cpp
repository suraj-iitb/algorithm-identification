#include <bits/stdc++.h>
using namespace std;

#define N_MAX 2000000
#define V_MAX 10000

void countingSort(short A[], short B[], long n) {
    long C[V_MAX + 1];
    for (long i = 0; i < V_MAX + 1; i++) {
        C[i]  = 0;
    }
    
    for (long i = 0; i < n; i++) {
        C[A[i]]++;
    }
    
    for (long i = 1; i < V_MAX + 1; i++) {
        C[i] += C[i - 1];
    }
    
    for (long i = n - 1; i >= 0; i--) {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
}

int main() {
    long n;
    cin >> n;
    short A[N_MAX];
    for (long i = 0; i < n; i++) {
        cin >> A[i];
    }
    
    short B[N_MAX];
    countingSort(A, B, n);
    
    for (long i = 0; i < n; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << B[i];
        if (i == n - 1) {
            cout << endl;
        }
    }
}
