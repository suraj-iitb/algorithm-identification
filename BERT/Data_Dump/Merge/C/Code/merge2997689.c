#include<stdio.h>
#define INF 600001
void mergeSort(int *,int,int);
void merge(int *,int,int,int);
int cnt=0;

int main(){
  int i, n;
  int s[INF];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  
  mergeSort(s,0,n);

  for(i=0;i<n-1;i++){
    printf("%d ",s[i]);
  }
  
  printf("%d\n",s[i]);
  printf("%d\n",cnt);
  return 0;
}


void merge(int *A,int left,int mid,int right){
  int n1,n2;
  int i,j,k;
  int R[INF],L[INF];
  
  n1 = mid - left;
  n2 = right - mid;
 
  for( i = 0 ;i< n1;i++){
    L[i] = A[left + i];
  }
  
  for( i = 0;i< n2;i++){
    R[i] = A[mid + i];
  }
  
  L[n1] = 999999999;
  R[n2] = 999999999;
  i = 0;
  j = 0;
  
  for (k = left;k< right;k++){
    if (L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      cnt++;
    }
    else {
      A[k] = R[j];
      j = j + 1;
      cnt++;
    }
  }
}


void mergeSort(int *A,int left,int right){
  int mid;
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}


