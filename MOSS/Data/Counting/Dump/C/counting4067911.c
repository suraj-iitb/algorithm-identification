#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

void CountingSort(short unsigned int*,short unsigned int*,int);

int n,C[VMAX+1];

int main(){
  unsigned short *A, *B;;
  int i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);
  for(i=1;i<=n;i++) scanf("%d",&A[i]);
  
  CountingSort(A,B,VMAX);



  return 0;
}

void CountingSort(short unsigned int *A,short unsigned int *B,int k){
  int i,j;
  
  for (i=0;i<=k;i++)
    C[i] = 0;
    for (j=1;j<=n;j++){
      C[A[j]]++;
    }
      for (i=1;i<=k;i++) C[i] = C[i] + C[i-1];
	for (j=1;j<=n;j++){
	  B[C[A[j]]] = A[j];
	  C[A[j]]--;
	}
      for (i=1;i<n;i++) printf("%d ",B[i]);
      printf("%d\n",B[n]);
}


