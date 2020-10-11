#include <stdio.h>

static const int N = 100;

void trace(int A[], int n, int count){
  int i;
  for(i = 0; i < n; i++){
    if(i > 0)printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", count);
}

int main(){
  int i, j, n,a;
  int count=0;
  int A[N];

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  
  for(i = 0; i < n; i++){
    for(j = n - 1; j >= i + 1; j--){
      if(A[j] < A[j-1]){
	a = A[j];
	A[j] = A[j-1];
	A[j-1] = a;
	count++;
      }
    }
  }
  trace(A, n, count);
  
  return 0;
}
