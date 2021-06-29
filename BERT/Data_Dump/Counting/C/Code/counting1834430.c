#include<stdio.h>
#define N 2000001
#define K 10000

int n,A[N],B[N];

void CountingSort(int[],int[],int);

int main(){

  int i,k=0;

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
  }

  CountingSort(A,B,K);

  for(i=1;i<n;i++) printf("%d ",B[i]);
  printf("%d\n",B[n]);

  return 0;
}

void CountingSort(int A[],int B[],int k){

  int i,j,C[k+2];

  for(i=0;i<=k;i++){
    C[i]=0;
  }

  for(j=1;j<=n;j++){
    C[A[j]]++;
  }

  for(i=1;i<=k;i++){
    C[i]=C[i]+C[i-1];
  }

  for(j=n;j>=1;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
