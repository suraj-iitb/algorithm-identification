#include<stdio.h>
#include<stdlib.h>

#define K 10000

int main(){
  int n;
  int i,j;
  int *A;
  int *B;
  int C[K+1];

  scanf("%d",&n);
  A=(int *)malloc((n+1)*sizeof(int));
  B=(int *)malloc((n+1)*sizeof(int));
  for(i=1;i<=n;i++)
    scanf("%d",&A[i]);
		  
  for(i=0;i<=K;i++)C[i]=0;
	  
  for(j=1;j<=n;j++)C[A[j]]++;
  
  for(i=1;i<=K;i++)C[i]=C[i]+C[i-1];

  for(j=n;j>0;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(i=1;i<n;i++)printf("%d ",B[i]);
  printf("%d\n",B[i]);
  free(A);
  free(B);
  return 0;
}

