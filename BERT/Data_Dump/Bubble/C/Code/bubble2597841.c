#include<stdio.h>

int bubbleSort(int A[], int N){
  int i, j, temp;
  int sw = 0;
  int flag = 1;

  for (i=0; flag == 1; i++) {
    flag = 0;
    for (j=N-1; j>=i+1; j--) {
      if (A[j-1] > A[j]) {
        temp   = A[j-1];
        A[j-1] = A[j];
        A[j]   = temp;
        sw++;
        flag = 1;
      }
    }
  }
  return sw;
}


int main(){
  int A[100], N, sw, i;
  scanf("%d", &N);
  for (i=0; i<N; i++)
    scanf("%d", &A[i]);

  sw = bubbleSort(A, N);

  for (i=0; i<N; i++) {
    if (i>0)
      putchar(' ');
    printf("%d", A[i]);
  }
  printf("\n%d\n", sw);
  return 0;
}
