#include <stdio.h>

#define MAX_N 100000

typedef struct {
  char mark;
  int num;
  int idx;
} Card;

int n;
Card A[MAX_N];

void swap(Card *a, Card *b) {
  Card tmp = *a;
  *a = *b;
  *b = tmp;
}

int partition(int p, int r) {
  Card x = A[r];
  int i = p-1, j;
  for(j = p; j < r; j++) {
    if(A[j].num <= x.num) {
      i++;
      swap(&A[i], &A[j]);
    }
  }
  swap(&A[i+1], &A[r]);
  return i+1;
}

void quickSort(int p, int r) {
  if(p < r) {
    int q = partition(p, r);
    quickSort(p, q-1);
    quickSort(q+1, r);
  }
}

int main() {
  int i;

  scanf("%d", &n);
  for(i = 0; i < n; i++) {
    scanf(" %c %d", &A[i].mark, &A[i].num);
    A[i].idx = i;
  }
  quickSort(0, n-1);
  int flag = 1;
  for(i = 0; i < n-1; i++) {
    if(A[i].num == A[i+1].num && A[i].idx > A[i+1].idx) flag = 0;
  }
  puts((flag ? "Stable" : "Not stable"));
  for(i = 0; i < n; i++) {
    printf("%c %d\n", A[i].mark, A[i].num);
  }

  return 0;
}
