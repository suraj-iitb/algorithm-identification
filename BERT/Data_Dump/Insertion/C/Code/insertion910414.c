#include<stdio.h>

static const int N = 1000;

void trace(int A[], int n){
  int i;
  for (i = 1; i <= n; i++){
    if(i > 1) printf(" ");
      printf("%d", A[i]);
  }  
  printf("\n");
}

int main(){
  int n, i ,j;
  int A[N + 1];
  scanf("%d", &n);
  for (i = 1; i <= n; i++){
    scanf("%d", &A[i]);
  }

  for (i = 2; i <= n; i++){
    A[0] = A[i];
    trace(A, n);
    j = i - 1;
    while (j >= 1 && A[j] > A[0]){
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = A[0];
  }
  trace(A, n);
  return 0;

}
