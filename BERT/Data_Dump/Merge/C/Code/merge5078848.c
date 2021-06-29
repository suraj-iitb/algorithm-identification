#include <stdio.h>
#include <math.h>

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int L[250002], R[250002], cnt = 0;

int main(){
    int i;
    int n, S[500000];
    
    scanf("%d", &n);
    for( i=0; i<n; i++ ) {
        scanf("%d", &S[i]);
    }
    mergeSort(S, 0, n);
    
    for( i=0; i<n; i++ ) {
        printf("%d", S[i]);
        if( i == n-1 )
            printf("\n");
        else
            printf(" ");
    }
    
    printf("%d\n", cnt);
    
    return 0;
}

void merge(int S[], int left, int mid, int right) {
    int i, j, k;
    int n1, n2;
    n1 = mid - left;
    n2 = right - mid;
    
    for( i=0; i<n1; i++ )
        L[i] = S[left+i];
    
    for( i=0; i<n2; i++ )
        R[i] = S[mid + i];
    
    L[n1] = INFINITY;
    R[n2] = INFINITY;
    i = 0;
    j = 0;
    
    for( k=left; k<right; k++ ) {
        cnt++;
        if( L[i] <= R[j] ) {
            S[k] = L[i];
            i += 1;
        } else {
            S[k] = R[j];
            j += 1;
        }
    }
}

void mergeSort(int S[], int left, int right) {
    int mid;
    
    if( left+1 < right ) {
        mid = ( left + right ) / 2;
        mergeSort(S, left, mid);
        mergeSort(S, mid, right);
        merge(S, left, mid, right);
    }
}
