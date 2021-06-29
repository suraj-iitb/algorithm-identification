#include <stdio.h>
#include <stdlib.h>

void Counting_Sort(int*, int*, int);

int n;
main(){
  int i,*A,*B,k=0;

  scanf("%d",&n);
  A=(int *)malloc(sizeof(int)*(n+1));
  B=(int *)malloc(sizeof(int)*(n+1));
  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if(k<A[i])k=A[i];
  }
  Counting_Sort(A,B,k);

  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i<n)printf(" ");
  }
  printf("\n");
  return 0;
}

void Counting_Sort(int *A, int *B, int k){
  int i,j,*C;
  C=(int *)malloc(sizeof(int)*(n));

  for(i=0;i<=k;i++){
    C[i]=0;
  }
  
  for(j=1;j<=n;j++){
    C[A[j]]++;
  }

  for(i=1;i<=k;i++){
    C[i]+=C[i-1];
  }
  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]--;
  }
}
