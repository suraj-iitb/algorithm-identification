#include <stdio.h>
#include <stdlib.h>

int main() {

  int i,j;
  int n;
  int *A;
  int *B;
  int C[10001];
  scanf("%d",&n);
  A=malloc(sizeof(int)*n+1);
  B=malloc(sizeof(int)*n+1);
 
  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
  }

  for(i=0;i<=10001;i++){
    C[i]=0;
  }
  for(j=1;j<=n;j++){
    C[A[j]]++;
  }
  for(i=1;i<=10001;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=1;j<=n;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i==n) break;
    printf(" ");
  }
 
  printf("\n");
  

  return 0;
}
