#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000
int main(){
  unsigned short *A, *B;
  int C[VMAX+1];
  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  /* your code */
  for(i = 1 ;i<=n ;i++){
    scanf("%hd",&A[i]);
  }
  for(i = 0;i<=VMAX+1;i++){
    C[i] = 0;
  }
  for(j=1;j<=n;j++){
    C[A[j]] = C[A[j]]+1;
  }
  
  for(i = 1 ;i<=VMAX+1;i++){
    C[i] = C[i]+C[i-1];
  }
  for(j=n ;j>=1 ;j--){
    B[C[A[j]]] = A[j];
    C[A[j]] = C[A[j]]-1;
  }
  for(j = 1;j<n+1;j++){
    if(j ==n)
    printf("%d\n",B[j]);
    else printf("%d ",B[j]);
    }
  return 0;
}

