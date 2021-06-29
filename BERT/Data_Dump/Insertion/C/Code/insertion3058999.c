# include<stdio.h>

void trace(int A[], int N) {
  int i;
  for ( i = 0; i < N; i++) {
    if (i > 0) printf(" "); // 2つ目の要素の前には空白
    printf("%d",A[i]);
  }
  printf("\n");
}

/* 挿入ソート */
void insertionSort(int A[], int N) {
  int j,v;
  for (int i = 1; i < N; i++) {
    v = A[i]; // pivot
    j = i - 1;
    while (j>=0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    trace(A, N);
  }
}

int main(void) {
  int N,i,j;
  int A[100];
  scanf("%d\n", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &A[i]);
  }
  trace(A, N);
  insertionSort(A,N);
  return 0;
}
