#include <stdio.h>

int bubbleSort(int A[], int n) {
    int i, j, t, cnt = 0;
    for(i = 0; i < (n-1); i++) {
        for(j = n-1; j > i; j--) {
            if(A[j] < A[j-1]) {
                t = A[j];
                A[j] = A[j-1];
                A[j-1] = t;
                cnt++;
            }
        }
    }

    return cnt;
}

void print(int A[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        if(i > 0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

int main(void) {
    int n, A[100], i;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", &A[i]);

    int ans = bubbleSort(A, n);
    print(A, n);
    printf("%d\n", ans);

    return 0;
}
