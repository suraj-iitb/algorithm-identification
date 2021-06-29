#include <stdio.h>

int main(){
  int n, i, j;
  scanf("%d", &n);
  int A[n], B[n], k=0;
  for(i=0;i<n;i++){
    scanf("%d", &A[i]);
    if(A[i]>k) k=A[i];
  }
  int C[k+1];

  for(i=0;i<=k;i++)C[i]=0;
  for(j=0;j<n;j++) C[A[j]]++;
  for(i=1;i<=k;i++) C[i] = C[i] + C[i - 1];
  for(j=n-1;j>=0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i=1;i<n;i++) printf("%d ", B[i]);
    printf("%d\n", B[n]);
  return 0;
}
