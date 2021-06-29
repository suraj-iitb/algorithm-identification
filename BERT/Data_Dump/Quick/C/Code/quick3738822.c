#include <stdio.h>

#define INFTY 1000000001
 
void merge(int a[], char mark[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int l[n1 + 1], r[n2 + 1];
  char lm[n1 + 1], rm[n2 + 1];
  int i, j, k;
  for (i = 0; i < n1; i++) {
    l[i] = a[left + i];
    lm[i] = mark[left + i];
  }
  for (i = 0; i < n2; i++) {
    r[i] = a[mid + i];
    rm[i] = mark[mid + i];
  }
  l[n1] = INFTY;
  r[n2] = INFTY;
  i = 0;
  j = 0;
  for (k = left; k < right; k++) {
    if (l[i] <= r[j]) {
      mark[k] = lm[i];
      a[k] = l[i++];
    }
    else {
      mark[k] = rm[j];
      a[k] = r[j++];
    }
  }
}
 
void merge_sort(int a[], char mark[], int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    merge_sort(a, mark, left, mid);
    merge_sort(a, mark, mid, right);
    merge(a, mark, left, mid, right);
  }
}

void sort_num(int *x, int *y) {
  int c;
  c = *x;
  *x = *y;
  *y = c;
}

void sort_mark(char *x, char *y) {
  char c;
  c = *x;
  *x = *y;
  *y = c;
}

int partition(int a[], char mark[], int p, int r) {
  int x = a[r];
  int i = p - 1;
  for (int j = p; j < r; j++)
    if (a[j] <= x) {
      i = i + 1;
      sort_num(&a[i], &a[j]);
      sort_mark(&mark[i], &mark[j]);
    }
  sort_num(&a[i + 1], &a[r]);
  sort_mark(&mark[i + 1], &mark[r]);
  return i + 1;
}

void quick_sort(int a[], char mark[], int p, int r) {
  int q;
  if (p < r) {
    q = partition(a, mark, p, r);
    quick_sort(a, mark, p, q - 1);
    quick_sort(a, mark, q + 1, r);
  }
}

int stable_check(int a[], int b[], char c[], char d[], int n) {
  for (int i = 0; i < n; i++)
    if (a[i] != b[i] || c[i] != d[i])
      return 0;
  return 1;
}

int main(void) {
  int n;
  int a[100000], acopy[100000];
  char mark[100001], markcopy[100000];
 
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf(" %c", &mark[i]);
    scanf("%d", &a[i]);
  }

  for (int i = 0; i < n; i++) {
    acopy[i] = a[i];
    markcopy[i] = mark[i];
  }

  quick_sort(a, mark, 0, n - 1);
  merge_sort(acopy, markcopy, 0, n);

  if (stable_check(a, acopy, mark, markcopy, n))
    printf("Stable\n");
  else
    printf("Not stable\n");
  
  for (int i = 0; i < n; i++)
    printf("%c %d\n", mark[i], a[i]);
  
  return 0;
}

