#include <stdio.h>
#include <limits.h>

long c = 0;

void merge(long *a, long left, long mid, long right){
  long n1, n2, i, j, k;
  n1 = mid - left;
  n2 = right - mid;
  long l[n1 + 1], r[n2 + 1];
  for(i = 0; i < n1; ++i) l[i] = a[left + i];
  for(i = 0; i < n2; ++i) r[i] = a[mid + i];
  l[n1] = LONG_MAX;
  r[n2] = LONG_MAX;
  i = 0;
  j = 0;
  for(k = left; k < right; ++k){
    if(l[i] <= r[j]) a[k] = l[i++];
    else a[k] = r[j++];
    c++;
  }
}

void merge_sort(long *a, long left, long right){
  if(left + 1 < right){
    long mid = (left + right) / 2;
    merge_sort(a, left, mid);
    merge_sort(a, mid, right);
    merge(a, left, mid, right);
  }
}

int main(){
  long n, s[500000], i, j;
  scanf("%ld", &n);
  for(i = 0; i < n; ++i) scanf("%ld", s + i);

  merge_sort(s, 0, n);

  for(i = 0; i < n; ++i) printf(i != 0 ? " %ld" : "%ld", s[i]);
  printf("\n%ld\n", c);
  return 0;
}
