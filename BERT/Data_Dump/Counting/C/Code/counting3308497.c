#include<stdio.h>
#include<stdlib.h>

int main(){
  unsigned short *A, *B;
  int i, j, n, C[10001], k = 0;
  scanf("%d", &n);
  
  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  if(n <= 2000000 && n >= 1){
    for(i = 1; i <= n; i++){
      scanf("%hd", &A[i]);

      if(A[i] > k)
	k = A[i];
    }

    for(i = 0; i <= k; i++){
      C[i] = 0;
    }
    for(j = 1; j <= n; j++){
      C[A[j]]++;
    }
 
    for(i = 1; i <= k; i++){
      C[i] = C[i] + C[i-1];
    }
    for(j = n; j > 0; j--){
      B[C[A[j]]] = A[j];
      C[A[j]]--;
    }

    for(i=1; i <= n; i++){
      if(i != n)printf("%d ", B[i]);
      else printf("%d\n", B[i]);
    }
  }
  return 0;
}
  

