#include <stdio.h>
#include <stdlib.h>
#define MAX 2000001
#define VMAX 10000
unsigned short *A, *B;
int C[VMAX+1];
int n, i, j;
void CountingSort(){
  for(i = 0;i < VMAX;i++){
    C[i] = 0;
  }
  
  for(j = 0;j < n;j++){
    C[A[j]]++;
  }
  for(i = 1;i < VMAX;i++){
    C[i] = C[i] + C[i-1];
  }
 
  for(j = n-1;j >= 0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

int main(){
 
  scanf("%d", &n);

  A = malloc(sizeof(short)*n+1);
  B = malloc(sizeof(short)*n+1);
  
  for(i=0;i < n;i++){
    scanf("%hd",&A[i]);
  }
  
  CountingSort();
  for(i=1;i < n;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[i]);
  
  return 0;
}

