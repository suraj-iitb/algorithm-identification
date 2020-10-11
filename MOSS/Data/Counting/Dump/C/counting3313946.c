#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  unsigned short *A, *B,k=0;
  int C[VMAX+1];
  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  /* your code */

  for(i=0;i<=VMAX;i++)C[i]=0;

  for(j=1;j<=n;j++){
   scanf("%hu",&A[j]);
    C[A[j]]++;
    if(k<A[j])k=A[j];
}
  
  for(i=1;i<=k;i++)C[i]=C[i]+C[i-1];

  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }

  for(i=1;i<=n;i++){
    printf("%u",B[i]);
    if(i<n)printf(" ");
  }
  
  printf("\n");

  return 0;
}

