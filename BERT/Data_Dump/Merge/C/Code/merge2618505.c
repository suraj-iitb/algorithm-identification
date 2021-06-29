#include <stdio.h>
#define MAX 500001
#define SENTINEL 1e9+1

int L[MAX/2+2], R[MAX/2+2];
int cnt;

void merge(int A[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left;
    int n2 = right - mid;
    for (i = 0; i < n1; i++) { L[i] = A[left + i]; }
    for (i = 0; i < n2; i++) { R[i] = A[mid + i]; }

    L[n1] = R[n2] = SENTINEL;

    i = 0; j = 0;

    for (k = left; k < right; k++) {
        cnt++;
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        }
        else {
            A[k] = R[j++];
        }
    }
}

void mergeSort(int A[], int left, int right) {
    if (left+1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {
    int A[MAX], n, i;
    cnt = 0;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    mergeSort(A, 0, n);

    for (i = 0; i < n; i++) {
        printf("%d", A[i]);
        printf( (i == n-1) ? "\n" : " ");
    }

    printf("%d\n", cnt);

    return 0;
}
