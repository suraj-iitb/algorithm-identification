#include<stdio.h>

#define K 10000

int main(){
  int n,i,num,A[2000001],B[2000001],C[K];

  scanf("%d",&n);

  for(i = 1;i <= n;i++){
    scanf("%d",&A[i]);
  }

  for(i = 0;i <= K;i++) C[i] = 0;

  for(i = 1;i <= n;i++) C[A[i]]++;

  for(i = 1;i <= K;i++) C[i] = C[i] + C[i-1];

  for(i = n;i >= 1;i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
  for(i = 1;i <= n;i++){
    if(i > 1) printf(" ");
    printf("%d",B[i]);
  }printf("\n");
  return 0;
}

