#include <stdio.h>
#define MAX 100

int count = 0;

void print_array(int *A, int N) {
  int i;
  for(i = 0; i < N - 1; i++) {
    printf("%d ", A[i]);
  }
  printf("%d\n", A[i]);
}

void bubbleSort(int *A, int N) {
  int j, v, frag = 1;
  while(frag) {
    frag = 0;
    for(j = N - 1; j >= 1; j--) {
      if(A[j] < A[j-1]) {
	v = A[j];
	A[j] = A[j-1];
	A[j-1] = v;
	frag = 1;
	count++;
      }
    }
  }
}

int main() {
  int n, i, a[MAX];
  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  bubbleSort(a, n);
  print_array(a, n);
  printf("%d\n", count);
  return 0;
}

