#include <stdio.h>
#include <stdlib.h>
#define N 10000
#define M 2000000
int main(){
  int n,i;
  int C[M];
  int *A,*B;

   scanf("%d",&n);
  A=malloc(sizeof(int)*n+1);
  B=malloc(sizeof(int)*n+1);
   
 
 for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
   
  for(i=0;i<M;i++){
    C[i]=0;
  }
   
 
  for(i=0;i<n;i++){
    C[A[i]]++;
  } 

  for(i=1;i<M;i++){
    C[i]=C[i]+C[i-1];
  }
  for(i=0;i<n;i++){
    B[C[A[i]]]=A[i];
    C[A[i]]--;
  }
  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i!=n) printf(" ");
  }
  printf("\n");
  return 0;
}
