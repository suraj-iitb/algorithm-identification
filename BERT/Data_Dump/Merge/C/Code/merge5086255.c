#include<stdio.h>
#include<limits.h>

#define MAX 500000

void merge(int *,int,int,int);
void mergesort(int *,int,int);

int ct=0;

int main(){
  int n,i,A[MAX];

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
  }

  mergesort(A,0,n);

  for(i = 0 ; i < n ; i++){
    if(i != 0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",ct);


  return 0;
  
}

void merge(int *A, int left, int mid, int right){
  int n1 = (mid - left), n2 = (right - mid);
  int L[(mid - left)+1], R[(right - mid)+1];
  int i,j,k=0;

  for(i = 0 ; i < n1 ; i++){
    L[i] = A[left + i];
  }
  for(i = 0 ; i < n2 ; i++){
    R[i] = A[mid + i];
  }

  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  i = 0;
  j = 0;

  for(k = left ; k < right  ; k++){
    ct++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i +1;
    }
    else{
      A[k] = R[j];
      j = j + 1;
    }
  }
}

void mergesort(int *A, int left, int right){
  int mid;
  
  if(left + 1 < right){
    mid = (left + right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}
  

