#include<stdio.h>

int s[10000];
int n;

int linerSearch(int);

int main()
{
  int q, c=0, i;
  int t[500];

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &s[i]);
  }

  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &t[i]);
  }

  for(i = 0; i < q; i++){
    if(1 == linerSearch(t[i])) c++;
  }

  printf("%d\n", c);

  return 0;
}

int linerSearch(int key)
{
  int i;
  
  i = 0;
  s[n] = key;
  while(s[i] != key) i++;
  if(i == n) return 0;
  else return 1;
}
