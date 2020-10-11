#include<stdio.h>
#define N 10000

void CountingSort(int k);

int A[2000001],B[2000001],C[N];

int main(){
  int i,k;
  
  scanf("%d",&k);
  for(i=1;i<k+1;i++)
    scanf("%d",&A[i]);

  CountingSort(k);

  for(i=1;i<k;i++)
    printf("%d ",B[i]);
  printf("%d\n",B[i]);

  return 0;
}
void CountingSort(int k){
  int i,j;
  
  for(i=0;i<=N;i++)
    C[i] = 0;

  /* C[i] に i の出現数を記録する */
  for(j=1;j<=k;j++)
    C[A[j]]++;
  
  /* C[i] に i 以下の数の出現数を記録する*/
  for(i=1;i<=N;i++)
    C[i] = C[i] + C[i-1];
  
  for(j=k;j>0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

