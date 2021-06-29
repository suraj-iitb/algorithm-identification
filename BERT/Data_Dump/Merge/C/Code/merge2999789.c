#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 2000000000
int count=0,n;
void merge(int* A,int left,int mid,int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int i,j,k;
  int L[n1+1];
  int R[n2+1];
  for(i = 0;i <n1;i++){
    L[i] = A[left + i];
  }
  for(i = 0;i < n2;i++){
    R[i] = A[mid + i];
  }
  L[n1] =MAX;
  R[n2] =MAX;
  i = 0;
  j = 0;
  for(k = left;k <right;k++){
    count++;
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

  void mergeSort(int* A,int left,int right){
    int mid,i;
    if(left+1 < right){
	mid = (left + right)/2;
      mergeSort(A, left, mid);
      mergeSort(A, mid, right);
      merge(A, left, mid, right);
    }
}

int main(){
  int *s;
  int i;
  scanf("%d",&n);
  s=(int*)malloc(sizeof(int) * n);
  for(i=0;i < n;i++){
    scanf("%d",&s[i]);
  }
  mergeSort(s,0,n);

  for(i=0;i < n-1;i++){
    printf("%d ",s[i]);
  }
  printf("%d\n",s[i]);
  printf("%d\n",count);

  return 0;
}

