#include<stdio.h>
#define MAX_ELEMENTS 500010
#define INFTY  1000000010
int n,count;
void merge(int A[],int left,int mid,int right){
  
    int n1, n2,i,j,k;

    n1 = mid - left;
    n2 = right - mid;

int L[n1+1];
int R[n2+1];
    //L[0...n1], R[0...n2] を生成
    for(i=0; i<=n1-1; i++)  L[i] = A[left + i];
    for(i=0; i<=n2-1; i++)  R[i] = A[mid + i];
    
    L[n1] = INFTY;
    R[n2] = INFTY;

    i = 0;
    j = 0;

    for(k=left; k<=right-1; k++){
        count++;
        if(L[i]<=R[j])   A[k] = L[i++];
        else             A[k] = R[j++];
    }
}

void mergeSort(int A[],int left,int right){
    int mid;
    if(left+1 < right){
        mid = left+(right-left)/2;
        mergeSort(A, left, mid);
        mergeSort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main(void){
    int i;
    int S[MAX_ELEMENTS];

    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &S[i]);

    mergeSort(S,0,n);
    for(i=0; i<n; i++) printf(i != 0 ? " %d" : "%d", S[i]);
    printf("\n", count);
    printf("%d\n", count);
    return 0;
}
