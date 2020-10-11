#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

void CountingSort(short A[],short B[],int C[],int n){
    int i,j;

    for(i=1;i<=n;i++){
      scanf("%d",&A[i]);
    }

    for(i=0;i<=VMAX;i++){
    C[i] = 0;
    }

  for(i=1;i<=n;i++){
    C[A[i]]++;
  }

  for(i=1;i<=VMAX;i++){
    C[i] += C[i-1];
  }

  for(j=n;j>=1;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  }


int main(){
  unsigned short *A, *B;
  int C[VMAX+1];
  int n, i, j;

  scanf("%d",&n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  /* your code */

  CountingSort(A,B,C,n);
 

  for(i=0;i<n;i++){
    if(i)printf(" ");
    printf("%d",B[i+1]);
  }
  printf("\n");

  return 0;
}


