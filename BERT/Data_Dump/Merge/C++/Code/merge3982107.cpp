#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


static int merge(int A[], int left, int mid, int right) {
    int *l, *r;
    int i, l_i, r_i;
    int n1 = mid - left;
    int n2 = right - mid;
    int ret = 0;

    l = (int*)malloc( sizeof(int) * (n1 + 1));
    r = (int*)malloc( sizeof(int) * (n2 + 1));

    for ( i = 0; i < n1; i++ ) {
        l[i] = A[left+i];
    }
    l[i] = INT_MAX;
    for ( i = 0; i < n2; i++ ) {
        r[i] = A[mid+i];
    }
    r[i] = INT_MAX;
    
    l_i = 0;
    r_i = 0;
    for ( i = left ; i < right ; i++ ) {
        if ( l[l_i] <= r[r_i] ) {
            A[i] = l[l_i];
            l_i++;
        } else {
            A[i] = r[r_i];
            r_i++;
        }
        ret++;
    }

    free(l);
    free(r);
    
    return ret;
}


static int mergeSort(int A[], int left, int right) {
    int r=0;
    int mid;
    
    if ( left + 1 < right ) {
        mid = (left + right) / 2;

        r += mergeSort(A, left, mid);
        r += mergeSort(A, mid, right);
        r += merge(A, left, mid, right);
    }

    return r;
}

int main(int argc, char* argv[]) {
    int n, i, r;
    int S[500000];

    scanf("%d\n", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &S[i]);
    }

    r = mergeSort(S, 0, n);

    for ( i = 0; i < n; i++ ) {
        printf("%d", S[i]);
        if ( i + 1 < n ){
            printf(" ");
        }
    }
    printf("\n");
    printf("%d\n", r);

    return 0;
}

