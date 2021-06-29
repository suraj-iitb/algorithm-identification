#include <stdio.h>
#define N 2000000
#define MAX 10000

void CountingSort(int *,int);
int n;

int main(){
  int i,*A;

  scanf("%d",&n);

  A = malloc(sizeof(int)*n+1);

  for(i=0;i<n;i++) scanf("%d",&A[i]);

  CountingSort(A,MAX);

  for(i=0;i<n-1;i++) printf("%d ",A[i]);
  printf("%d\n",A[n-1]);

  return 0;
}

void CountingSort(int *A,int k){
  int i,*B,C[k+1];

  B = malloc(sizeof(int)*n+1);

  for(i=0;i<=k;i++) C[i]=0;
  for(i=0;i<n;i++) C[A[i]]++;
  for(i=1;i<=k;i++) C[i]+=C[i-1];

  for(i=n-1;i>=0;i--){
    B[C[A[i]]-1]=A[i];
    C[A[i]]--;
  }

  for(i=0;i<n;i++) A[i]=B[i];
}
