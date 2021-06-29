#include<stdio.h>
using namespace std;

void trace(int A[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        if (i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

void insertionsort(int A[], int n) {
    int i, j, v;
    for (i = 1; i < n; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        trace(A, n);
    }
}

int main() {
    int n, i;
    int A[100];
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &A[i]);
    
    trace(A, n);
    insertionsort(A, n);
    
    return 0;
}
