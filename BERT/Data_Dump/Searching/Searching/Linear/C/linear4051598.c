#include <stdio.h>

#define N 10000
#define NIL -1

int linearSearch(int *, int, int);

int main() {

  int s[N];
  int t[N];
  int n, q;
  int cnt = 0;
  int i;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &s[i]);
  }

  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &t[i]);
  }

  for (i = 0; i < q; i++) {
    if(linearSearch(s, n, t[i]) != NIL){
      cnt++;
    }
  }
  printf("%d\n", cnt);
  
  return 0;
}


int linearSearch(int s[], int n, int k) {
  int i;
  for (i = 0; i < n; i++) {
    if(s[i] == k) {
      return i;
    }
  }
  return NIL;
}

