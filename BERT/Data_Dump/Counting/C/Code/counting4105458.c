#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  unsigned short *A, *B;
  int A1[MAX];
  int k=VMAX;
  int C[VMAX+1];
  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);
  for(i=1; i<=n; i++){
      scanf("%hu",&A[i]);
  }

  for(i=0; i<=k; i++){
      C[i]=0;
  }
  for(j=1; j<=n; j++){
      C[A[j]]++;
  }
  for(i=1; i<=k; i++ ){
      C[i]=C[i]+C[i-1];
  }
  for(j=n; j>=1; j--){
      B[C[A[j]]]=A[j];
      C[A[j]]--;
  }
  
  for(i=1; i<=n; i++){
      if(i==n)printf("%u\n",B[i]);
      else printf("%u ",B[i]);
  }
  return 0;
}
