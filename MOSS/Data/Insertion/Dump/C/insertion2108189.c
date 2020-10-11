#include <stdio.h>
#define N 100

void print_numrow(int A[], int n) {
    int i;

    for (i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d\n", A[i]);
        } else {
            printf("%d ", A[i]);
        }
    }
}

int main(void) {
    int i, j, n, v;
    int A[N];

    scanf("%d", &n);
    for (i = 0; i < N; i++) A[i] = 0;
    for (i = 0; i < n; i++) scanf("%d", &A[i]);

    print_numrow(A, n);
    for (i = 1; i < n; i++) {
        v = A[i];
        j = i - 1;
        while ((j >= 0) && (A[j] > v)) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        print_numrow(A, n);
    }

    return 0;

}
