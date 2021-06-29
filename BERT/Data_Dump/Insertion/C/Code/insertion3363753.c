#include <stdio.h>
#include <stdlib.h>
#define N 100

int main(){
  int n,A[N],i,j,v,k;

  scanf("%d",&n);
  if(n>1000) exit(1);
  for(i=0; i<n; i++) scanf("%d",&A[i]);

  for(k=0; k<n-1; k++) printf("%d ",A[k]);
  printf("%d\n",A[n-1]);

  for(i=1; i<n; i++){
    v = A[i];
    j = i-1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    for(k=0; k<n-1; k++) printf("%d ",A[k]);
    printf("%d",A[n-1]);
    printf("\n");

  }

  return 0;
}
