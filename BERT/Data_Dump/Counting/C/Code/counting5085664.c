#include <stdio.h>
#define  N 2000001//AOJ:add e+1

int main (){
  int i,j,n,k=0;
  int A[N],C[N],B[N];

  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if(k<A[i])k=A[i]+1;
  }

  for(i=0;i<=k;i++){
    C[i] = 0;
  }
  /* C[i] に i の出現数を記録する */
  for(j=1;j<=n;j++){
      C[A[j]]++;
  }
  /* C[i] に i 以下の数の出現数を記録する*/
  for(i=1;i<=k;i++){
    C[i] = C[i] + C[i-1];
  }
  for(j=n;j>0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  for(i=1;i<n;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[n]);
  return 0;
}

