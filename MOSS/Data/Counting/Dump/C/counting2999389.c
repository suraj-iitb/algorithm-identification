#include <stdio.h>
#include<stdlib.h>
#define M 2000001
#define VM 10000

int main(){

  int C[VM+1],n,i,j;

  scanf("%d",&n);

  int A[n],B[n];
  for(i=0;i<=VM;i++){
    C[i] = 0;
}
  for(j=0;j<n;j++){
    scanf("%d",&A[j+1]);
    C[A[j+1]]++;
  }

  for(i=1;i<=VM;i++)C[i] = C[i] + C[i-1];

    for(j=1;j<=n;j++){
              B[C[A[j]]] = A[j];
              C[A[j]]--;
    }

for(i=1;i<=n;i++){
  if(i==n)printf("%d",B[i]);
  else printf("%d ",B[i]);
    }
 printf("\n");

  return 0;
}
