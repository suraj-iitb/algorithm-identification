#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct card {
  char mark;
  int rank;
};

void quicksort(struct card *A, int p, int r);
int partition(struct card *A, int p, int r);

int main(int argc, char *argv[])
{
  int n, i, j, stable, order, max = 0;
  struct card *A;
  struct card *original;
  char m[4];

  scanf("%d", &n);
  A = (struct card *)malloc(sizeof(struct card) * n);
  for (i = 0; i < n; i++) {
    scanf("%s", &(A[i].mark));
    scanf("%d", &(A[i].rank));
    max = (int)fmax(max, A[i].rank);
  }
  original = (struct card *)malloc(sizeof(struct card) * n);
  memcpy(original, A, sizeof(struct card) * n);

  quicksort(A, 0, n - 1);

  stable = 1;
  for (i = 1; i <= max; i++) {
    order = 0;
    for (j = 0; j < n; j++) {
      if (original[j].rank == i) m[order++] = original[j].mark;
    }
    order = 0;
    for (j = 0; j < n; j++) {
      if (A[j].rank == i) {
        if (A[j].mark != m[order]) {
          stable = 0;
          break;
        }
        order++;
      }
    }
    if (stable == 0) break;
  }

  if (stable == 1) printf("Stable\n");
  else printf("Not stable\n");
  for (i = 0; i < n; i++) printf("%c %d\n", A[i].mark, A[i].rank);

  return 0;
}

void quicksort(struct card *A, int p, int r)
{
  int q;

  if (p < r) {
    q = partition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}

int partition(struct card *A, int p, int r)
{
  int x = A[r].rank, i = p - 1, j;
  struct card tmp;

  for (j = p; j < r; j++) {
    if (A[j].rank <= x) {
      i++;
      memcpy(&tmp, &A[j], sizeof(struct card));
      memcpy(&A[j], &A[i], sizeof(struct card));
      memcpy(&A[i], &tmp, sizeof(struct card));
    }
  }
  memcpy(&tmp, &A[r], sizeof(struct card));
  memcpy(&A[r], &A[i+1], sizeof(struct card));
  memcpy(&A[i+1], &tmp, sizeof(struct card));

  return i+1;
}
