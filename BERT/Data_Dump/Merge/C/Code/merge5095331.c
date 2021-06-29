#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count = 0;

int main(void) {
    int i, n;
    int a[500000];
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    merge_sort(a, 0, n);
    for (i = 0; i < n-1; i++) {
        printf("%d ", a[i]);
    }
    printf("%d\n", a[n-1]);
    printf("%d\n", count);
  
    return 0;
}

void merge(int A[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left;
    int n2 = right - mid;

    int *L = malloc(sizeof(int)*(n1+1));
    int *R = malloc(sizeof(int)*(n2+1));
    for (i = 0; i <= n1-1; i++) {
        L[i] = A[left+i];
    }
    for (i = 0; i <= n2-1; i++) {
        R[i] = A[mid+i];
    }
    L[n1] = INFINITY;
    R[n2] = INFINITY;

    i = 0;
    j = 0;
    for (k = left; k <= right-1; k++) {
        count++;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }

  free(L);
  free(R);
}
void merge_sort(int A[], int left, int right) {
    if (left + 1 < right) {
        int mid = 0;
        mid = (left + right)/2;
        merge_sort(A, left, mid);
        merge_sort(A, mid, right);
        merge(A, left, mid, right);
    }
}
