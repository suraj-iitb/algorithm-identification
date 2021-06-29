#include <stdio.h>

int l[250002];
int r[250002];
int count = 0;

void merge(int a[], int left, int mid, int right) {
  int n1, n2, i;
  n1 = mid - left;
  n2 = right - mid;
  for (i = 0; i < n1; i++)
    l[i] = a[left+i];
  for (i = 0; i < n2; i++)
    r[i] = a[mid+i];
  l[n1] = 2000000000;
  r[n2] = 2000000000;
  i = 0;
  int j = 0;
  int k;
  for (k = left; k < right; k++) {
    if (l[i] <= r[j]) {
      a[k] = l[i++];
    } else {
      a[k] = r[j++];
    }
    count++;
  }
}

void mergesort(int a[], int left, int right) {
  if (left+1 < right) {
    int mid = (left + right) / 2;
    mergesort(a, left, mid);
    mergesort(a, mid, right);
    merge(a, left, mid, right);
  }
}

int main(void)
{
  int n, i;
  int s[500000];
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &s[i]);
  mergesort(s, 0, n);
  printf("%d", s[0]);
  for (i = 1; i < n; i++)
    printf(" %d", s[i]);
  printf("\n");
  printf("%d\n", count);
  return 0;
}

