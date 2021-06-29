#include<stdio.h>

#define MAX 1000000001

void mergesort(int *,int,int);
void merge(int *,int,int,int);

int c,A[500000];

int main(){
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  
  mergesort(A,0,n-1);
  
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1)printf(" ");
    else printf("\n");
  }
  printf("%d\n",c);
  
  return 0;
}

void mergesort(int *A,int left,int right){
  int mid;
  if(left < right){
    mid = (left + right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid+1,right);
    merge(A,left,mid,right);
  }
}

void merge(int *A,int left,int mid,int right){
  int n1,n2,i,j,k;

  n1 = mid - left+1;
  n2 = right - mid;

  int L[n1],R[n2];

  for(i=0;i<n1;i++)L[i] = A[left+i];
  for(i=0;i<n2;i++)R[i] = A[mid+i+1];
  L[n1] = MAX;
  R[n2] = MAX;
  i=0;
  j=0;
  for(k=left;k<=right;k++){
    c++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
  }
}

