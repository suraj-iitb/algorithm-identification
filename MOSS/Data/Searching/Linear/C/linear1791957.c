#include <stdio.h>

int calcu(int, int);

int C = 0;
int S[10001];

int main()
{
  int i, n, q;
  int key; 

  scanf("%d",&n);

  for( i = 0 ; i < n ; i++ ) scanf("%d", &S[i]);
  
  scanf("%d",&q);
  
  for( i = 0 ; i < q ; i++ ){
    scanf("%d", &key);
    if( calcu(key, n) ) C++;;
  }
  
  printf("%d\n", C);
  
  return 0;
}
 
int calcu(int k, int n)
{
  int i=0;

  S[n] = k;
  while( S[i] != k ) i++;

  return  i != n;
}
