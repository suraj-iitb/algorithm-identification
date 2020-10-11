#include <stdio.h>
#include <stdlib.h>
#define N 200001
#define K 10000
int main()
{
  int *A,*B;
  int i,j,n;
  int hi[K+1];
  scanf ("%d",&n);
  
  A=malloc(sizeof(int)*n+1);
  B=malloc(sizeof(int)*n+1); 

  for (i=0;i<=K;i++)
    hi[i]=0;


  for(i=0;i<n;i++){
    scanf ("%d",&A[i+1]);
    hi[A[i+1]]++;
  }

  for(i=1;i<=K;i++)
    hi[i]=hi[i]+hi[i-1];
  
  for(j=1;j<=n;j++){
    B[hi[A[j]]]=A[j];
    hi[A[j]]--;
  }
    
  for(i=1;i<=n;i++){
    if(i>1)
      printf(" ");
      
    printf("%d",B[i]);
  }
  printf("\n");

  return 0;
}

