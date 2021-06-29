#include<stdio.h>

int n;
int A[2000001], B[2000001];
void countingSort(int*, int*, int);

int main(){
  int i;
  scanf("%d", &n);
  for(i = 0 ; i < n ; i++){
    scanf("%d", &A[i]);
  }
  countingSort(A, B, 10001);
  for(i = 1 ; i <= n ; i++){
    printf("%d", B[i]);
    if(i != n) printf(" ");
    else printf("\n");
  }
}

void countingSort(int* A, int* B, int k){
  int C[k], i;
  for(i = 0 ; i < k ; i++) C[i] = 0;
  for(i = 0 ; i < n ; i++) C[A[i]]++;
  for(i = 1 ; i < k ; i++) C[i] = C[i] + C[i-1];
  for(i = n-1 ; i >= 0 ; i--){
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
}

