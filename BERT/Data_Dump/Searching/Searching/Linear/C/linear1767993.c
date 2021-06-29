#include <stdio.h>
#define N 10000

int linearSearch(int x);

int s[N], t[N], n, q;

int main()
{
  int c=0, i, j;

  scanf("%d", &n);
  for(i=0; i<n; i++)
    scanf("%d", &s[i]);

  scanf("%d", &q);
  for(i=0; i<q; i++)
    scanf("%d", &t[i]);

  
  for(i=0; i<q; i++){
    c += linearSearch(i);
  }
  printf("%d\n",c);

  return 0;
}

int linearSearch(int x)
{
  int i = 0;
  s[n] = t[x];
  while(s[i]!=t[x]){
    i++;
    if(i==n) return 0;
  }
  return 1;
}
