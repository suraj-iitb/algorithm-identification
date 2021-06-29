#include<stdio.h>
#define MAX 500000

int cnt;
int L[MAX/2+2],R[MAX/2+2];

void merge(int A[],int n,int left,int mid,int right){
  int n1,n2,i,j,k;
  
  n1=mid-left;
  n2=right-mid;
  
  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1] = 2000000000;
  R[n2] = 2000000000;
  i=0;
  j=0;
  for(k=left;k<right;k++){
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

void mergeSort(int A[],int n,int left,int right){
  int mid;
  
  if(left+1<right){
    mid = (left + right)/2;
    mergeSort(A, n,left, mid);
    mergeSort(A, n,mid, right);
    merge(A,n, left, mid, right); 
  }
}


int main(){
  int A[MAX],i,n;
  cnt=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  mergeSort(A,n,0,n);

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);

  return 0;
}
