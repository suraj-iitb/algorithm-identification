#include<stdio.h>
#include<limits.h>
void merge(int *,int,int,int);
void mergesort(int *,int,int);
int num=0;
int main(){
  int i,n,l=0,m;
  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  int r=n;
  mergesort(S,l,r);
  for(i=0;i<n;i++){
    if(i<n-1) printf("%d ",S[i]);
    else printf("%d\n",S[i]);
  }
  printf("%d\n",num);
  return 0;
}
void merge(int *A,int left,int mid,int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int i,j,k;
  int L[n1],R[n2];
  for(i = 0;i<n1;i++) L[i] = A[left + i];
  for(i = 0;i<n2;i++) R[i] = A[mid + i];
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    num++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else{ 
      A[k] = R[j];
      j = j + 1;
    }
  }
}
void mergesort(int *A,int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergesort(A, left, mid);
    mergesort(A, mid, right);
    merge(A, left, mid, right);
  }
}
