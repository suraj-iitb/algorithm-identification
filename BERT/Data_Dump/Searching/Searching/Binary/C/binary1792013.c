#include <stdio.h>

int binarySearch(int);

int S[100000], n;

int main()
{
  int i, key, q, C = 0;

  scanf("%d", &n);

  for( i = 0 ; i < n ; i++ ) scanf("%d", &S[i]);

  scanf("%d", &q);

  for( i = 0 ; i < q ; i++ ){
    scanf("%d", &key);
    if( binarySearch(key) != 0 ) C++;
  }

  printf("%d\n", C);

  return 0;
}

int binarySearch(int k)
{
  int left = 0;
  int right = n;
  int mid;
  
  while( left < right ){
    mid = (left + right) / 2;
    if( S[mid] == k ) return 1;
    else if( k < S[mid] ) right = mid;
    else left = mid + 1;
  }

  return 0;
}
