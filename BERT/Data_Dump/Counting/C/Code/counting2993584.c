#include<stdio.h>
#include<stdlib.h>
#define N 2000000
#define K 10000

int main(){
  unsigned short *A,*B;
  int n;
  int C[K];
  int i,j;

  
  scanf("%d",&n);

  A=malloc(sizeof(short)*n+1);
  B=malloc(sizeof(short)*n+1);

  for(i=1;i<n+1;i++)scanf("%d",&A[i]);

  for(i=0;i<K;i++)C[i]=0;

  for(j=1;j<=n;j++)C[A[j]]++;

  for(i=1;i<K;i++){
    C[i]=C[i]+C[i-1];
  }

  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

  for(i=1;i<n;i++)printf("%d ",B[i]);
  printf("%d\n",B[n]);


  return 0;
}


