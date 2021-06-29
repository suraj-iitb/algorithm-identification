#include <stdio.h>
int main() {
  int n;
  scanf("%d", &n);
  int q[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &q[i]);
  }
  int s;
  scanf("%d", &s);
  int t[s];
  for (int i = 0; i < s; i++) {
    scanf("%d", &t[i]);
  }
  int count = 0;
  for (int i = 0; i < s; i++) {
    for (int j = 0; j < n; j++) {
      if (t[i] == q[j]) {
        count++;
        break;
      }
    }
  }
  printf("%d\n", count);
  return 0;
}
