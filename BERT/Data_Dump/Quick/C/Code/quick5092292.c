#include <stdio.h>
#include <string.h>
int Partition(int *, int *, char *, int, int);
void QSort(int *, int *, char *, int, int);
int main() {
  int i, n, s = 0;
  int A[200000], B[200000];
  char ch, C[100000];

  scanf("%d%c", &n, &ch);
  for (i = 0; i < n; i++) {
    scanf("%c%c%d%c", &C[i], &ch, &A[i], &ch);
    B[i] = i;
  }

  QSort(A, B, C, 0, n - 1);
  for (i = 0; i < n; i++) {
    if (B[i] > B[i + 1] && A[i] == A[i + 1]) {
      s = 1;
      break;
    }
  }
  if (s == 0)
    printf("Stable\n");
  else
    printf("Not stable\n");
  for (i = 0; i < n; i++) {
    printf("%c %d\n", C[i], A[i]);
  }
  return 0;
}

void QSort(int *A, int *B, char *C, int p, int r) {
  int q;
  if (p < r) {
    q = Partition(A, B, C, p, r);
    QSort(A, B, C, p, q - 1);
    QSort(A, B, C, q + 1, r);
  }
}

int Partition(int *A, int *B, char *C, int p, int r) {
  int x, i, j, temp;
  char ch;
  x = A[r];
  i = p - 1;
  for (j = p; j < r; j++) {
    if (A[j] <= x) {
      i++;
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
      temp = B[i];
      B[i] = B[j];
      B[j] = temp;
      ch = C[i];
      C[i] = C[j];
      C[j] = ch;
    }
  }
  temp = A[i + 1];
  A[i + 1] = A[r];
  A[r] = temp;
  temp = B[i + 1];
  B[i + 1] = B[r];
  B[r] = temp;
  ch = C[i + 1];
  C[i + 1] = C[r];
  C[r] = ch;
  return i + 1;
}

