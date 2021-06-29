#include <stdio.h>
#include <limits.h>

#define SENTINEL INT_MAX

int cmpCnt = 0;

void merge(int S[], int left, int mid, int right) {
    int n1 = (mid + 1) - left;
    int n2 = right - mid;

    int L[n1 + 1], R[n2 + 1];
    for (int i = 0; i < n1; i++) L[i] = S[left + i];
    for (int i = 0; i < n2; i++) R[i] = S[(mid + 1) + i];

    L[n1] = SENTINEL;
    R[n2] = SENTINEL;

    int i = 0, j = 0;

    for (int k = left; k <= right; k++) {
        cmpCnt++;
//        printf("L[%d]: %d, R[%d]: %d\n", i, L[i], j, R[j]);
        if (L[i] <= R[j]) {
            S[k] = L[i];
            i++;

        } else {
            S[k] = R[j];
            j++;
        }
    }

    // for (int p = left; p <= right; p++) {
    //     printf("S[%d]: %d\n", p, S[p]);
    // }
}

void mergeSort(int S[], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = (left + right) / 2;
//    printf("left: %d, mid: %d, right: %d\n", left, mid, right);
    mergeSort(S, left, mid);
    mergeSort(S, mid + 1, right);
//    printf("call merge arg[left: %d, mid: %d, right: %d]\n", left, mid+1, right);
    merge(S, left, mid, right);
}

int main() {
    int n;
    scanf("%d", &n);

    int S[n];
    for (int i = 0; i < n; i++) scanf("%d", &S[i]);

    mergeSort(S, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d", S[i]);
        } else {
            printf("%d ", S[i]);
        }
    }
    printf("\n%d\n", cmpCnt);

    return 0;
}

