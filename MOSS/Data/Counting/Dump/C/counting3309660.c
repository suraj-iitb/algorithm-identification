#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000

int C[VMAX+1];
void CountingSort(short*,short*,int);

int main(){
  int i,j,n;
  unsigned short *A,*B;

  scanf("%d",&n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);

  for(i=0;i<n;i++){
    scanf("%d",&A[i+1]);
  }
  CountingSort(A,B,n);
  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i != n)printf(" ");
  }
  printf("\n");
  return 0;
}

void CountingSort(short A[],short B[],int n){
  int i,j;
  for(i=0;i<=VMAX;i++){
    C[i] = 0;
  }
  for(j=1;j<=n;j++){
    C[A[j]]++;
  }
  for(i=1;i<=VMAX;i++){
    C[i] = C[i] + C[i-1];
  }
  for(j=n;j>=1;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
