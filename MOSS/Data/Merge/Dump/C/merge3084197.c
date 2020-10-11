#include <stdio.h>
#include <stdlib.h>
#define SENTINEL (1<<30)
#define MAX_LENGTH 500001

int count = 0, A[MAX_LENGTH];
void Merge(left, mid, right){
    int n1 = mid - left;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (int ix = 0; ix < n1; ix++)
        L[ix] = A[left + ix];
    for (int ix = 0; ix < n2; ix++)
        R[ix] = A[mid + ix];
    L[n1] = SENTINEL;
    R[n2] = SENTINEL;
    int i = 0, j = 0;
    for (int kx = left; kx < right; kx++){
        if ( R[j] > L[i] ){
            A[kx] = L[i];
            i++;
        }
        else {
            A[kx] = R[j];
            j++;
        }
        count++;
    }
}

void MergeSort(left, right){
    if ( left+1 < right ){
        int mid = (left + right)/2;
        MergeSort(left, mid);
        MergeSort(mid, right);
        Merge(left, mid, right);
    }
}

int main(){
    int n;
    scanf("%d\n",&n);
    for (int ix = 0; ix < n; ix++)
        scanf("%d",&A[ix]);
        
    MergeSort(0,n);
    for (int ix = 0; ix < n; ix++){
        if (ix != n-1) printf("%d ",A[ix]);
        else printf("%d\n",A[ix]);
    }
    printf("%d\n",count);
    return 0;
}
