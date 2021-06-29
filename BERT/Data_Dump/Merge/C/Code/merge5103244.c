#include <stdio.h>
#define MAX 500000

void merge(int S[], int left, int mid, int right);
void mergeSort(int S[], int left, int rifgt);

int L[MAX/2+2], R[MAX/2+2];
int cnt=0, n;

int main(){
    int i;
    int S[MAX];
    scanf("%d", &n);
    for ( i = 0; i < n; i++ ) scanf("%d", &S[i]);
    mergeSort(S, 0, n);
    for ( i = 0; i < n; i++ ){
        if ( i > 0 ) printf(" ");
        printf("%d", S[i]);
    }
    printf("\n");
    printf("%d\n", cnt);
    return 0;
}

void merge(int S[], int left, int mid, int right){
    int n1, n2, i, j, k;
    n1 = mid - left;
    n2 = right - mid;

    for ( i = 0; i < n1; i++ ) L[i] = S[left+i];
    for ( i = 0; i < n2; i++ ) R[i] = S[mid+i];
    L[n1] = R[n2] = 2000000000;

    i = 0;
    j = 0;
    for ( k = left; k < right; k++ ){
        cnt++;
        if ( L[i] <= R[j] ) S[k] = L[i++];
        else S[k] = R[j++];
    }
}

void mergeSort(int S[], int left, int right){
    if ( left+1 < right ){
        int mid;
        mid = (left+right) / 2;
        mergeSort(S, left, mid);
        mergeSort(S, mid, right);
        merge(S, left, mid, right);
    }
}

