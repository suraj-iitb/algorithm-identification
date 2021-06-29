#include <iostream>
#include <stdio.h>

using namespace std;

void trace(int A[], int N) {
    for(int i = 0 ; i < N ; i++) {
        if(N-1 != i) {
            printf("%d ", A[i]);
        } else {
            printf("%d", A[i]);
        }
    }
    printf("\n");
}

void insertion(int A[], int N) {
    int c, j;
    for (int i = 1; i < N; i++) {
        c = A[i];
        j = i - 1;
        while(j >= 0 && c < A[j]) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = c;
        trace(A, N);
    }
}

int main(void) {

    int A[100], N;
    cin >> N;

    for (int i = 0; i < N; i ++) cin >> A[i];

    trace(A, N);
    insertion(A, N);

    return 0;
}
