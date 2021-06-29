#include<stdio.h>

void MergeSort(int*,int,int);
void Merge(int*,int,int,int);
#define INFTY 1000000000

int count=0;

int main(){
    int A[500000];
    int i,n;
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    MergeSort(A,0,n);
    for(i=0;i<n-1;i++){
        printf("%d ",A[i]);
    }
    printf("%d\n",A[n-1]);
    printf("%d\n",count);
    return 0;
}
void Merge(int *A, int left, int mid, int right){
    int n1,n2;
    int L[250002],R[250002];
    int i,j,k;

    n1=mid-left;
    n2=right-mid;

    for(i=0;i<=n1-1;i++){
        L[i]=A[left+i];
    }
    for(i=0;i<=n2-1;i++){
        R[i]=A[mid+i];
    }
    L[n1]=INFTY;
    R[n2]=INFTY;
    i=0;
    j=0;
    for(k=left;k<right;k++){
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
            count++;
        }
        else {
            A[k]=R[j];
            j++;
            count++;
        }
    }
}
void MergeSort(int *A, int left, int right){
    int mid;
    if (left+1 < right){
        mid = (left + right)/2;
        MergeSort(A, left, mid);
        MergeSort(A, mid, right);
        Merge(A, left, mid, right);
    }
}
