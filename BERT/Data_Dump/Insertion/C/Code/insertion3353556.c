#include<stdio.h>

void trace(int *A, int n){
  int i;
  for(i = 0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}

void insertionSort(int  *A, int n){
  int i,j,temp;
  for(i = 1;i<n;i++){
    temp = A[i];
    j = i-1;
    while(j>=0 && A[j] > temp){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = temp;
    trace(A,n);
  }
}

int main(){
  int i,j,n,A[1000];

  scanf("%d",&n);
  for(i = 0; i < n; i++)scanf("%d",&A[i]);

  trace(A,n);
  insertionSort(A,n);

  return 0;
}

