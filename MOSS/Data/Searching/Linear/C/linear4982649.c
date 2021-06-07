#include <stdio.h>

  int a[10000] = {0}, b, m, n, count = 0;

int find(int x) {
    for (int i = 0; i < m; i++) {
        if (a[i]==b) {
            return 1;
        }
    }
    return 0;
}

int main(){

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &a[i]);
  }

  scanf("%d", &n);
  for (int j = 0; j < n; j++) {
    scanf("%d", &b);
    if (find(b)==1) {
      count++;
    }
  }
  printf("%d\n", count);
  return 0;
}
