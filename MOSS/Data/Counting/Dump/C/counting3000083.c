#include<stdio.h>
#include<stdlib.h>

#define MAX 2000001
#define AMAX 10000

int main() {
  int n,i,j,*A,*B;
  int C[AMAX+1];

  scanf("%d",&n);

  A = (int *)malloc(sizeof(int) * n+1);
  B = (int *)malloc(sizeof(int) * n+1);
  
  for(i = 0 ; i <= AMAX ; i++) {
    C[i] = 0;
  }

  for(i = 0 ; i < n ; i++) {
    scanf("%d",&A[i+1]);
    C[A[i+1]]++;
  }

  for(i = 1 ; i <= AMAX ; i++) {
    C[i] = C[i] + C[i-1];
  }

  for(j = 1 ; j <= n ; j++) {
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i = 1 ; i <= n-1 ; i++) {
    printf("%d ",B[i]);
  }
  printf("%d\n",B[i]);
  return 0;
}
