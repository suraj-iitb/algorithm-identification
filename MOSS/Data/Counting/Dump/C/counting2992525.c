#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int main(){
  int i,k,n;
  int C[VMAX];
  unsigned short *A,*B;

  scanf("%d",&n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);
  
  k = 0;
  for(i = 1; i <= n; i++){
    scanf("%hd",&A[i]);
    if(A[i] > k) k = A[i];
  }

  for(i = 0; i <= k; i++){
    C[i] = 0;
  }
 
  for(i = 1; i <= n; i++){
    C[A[i]]++;
  }

  for(i = 1; i <= k; i++){
    C[i] = C[i] + C[i-1];
  }

  for(i = n; i >= 1; i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }

  for(i = 1; i <= n; i++){
    printf("%d",B[i]);
    if(i != n) printf(" ");
    else printf("\n");
  }

  free(A);
  free(B);

  return 0;
}

