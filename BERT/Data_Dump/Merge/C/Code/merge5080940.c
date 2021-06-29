#include <stdio.h>
#define N 500000
#define INFTY 2000000000

int count;
void merge(int A[], int left, int mid, int right){
  int n1,n2,i,j,k;
  n1= mid -left;
  n2= right-mid;
  int L[n1],R[n2];
  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];
  L[n1]=INFTY;
  R[n2]=INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    count++;
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }else{
      A[k]=R[j];
      j++;
    }
  }
}

void mergeSort(int A[], int left,int right){
int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
    }
}

int main(){
  int n,i,left,right;
  int A[N];

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);
  left=0;
  right=n;
  mergeSort(A,left,right);

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}

