#include <stdio.h>

#define N 2000000
#define K 10000

int B[N];

int main(){
  int n,i,j,A[N],C[K];
  scanf("%d",&n);
  //for(i=0;i<n;i++) scanf("%d",&A[i]);


  for(i=0;i<K;i++) C[i]=0;

  for(j=1;j<=n;j++){
     scanf("%d",&A[j]);
     C[A[j]]++;
   }

  for(i=1;i<=K;i++) C[i]=C[i]+C[i-1];

  for(j=n;j>=1;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  for(i=1;i<=n;i++) {
    if(i!=1) printf(" ");
    printf("%d",B[i]);

  }
  printf("\n");
  return 0;
}

