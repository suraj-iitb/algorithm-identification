#include<stdio.h>

int A[2000001],B[2000001];

int main(){
  int C[10001];
  int n,i;

  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&A[i]); 

  for(i = 0; i < 10001; i++) C[i]=0;
  for(i = 0; i < n; i++) C[A[i]]++;
  for(i = 1; i < 10001; i++) C[i] = C[i] + C[i-1];

  for(i = n-1;i >= 0 ; i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
  for(i = 0; i < n; i++){
    if(i) printf(" ");
    printf("%d",B[i+1]);
  }
  printf("\n");
  return 0;
}

