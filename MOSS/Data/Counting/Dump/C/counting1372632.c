#include <stdio.h>
#define MAX 2000001

int A[MAX], B[MAX], C[MAX];

int main(){

  int i, n;

  // Input n
  scanf("%d", &n);

  // Initialize
  for(i = 0; i < MAX; i++){
    A[i] = 0;    
    B[i] = 0;
    C[i] = 0;
  }

  // Input A[]
  for(i = 1; i <= n; i++) scanf("%d", &A[i]);

  // Counting number
  for(i = 0; i < n; i++) C[A[i+1]]++;

  // Calculate cumulative sum
  for(i = 1; i < MAX; i++) C[i] = C[i] + C[i-1];

  // Counting Sort
  for(i = n; i >= 1; i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }

  // Output
  for(i = 1; i <= n; i++){
    printf("%d", B[i]);
    if(i < n) printf(" ");
   }
  printf("\n");

  return 0;
}
