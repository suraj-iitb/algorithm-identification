#include <stdio.h>

void CS(int*,int*,int);

int main(){
  int i,n;

  scanf("%d",&n);
  int A[n],B[n];
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  CS(A,B,n);

  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);

  return 0;
}

void CS(int *A, int *B,int n){
  int i,j,C[10001];

  for(i=0;i<10001;i++){
    C[i]=0;
  }

  for(j=0;j<n;j++){
    C[A[j]]++;
  }

  for(i=1;i<10001;i++){
    C[i]+=C[i-1];
  }

  for(j=n-1;j>=0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}
