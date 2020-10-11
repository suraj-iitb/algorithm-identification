#include <stdio.h>
#include <stdlib.h>

#define MAX 10001

void Count(int *,int *,int);

int main(void){

  int i,n;
  int *A,*B;

  scanf("%d",&n);
  A = malloc(sizeof(int)*(n+1));
  B = malloc(sizeof(int)*(n+1));

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  Count(A,B,n);

  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i!=n) printf(" ");
  }
  printf("\n");
  return 0;
}

void Count(int *A,int *B,int n){

  int i,j;
  int C[MAX];

  for(i=0;i<MAX;i++){
    C[i] = 0;
  }

  for(j=0;j<n;j++){
    C[A[j]]++;
  }

  for(i=1;i<MAX;i++){
    C[i] = C[i] + C[i - 1];
  }

  for(j=n-1;j>=0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
