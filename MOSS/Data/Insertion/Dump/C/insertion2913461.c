#include <stdio.h>

static const int N=1000;

void trace(int *A, int n) {
    int i;

    for (i=0; i<n; i++) {
        if (i>0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

void sort(int *A, int n) {
    int i, j, tmp;

    for (i=0;i<n;i++) {
        for (j=i+1;j<n;j++) {
            if (A[j]<A[i]) {
                tmp=A[i];
                A[i]=A[j];
                A[j]=tmp;
            }
        }
    }
}

int main(void) {
    int n, i;
    int A[N+1];

    scanf("%d", &n);
    for (i=0; i<n; i++) scanf("%d", &A[i]);

    //trace(A, n);
    for (i=1; i<=n; i++) sort(A, i), trace(A, n);

    return 0;
}

