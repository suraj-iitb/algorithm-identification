#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int n;

void CountingSort(int A[], int B[], int k) {
    int C[k+1];
    for(int i = 0; i < k+1; i++) {
        C[i] = 0;
    }
    for(int j = 1; j < n+1; j++) {
        C[A[j]]++;
    }
    for(int i = 1; i < k+1; i++) {
        C[i] = C[i] + C[i-1];
    }
    for(int j = 1; j < n+1; j++) {
        B[C[A[j]]] = A[j];
        C[A[j]]--;
    }
}

int main() {
    int A[2000001], B[2000001];
    cin >> n;
    for(int i = 1; i < n+1; i++) {
        cin >> A[i];
    }
    CountingSort(A, B, 10000);
    for(int i = 1; i < n+1; i++) {
        if(i > 1) cout << " ";
        cout << B[i];
    }
    cout << endl;
    return 0;
}
