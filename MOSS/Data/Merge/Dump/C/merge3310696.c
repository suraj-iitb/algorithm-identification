#include<stdio.h>
#define INFTY 2000000000
#define N 500001

int n,count;

void merge(int A[],int left,int mid,int right){
    int n1,n2,i,j,k;
    
    n1=mid-left;
    n2=right-mid;
    int L[n1+1],R[n2+1];
    for(i=0;i<n1+1;i++) L[i]=A[left+i];
    for(i=0;i<n2+1;i++) R[i]=A[mid+i];
    L[n1]=R[n2]=INFTY;
    i=j=0;
    for(k=left;k<right;k++){
        count++;
        if(L[i]<=R[j])A[k]=L[i++];
        else A[k]=R[j++];
    }
}

void mergeSort(int A[],int left,int right){
    int mid;
    
    if(left+1<right){
        mid=(left+right)/2;
        mergeSort(A,left,mid);
        mergeSort(A,mid,right);
        merge(A,left,mid,right);
    }
}

int main(){
  int i;
  int A[N];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  mergeSort(A,0,n);
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",count);
   
  return 0;
}

