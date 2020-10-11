#include<stdio.h>
#define N 2000001
#define M 10001

void CountingSort(int);

int A[N],B[N],C[M],n=0;

int main(){

  int i,j,t;

  scanf("%d",&n);

  for(i = 0; i < n; i++) {

    scanf("%d",&A[i]);

    if(t < A[i]) {
      t = A[i];
    }

  }
 
    CountingSort(t);
  
  for(i = 1; i <= n-1; i++){
    printf("%d ",B[i]);
}
  printf("%d",B[i]);
  printf("\n");

  return 0;
}


void CountingSort(int k) {
  int i ,j;

  for(i = 0; i <= k; i++) {
    C[i]=0;
  }

  for(j = 0; j < n; j++) {
    C[A[j]] = C[A[j]]+1;
  }

    for (i = 0; i <= k; i++) {
      C[i] = C[i]+C[i-1];
    }

      for(j = n-1; j >= 0; j--) {
	B[C[A[j]]] = A[j];
      C[A[j]] = C[A[j]]-1;
  }
}
