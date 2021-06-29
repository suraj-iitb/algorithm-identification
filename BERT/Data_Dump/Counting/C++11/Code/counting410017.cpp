#include <iostream>
#include <stdio.h>
void cs(int k);

int A[2000001];
int B[2000001];
int n;

// length is n
main(){

  int i,k=0;
  scanf("%d",&n);

  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if(A[i]>k) k=A[i];
  }
  // setting is finished

  cs(k);

  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i!=n) printf(" ");
  }
  printf("\n");

  return 0;
}

void cs(int k){
  int C[k+1];
  int i,j,len;
  for(i=0; i<=k; i++)
    C[i] = 0;

  for(j=1; j<=n;j++)
    C[A[j]]++;

  for(i=1; i<=k; i++)
    C[i] = C[i] + C[i-1];

  for(j=n; j>=1; j--){

    B[C[A[j]]] = A[j];
    C[A[j]] = C[A[j]]-1;

  }

}
