#include<bits/stdc++.h>
using namespace std;

const int n_MAX = 2000010;
const int A_MAX = 10010;

int main() {
    int n, C[A_MAX+1];
    int *A, *B;

    cin >> n;

    A = (int*)malloc( sizeof(int) * n + 1);
    B = (int*)malloc( sizeof(int) * n + 1);
    
    for ( int i = 0; i <= A_MAX; i++) {
        C[i] = 0;
    }
    for ( int i = 0; i < n; i++) {
        scanf("%d", &A[i+1]);
        C[A[i+1]]++;
    }    
    for (int i = 1; i <= A_MAX; i++) {
        C[i] = C[i] + C[i-1];
    }
    for (int j = 1; j <= n; j++) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
    for (int i = 1; i <= n; i++) {
        if (i>1) {cout << " ";}
        cout << B[i];
    }
    cout << endl;

    return 0;
}
