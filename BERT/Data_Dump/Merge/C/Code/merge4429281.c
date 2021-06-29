#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

static int A[500000];
int cnt = 0;

void merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    int *L;
    int *R;
    int i, j, k;

    L = malloc(sizeof(int) * (n1 + 1) );
    R = malloc(sizeof(int) * (n2 + 1) );

    for ( i = 0; i < n1; i++ ) {
        L[i] = A[left + i];
    }
    for ( i = 0; i < n2; i++ ) {
        R[i] = A[mid + i];
    }
    
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    i = 0;
    j = 0;

    for ( k = left; k < right; k++ ) {
        if ( L[i] <= R[j] ) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        cnt++;
    }

    free(L);
    free(R);
}

void mergeSort(int A[], int left, int right)
{
    int mid;

    if ( left + 1 < right ) {
        mid = (left + right) / 2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(void)
{
    int n;

    scanf("%d", &n);
    for ( int i = 0; i < n; i++ ) {
        scanf("%d", &A[i]);
    }

    mergeSort(A, 0, n);

    for ( int i = 0; i < n; i++ ) {
        printf("%d", A[i]);
        if ( i != n - 1 ) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    printf("%d\n", cnt);

    return 0;
}
