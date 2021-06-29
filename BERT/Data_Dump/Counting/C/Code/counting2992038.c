#include<stdio.h>
#define LEN 2000010
#define ALEN 10000

int n, C[LEN+1];

void Counting(int A[],int B[] ,int k){
  int i,j;
  for(i=0;i<=k;i++) C[i] = 0;

  for(j=1;j<=n;j++) C[A[j]]++;

  for(i=1;i<=k;i++) C[i] = C[i] + C[i-1];

  for(j=n;j>0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}


int main(){
  int A[LEN],B[LEN];
  int i,k=0;
  scanf("%d",&n);
  for(i=1;i<n+1;i++) scanf("%d",&A[i]);
  for(i=1;i<n+1;i++){
    if(k<A[i]) k=A[i];
  }
  Counting(A,B,k);

  for(i=1;i<n+1;i++){
    if(i!=1) printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");

  return 0;
}

