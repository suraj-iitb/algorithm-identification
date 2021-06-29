/* Bubble Sort */
#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int* A, int N) { 
  int flag = 1; // 逆の隣接要素が存在する
  int counter = 0;

  while (flag) {
    int j;

    flag = 0;
    for (j=N-1; j>=1; j--) {
      if (A[j] < A[j-1]) {
	int tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	
	flag = 1;
	counter++;
      }
    }
  }

  return counter;
}

int main(void) {
  int A[100]; // 数列
  int N; // 数列の長さ
  int i;
  int count; // 交換回数
  
  scanf("%d", &N);

  // 数列読み込み
  for (i=0; i<N; i++)
    scanf("%d", &A[i]);

  count = bubbleSort(A, N);

  for (i=0; i<N; i++) {
    printf("%d", A[i]);
    if (i != N-1)
      putchar(' ');
  }
  putchar('\n');

  printf("%d\n", count);

  return 0;
}
