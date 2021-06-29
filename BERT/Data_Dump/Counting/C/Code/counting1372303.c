#include<stdio.h>

void CountingSort(int);

int A[20000000];
int B[20000000];
int C[20000000];

int n;

int main(){

  int i;
  int Max = 0;
  scanf("%d",&n);

  for(i = 1;i <= n;i++){
    scanf("%d",&A[i]);
      
    if(Max < A[i]){ 
      Max = A[i];
    }
  }

  CountingSort(Max);
  
  for(i = 1;i <= n-1;i++){
    printf("%d ",B[i]);
  }
  printf("%d\n",B[i]);
  return 0;
}

void CountingSort(int k){

  int i, j;

  for(i = 0;i <=k;i++){
    C[i] = 0;
  }

  for(j = 1;j <=n;j++){

    C[A[j]]++;
  }

  for(i = 1;i <=k;i++){
    C[i] = C[i] + C[i-1];
  }

    for(j = n;j >=1;j--){

      B[C[A[j]]] = A[j];
      C[A[j]]--;

  }
}
