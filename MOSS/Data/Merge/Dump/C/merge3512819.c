#include <stdio.h>
#include <limits.h>

int exchanged = 0;

void merge(int A[], int left, int mid, int right) {

    int n1 = mid - left;
    int n2 = right - mid;

    int L[n1];
    int R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }

    for (int i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0;
    int j = 0;

    for (int k = left; k < right; k++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
            exchanged++;
        } else {
            A[k] = R[j];
            j++;
            exchanged++;
        }
    }
}

void mergeSort(int A[], int left, int right) {

    if (left + 1 < right) {
        int mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main() {

    int num;
    scanf("%d", &num);

    int A[num];
    for (int i = 0; i < num; i++) {
        scanf("%d", &A[i]);
    }

    mergeSort(A, 0, num);

    for (int i = 0; i < num; i++) {
        printf("%d", A[i]);
        if (i != num - 1) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    printf("%d\n", exchanged);

    return 0;
}

