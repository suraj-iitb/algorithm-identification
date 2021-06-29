#include <stdio.h>
#include <stdlib.h>

#define N 500000
#define INFTY (1000000001)

typedef struct {
    char c[3];
    int n;
} Card;

void swap(Card *, Card *);
int partition(Card *, int, int);
void quickSort(Card *, int, int);

void merge(Card *, int, int, int);
void mergeSort(Card *, int, int);
Card *makeArray(int);
void copyArray(Card *, Card *, int, int);

int main() {
  Card card[N];
  Card m[N];
  int n, i, flg;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%s %d", card[i].c, &card[i].n);
  }

  for (i = 0; i < n; i++) {
    m[i] = card[i];
  }

  quickSort(card, 0, n-1);
  mergeSort(m, 0, n);

  flg = 0;
  for (i = 0; i < n; i++) {
    if (m[i].c[0] != card[i].c[0]) {
        flg = 1;
    }
  }
  if (flg == 0) {
      printf("Stable\n");
  }
  else {
      printf("Not stable\n");
  }

  for (i = 0; i < n; i++) {
    printf("%s %d\n", card[i].c, card[i].n);
  }

  return 0;
}

void swap(Card *a, Card *b) {
  Card temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

int partition(Card *A, int p, int r) {
  int x = A[r].n;
  int i = p - 1;
  int j;

  for (j = p; j < r; j++) {
    if (A[j].n <= x) {
      i++;
      swap(&A[i], &A[j]);
    }
  }
  swap(&A[i + 1], &A[r]);

  return i + 1;
}

void quickSort(Card *A, int p, int r) {
  int q;
  if (p < r) {
    q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

void mergeSort(Card *A, int left, int right) {
  int mid;

  if (left + 1 < right) {
    mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }

}

void merge(Card *A, int left, int mid, int right) {
  int i, j, k;

  int nl = mid - left;
  int nr = right - mid;

  Card *L = makeArray(nl + 1);
  Card *R = makeArray(nr + 1);

  copyArray(L, A, nl, left);
  copyArray(R, A, nr, mid);
  L[nl].n = R[nr].n = INFTY;

  j = i = 0;
  for (k = left; k < right; k++) {
    if (L[i].n <= R[j].n) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }

  free(L);
  free(R);
}

Card *makeArray(int size) {
  return (Card *)malloc(size * sizeof(Card));
}

void copyArray(Card *A, Card *B, int n, int m) {
  int i;
  for (i = 0; i < n; i++) {
    A[i] = B[m + i];
  }
}

