#include <iostream>
#include <stdlib.h>
using namespace std;

#define VMAX 10001

void counting_sort(int A[], int B[], int C[], int k, int n) {
    for (int i = 0; i < k; i++) {
        C[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        C[A[i]]++;
    }

    for (int i = 1; i < k; i++) {
        C[i] = C[i] + C[i-1];
    }

    for (int i = n; i > 0; i--) {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
}

int main() {
    int n;
    cin >> n;
    int *A, *B;
    A = (int*)malloc(sizeof(int) * n + 1);
    B = (int*)malloc(sizeof(int) * n + 1);
    int C[VMAX];
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    counting_sort(A, B, C, VMAX, n);
    for (int i = 1; i <= n; i++) {
        if (i-1) cout << " ";
        cout << B[i];
    }
    cout << endl;
    return 0;
}

