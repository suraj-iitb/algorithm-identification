#include<stdio.h>
#include<stdlib.h>

int n;

void CountingSort(int A[],int B[],int k){
  int C[k+1];
  int i,j;
  for(i=0;i<k+1;i++){
    C[i] = 0;
  }
  for(i=1;i<=n;i++){
    C[A[i]]++;
  }
  for(i=1;i<k+1;i++){
    C[i] = C[i] + C[i-1];
  }
  for(j=n;j>0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

int main(){
  int i,max = -100000;
  int *A,*B;

  scanf("%d",&n);
  A = malloc(sizeof(int)*(n+1));
  B = malloc(sizeof(int)*(n+1));

  for(i=1;i<=n;i++){
    scanf("%d",&A[i]);
    if(max<A[i])max = A[i];
  }
  CountingSort(A,B,max);

  for(i=1;i<=n;i++){
    printf("%d",B[i]);
    if(i<n)printf(" ");
  }
  puts("");
  free(A);
  free(B);

  return 0;
}
