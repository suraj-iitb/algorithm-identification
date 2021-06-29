#include <stdio.h>

int main()
{
  int A[2000001],B[2000001]={},C[10001]={},i,n;

  scanf("%d",&n);
  for(i = 1; i <= n; i++){
    scanf("%d",&A[i]);
    C[A[i]]++;
  }

  for(i = 1; i <= 10000; i++) C[i] = C[i] + C[i-1];

  for(i = n; i > 0; i--){
    B[C[A[i]]] = A[i];
    
    C[A[i]]--;
  }

  for(i = 1; i <= n; i++){
    if(i > 1) printf(" ");
    printf("%d",B[i]);
  }

  printf("\n");

  return 0;

}

