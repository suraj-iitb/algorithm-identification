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
  int left, mid, right;

  left = 0;
  right = n;

  while( left < right ){
    mid = ( left + right ) / 2;

    if( s[mid] == num ) return 1;
    else if( num < s[mid] ) right = mid;
    else left = mid +1;
  }

  return 0;
}
