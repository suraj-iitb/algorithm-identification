#include<stdio.h>

void Cnt(int *,int);

int n,A[2000000],B[2000000],C[2000000];

int main()
{
  int i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  Cnt(A,n);

  printf("%d",B[0]);
  for(i=1;i<n;i++){
    printf(" %d",B[i]);
  }
  printf("\n");

  return 0;
  
}

void Cnt(int *A,int k){
  int i;

  for(i=0;i<2000000;i++){
    C[i]=0;
  }

  for(i=0;i<n;i++){
    C[A[i]]++;
  }

  for(i=1;i<2000000;i++){
    C[i]=C[i]+C[i-1];
  }

  for(i=n-1;i>=0;i--){
    B[C[A[i]]-1]=A[i];
    C[A[i]]--;
  }
}
