#include <stdio.h>
#include <math.h>
#include <string.h> 
#include <stdlib.h>
#include <stdbool.h>
#define ll long long
#define PI acos(-1)
#define Max 100000
#define SEX 2000000000

typedef struct {
  char suit;
  int value;
} Card;

int partition(Card a[], int p, int r) {
  int i;
  Card x, t;
  x = a[r];
  i = p - 1;
  for (int j = p; j < r; j++) {
    if (a[j].value <= x.value) {
      i++;
      t = a[j]; a[j] = a[i]; a[i] = t;
    }
  }
  t = a[r]; a[r] = a[i+1]; a[i+1] = t;

  return i+1;
}

void quicksort(Card a[], int p, int r) {
  if (p < r) {
    int q = partition(a, p, r);
    quicksort(a, p, q-1);
    quicksort(a, q+1, r);
  }
}

void merge(Card a[], int left, int mid, int right) {
  Card L[Max / 2 + 2], R[Max / 2 + 2];
  int n1 = mid - left;
  int n2 = right - mid;
  for (int i = 0; i < n1; i++) L[i] = a[left + i];
  for (int i = 0; i < n2; i++) R[i] = a[mid + i];
  L[n1].value = R[n2].value = SEX;

  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    if (L[i].value <= R[j].value) a[k] = L[i++];
    else a[k] = R[j++];
  }
 }

void mergesort(Card a[], int n, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(a, n, left, mid);
    mergesort(a, n, mid, right);
    merge(a, left, mid, right);
  }
}

int main () {
  int n;
  scanf("%d", &n);

  Card a[Max], b[Max];

  for (int i = 0; i < n; i++) {
    char s[10];
    int v;
    scanf("%s %d", s, &v);
    a[i].suit = s[0];
    b[i].suit = s[0];
    a[i].value = b[i].value = v;
  }

  mergesort(b, n, 0, n);
  quicksort(a, 0, n-1);

  int stable = 1;
  for (int i = 0; i < n; i++) {
    if (a[i].suit != b[i].suit) stable = 0;
  }

  if (stable) printf("Stable\n");
  else printf("Not stable\n");
  
  for (int i = 0; i < n; i++) {
    printf("%c %d\n", a[i].suit, a[i].value);
  }

  return 0;
}
