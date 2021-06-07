#include <stdio.h>

#define NMAX 100000
#define QMAX 50000

int BSearch(int, int);

int s[NMAX], t[QMAX];

int main(){
  int n, i, q, c = 0;
  scanf("%d", &n);
  for(i=0; i<n; i++)
    scanf("%d", &s[i]);

  scanf("%d", &q);
  for(i=0; i<q; i++)
    scanf("%d", &t[i]);

  for(i=0; i<q; i++)
    if(BSearch(i, n) == 1)
     c++;

  printf("%d\n", c);
  return 0;
}

int BSearch(int i, int n){
  int k, l = 0, m, sum;
  k = t[i];

  while(n > l){
    m = (n + l) / 2;

    if(k < s[m])
      n = m;

    else if(k == s[m])
      return 1;

    else
      l = m + 1;
  }
  return 0;
}

