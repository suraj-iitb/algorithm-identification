#include<stdio.h>

#define MAX 100

void Bsort(int a[], int n);

int main(void) {
  int A[MAX];
  int N;
  scanf("%d", &N);

  for(int i=0; i<N; ++i) {
    scanf("%d", &A[i]);
  }

  Bsort(A, N);

  return 0;
}

void Bsort(int a[], int n) {
  int tmp, j;
  int c = 0;
  int flag = 1;
  int i = 0;

  while(flag) {
    flag = 0;
    for(j=n-1; j>=i+1; --j) {
      if(a[j] < a[j-1]) {
        tmp = a[j];
        a[j] = a[j-1];
        a[j-1] = tmp;

        c++;
        flag = 1;
      }
    }
    ++i;
  }

  for(j=0; j<n; ++j) {
    if(j != n-1) {
      printf("%d ", a[j]);
    }
    else printf("%d\n", a[j]);
  }
  printf("%d\n", c);

}

