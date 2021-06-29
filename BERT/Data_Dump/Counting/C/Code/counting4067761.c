#include <stdio.h>

int main(){
  int i,j,n;
  int A[2000001],B[2000001],C[2000001];

  scanf("%d",&n);
  
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

  
  for(i = 0; i < 2000000; i++){
    C[i] = 0;
  }

  for(j = 0; j < n; j++){
    C[A[j]]++;
  }

  for(i = 1; i <= 2000000; i++){
    C[i] = C[i] + C[i-1];
  }
  
  for(j = n-1; j >= 0; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  
  for(i = 1; i <= n; i++){
    printf("%d",B[i]);
    if(i == n)printf("\n");
    else printf(" ");
  }
  
  return 0;
}

