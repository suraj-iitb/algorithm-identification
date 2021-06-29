#include <stdio.h>
#include <stdlib.h>
#define INFTY 1000000001
void mergeSort(int [],int,int);
void merge(int [],int,int,int);
int count = 0;
int A[500002];
int L[250001];
int R[250001];

int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    mergeSort(A,0,n);
    for(i=0;i<n;i++){
        if(i<n-1) printf("%d ",A[i]);
        else printf("%d\n",A[i]);
    }
    printf("%d\n",count);
    return 0;
}
void merge(int A[],int left,int mid,int right){
    int n1,n2,i,j,k;
    n1 = mid - left;
    n2 = right - mid;
    for(i=0;i<n1;i++){
        L[i] = A[left + i];
    }
    for(i=0;i<n2;i++){
        R[i] = A[mid+i];
    }
    L[n1] = INFTY;
    R[n2] = INFTY;
    i = 0;
    j = 0;
    for(k = left;k<right;k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i = i + 1;
            count++;
        }
        else{
            A[k] = R[j];
            j = j + 1;
            count++;
        }
    }
}
void mergeSort(int A[],int left,int right){
    int mid;
    if(left+1 < right){
        mid = (left + right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}
