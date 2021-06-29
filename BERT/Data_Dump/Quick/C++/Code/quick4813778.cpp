/**
** クイックソート
**/

#include<cstdio>

#define  MAX 100000
#define SENTINEL 2000000000

struct Card {
  char suit;
  int value;
};

struct Card L[MAX/2+2], R[MAX/2+2];

int partition(struct Card A[], int p, int r) {
  struct Card x = A[r];
  int i = p - 1;

  for (int j = p; j < r; j++) {
    if (A[j].value <= x.value) {
      i++;
      struct Card tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }

  A[r] = A[i+1];
  A[i+1] = x;
  return i+1;
}

void quickSort(struct Card A[], int p, int r) {
  int q;
  if (p < r) {
      q = partition(A, p, r);
      quickSort(A, p, q-1);
      quickSort(A, q+1, r);
  }
}

void merge(struct Card A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;

  for (int i = 0; i < n1; i++) L[i] = A[left+i];
  for (int i = 0; i < n2; i++) R[i] = A[mid+i];
  L[n1].value = R[n2].value = SENTINEL;

  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    if (L[i].value <= R[j].value) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

void mergeSort(struct Card A[], int left, int right) {
  int mid;
  if (left + 1 < right) {
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  struct Card A[MAX], B[MAX];
  int stable = 1;

  int n, v; char S[10];
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s %d", S, &v);
    A[i].suit = B[i].suit = S[0];
    A[i].value = B[i].value = v;
  }

  quickSort(A, 0, n-1);
  mergeSort(B, 0, n);

  for (int i = 0; i < n; i++) {
    if (A[i].suit != B[i].suit) {
      stable = 0;
      break;
    }
  }

  if (stable) printf("Stable\n");
  else printf("Not stable\n");
  for (int i = 0; i < n; i++) {
    printf("%c %d\n", A[i].suit, A[i].value);
  }

  return 0;
}

