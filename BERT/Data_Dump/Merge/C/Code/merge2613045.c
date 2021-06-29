#include<stdio.h>
#define INFTY 2000000000;
 
int cnt = 0;
 
void merge(int A[], int left, int mid, int right){
  int n1, n2, i, j, k;
  int L[250002], R[250002];
 
  n1 = mid-left;
  n2 = right-mid;
 
  for(i=0; i<n1; i++){
    L[i] = A[left + i];
  }
 
  for(i=0; i<n2; i++){
    R[i] = A[mid + i];
  }
 
  L[n1] = INFTY;
  R[n2] = INFTY;
 
  i=0;
  j=0;
 
  for(k=left; k<right; k++){
    cnt++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i+1;
    }else{
      A[k] = R[j];
      j = j+1;
    }
  }
}
 
void mergeSort(int A[], int left, int right){
  int mid;
 
  if(left+1 < right){
    mid = (left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
 
  }
}
 
int main(){
  int i, n, left, right;
  int S[500000];
 
  scanf("%d", &n);
 
  for(i=0; i<n; i++){
    scanf("%d", &S[i]);
  }
 
  left = 0;
  right = n;
 
  mergeSort(S,left,right);
 
  printf("%d", S[0]);
 
  for(i=1; i<n; i++){
    printf(" %d", S[i]);
  }
  printf("\n");
  printf("%d", cnt);
  printf("\n");
}
