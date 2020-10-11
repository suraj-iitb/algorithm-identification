#include<stdio.h>
#define X 10000

void countingSort(int A[],int B[], int n){
  int i;
  int C[X+1];

  for(i=0;i<=X;i++){
    C[i] = 0;
  }

  for(i=0;i<n;i++){
    C[A[i]]++;
  }

  for(i=1;i<=X;i++){
    C[i] += C[i-1];
  }

  for(i=n-1;i>=0;i--){
    B[C[A[i]]-1] = A[i];
    C[A[i]]--;
  }
}

int main(){

  int n,i;

  scanf("%d",&n);

  int A[n],B[n];
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  countingSort(A,B,n);

  for(i=0;i<n;i++){
    printf("%d",B[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n");

  return 0;
}

