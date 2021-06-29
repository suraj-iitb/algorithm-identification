#include<stdio.h>
#include<stdlib.h>
#define M 2000001
#define N 10000

int main(){
  unsigned short *A,*B;

  int C[N+1];
  int i,j,n;
  
  scanf("%d",&n);
  A=malloc(sizeof(short)*n+1);
  B=malloc(sizeof(short)*n+1);

  for(i=0;i<=N;i++)C[i]=0;

   /* C[i] に i の出現数を記録する */
  for(i=0;i<n;i++){
    scanf("%hu",&A[i+1]);
    C[A[i+1]]++;
      }
  /* C[i] に i 以下の数の出現数を記録する*/
  for(i=1;i<=N;i++) C[i]+=C[i-1];
  
  for(j=1;j<=n;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  
  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);

  return 0;
}


