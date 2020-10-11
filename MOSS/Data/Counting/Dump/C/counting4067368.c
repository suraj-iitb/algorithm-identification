#include <stdio.h>
#include <stdlib.h>

#define MAX 2000001
#define VMAX 10000

void CountingSort(int *,int *,int);

int C[VMAX+1],n;

int main(){
  int *A,*B;
  int i,m = 0;
  
  scanf("%d", &n);
  if(n < 1 || n > 2000000)return 0;

  A = malloc(sizeof(int)*n+1);
  B = malloc(sizeof(int)*n+1);
 
  for(i = 1;i < n+1; i++){
    scanf("%d",&A[i]);
    if(m < A[i])m = A[i];
  }
 CountingSort(A,B,m);

 for(i = 1;i < n+1; i++){
    if(i > 1)printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
  return 0;
}

void CountingSort(int *A,int *B,int k){
  int i,j;
  for(i = 0;i <= k; i++){
    C[i] = 0;
  }
  for(j = 1;j < n+1; j++){
    C[A[j]]++;
  }
  for(i = 1;i <= k; i++){
    C[i] += C[i-1];
  }
  for(j = n; j > 0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  
}

