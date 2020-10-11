#include <stdio.h>
#include <stdlib.h>
 
int L[1000000], R[1000000];
int count = 0;
 
void merge(int A[], int left, int mid, int right) {
    int i, j, k, n1, n2;
    n1 = mid - left;
    n2 = right - mid;
     
    for (i = 0; i < n1; i++) {
        L[i] = A[left + i];
    }
    for (i = 0; i < n2; i++) {
        R[i] = A[mid + i];
    }
 
    L[n1] = 2000000000;
    R[n2] = 2000000000;
    i = 0; 
    j = 0;
 
    for (k = left; k < right; k++) {
        count++;
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i = i + 1;
        }
        else {
            A[k] = R[j];
            j = j + 1;
        }
    }
}
 
void mergeSort(int A[], int left, int right) {
    int mid;
     
    if ((left + 1) < right) {
        mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}
 
int main(void)
{
    int n, i;
    int A[500000];
 
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
 
    mergeSort(A, 0, n);
 
    for (i = 0; i < n; i++) {
        printf("%d", A[i]);
 
        if (i != (n - 1)) {
            putchar(' ');
        }
        else {
            putchar('\n');
        }
    }
 
    printf("%d\n", count);
 
    return 0;   
}
