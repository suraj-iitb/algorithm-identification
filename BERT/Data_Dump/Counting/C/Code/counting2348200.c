#include <stdio.h>
#include <stdlib.h>
#define Max 2000001
#define AMax 10001
int main() {
  /* code */
  short *A,*B;
  int C[AMax];

  int n,i,j;
  for (i=0;i<=AMax;i++) C[i]=0;
  scanf("%d\n",&n);

  A=malloc(sizeof(short)*n+1);
  B=malloc(sizeof(short)*n+1);

  for (i=0;i<n;i++) {
    scanf("%hu",&A[i+1]);
    C[A[i+1]]++;
  }
  for(i=1;i<AMax;i++){
    C[i]=C[i]+C[i-1];
  }
  for(i=1;i<=n;i++){
    B[C[A[i]]]=A[i];
    C[A[i]]--;
  }
  for(i=1;i<=n;i++){
    if(i==n) printf("%d\n",B[i]);
    else printf("%d ",B[i]);
  }
  return 0;
}
