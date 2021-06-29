#include <stdio.h>

int selectionSort(int A[], int n) {
    int i, j, cnt = 0, minj, t;
    for(i = 0; i < (n-1); i++) {
        minj = i;
        for(j = i+1; j < n; j++) {
            if(A[j] < A[minj]) minj = j;
        }
        if(minj != i) {
            t = A[minj];
            A[minj] = A[i];
            A[i] = t;
            cnt++;
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

    int ans = selectionSort(A, n);
    print(A, n);
    printf("%d\n", ans);

    return 0;
}
