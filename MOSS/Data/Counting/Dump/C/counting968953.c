#include <stdio.h>

#define N 2000002
int B[N];
main(){
  int i,j,n,A[N],C[10002],k=0;
  scanf("%d",&n);
  for(i = 1; i < n+1; i++){
    scanf("%d",&A[i]);
    if(A[i] > k){
      k = A[i];
    }
  }
  for(i = 0; i < k+1; i++){
    C[i] = 0;
  }
  for(j = 1; j < n+1;j++){
    C[A[j]]++;
  }
  for(i = 1; i < k+1; i++){
    C[i] = C[i] + C[i-1];
  }
  for(j = n; j > 0; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  for(i = 1; i < n; i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);
  return 0;
}
