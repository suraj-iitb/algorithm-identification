#include<stdio.h>
#define N 2000000
#define M 10000

void CountingSort(int*,int*,int);
int A[N+1],B[N+1],C[M+1],n;

int main(){
  int i;

  scanf("%d",&n);
  for(i = 0; i < n; i++)
  scanf("%d",&A[i+1]);

  CountingSort(A,B,M);

  for(i = 0; i < n; i++){
    if(i >= 1) printf(" ");
    printf("%d",B[i+1]);
  }
  printf("\n");
  return 0;

}

void CountingSort(int A[],int B[],int k){
  int i,j;

  for(i = 0; i <= k; i++)
    C[i] = 0;

  for(j = 1; j <= n; j++)
    C[A[j]]++;

  for(i = 1; i <= k; i++)
    C[i] = C[i] + C[i-1];

  for(j = n; j >= 1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
