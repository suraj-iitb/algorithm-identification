#include <stdio.h>
 
int linear_search(int s[], int n,  int key) {
  int i = 0;
  s[n] = key;
  while(s[i] != key)
    i++;
  return i != n;
}
 
int main(void) {
  int n ,q;
  int s[10001];
  int t[500];
  int i;
  int count = 0;
   
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &s[i]);
  scanf("%d", &q);
  for (i = 0; i < q; i++)
    scanf("%d", &t[i]);
 
  for (i = 0; i < q; i++) {
    count += linear_search(s, n, t[i]);
  }
 
  printf("%d\n", count);
   
  return 0;
}
