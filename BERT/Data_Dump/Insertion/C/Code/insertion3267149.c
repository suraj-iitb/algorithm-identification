#include<stdio.h>

void insertionSort(int);

int main(){
  int N;
  scanf("%d",&N);
  
  insertionSort(N);
  
  return 0;
}

void insertionSort(int N){
  int i, j, v, A[N], k;

  for(k = 0; k <= N - 1; k++)
    scanf("%d", &A[k]);
  
  for(k = 0; k <= N - 1; k++)
    if(k == N - 1)
      printf("%d", A[k]);
    else
      printf("%d ", A[k]);
  
  printf("\n");
  
  for(i = 1; i <= N - 1; i++){
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
    
    for(k = 0; k <= N - 1; k++)
      if(k == N - 1)
	printf("%d", A[k]);
      else
	printf("%d ", A[k]);
    printf("\n");
  }
}

