#include <stdio.h>

int bubblesort(int [100], int N);

int main(){
  int A[100], N, i, x;
  scanf("%d", &N);
  for(i=0;i<N;i++) scanf("%d", &A[i]);
  x=bubblesort(A,N);
  for(i=0;i<N-1;i++) printf("%d ", A[i]);
  printf("%d\n", A[N-1]);
  printf("%d\n", x);
  return 0;
}

int bubblesort(int A[100], int N){
  int flag = 1, count=0, v, j;
  while (flag){
    flag = 0;
    for(j=N-1;j>=1;j--){
      if(A[j] < A[j-1]){
	v=A[j];
	A[j]=A[j-1];
	A[j-1]=v;
	count++;
	flag = 1;
      }
    }
  }
  return count;
}

