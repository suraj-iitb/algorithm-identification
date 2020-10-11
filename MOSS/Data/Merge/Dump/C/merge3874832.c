#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

static int compare = 0;

static void merge(int A[], int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    int i, j, k;
    int *L, *R;

    L = malloc(sizeof(int) * n1);
    R = malloc(sizeof(int) * n2);
    for ( i = 0; i < n1; i++ ) {
        L[i] = A[left + i];
    }
    for ( i = 0; i < n2; i++ ) {
        R[i] = A[mid + i];
    }

    
    for ( i = 0, j = 0, k = left; k < right; k++ ) {
        compare++;
        if ( (i < n1) && (j < n2) ) {
            if ( L[i] <= R[j] ) {
                A[k] = L[i];
                i++;
            } else {
                A[k] = R[j];
                j++;
            }
        } else if ( i < n1 ) {
            A[k] = L[i];
            i++;
        } else if ( j < n2 ) {
            A[k] = R[j];
            j++;
        } else {
            assert( 0 ) ;
        }
    }
    free(L);
    free(R);

    return;
}

static void MergeSort(int A[], int left, int right) {
    if ( left + 1 >= right ) {
        return;
    }

    int mid = (left + right) / 2;
    MergeSort(A, left, mid);
    MergeSort(A, mid, right);
    merge(A, left, mid, right);
}

int main(int argc, char* argv[]) {
    int n, i;
    int* S;

    scanf("%d\n", &n);
    S = malloc(sizeof(int) * n);
    for ( i = 0; i < n; i++ ) {
        int s;
        scanf("%d", &s);
        S[i] = s;
        (void)fgetc(stdin);
    }

    MergeSort(S, 0, n);

    for ( i = 0; i < n; i++ ){
        printf("%d", S[i]);
        if ( i + 1 < n ){
            printf(" ");
        }
    }
    printf("\n");

    printf("%d\n", compare);

    return 0;
}

