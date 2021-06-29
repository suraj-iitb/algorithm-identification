#include <stdio.h>
#define N 2000000
int n,A[N],B[N],i;
void CountingSort(int*,int*,int);
int main(){
  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&A[i]);
    }
  CountingSort(A,B,n);
  return 0;
}
void CountingSort(int *A,int *B,int n){
  int i,j,C[N];
  for(i = 0;i < N;i++){
    C[i] = 0;
    }
  for(j = 0;j < n;j++){
    C[A[j]]++;
    }
  for(i = 1;i <= N;i++){
    C[i] = C[i] + C[i - 1];
    }
  for(j = n;j >= 0;j--){
    B[C[A[j]]] = A[j];
    (C[A[j]])--;
  }
  for(i = 1;i <= n;i++){
    if(i-1)printf(" ");
    printf("%d",B[i]);
    }
  printf("\n");
}

