#include<stdio.h>
#include<stdlib.h>
#define MAX 2000001
#define max 10000
int main()

{
  int *A,*B,C[max+1];
  int n,i,j;

  scanf("%d",&n);
  
  A=malloc(sizeof(int)*n+1);
  
  B=malloc(sizeof(int)*n+1);
 
  for(i=0;i<=max;i++) C[i]=0;

  for(j=0;j<n;j++){
    scanf("%d",&A[j+1]);
    C[A[j+1]]++;
  }

  for(i=1;i<=max;i++)
    C[i]=C[i]+C[i-1];

  for(j=1;j<=n;j++)
    {
      B[C[A[j]]]=A[j];
      C[A[j]]--;
    }

  for(i=1;i<=n;i++){
    if(i>1) printf(" ");
    printf("%d",B[i]);
  }

  printf("\n");
  return 0;
}
