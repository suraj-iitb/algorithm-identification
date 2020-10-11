#include <stdio.h>

void CountingSort(short*,short*,int);

int n;

int main(){
  int i;
  int k=0;
  short A[2000001], B[2000001];

  scanf("%d",&n);

  for(i = 1; i <= n; i++){
    scanf("%d",&A[i]);
    if(k < A[i]) k = A[i];
  }
  CountingSort(A,B,k);

  for(i = 1; i < n; i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[i]);

  return 0;
}

void CountingSort(short* A,short* B,int k){
  int i,j;
  int C[10001];
  for(i = 0; i <= k; i++){
    C[i] = 0;
  }

  for(j = 1; j <= n; j++){
    C[A[j]]++;
  }

  for(i = 1; i <= k; i++){
    C[i] = C[i] + C[i-1];
  }

  for(j = n; j >= 1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
