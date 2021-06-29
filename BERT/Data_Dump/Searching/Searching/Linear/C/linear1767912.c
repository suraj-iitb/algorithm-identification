#include <stdio.h>

#define MAX 100000

int n, s[MAX];

int numsearch(int );

int main()
{
  int i, j, ans, count=0, q, t[MAX];

  scanf("%d", &n);

  for( i=0; i<n; i++){
    scanf("%d", &s[i]);
  }

  scanf("%d", &q);

  for( i=0; i<q; i++){
    scanf("%d", &t[i]);
  }

  for( i=0; i<q; i++){
    if( numsearch(t[i]) == 1 )count++;
  }

  printf("%d\n", count);

  return 0;
}

int numsearch(int num)
{
  int i;

  for( i=0; i<n; i++){
    if( s[i] == num )return 1;
  }

  return 0;
}
