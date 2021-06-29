#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
const int MAX = 2000000;
const int EL_MAX = 10001;

void countingSort(int N, int A[], int B[]) {
    int C[EL_MAX];
    for (int i = 0; i <= EL_MAX; i++) {
        C[i] = 0;
    }
    
    for (int i = 0; i < N; i++) {
        C[A[i]]++;
    }
    
    for (int i = 0; i < EL_MAX; i++) {
        if (i != 0) {
            C[i] = C[i] + C[i-1];
        }
    }
    
    for (int j = N - 1; j >= 0; j--) {
        B[C[A[j]]-1] = A[j];
        C[A[j]]--;
    }
}

int main() {
    int N;
    int A[MAX], B[MAX];

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        B[i] = 0;
    }
    
    countingSort(N, A, B);
    
    
    for (int i = 0; i < N; i++) {
        if (i != 0) cout << " ";
        cout << B[i];
    }
    
    cout << endl;

    return 0;
}
