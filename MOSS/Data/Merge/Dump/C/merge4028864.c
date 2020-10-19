#include<stdio.h>
#define MAX 500000
#define SENTINEL 2000000000

int L[MAX/2+2],R[MAX/2+2];
int cnt;

void merge(int A[],int n,int left,int mid,int right){
    int n1=mid-left;
    int n2=right-mid;

    for(int i=0;i<n1;i++)L[i]=A[left+i];
    for(int i=0;i<n2;i++)R[i]=A[mid+i];
    L[n1]=SENTINEL;
    R[n2]=SENTINEL;
    int i=0,j=0;
    for(int k=left;k<right;k++){
        cnt++;
        if(L[i]<=R[j]){
            A[k]=L[i];
            i++;
        }
        else{
            A[k]=R[j];
            j++;
        }
    }
}

void mergesort(int A[],int n,int left,int right){
    if(left+1<right){
        int mid=(left+right)/2;
        mergesort(A,n,left,mid);
        mergesort(A,n,mid,right);
        merge(A,n,left,mid,right);
    }
}

int main(void){
    int n;
    scanf("%d",&n);
    int A[n];
    for(int i;i<n;i++)scanf("%d",&A[i]);

    cnt=0;
    mergesort(A,n,0,n);

    for(int i=0;i<n-1;i++){
        printf("%d ",A[i]);
    }
    printf("%d\n",A[n-1]);
    printf("%d\n",cnt);

    return 0;
}