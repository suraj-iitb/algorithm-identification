#include<stdio.h>
#include<stdlib.h>
#define N 10000
int n;
void CountingSort(int *,int *);
int main(){
  int A[2000000],i,B[2000000];
  scanf("%d",&n);
  for(i=1;i<n+1;i++){
    scanf("%d",&A[i]);
  }
  CountingSort(A,B);
  for(i=1;i<=n-1;i++){
    printf("%d ",B[i]);
  }
  printf("%d",B[n]);
  printf("\n");
  return 0;
}

void CountingSort(int A[],int B[]){
  int i,j;
  int C[N];
  for(i=0;i<=N;i++){
    C[i] = 0;
  }
  for(j=1;j<n+1;j++){
    C[A[j]]++;
  }
  for(i=1;i<=N;i++){
    C[i]=C[i]+C[i-1];
  }
  for(j=n;0<j;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

