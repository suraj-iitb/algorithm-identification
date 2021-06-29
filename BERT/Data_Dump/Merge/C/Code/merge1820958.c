#include<stdio.h>

#define MAX 500000

int n;

int merge(int *A, int left, int mid, int right) {
  
  int cnt=0,n1,n2,L[MAX],R[MAX],i,j,k;
  
  n1 = mid - left;
  n2 = right - mid;

  for(i=0;i<=n1;i++){
    L[i] = i;
  }
  for(i=0;i<=n2;i++){
    R[i] = i;
  }
  
  for(i=0;i<n1;i++){
    L[i] = A[left + i];
  }
  for(i=0;i<n2;i++){
    R[i] = A[mid + i];
  }
  L[n1] = 10e9+1;
  R[n2] = 10e9+1;
  
  i = 0;
  j = 0;
  
  // merge from two list to one list
  for( k = left ; k < right ; k++){
    if( L[i] <= R[j] ){
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
    }
    cnt++;
  }

  
  return cnt;
}

int mergeSort(int *A, int left, int right){
  int mid,cnt=0;
  
  if(left+1 < right){
    mid = (left + right)/2;
    cnt += mergeSort(A, left, mid);
    cnt += mergeSort(A, mid , right);
    cnt += merge(A, left, mid, right);
  }
  return cnt;
}


int main(char args[]){
  
  int S[MAX],cnt=0,i;
  
  // input 
  scanf("%d",&n);
  for(i=0;i<n;i++) {
    scanf("%d",&S[i]);
  }
  
  cnt = mergeSort(S,0,n);
  
  // output
  for(i=0;i<n-1;i++) {
    printf("%d ",S[i]);
  }
  printf("%d\n",S[n-1]);
  printf("%d\n",cnt);
  
  return 0;  
}
