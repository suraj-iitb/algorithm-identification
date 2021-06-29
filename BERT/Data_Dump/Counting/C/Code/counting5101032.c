#include <stdio.h>

#define MAX 2000001

void counting(int A[],int c,int b){
  int i, j;
  int B[b];
  int C[c];

  for (j = 0 ; j < b ; j++)
    B[j] = 0;

  for (i = 0 ; i < c ; i++ )
    B[A[i]]++;

  for (j = 1 ; j < b ; j++)
    B[j] += B[j - 1];

  for (i = c - 1 ; i >= 0 ; i--) {
    C[B[A[i]]-1] = A[i];
    B[A[i]]--;
  }

  for(i = 0 ; i < c ; i++)
    A[i] = C[i];
}

int main(){
  int A[MAX];
  int n, i, j,max=0;

  scanf("%d", &n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
    if(max < A[i]){
      max = A[i];
    }
  }

  for(i = 0 ; i < n ; i++){
    if(i == 0)
      counting(A,n,max+1);
      printf("%d",A[i]);
    if(i != n - 1) printf(" ");
  }
  printf("\n");

  return 0;
}
