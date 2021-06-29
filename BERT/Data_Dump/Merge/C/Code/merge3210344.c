#include <stdio.h>
#include <math.h>
#define Max 500000
int S[Max], n;
int Inf = (int)INFINITY;
int cnt = 0;
int L[Max / 2 + 1], R[Max / 2 + 1];

void merge (int S[], int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  for (i = 0; i < n1; ++i) {
    L[i] = S[left + i];
  }
  for (i = 0; i < n2; ++i) {
    R[i] = S[mid + i];
  }
  L[n1] = Inf;
  R[n2] = Inf;
  i = 0;
  j = 0;
  for (k = left; k < right; ++k) {
    ++cnt;
    if (L[i] <= R[j]) {
      S[k] = L[i];
      ++i;
    }
    else {
      S[k] = R[j];
      ++j;
    }
  }
}

void mergeSort (int S[], int left, int right) {
  if (left+1 < right) {
    int mid = (left + right)/2;
    mergeSort(S, left, mid);
    mergeSort(S, mid, right);
    merge(S, left, mid, right);
  }
}

int main(void) {
  int i = 0;
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &S[i]);
  }
  mergeSort(S, 0, n);
  for (i = 0; i < n; ++i) {
    printf("%d", S[i]);
    if (i == n - 1) break;
    printf(" ");
  }
  putchar('\n');
  printf("%d\n", cnt);
}

