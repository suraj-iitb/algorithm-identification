#include <stdio.h>
#define N 2000001

void countingSort(int A[], int k, int n){
  int i, j;
  int B[N],C[N];

  for(i = 0 ; i <= k ; i++){
    C[i] = 0;
  }
  for(j = 1 ; j <= n ; j++){
    C[A[j]]++;
  }
  for(i = 1 ; i <= k ; i++){
    C[i] = C[i] + C[i - 1];
  }
  for(j = n ; j >= 1 ; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i = 1 ; i <= n ; i++){
    printf("%d", B[i]);
    if(i != n){
       printf(" ");
     }
  }
  printf("\n");

}

int main(){
  int i, j, n;
  int k=0;


  scanf("%d", &n);
  int A[n];
  for(i = 1 ; i <= n ; i++){
    scanf("%d", &A[i]);
    if(k < A[i]){
      k = A[i];
    }
  }

  countingSort(A,k,n);
  return 0;
}

