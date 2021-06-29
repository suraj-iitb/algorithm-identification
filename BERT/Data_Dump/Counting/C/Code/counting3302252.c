#include <stdio.h>
#include <stdlib.h>

int A[2000001], B[2000001], C[10000];

int main(){
  int n, k=0, i, j;

  scanf("%d",&n);
  if(n < 0 || 2000000 < n) exit(1);

  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
    if(A[i] < 0 || 10000 < A[i]) exit(2);
    if(A[i] > k) k=A[i];
  }

  for(i=0; i<=k; i++){
    C[i]=0;
  }

  for(j=0; j<n; j++){
    C[A[j]]++;
  }

  for(i=1; i<=k; i++){
    C[i]=C[i]+C[i-1];
  }

  for(j=n-1; j>=0; j--){
    B[C[A[j]]-1]=A[j];
    C[A[j]]--;
  }

  for(j=0; j<n; j++){
    printf("%d", B[j]);
    if(j < n-1) printf(" ");
  }
  printf("\n");

  return 0;
}
  

