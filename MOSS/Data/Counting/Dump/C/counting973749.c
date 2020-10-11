#include<stdio.h>
#define N 2000001
void CountingSort(int);

int n, A[N], B[N];



int main(void){
  int i, k=0;
  scanf("%d", &n);
  for(i=1; i <= n; i++){
    scanf("%d", &A[i]);
    if(A[i] > k) k = A[i];
}
  CountingSort(k);
  for(i=1; i <= n; i++){
 printf("%d", B[i]);
 if(i < n)printf(" ");
  }
  printf("\n");
  return 0;
}


void CountingSort(int k){
  int i, j, C[N];
  for(i = 0; i <= k; i++) C[i]=0;
  for(j = 1; j <= n; j++) C[A[j]]++;
  for(i = 1; i <= k; i++) C[i] = C[i] + C[i-1];
  for(j = n; j >=0; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}
