#include <stdio.h>
#include <math.h>
#include <string.h> 
#include <stdlib.h>
#include <stdbool.h>
#define ll long long
#define PI acos(-1)
#define Max 500000
#define SENTINEl 2000000000

int L[Max/2+2], R[Max/2+2];
int cnt;
void merge(int a[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  for (int i = 0; i < n1; i++) L[i] = a[left + i];
  for (int i = 0; i < n2; i++) R[i] = a[mid + i];
  L[n1] = SENTINEl;
  R[n2] = SENTINEl;

  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    cnt++;
    if (L[i] <= R[j]) a[k] = L[i++];
    else a[k] = R[j++];
  }
 }

void mergesort(int a[], int n, int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergesort(a, n, left, mid);
    mergesort(a, n, mid, right);
    merge(a, left, mid, right);
  }
}

int main () {
  cnt = 0;
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  mergesort(a, n, 0, n);

  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%d", a[i]);
  }

  printf("\n");
  printf("%d\n", cnt);
  return 0;
}
