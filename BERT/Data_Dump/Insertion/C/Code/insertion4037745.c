#include <stdio.h>

int main(){
  int i,j,v,N,n,z;
  int A[1000];

  scanf("%d",&N);
  if (N>=1 && N<=100){
    for (n=0; n<N; n++) scanf("%d",&A[n]);
  }

  for (z=0; z<N-1; z++) printf("%d ",A[z]);
  printf("%d", A[z]);
  printf("\n");

  for (i=1; i<N; i++){
    v = A[i];
    j = i-1;
    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for (z=0; z<N-1; z++) printf("%d ",A[z]);
    printf("%d", A[z]);
    printf("\n");
  }

  return 0;
}

