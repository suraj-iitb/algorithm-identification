#include<stdio.h>

#define MAX 100

void Ssort(int a[], int n);

int main(void) {
  int A[MAX];
  int N;
  scanf("%d", &N);

  for(int i=0; i<N; ++i) {
    scanf("%d", &A[i]);
  }

  Ssort(A, N);

  return 0;
}

void Ssort(int a[], int n) {
  int i, j, count = 0;
  int tmp, minj;

  for(i=0; i<=n-1; ++i) {
    minj = i;
    for(j=i; j<=n-1; ++j) {
      if(a[j] < a[minj]) minj = j;
    }
    tmp = a[i];
    a[i] = a[minj];
    a[minj] = tmp;
    if(i != minj) ++count;
  }

  for(i=0; i<n; ++i) {
    if(i != n-1) {
      printf("%d ", a[i]);
    }
    else printf("%d\n", a[i]);
  }
  printf("%d\n", count);
  
}

