#include <stdio.h>

#define MAX 2000001

void CountingSort(int [], int [], int, int);

int B[MAX], C[MAX];

int main(){
  
  int A[MAX];
  int n, i, j, l = 0;

  scanf("%d", &n); 
  for(i = 1; i <= n; i++){
    scanf("%d", &A[i]);
    if(l < A[i]) l = A[i];
  }

  CountingSort(A, B, l, n);

  return 0;
}

void CountingSort(int A[], int B[], int l, int n){
  
  int i, j;

  for(i = 0; i <= l; i++)
    C[i] = 0;
  
  for(j = 1; j <= n; j++)
    C[A[j]]++;

  for(i = 1; i <= l; i++)
    C[i] = C[i] + C[i - 1];
 
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


