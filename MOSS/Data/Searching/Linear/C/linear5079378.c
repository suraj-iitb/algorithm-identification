#include <stdio.h>

#define NMAX 10000
#define QMAX 500

int LSearch(int, int);

int t[QMAX], s[NMAX];

int main(){
  int n, i, q, c = 0;

  scanf("%d", &n);
  for(i=0; i<n; i++)
    scanf("%d", &s[i]);

  scanf("%d", &q);
  for(i=0; i<q; i++)
    scanf("%d", &t[i]);

  for(i=0; i<q; i++)
    if(LSearch(i, n) == 1)
      c++;

  printf("%d\n", c);
}

int LSearch(int i, int n){
  int m;
    s[n] = t[i];
    for(m = 0; s[m] != t[i]; m++);
    if(m == n)
      return 0;
    else
      return 1;
}

