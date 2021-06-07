#include <stdio.h>

#define N 10000
#define Q 501

int LinerSearch(int *, int *, int, int);


int main() {
  int i, n, q, ans;
  int data1[N], data2[Q];


  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &data1[i]);
  }

  scanf("%d", &q);

  for (i = 0; i < q; i++) {
    scanf("%d", &data2[i]);
  }

  ans = LinerSearch(data1, data2, n, q);
  
  printf("%d\n", ans);
  
  return 0;
  
}


int LinerSearch(int *s, int *t, int n, int q) {
  int i, j, key, count = 0;
  
  for (i = 0; i < q; i++) {
    s[n] = t[i];
    for (j = 0; j <= n; j++) {
      if (j != n && s[j] == t[i]) {
	count++;
	break;
      }
    }
  }

  return count;
}


