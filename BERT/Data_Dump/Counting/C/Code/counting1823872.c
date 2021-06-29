#include<stdio.h>
#include<stdlib.h>
#define MAX 200001
#define AMAX 10000
void CountingSort(int);
  int *A,*B;
  int C[AMAX+ 1]; 

int main(){
  int n,i,j;
  scanf("%d",&n);
 A = malloc(sizeof(int)*n+1);
 B = malloc(sizeof(int)*n+1);
  CountingSort(n);
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");

  return 0;
}

void CountingSort(n){
  int i,j;
  for(i = 0;i < AMAX; i++)C[i] = 0;

  for(i = 0;i < n; i++){
    scanf("%d", &A[i]);
    C[A[i]]++;
  }

  for(i = 1;i <= AMAX; i++) C[i] = C[i] + C[i-1];

  for(j = n;j >= 0; j--){
    B[C[A[j]]-1] = A[j];
    C[A[j]]--;
  }
}
