#include <stdio.h>

#define INFTY 1000000001

int count = 0;

void merge(int a[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int l[n1 + 1], r[n2 + 1];
  int i, j, k;
  for (i = 0; i < n1; i++)
    l[i] = a[left + i];
  for (i = 0; i < n2; i++)
    r[i] = a[mid + i];
  l[n1] = INFTY;
  r[n2] = INFTY;
  i = 0;
  j = 0;
  for (k = left; k < right; k++) {
    if (l[i] <= r[j]) 
      a[k] = l[i++];
    else
      a[k] = r[j++];
    count++;
  }
}

void merge_sort(int a[], int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    merge_sort(a, left, mid);
    merge_sort(a, mid, right);
    merge(a, left, mid, right);
  }
}

int main(void) {
  int n;
  int s[500000];
  
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &s[i]);

  merge_sort(s, 0, n);
  
  for (int i = 0; i < n; i++) {
    printf("%d", s[i]);
    if (i != n - 1)
      printf(" ");
  }
  printf("\n%d\n", count);
  
  return 0;
}

