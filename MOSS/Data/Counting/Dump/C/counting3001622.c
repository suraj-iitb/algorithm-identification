#include<stdio.h>
#include<stdlib.h>
#define max 10000

int main(){
  unsigned short *A,*B;

  int C[max +1];
  int n,i;
  scanf("%d",&n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i=0;i<=max;i++){
    C[i] = 0;
  }

    for(i=0;i<n;i++){
      scanf("%hu",&A[i+1]);
      C[A[i+1]]++;
    }

  for(i=1;i<=max;i++){
    C[i]=C[i]+C[i-1];
  }

  for(i=1;i<=n;i++){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }

printf("%d",B[1]);
  for(i=2;i<=n;i++){
    printf(" %d",B[i]);
  }
  printf("\n");

  return 0;
}

