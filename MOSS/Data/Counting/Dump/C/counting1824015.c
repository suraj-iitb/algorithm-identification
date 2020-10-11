#include<stdio.h>

#define MAX 2000001
#define VMAX 10000

void CountingSort(int, int*, int*);
int A[MAX],B[MAX];
int n;
int  main() {

  
  int i;
  scanf("%d",&n);
  

  for(i = 1; i < n+1; i++) {
    scanf("%d", &A[i]);
  }

  CountingSort(VMAX,A,B);
  for(i = 1; i <= n; i++) {
    printf("%d",B[i]);
    if(n != i) printf(" ");
  } 
  printf("\n");
  return 0;
}

void CountingSort(int k,int *A, int *B ){
  int i,C[VMAX + 1];

  for(i = 0; i <= VMAX; i++) {
    C[i] = 0;
  }

  for(i = 1; i <=n; i++) {
    C[A[i]]++;
  }
  
  for(i = 1; i < VMAX+1; i++) {
    C[i] += C[i-1];
  }

  for( i = 1; i <= n; i++) {
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
 return;
}
