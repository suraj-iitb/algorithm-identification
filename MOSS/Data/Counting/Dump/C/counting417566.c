#include<stdio.h>
int Counting(void);
int A[2000001], B[2000001], C[10001];
int  n, k=0;

int main(void){
  int i, j;
  scanf("%d",&n);
  for(i=1; i<=n; i++){
    scanf("%d",&A[i]);
    if(A[i] > k) k = A[i];
  }
  Counting();
    for(i=1; i<=n; i++){
      printf("%d",B[i]);
      if(i < n) printf(" ");
    }
  printf("\n");
  return 0;
}


int Counting(){
  int i, j;
  for(i=0; i<=k; i++) C[i] = 0;
  for(j=1; j<=n; j++) C[A[j]] = C[A[j]]+1;
  for(i=1; i<=k; i++) C[i] = C[i] + C[i-1];
  for(j=n; j>=1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]] = C[A[j]]-1;
  }
}
