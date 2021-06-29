#include <stdio.h>
#include <limits.h>

int left,right,n;
int cnt = 0;

void merge(int *,int,int,int);
void mergesort(int *,int,int);

int main(){
  int n,i,A[500000];

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

  mergesort(A,0,n);

  for(i = 0; i < n; i++){
    printf("%d",A[i]);
    if(i == n-1)printf("\n");
    else printf(" ");
  }

  printf("%d\n",cnt);
  
  return 0;
}

void merge(int *A,int left,int mid,int right){
  int n1,n2,i,j,k;
  int L[500000],R[500000];

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0; i < n1;i++){
    L[i] = A[left + i];
  }
  for(i = 0; i < n2;i++){
    R[i] = A[mid + i];
  }
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;

  i = 0;
  j = 0;

  for(k = left; k < right; k++, cnt++){
    if(L[i] <= R[j]){
      A[k] = L[i++];
    }else{
      A[k] = R[j++];
    }
  }
}

void mergesort(int *A,int left,int right){
  int mid;
  
  if(left+1 < right){
    mid = (left + right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}
  

