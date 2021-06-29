#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define AMAX 10000

int main(){
  int n,i,j,C[AMAX+1];
  int *A,*B;

  scanf("%d",&n);

  A=malloc(sizeof(int)*n+1);
  B=malloc(sizeof(int)*n+1);
  
  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
  }

  for(i=0;i<=AMAX;i++){
    C[i]=0;
  }
  for(j=0;j<n;j++){
    C[A[j+1]]++;
  }
  for(j=1;j<=AMAX;j++){
    C[j]=C[j]+C[j-1];
  }
  for(i=1;i<=n;i++){
    B[C[A[i]]]=A[i];
    C[A[i]]--;
  }
    
  for(j=1;j<=n;j++){
    if(j>1)printf(" ");
    printf("%d",B[j]);
  }
  printf("\n");
  return 0;
}
	

