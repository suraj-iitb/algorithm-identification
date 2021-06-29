#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int A[], int N){
  int flag = 1, i, t, c = 0;
  while(flag){
    flag = 0;
    for(i = N-1; i > 0; i--){
      if(A[i] < A[i-1]){
	t = A[i];
	A[i] = A[i-1];
	A[i-1] = t;
	flag = 1;
	c++;
      }
    }
  }
  for(i = 0; i < N; i++){
    printf("%d",A[i]);
    if(i <= N-2) printf(" ");
  }
  printf("\n%d\n", c);
}


int main(void){
  int i, n;
  scanf("%d", &n);
  int *a;
  a = malloc(n * sizeof(int));
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  bubbleSort(a, n);
  return 0;
}
