#include <iostream>
#define MAX 2000000

using namespace std;

int n;
int C[10000];

void countingSort(const int *A, int *B, int k) {
    for ( int i = 0; i <= k; ++i ) {
        C[i] = 0;
    }

    for ( int j = 0; j < n; ++j ) {
        C[A[j]]++;

    }

    for ( int i = 1; i <= k; ++i ) {
        C[i] = C[i] + C[i-1];
    }

    for ( int j = n-1;j >= 0; --j ) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}

int main() {
    cin >> n;
    int A[MAX];
    int B[MAX];
    for ( int i = 0; i < n; ++i ) {
        cin >> A[i];
    }
    int max = A[0];
    for (int i = 1; i < n; ++i ) {
        if ( A[i] > max ) {
            max = A[i];
        }
    }

    countingSort(A,B,max);
    for (int i = 1; i <= n; ++i ) {
        if ( i > 1 ) cout << " ";
        cout << B[i];
    }
    cout << endl;
    return 0;
}
