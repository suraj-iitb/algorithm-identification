#include <iostream>
using namespace std;

#define SIZE 200000

void CountingSort(int* A, int* B, int k, int n) {
    int C[10001] = {};
    
    for(int i = 0; i < n; ++i) {
        ++C[A[i]];
    }
    
    for(int i = 1; i <= k; ++i) {
        C[i] += C[i - 1];
    }

    for(int i = 0; i < n; ++i) {
        B[C[A[i]]] = A[i];
        --C[A[i]];
    }
}

int main(void) {
    int n;
    int k = 0;
    
    cin >> n;
    
    int* A = new int [n];
    int* B = new int [n + 1];
    
    for(int i = 0; i < n; ++i) {
        cin >> A[i];
        if(k < A[i]) {
            k = A[i];
        }
    }
    
    CountingSort(A, B, k, n);
    
    cout << B[1];
    for(int i = 2; i <= n; ++i) {
        cout << ' ' << B[i];
    }
    cout << endl;
    
    delete[] A;
    delete[] B;
    
    return 0;
}
