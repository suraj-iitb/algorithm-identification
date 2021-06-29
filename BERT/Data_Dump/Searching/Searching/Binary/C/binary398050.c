#include <stdio.h>
#include <math.h>
#define MAX_N 100001

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void quick_sort(int *begin, int *end) {
  int n = end - begin;
  int p, i;
  if(n < 1) return;
  swap(begin, begin+rand()%n);
  p = 0;
  for(i = 1; i < n; ++i) {
    if(begin[i] < begin[0]) {
      ++p;
      swap(begin+p,begin+i);
    }
  }
  swap(begin+p, begin);
  quick_sort(begin,begin+p);
  quick_sort(begin+p+1,end);
}

int binarry_search(int *begin, int *end, int value) {
  int l, r, m;
  l = 0;
  r = end-begin;
  while(l < r) {
    m = (l+r)/2;
    if(begin[m] == value)
      return 1;
    else if(begin[m] < value) 
      l = m+1;
    else
      r = m;
  }
  return 0;
}

int main() {
  int n, q, S[MAX_N], t, num;
  int i;
  scanf("%d", &n);
  for(i = 0; i < n; ++i) {
    scanf("%d", S+i);
  }
  quick_sort(S,S+n);
  num = 0;
  scanf("%d", &q);
  while(q--) {
    scanf("%d", &t);
    if(binarry_search(S,S+n,t)) ++num;
  }
  printf("%d\n", num);
  return 0;
}
