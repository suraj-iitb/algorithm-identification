#include<stdio.h>
int cnt=0;
#define N 1000000000

void merge(int A[],int left,int right,int mid){
    int n1=mid-left;
    int n2=right-mid;
    int L[1000000],R[1000000];
    int i,j,k;
    for(i=0;i<n1;i++){
        L[i]=A[left+i];
    }
    for(i=0;i<n2;i++){
        R[i]=A[mid+i];
    }
    L[n1]=R[n2]=N;
    i=0,j=0;
    for(k=left;k < right;k++){
        cnt++;
        if(L[i] <=R[j]){
            A[k]=L[i++];
        }else{
            A[k]=R[j++];
        }
    }
    return;
}
void mergesort(int A[],int left,int right){
    int mid=0;
    if(left+1 < right){
    mid=(left+right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,right,mid);
    }
    return;
}

int main(){
    int left=0,right,i,n,A[10000000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    right=n;
    mergesort(A,left,right);
    for(i=0;i<n;i++){
        if(i!=0){
            printf(" ");
        }
        printf("%d",A[i]);
    }
    printf("\n%d\n",cnt);
    return 0;
}
