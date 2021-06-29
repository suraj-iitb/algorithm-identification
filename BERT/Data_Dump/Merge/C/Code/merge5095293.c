#include<stdio.h>
#define MAX 500000
#define INFTY 2000000000

void merge(int *,int ,int ,int ,int);
void mergeSort(int *,int ,int ,int );

int L[MAX],R[MAX];
int count=0;

int main()
{
    int A[MAX],N,i;
 scanf("%d",&N);
 if(N<=MAX){
 for(i=0;i<N;i++) scanf("%d",&A[i]);

 mergeSort(A,N,0,N);

 for(i=0;i<N-1;i++) printf("%d ",A[i]);
     printf("%d\n",A[i]);

 printf("%d\n",count);
 }
 return 0;
}

void merge(int A[],int n,int left,int mid,int right)
{
    int n1,n2,i,j,k;

    n1=mid-left;
    n2=right-mid;

    for(i=0;i<n1;i++) L[i]=A[left+i];
    for(i=0;i<n2;i++) R[i]=A[mid+i];

    L[n1]=R[n2]=INFTY;

    i=0,j=0;
    
    for(k=left;k<right;k++){

        count++;
        if(L[i]<=R[j]){
        A[k]=L[i++];
    }
    else{
        A[k]=R[j++];
    }
}
}

void mergeSort(int A[],int n,int left,int right){

    if(left+1<right){
        int mid;

        mid=(left+right)/2;
        mergeSort(A,n,left,mid);
        mergeSort(A,n,mid,right);
        merge(A,n,left,mid,right);
    }
}
