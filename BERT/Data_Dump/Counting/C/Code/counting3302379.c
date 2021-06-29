#include <stdio.h>
#include <stdlib.h>

  int n, A[2000001], i, C[10001], B[2000001], max=0;

int main(){


  for(i=0;i<=10000;i++){
    C[i]=0;
  }
    
  scanf("%d", &n);
  for(i=1;i<=n;i++){
    scanf("%d", &A[i]);
    if(max < A[i]) max = A[i];
    C[A[i]]++;
  }

  for(i=1;i<=max;i++){
    C[i] = C[i-1] + C[i];
  }

  for(i=n;i>0;i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }

  for(i=1;i<=n;i++){
    printf("%d", B[i]);
    if(i != n) printf(" ");
  }

  printf("\n");

  return 0;
}
    
    

