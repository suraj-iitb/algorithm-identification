#include<stdio.h>

#define K 10001
#define L 2000001

void CountingSort(int *,int *,int);

int main(){
  int i,n;
  int A[L],B[L],C[K];

  scanf("%d",&n);
  for(i=1;i<=n;i++) scanf("%d",&A[i]);

  CountingSort(A,B,n);

  for(i=1;i<n;i++) printf("%d ",B[i]);
  printf("%d\n",B[i]);
  
  return 0;

}

void CountingSort(int *A,int *B,int n){
  int i,j;
  int C[K];
  
  for(i=0;i<K;i++) C[i]=0;

  /*C[i]にiの出現回数を記録*/
  for(j=1;j<=n;j++) C[A[j]]++;

  /*C[i]にi以下の出現回数を記録*/
  for(i=1;i<K;i++) C[i]=C[i]+C[i-1];

  for(j=n;0<j;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

}


