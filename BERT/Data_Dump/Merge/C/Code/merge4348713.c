#include <stdio.h>

int ans = 0;

void merge(int *A, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1+1]; int R[n2+1];
    int i, j, k;
    for (i = 0; i < n1; i++) {
        L[i] = A[left+i];
    }
    for (i = 0; i < n2; i++) {
        R[i] = A[mid+i];
    }
    L[n1] = (1e+9)+1;
    R[n2] = (1e+9)+1;
    i = 0; j = 0;
    for (k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        ans++;
    }
}

void mergeSort(int *A, int left, int right) {
    if (left+1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(void) {
    int n, i;
    scanf("%d", &n);
    int S[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    mergeSort(S, 0, n);

    for (i = 0; i < n; i++) {
        printf("%d", S[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    printf("%d\n", ans);
    return 0;
}
