#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cnt = 0;

void merge(int A[], int left, int mid, int right) {
    int i = 0;
    int j = 0;
    int k;
    int n1 = mid - left;
    int n2 = right - mid;
    int *L = (int *)malloc((n1 + 1) * sizeof(int));
    int *R = (int *)malloc((n2 + 1) * sizeof(int));
    memcpy(L, A + left, (n1 + 1) * sizeof(int));
    memcpy(R, A + mid, (n2 + 1) * sizeof(int));
    L[n1] = 2000000000;
    R[n2] = 2000000000;
    for (k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        cnt++;
    }
    free(R);
    free(L);
}

void mergeSort(int A[], int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

void printarray(int A[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (i) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

int main(void) {
    int n, i;
    int S[500000];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &S[i]);
    mergeSort(S, 0, n);
    printarray(S, n);
    printf("%d\n", cnt);
    return 0;
}

