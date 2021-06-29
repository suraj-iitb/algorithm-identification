#include <iostream>
#define NMAX 100
#define AMAX 100
using namespace std;

int selectionSort(int *A, int n) {
    int exc = 0;
    for (int i=0; i<n; i++) {
        int minj = i;
        for (int j=i; j<n; j++) {
            if ( A[j] < A[minj] ) {
                minj = j;
            }
        }
        if ( A[i] != A[minj] ) {
            swap( A[i], A[minj] );
            exc += 1;
        }
    }
    return exc;
}

int main() {
    // input
    int n;
    cin >> n;

    int A[NMAX];
    for (int i=0; i<n; i++) {
        cin >> A[i];
    }

    // solve
    int exc = selectionSort(A, n);

    // output
    for (int i=0; i<n; i++) {
        cout << A[i];
        if (i == n-1) {
            cout << endl;
        } else cout << " ";
    }
    cout << exc << endl;
}
