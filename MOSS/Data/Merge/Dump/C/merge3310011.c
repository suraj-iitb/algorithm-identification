#include <stdio.h>
#define N 500001
#define INFTY 1000000000
int A[N],L[N],R[N],cnt=0;

void merge(int A[],int left,int mid,int right){
  int n1,n2,i,j,k;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++)L[i]=A[left+i];
  for(i=0;i<n2;i++)R[i]=A[mid+i];
  
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }
    else {
      A[k]=R[j];
      j++;
    }
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
  int i,j;

  scanf("%d",&j);
  for(i=0;i<j;i++)scanf("%d",&A[i]);

  mergeSort(A,0,j);


  for(i=0;i<j;i++){
    printf("%d",A[i]);
    if(i<j-1)printf(" ");
  }
  printf("\n%d\n",cnt);
  
  return 0;
}

