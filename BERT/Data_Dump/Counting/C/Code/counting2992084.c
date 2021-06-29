#include <stdio.h>

#define N 2000001

int B[N], C[N];

void countingSort(int A[], int B[], int k, int n){
  int i, j;

  for(i = 0; i <= k; i++){
    C[i] = 0;
  }
  for(j = 1; j <= n; j++){
    C[A[j]]++;
  }   
  for(i = 1; i <= k; i++){
    C[i] = C[i] + C[i - 1];
  } 
  for(j = n; j >= 1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i = 1; i <= n; i++){
    printf("%d", B[i]);
    if(i != n) printf(" ");
  }
  printf("\n");

}

int main(){
  int A[N];
  int i, j, n, k = 0;

  //input
  scanf("%d", &n); 
  for(i = 1; i <= n; i++){
    scanf("%d", &A[i]);
    if(k < A[i]) k = A[i];
  }

  //sort and out
  countingSort(A, B, k, n);

  return 0;
}

