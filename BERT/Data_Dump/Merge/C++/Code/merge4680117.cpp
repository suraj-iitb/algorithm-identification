#include <stdio.h>

#define INF (1 << 30)
#define NMAX 500000

int merge(int A[], int left, int mid, int right) {
    int L[NMAX], R[NMAX], i, j, k, cnt;
    for (i = 0; i < mid - left; i++) {
        L[i] = A[left + i];
    }
    L[i] = INF;
    for (i = 0; i < right - mid; i++) {
        R[i] = A[mid + i];
    }
    R[i] = INF;
    i = 0, j = 0, cnt = 0;
    for (k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
            //cnt += mid - left - i; 
        }
        cnt++;
    }
    return cnt;
}

int mergeSort(int A[], int left, int right) {
    if (right - left <= 1) {
        return 0;
    }
    int mid = (left + right) / 2, cnt = 0;
    cnt += mergeSort(A, left, mid);
    cnt += mergeSort(A, mid, right);
    cnt += merge(A, left, mid, right);
    return cnt;
}

int main() {
    int A[NMAX], N = 50000;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    int cnt = mergeSort(A, 0, N);
    for (int i = 0; i < N; i++) {
        printf("%d", A[i]);
        if (i == N-1) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
    printf("%d\n", cnt);
    return 0;
}

