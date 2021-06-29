#include <stdio.h>
#include <stdlib.h>


#define INFTY 1000000001

int comp = 0;
int *L, *R;

void merge(int *A, const int left, const int mid, const int right) {
    int n1 = mid - left;
    int n2 = right - mid;

    for (int i = 0; i < n1; i++) {
        L[i] = A[left+i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = A[mid+i];
    }
    L[n1] = INFTY;
    R[n2] = INFTY;
    int i = 0;
    int j = 0;
    for (int k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
            comp++;
        }
        else {
            A[k] = R[j];
            j++;
            comp++;
        }
    }
}

void merge_sort(int *A, const int left, const int right) {
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        merge_sort(A, left, mid);
        merge_sort(A, mid, right);
        merge(A, left, mid, right);
    }
    return;
}

int main (void) {

    int n;

    scanf("%d", &n);
    int* A = new int[n];
    L = new int[n];
    R = new int[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    merge_sort(A, 0, n);

    for (int i = 0; i < n; i++) {
        printf("%d", A[i]);
        if (i == n-1) printf("\n");
        else printf(" ");
    }
    printf("%d\n", comp);
}

