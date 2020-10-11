#include <stdio.h>
#define N 2000001
int X[N];
main(){
  int i, j, n, m=0, A[N], C[10001];
  
  scanf("%d", &n);
  for(i=1; i<n+1; i++){
    scanf("%d", &A[i]);
    
    if(A[i]>m){
      m=A[i];
    }
  }
  
  for(i=0; i<m+1; i++){
    C[i]=0;
  }
  for(j=1; j<n+1; j++){
    C[A[j]]++;
  }
  for(i=1; i<m+1; i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=n; j>0; j--){
    X[C[A[j]]]=A[j];
    C[A[j]]--;
  }
  for(i=1; i<n; i++){
    printf("%d ", X[i]);
  }
  printf("%d\n", X[n]);
  
  return 0;
}
