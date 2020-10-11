#include <stdio.h>

#define MAX_VAL 10000
#define MAX_LEN 2000001

int C[MAX_VAL + 1];

void countingSort(unsigned short A[], unsigned short B[], int n) {
    int i;
    for (i = 0; i <= MAX_VAL; i++) C[i] = 0;
    for (i = 1; i <= n; i++) C[A[i]]++;
    for (i = 1; i <= MAX_VAL; i++) C[i] += C[i - 1];
    for (i = n; i >= 1; i--) {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
}

void printarray(unsigned short A[], int n) {
    int i;
    for (i = 1; i <= n; i++) {
        if (i > 1) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

int main(void) {
    int n, i;
    unsigned short A[MAX_LEN];
    unsigned short B[MAX_LEN];
    scanf("%d", &n);
    for (i = 1; i <= n; i++) scanf("%hd", &A[i]);
    countingSort(A, B, n);
    printarray(B, n);
    return 0;
}

