#include <stdio.h>
void CountingSort(int *,int *,int);
int C[2000000],max=0;
int main(void){
  int n,A[2000000],B[2000000],i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
    if(max<A[i])max=A[i];
  }
  CountingSort(A,B,n);
  for(i=0;i<n;i++){
    printf("%d",B[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n");
  return 0;
}
void CountingSort(int *A,int *B,int k){
  int i;
  for(i=0;i<=k;i++)
    C[i]=0;

  /* C[i] に i の出現数を記録する */
  for(i=0;i<k;i++)
    C[A[i]]++;

  /* C[i] に i 以下の数の出現数を記録する*/
  for(i=1;i<=max;i++)
    C[i]=C[i]+C[i-1];

  for(i=k-1;i>=0;i--){
    B[C[A[i]]-1]=A[i];
    C[A[i]]--;
  }
}
