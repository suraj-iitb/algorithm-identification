#include <stdio.h>
#include <stdlib.h>

#define MAX 2000001
#define VMAX 10000

void countingSort(unsigned short *,unsigned short *,int);

int C[VMAX+1];

int main(){
  unsigned short *A, *B;
  int n, i, j;

  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i=1;i<=n;i++) scanf("%hd",&A[i]);

  countingSort(A,B,n);

  for(i=1;i<n;i++) printf("%d ",B[i]);
  printf("%d\n",B[i]);

  return 0;
}

void countingSort(unsigned short *A,unsigned short *B,int n){
  int i,j;

  for(i=0;i<=VMAX;i++) C[i]=0;
  for(j=1;j<=n;j++) C[A[j]]=C[A[j]]+1;
  for(i=1;i<=VMAX;i++) C[i]=C[i]+C[i-1];
  for(j=n;j>=1;j--){
    B[C[A[j]]]=A[j];
    C[A[j]]=C[A[j]]-1;
  }
}

