#include<stdio.h>

#define MAX 1000000000

int n;
int s[MAX];
int linearSearch(int);

int main()
{
  int i, q, count = 0;
  int t;

  scanf("%d", &n);
  for( i = 0; i < n; i++)
    {
      scanf("%d", &s[i]);
    }
  
  scanf("%d", &q);
  for( i = 0; i < q; i++)
    {
      scanf("%d", &t);
      count += linearSearch(t);
    }
  printf("%d\n", count);

  return 0;
}
  
int linearSearch(int key)
{
  int i = 0;
  
  s[n] = key;

  while(s[i] != key)
    {
      i++;
    }
  if(i==n)return 0;
  return 1;
}

