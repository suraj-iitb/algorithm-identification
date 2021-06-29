#include<stdio.h>

#define N 2000001

int Max(int*,int);
void CountingSort(int*,int*,int,int);

int main(void){
  int n,A[N],B[N];
  int i;

  scanf(" %d",&n);
  for(i = 0; i < n; i++){
    scanf(" %d",&A[i]);
  }

  CountingSort(A,B,Max(A,n),n);

  for(i = 1; i < n+1; i++){
    if(i > 1)printf(" ");
    printf("%d",B[i]);
  }
  printf("\n");
  
  return 0;
}

int Max(int *A, int n){
  int max=A[0];
  int i;

  for(i = 1; i < n; i++){
    if(A[i] > max) max = A[i];
  }
  return max;
}

void CountingSort(int *A, int *B, int k, int n){
  int C[k+1];
  int i,j;

  for(i = 0; i < k+1; i++){
    C[i] = 0;
  }

  for(j = 0; j < n; j++){
    C[A[j]]++;
  }
  
  for(i = 1; i < k+1; i++){
    C[i] = C[i] + C[i-1];
  }

  for(j = n-1; j >= 0; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}


