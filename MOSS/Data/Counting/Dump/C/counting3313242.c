#include <stdio.h>
#include <stdlib.h>

int main(){
  int n,i,j;
  int C[10000];
  short *A,*B;
  scanf("%d",&n);
  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i=0;i<=10000;i++){C[i]=0;}
  for(j=1;j<=n;j++){
    scanf("%hd",&A[j]);
    C[A[j]]++;
  }
  for(i=1;i<=10000;i++){C[i]=C[i]+C[i-1];}
  for (j=1;j<=n;j++){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(i=1;i<n;i++){printf("%d ",B[i]);}
  printf("%d\n",B[n]);

  return 0;
}

